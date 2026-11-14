/*
 * vtx_uh60_cas_fnc_removeCautionAdvisory
 *
 * removes a caution/advisory in the cas system
 *
 * params (array)[(object) vehicle,(string) text]
 */

params ["_vehicle", ["_text",""]];

private _casList = (_vehicle getVariable ["vtx_cas_list",[]]);
{ // forEach _casList
    if (_text == _x # 0) exitWith {
        _casList deleteat _forEachIndex;
    };
} forEach _casList;

private _logIndex = vtx_uh60_cas_cautionsLog find _text;
if (_logIndex > -1) then {
    vtx_uh60_cas_cautionsLog deleteAt _logIndex;
    vtx_uh60_cas_cautionsUnacked = (vtx_uh60_cas_cautionsUnacked - 1) max 0;
};

_vehicle setVariable ["vtx_cas_list", _casList];
[_vehicle] call vtx_uh60_cas_fnc_updateCautionsList;
[_vehicle,false] call vtx_uh60_cas_fnc_updateOverlayList;
