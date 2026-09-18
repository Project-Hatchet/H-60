/*
 * vtx_uh60_misc_fnc_ccLockSeats
 *
 * Reconciles the DAP crew-chief seat locks to the desired state - the single
 * source of truth, recomputed from occupancy on every call (callers guard
 * vehicle locality):
 *  - "(Turned Out)" spots: ALWAYS locked - swap-only, fnc_ccSwap is the only
 *    way in or out (it briefly unlocks its target and marks the path in the
 *    vtx_ccSwapBusy variable, which this function skips).
 *  - "L/R Crew Chief": locked while their "(Turned Out)" counterpart is
 *    OCCUPIED (Riverman ruling 2026-09-18: the vacated seat stays reserved
 *    for the turned-out crew chief), open otherwise. The GetOut hook
 *    reconciles again when the crew chief dismounts entirely from the
 *    turned-out spot, so the seat reopens. (A crew chief killed in a seat
 *    reopens it on the next crew change - any GetIn/GetOut reconciles.)
 *  - everything else (pax "Door ..." seats, copilot): untouched.
 *
 * Toggle mode drops and re-asserts the WANTED locks one frame apart: a lock
 * TRANSITION is what invalidates the stale in-vehicle action list (test-fit
 * 5, 2026-09-18) - and an occupant survives a re-lock (47 hoist-crew law),
 * so this is safe with someone seated.
 *
 * params (array)[(object) vehicle, (optional bool) toggle re-assert]
 * returns nothing
 */
params ["_veh", ["_toggle", false]];

private _busy = _veh getVariable ["vtx_ccSwapBusy", []];
private _turrets = (allTurrets [_veh, true]) apply {
    [_x, getText (([_veh, _x] call BIS_fnc_turretConfig) >> "gunnerName")]
};

private _lock = [];
private _unlock = [];
{
    _x params ["_path", "_name"];
    if !(_path in _busy) then {
        if (_name find "(Turned Out)" > -1) then {
            _lock pushBack _path;
        } else {
            if (_name in ["L Crew Chief", "R Crew Chief"]) then {
                private _outName = _name + " (Turned Out)";
                private _i = _turrets findIf {(_x # 1) == _outName};
                if (_i > -1 && {!isNull (_veh turretUnit ((_turrets # _i) # 0))}) then {
                    _lock pushBack _path;
                } else {
                    _unlock pushBack _path;
                };
            };
        };
    };
} forEach _turrets;

{_veh lockTurret [_x, false]} forEach _unlock;
if (_toggle) then {
    {_veh lockTurret [_x, false]} forEach _lock;
    [{
        params ["_veh", "_lock", "_unlock"];
        {_veh lockTurret [_x, true]} forEach _lock;
        diag_log format ["VTX CC RELOCK: %1 locked %2 open %3 readback %4", typeOf _veh, _lock, _unlock, _lock apply {_veh lockedTurret _x}];
    }, [_veh, _lock, _unlock]] call CBA_fnc_execNextFrame;
} else {
    {_veh lockTurret [_x, true]} forEach _lock;
    diag_log format ["VTX CC LOCK: %1 locked %2 open %3 readback %4", typeOf _veh, _lock, _unlock, _lock apply {_veh lockedTurret _x}];
};
