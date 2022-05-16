/*
 * vtx_uh60_fms_fnc_interaction_pageChange
 *
 * handle page changes
 *
 * params (array)[(object) vehicle, (array) newpage]
 */

params ["_vehicle", "_newPage", "_propagate"];

if (_newPage # 1 == 18) then {
    private _displayName = getText (configFile >> "cfgVehicles" >> typeof _vehicle >> "displayName");
    if (!("MH-60" in _displayName)) then {
        _newPage set [1, 19];
    };
};

if (_propagate) exitWith {
    [_vehicle, _newPage, false] remoteExecCall ["vtx_uh60_fms_fnc_interaction_pageChange", crew _vehicle];
};

_vehicle setUserMFDValue _newPage;
[_vehicle] call vtx_uh60_fms_fnc_perSecond;
