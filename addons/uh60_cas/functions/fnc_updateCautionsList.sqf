/*
 * vtx_uh60_cas_fnc_updateCautionsList
 *
 * Updates the cautions list to the proper userTexts
 * This gets run from registerCautionAdvisory, removeCautionAdvisory and setup
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

private _casList = (_vehicle getVariable ["vtx_cas_list",[]]);

for "_i" from 0 to 6 do {
    if (_i >= count _casList) then {
        [_vehicle, 6 - _i, ""] call vtx_uh60_mfd_fnc_setUserText;
    } else {
         [_vehicle, 6 - _i, _casList # (((count _casList) - 1) - _i) # 0] call vtx_uh60_mfd_fnc_setUserText;
        
    };
};
