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
 * hoist-crew law), so the target is unlocked for exactly this one move and
 * relocked once the unit is aboard. Lock commands go to the vehicle's owner
 * (remoteExecCall on the object = its owner; local call in SP/hosted).
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

// the target is locked whenever it matters (turned-out spots always; the
// vacated crew-chief seat while its owner is turned out), and a locked
// turret refuses even moveInTurret (47 hoist-crew law) - so open it for
// exactly this one move. The busy marker keeps the lock reconcile
// (fnc_ccLockSeats, fired by any GetIn/GetOut mid-swap) off that path; the
// finish step clears it and reconciles, which computes every final lock
// state from the new occupancy - including the fail paths, so a botched
// move can't strand a seat locked or open.
private _finish = {
    params ["_unit", "_veh", "_path"];
    _veh setVariable ["vtx_ccSwapBusy", [], true];
    [_veh, false] remoteExecCall ["vtx_uh60_misc_fnc_ccLockSeats", _veh];
};
_veh setVariable ["vtx_ccSwapBusy", [_path], true];
[_veh, [_path, false]] remoteExecCall ["lockTurret", _veh];
moveOut _unit;
[{isNull objectParent (_this # 0)},
 {
    params ["_unit", "_veh", "_path", "_finish"];
    _unit moveInTurret [_veh, _path];
    [{objectParent (_this # 0) isEqualTo (_this # 1)},
     (_this # 3), [_unit, _veh, _path], 5, (_this # 3)
    ] call CBA_fnc_waitUntilAndExecute;
 },
 [_unit, _veh, _path, _finish], 3, _finish] call CBA_fnc_waitUntilAndExecute;
true
