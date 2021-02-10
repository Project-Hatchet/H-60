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

_vehicle setVariable ["vtx_cas_list", _casList];
[_vehicle] call vtx_uh60_cas_fnc_updateCautionsList;
