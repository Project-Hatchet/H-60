/*
 * vtx_uh60_misc_fnc_ccSwap
 *
 * DAP crew-chief "turn out" replacement (Riverman rulings 2026-09-17/18): the
 * aft MFOS seats have no FFV turn-out (the out-pose clips through floor and
 * seat back), so this swaps the occupant between their crew-chief seat and
 * the turned-out spot on the SAME side - the aft door-sill sitting position
 * in the cargo door (the base M's "Door Left 1"/"Door Right 2" proxies) - out
 * to see and clear the tail, back to the seat. Driven by the contextual
 * "Turn Out"/"Turn In" vehicle interactions in XEH_postInit. Uses the
 * moveOut -> one-beat -> moveInTurret pattern (a direct move from inside
 * silently fails).
 *
 * The turned-out seats stay LOCKED (init hook in XEH_postInit) so they never
 * show in any menu; a locked turret refuses even moveInTurret (the 47's
 * hoist-crew law), so the swap is a handshake with the vehicle's owner
 * (fnc_ccSwapLocks), which is rarely the crew chief's machine in MP:
 *  1. ask the owner to open the target AND the seat being left
 *  2. wait until the target READS BACK unlocked - nobody is moved before
 *     that, so a request that never lands leaves the unit in its seat
 *  3. moveOut, then moveInTurret every frame until aboard; if the target
 *     keeps refusing, fall back to the seat the unit came from
 *  4. hand both paths back to the owner, which reconciles the locks
 * (dev tester report 2026-09-29: in hosted MP the one-shot move-in was
 * refused and the swap left the crew chief outside the aircraft.)
 *
 * Seats are matched by gunnerName so the turret paths never need hardcoding:
 * "L Crew Chief" <-> "L Crew Chief (Turned Out)", same for R.
 *
 * params (array)[(object) unit, (optional bool) dry-run,
 *                (optional string) direction "out"/"in"/"" = either]
 * returns bool - dry-run: whether a swap is currently possible
 */
params ["_unit", ["_dryRun", false], ["_dir", ""]];

private _veh = objectParent _unit;
if (isNull _veh) exitWith {false};

// [seated name, counterpart, direction of the swap FROM that seat]
private _pairs = [
    ["L Crew Chief", "L Crew Chief (Turned Out)", "out"],
    ["R Crew Chief", "R Crew Chief (Turned Out)", "out"],
    ["L Crew Chief (Turned Out)", "L Crew Chief", "in"],
    ["R Crew Chief (Turned Out)", "R Crew Chief", "in"]
];

private _crew = fullCrew [_veh, "", true];
private _mine = _crew findIf {(_x # 0) isEqualTo _unit};
if (_mine == -1) exitWith {false};
private _myName = getText (([_veh, (_crew # _mine) # 3] call BIS_fnc_turretConfig) >> "gunnerName");

private _pair = _pairs select {(_x # 0) == _myName && {_dir == "" || {(_x # 2) == _dir}}};
if (_pair isEqualTo []) exitWith {false};
private _tgtName = (_pair # 0) # 1;

private _tgt = _crew findIf {
    isNull (_x # 0)
    && {!((_x # 3) isEqualTo [])}
    && {getText (([_veh, _x # 3] call BIS_fnc_turretConfig) >> "gunnerName") == _tgtName}
};
if (_tgt == -1) exitWith {false};
if (_dryRun) exitWith {true};

private _path = (_crew # _tgt) # 3;
private _from = (_crew # _mine) # 3;

// the target is locked whenever it matters (turned-out spots always; the
// vacated crew-chief seat while its owner is turned out). Both ends of the
// swap are opened and marked busy on the owner, which keeps the lock
// reconcile (fnc_ccLockSeats, fired by any GetIn/GetOut mid-swap) off them;
// the close step releases them and reconciles, which computes every final
// lock state from the new occupancy - including the fail paths, so a botched
// move can't strand a seat locked or open.
["vtx_uh60_misc_ccSwapOpen", [_veh, [_from, _path]], _veh] call CBA_fnc_targetEvent;

[{
    params ["", "_veh", "", "_path"];
    !(_veh lockedTurret _path)
 },
 {
    params ["_unit", "_veh", "_from", "_path"];
    if !(objectParent _unit isEqualTo _veh) exitWith {
        ["vtx_uh60_misc_ccSwapClose", [_veh, [_from, _path]], _veh] call CBA_fnc_targetEvent;
    };
    moveOut _unit;
    [{
        params ["_args", "_handle"];
        _args params ["_unit", "_veh", "_from", "_path", "_start", "_wasOut"];
        private _out = isNull objectParent _unit;
        if (_out) then {_args set [5, true];};
        private _elapsed = CBA_missionTime - _start;
        if ((_wasOut && {!_out}) || {!alive _unit} || {_elapsed > 4}) exitWith {
            [_handle] call CBA_fnc_removePerFrameHandler;
            ["vtx_uh60_misc_ccSwapClose", [_veh, [_from, _path]], _veh] call CBA_fnc_targetEvent;
        };
        if (_out) then {
            // target first; back to the seat the unit came from if it
            // keeps refusing
            _unit moveInTurret [_veh, if (_elapsed < 1.5) then {_path} else {_from}];
        };
    }, 0, [_unit, _veh, _from, _path, CBA_missionTime, false]] call CBA_fnc_addPerFrameHandler;
 },
 [_unit, _veh, _from, _path], 3,
 {
    // the unlock never read back: nobody was moved, just release the paths
    params ["", "_veh", "_from", "_path"];
    ["vtx_uh60_misc_ccSwapClose", [_veh, [_from, _path]], _veh] call CBA_fnc_targetEvent;
 }] call CBA_fnc_waitUntilAndExecute;
true
