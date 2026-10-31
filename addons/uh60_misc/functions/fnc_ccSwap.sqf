/*
 * vtx_uh60_misc_fnc_ccSwap
 *
 * Scripted seat swap between two seats of the SAME vehicle, driven by the
 * contextual vehicle interactions in XEH_postInit. Two uses:
 *  - DAP crew-chief "turn out" (Riverman rulings 2026-09-17/18): the aft
 *    MFOS seats have no FFV turn-out (the out-pose clips through floor and
 *    seat back), so the occupant swaps between their crew-chief seat and
 *    the door-sill turned-out spot on the same side - out to see and clear
 *    the tail, back to the seat.
 *  - Hoist operator (Riverman ruling 2026-09-23): the right crew chief
 *    swaps onto the "(hoist controls)" pendant seat and back. The owner
 *    designates them the vehicle's hoist operator when the swap lands
 *    (fnc_ccSwapLocks) - the pendant seat itself stays an ordinary pax seat.
 *
 * The move is the engine's own in-vehicle seat change first, with the
 * moveOut -> moveInTurret pattern as the fallback (a direct moveInTurret
 * from inside silently fails). The pairs, their kinds and extra conditions live
 * in vtx_uh60_misc_ccPairs (XEH_preInit), matched by gunnerName so the
 * turret paths never need hardcoding and a vehicle only offers the pairs
 * whose seats it has.
 *
 * Several targets are LOCKED when it matters (turned-out spots always; a
 * vacated crew seat while its owner is away), and a locked turret refuses
 * even moveInTurret (the 47's hoist-crew law), so the swap is a handshake
 * with the vehicle's owner (fnc_ccSwapLocks), which is rarely the crew
 * chief's machine in MP:
 *  1. ask the owner to open the target AND the seat being left
 *  2. wait until the target READS BACK unlocked - nobody is moved before
 *     that, so a request that never lands leaves the unit in its seat
 *  3. native seat change; if refused for 1 s: moveOut, then moveInTurret
 *     every frame until aboard, and if the target keeps refusing, back to
 *     the seat the unit came from
 *  4. hand both paths back to the owner, which settles the hoist-operator
 *     designation from where the unit actually ended up and reconciles
 *     the locks
 * (dev tester report 2026-09-29: in hosted MP the one-shot move-in was
 * refused and the swap left the crew chief outside the aircraft.)
 *
 * params (array)[(object) unit, (optional bool) dry-run,
 *                (optional string) kind "out"/"in"/"hoist"/"unhoist"/"" = any]
 * returns bool - dry-run: whether a swap is currently possible
 */
params ["_unit", ["_dryRun", false], ["_kind", ""]];

private _veh = objectParent _unit;
if (isNull _veh) exitWith {false};

