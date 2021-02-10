/*
 * vtx_uh60_Cas_fnc_perSecond
 *
 * handles occasional updates of the caution system
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];

[_vehicle] call vtx_uh60_cas_fnc_updateCautionPanel;
[_vehicle] call vtx_uh60_cas_fnc_updateAdvisories;
