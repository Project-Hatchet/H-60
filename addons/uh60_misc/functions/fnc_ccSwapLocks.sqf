/*
 * vtx_uh60_misc_fnc_ccSwapLocks
 *
 * Owner side of the seat-swap handshake (fnc_ccSwap): runs where the
 * vehicle is LOCAL, reached through the vtx_uh60_misc_ccSwapOpen/Close CBA
 * target events (XEH_preInit). The owner is the ONLY writer of the
 * vtx_ccSwapBusy list, so two crew chiefs swapping at the same time add and
 * remove their own paths without clobbering each other (the variable is
 * public only so a new owner inherits it on a locality transfer).
 *  - open:  marks the paths busy (fnc_ccLockSeats skips them) and unlocks
 *           them - the swapping client waits for the unlock to read back
 *           before it moves anyone
 *  - close: releases the paths, settles the hoist-operator designation and
 *           reconciles, which computes every final lock state from the new
 *           occupancy
 *
 * The hoist-operator designation (vtx_hoistOperator, public, on the
 * vehicle) is written HERE and only here, from where the unit actually
 * ended up - so a swap that fell back to the origin seat never designates,
 * and the designation can't race ahead of the reconcile that reserves the
 * crew seat (setVariable and the close event are separate network messages
 * if the client wrote it). fnc_ccLockSeats clears a stale designation
 * (operator no longer on the pendant seat) on every crew change.
 *
 * params (array)[(object) vehicle, (array) turret paths, (bool) open,
 *                (optional object) swapping unit, (optional string) kind]
 * returns nothing
 */
params ["_veh", "_paths", "_open", ["_unit", objNull], ["_kind", ""]];

if (isNull _veh) exitWith {};

private _busy = +(_veh getVariable ["vtx_ccSwapBusy", []]);
if (_open) then {
    {_busy pushBackUnique _x} forEach _paths;
    _veh setVariable ["vtx_ccSwapBusy", _busy, true];
    {_veh lockTurret [_x, false]} forEach _paths;
} else {
    _busy = _busy - _paths;
    _veh setVariable ["vtx_ccSwapBusy", _busy, true];
    if (_kind in ["hoist", "unhoist"] && {!isNull _unit}) then {
        private _onPendant = false;
        if (objectParent _unit isEqualTo _veh) then {
            private _seat = (fullCrew [_veh, "", true]) select {(_x # 0) isEqualTo _unit};
            if !(_seat isEqualTo []) then {
                private _name = getText (([_veh, (_seat # 0) # 3] call BIS_fnc_turretConfig) >> "gunnerName");
                _onPendant = _name == vtx_uh60_misc_ccHoistSeat;
            };
        };
        private _operator = _veh getVariable ["vtx_hoistOperator", objNull];
        if (_onPendant) then {
            if !(_operator isEqualTo _unit) then {_veh setVariable ["vtx_hoistOperator", _unit, true];};
        } else {
            if (_operator isEqualTo _unit) then {_veh setVariable ["vtx_hoistOperator", nil, true];};
        };
    };
    [_veh, false] call vtx_uh60_misc_fnc_ccLockSeats;
};
