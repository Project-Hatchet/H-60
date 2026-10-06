/*
 * vtx_uh60_misc_fnc_ccSwapLocks
 *
 * Owner side of the crew-chief swap handshake (fnc_ccSwap): runs where the
 * vehicle is LOCAL, reached through the vtx_uh60_misc_ccSwapOpen/Close CBA
 * target events (XEH_preInit). The owner is the ONLY writer of the
 * vtx_ccSwapBusy list, so two crew chiefs swapping at the same time add and
 * remove their own paths without clobbering each other (the variable is
 * public only so a new owner inherits it on a locality transfer).
 *  - open:  marks the paths busy (fnc_ccLockSeats skips them) and unlocks
 *           them - the swapping client waits for the unlock to read back
 *           before it moves anyone
 *  - close: releases the paths and reconciles, which computes every final
 *           lock state from the new occupancy
 *
 * params (array)[(object) vehicle, (array) turret paths, (bool) open]
 * returns nothing
 */
params ["_veh", "_paths", "_open"];

if (isNull _veh) exitWith {};

private _busy = +(_veh getVariable ["vtx_ccSwapBusy", []]);
if (_open) then {
    {_busy pushBackUnique _x} forEach _paths;
    _veh setVariable ["vtx_ccSwapBusy", _busy, true];
    {_veh lockTurret [_x, false]} forEach _paths;
} else {
    _busy = _busy - _paths;
    _veh setVariable ["vtx_ccSwapBusy", _busy, true];
    [_veh, false] call vtx_uh60_misc_fnc_ccLockSeats;
};