private _crew = fullCrew [_veh, "", true];
private _mine = _crew findIf {(_x # 0) isEqualTo _unit};
if (_mine == -1) exitWith {false};
private _myName = getText (([_veh, (_crew # _mine) # 3] call BIS_fnc_turretConfig) >> "gunnerName");

// Every row seated here of the wanted kind is a candidate: several crew-seat
// names share the pendant seat, so the way back has one row per name and
// only the row whose target exists on THIS vehicle can match (test report
// 2026-10-06: taking just the first row left the MEDEVAC and S-70i operator
// with no way back). The target must also be EMPTY - a pax sitting on the
// pendant seat blocks the way in, a pax who took the reserved crew seat
// after its owner died blocks the way back.
private _tgt = -1;
private _pairKind = "";
{
    _x params ["_fromName", "_tgtName", "_rowKind", "_condition"];
    if (_fromName == _myName && {_kind == "" || {_rowKind == _kind}} && {[_veh, _unit] call _condition}) then {
        _tgt = _crew findIf {
            isNull (_x # 0)
            && {!((_x # 3) isEqualTo [])}
            && {getText (([_veh, _x # 3] call BIS_fnc_turretConfig) >> "gunnerName") == _tgtName}
        };
        if (_tgt > -1) then {_pairKind = _rowKind;};
    };
    if (_tgt > -1) exitWith {};
} forEach vtx_uh60_misc_ccPairs;
if (_tgt == -1) exitWith {false};
if (_dryRun) exitWith {true};

private _path = (_crew # _tgt) # 3;
private _from = (_crew # _mine) # 3;

private _debug = missionNamespace getVariable ["vtx_uh60_ui_showDebugMessages", false];
private _hatchOf = {
    params ["_veh", "_turret"];
    getText (([_veh, _turret] call BIS_fnc_turretConfig) >> "animationSourceHatch")
};
if (_debug) then {
    private _hatch = [_veh, _from] call _hatchOf;
    diag_log format ["VTX CC SWAP START: %1 kind %2 from %3 target %4 | unit turnedOut %5 anim %6 | origin hatch '%7' phase %8 | airborne %9",
        typeOf _veh, _pairKind, _from, _path, isTurnedOut _unit, animationState _unit,
        _hatch, if (_hatch == "") then {-1} else {_veh animationSourcePhase _hatch},
        !isTouchingGround _veh];
};

// The handshake proper. Both ends of the swap are opened and marked busy on
// the owner, which keeps the lock reconcile (fnc_ccLockSeats, fired by any
// crew change mid-swap) off them; the close step releases them and
// reconciles, which computes every final lock state from the new occupancy -
// including the fail paths, so a botched move can't strand a seat locked or
// open.
//
// The move itself is tried two ways:
//  1. NATIVE - the engine's own in-vehicle seat change (the scroll-menu
//     action). The unit never leaves the aircraft, so it gets the seat's
//     real boarding animation. This is the only method that works for the
//     MEDEVAC window seats: after an eject-and-reboard the engine keeps
//     dropping the unit back into an on-foot weapon animation while seated
//     ("floating outside the window", four test rounds 2026-10-06; a
//     switchMove repair fired 9 times in 4 s and lost every time).
//  2. EJECT - moveOut, then moveInTurret every frame until aboard, falling
//     back to the origin seat after 1.5 s. Used only when the native action
//     is refused for 1 s (it needs both seats in the same compartment). This
//     is the original method, proven on the DAP and the minigun seats in
//     hosted MP (2026-09-29).
private _swap = {
    params ["_unit", "_veh", "_from", "_path", "_pairKind", "_debug"];
    if !(objectParent _unit isEqualTo _veh) exitWith {};
    ["vtx_uh60_misc_ccSwapOpen", [_veh, [_from, _path]], _veh] call CBA_fnc_targetEvent;

    [{
        params ["", "_veh", "", "_path"];
        !(_veh lockedTurret _path)
     },
     {
        params ["_unit", "_veh", "_from", "_path", "_pairKind", "_debug"];
        if !(objectParent _unit isEqualTo _veh) exitWith {
            ["vtx_uh60_misc_ccSwapClose", [_veh, [_from, _path], _unit, _pairKind], _veh] call CBA_fnc_targetEvent;
        };
        _unit action ["MoveToTurret", _veh, _path];
        [{
            params ["_args", "_handle"];
            _args params ["_unit", "_veh", "_from", "_path", "_pairKind", "_debug", "_start", "_mode", "_wasOut"];
            private _out = isNull objectParent _unit;
            private _elapsed = CBA_missionTime - _start;
            private _done = false;

            if (_mode == "native") then {
                private _seated = !_out && {(_veh unitTurret _unit) isEqualTo _path};
                if (_seated || {_out} || {!alive _unit}) then {
                    _done = true;
                } else {
                    if (_elapsed > 1) then {
                        // refused: fall back to the eject method, clock restarted
                        _args set [6, CBA_missionTime];
                        _args set [7, "eject"];
                        moveOut _unit;
                    };
                };
            } else {
                if (_out) then {_args set [8, true];};
                if ((_wasOut && {!_out}) || {!alive _unit} || {_elapsed > 4}) then {
                    _done = true;
                } else {
                    if (_out) then {
                        // target first; back to the seat the unit came from
                        // if it keeps refusing
                        _unit moveInTurret [_veh, if (_elapsed < 1.5) then {_path} else {_from}];
                    };
                };
            };

            if (_done) then {
                [_handle] call CBA_fnc_removePerFrameHandler;
                ["vtx_uh60_misc_ccSwapClose", [_veh, [_from, _path], _unit, _pairKind], _veh] call CBA_fnc_targetEvent;
                if (_debug) then {
                    // logged now and again 2 s later: the pose a unit
                    // settles into is the evidence, not the one it lands with
                    private _log = {
                        params ["_unit", "_veh", "_path", "_from", "_elapsed", "_mode", "_tag"];
                        private _hatch = getText (([_veh, _path] call BIS_fnc_turretConfig) >> "animationSourceHatch");
                        diag_log format ["VTX CC SWAP %1 (%2): target %3 from %4 -> seat now %5 after %6s | turnedOut %7 anim %8 | target hatch '%9' phase %10 | in vehicle %11",
                            _tag, _mode, _path, _from,
                            ((fullCrew [_veh, "", false]) select {(_x # 0) isEqualTo _unit}) apply {_x # 3},
                            _elapsed, isTurnedOut _unit, animationState _unit,
                            _hatch, if (_hatch == "") then {-1} else {_veh animationSourcePhase _hatch},
                            objectParent _unit isEqualTo _veh];
                    };
                    [_unit, _veh, _path, _from, _elapsed, _mode, "END"] call _log;
                    [_log, [_unit, _veh, _path, _from, _elapsed, _mode, "END+2s"], 2] call CBA_fnc_waitAndExecute;
                };
            };
        }, 0, [_unit, _veh, _from, _path, _pairKind, _debug, CBA_missionTime, "native", false]] call CBA_fnc_addPerFrameHandler;
     },
     [_unit, _veh, _from, _path, _pairKind, _debug], 3,
     {
        // the unlock never read back: nobody was moved, just release the paths
        params ["", "_veh", "_from", "_path", "_pairKind"];
        ["vtx_uh60_misc_ccSwapClose", [_veh, [_from, _path], objNull, _pairKind], _veh] call CBA_fnc_targetEvent;
     }] call CBA_fnc_waitUntilAndExecute;
};

[_unit, _veh, _from, _path, _pairKind, _debug] call _swap;
true
