/*
 * vtx_uh60_flir_fnc_perSecond
 *
 * handles occasional updates of data for FLIR
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

if (vtx_uh60_flir_setting_animateTurret && {local _vehicle}) then {
  [_vehicle] call vtx_uh60_flir_fnc_syncAnimation;
};
