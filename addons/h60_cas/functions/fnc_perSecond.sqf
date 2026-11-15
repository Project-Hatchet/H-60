/*
 * hct_h60_Cas_fnc_perSecond
 *
 * handles occasional updates of the caution system
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];

[_vehicle] call hct_h60_cas_fnc_updateCautionPanel;
[_vehicle] call hct_h60_cas_fnc_updateCautions;
[_vehicle] call hct_h60_cas_fnc_updateAdvisories;
