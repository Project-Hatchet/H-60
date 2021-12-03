/*
 * vtx_uh60_cas_fnc_clearCautionsList
 *
 * clears clearable master cautions
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle", ["_autoClearOnly", false]];

private _casList = (_vehicle getVariable ["vtx_cas_list",[]]);

private ["_condition"];
{ // forEach _casList;
    _condition = _x # 1;
    _wantToClear = (_x # 2 && _autoClearOnly || !_autoClearOnly);
    if (!(call _condition) && _wantToClear) then {
        [_vehicle, _x # 0] call vtx_uh60_cas_fnc_removeCautionAdvisory;
    };
} forEach _casList;
if(!_autoClearOnly) then { _vehicle animate ["CautionMasterCaution", 0] };
