/*
 * vtx_uh60_misc_fnc_ccLockSeats
 *
 * Reconciles the swap-seat locks to the desired state - the single source
 * of truth, recomputed from occupancy on every call (callers guard vehicle
 * locality). Rules come from the pair table (vtx_uh60_misc_ccPairs):
 *  - "out" pairs (DAP turn-out): the turned-out spot is ALWAYS locked -
 *    swap-only, fnc_ccSwap is the only way in or out (the owner opens both
 *    ends of the swap and marks them in vtx_ccSwapBusy, which this function
 *    skips - see fnc_ccSwapLocks). The crew-chief seat is locked while the
 *    spot is OCCUPIED (Riverman ruling 2026-09-18: the vacated seat stays
 *    reserved for the turned-out crew chief), open otherwise.
 *  - "hoist" pairs (hoist operator): the pendant seat is NOT touched - it
 *    is an ordinary pax seat owned by the #612 door lock. The crew seat is
 *    locked while the vehicle's designated hoist operator is on the pendant
 *    seat (reserved for their return), open otherwise - a pax merely
 *    sitting on the pendant seat reserves nothing. A designation whose
 *    unit is no longer on the pendant seat (dismounted, changed seat, died)
 *    is cleared here, so the reservation can never outlive the operator.
 *  - everything else (pax "Door ..." seats, copilot): untouched.
 * Only seats THIS function locked are ever unlocked by it (vtx_ccHeld on
 * the vehicle, public so a new owner inherits it): the reconcile runs on
 * every crew change of every variant, and a mission maker's own lockTurret
 * on a gunner seat must survive that.
 * Any GetIn/GetOut/SeatSwitched reconciles, so a crew chief killed in a
 * seat reopens it on the next crew change.
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
private _pathOf = {
    params ["_name"];
    private _i = _turrets findIf {(_x # 1) == _name};
    if (_i == -1) then {[]} else {(_turrets # _i) # 0}
};

// hoist operator: drop a designation that no longer points at the pendant seat
private _operator = _veh getVariable ["vtx_hoistOperator", objNull];
if (!isNull _operator) then {
    private _pendant = [vtx_uh60_misc_ccHoistSeat] call _pathOf;
    if (_pendant isEqualTo [] || {!((_veh turretUnit _pendant) isEqualTo _operator)}) then {
        _veh setVariable ["vtx_hoistOperator", nil, true];
        _operator = objNull;
    };
};

private _lock = [];
private _unlock = [];
{
    _x params ["_from", "_to", "_kind"];
    private _fromPath = [_from] call _pathOf;
    private _toPath = [_to] call _pathOf;
    if (!(_fromPath isEqualTo []) && {!(_toPath isEqualTo [])}) then {
        switch (_kind) do {
            case "out": {
                _lock pushBackUnique _toPath;
                if (isNull (_veh turretUnit _toPath)) then {
                    _unlock pushBackUnique _fromPath;
                } else {
                    _lock pushBackUnique _fromPath;
                };
            };
            case "hoist": {
                if (!isNull _operator && {(_veh turretUnit _toPath) isEqualTo _operator}) then {
                    _lock pushBackUnique _fromPath;
                } else {
                    _unlock pushBackUnique _fromPath;
                };
            };
        };
    };
} forEach vtx_uh60_misc_ccPairs;
_lock = _lock - _busy;
private _held = _veh getVariable ["vtx_ccHeld", []];
_unlock = (_unlock - _busy) select {_x in _held};
_veh setVariable ["vtx_ccHeld", (_held - _unlock) + (_lock - _held), true];

private _debug = missionNamespace getVariable ["vtx_uh60_ui_showDebugMessages", false];
{_veh lockTurret [_x, false]} forEach _unlock;
if (_toggle) then {
    {_veh lockTurret [_x, false]} forEach _lock;
    [{
        params ["_veh", "_lock", "_unlock", "_debug"];
        // a swap may have opened one of these paths since they were computed
        _lock = _lock - (_veh getVariable ["vtx_ccSwapBusy", []]);
        {_veh lockTurret [_x, true]} forEach _lock;
        if (_debug) then {diag_log format ["VTX CC RELOCK: %1 locked %2 open %3 readback %4", typeOf _veh, _lock, _unlock, _lock apply {_veh lockedTurret _x}];};
    }, [_veh, _lock, _unlock, _debug]] call CBA_fnc_execNextFrame;
} else {
    {_veh lockTurret [_x, true]} forEach _lock;
    if (_debug) then {diag_log format ["VTX CC LOCK: %1 locked %2 open %3 readback %4", typeOf _veh, _lock, _unlock, _lock apply {_veh lockedTurret _x}];};
};
