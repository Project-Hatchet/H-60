/*
 * vtx_uh60_cas_fnc_updateCautionPanel
 *
 * Updates the caution list, called from various eventhandlers.
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

if (!difficultyEnabledRTD || !(local _vehicle) || _vehicle != vehicle player) exitWith {};

private _eng1Powered = if (((enginesRpmRTD _vehicle) # 0) > 3000) then [{0},{1}];
private _eng2Powered = if (((enginesRpmRTD _vehicle) # 1) > 3000) then [{0},{1}];

_vehicle animate ["CautionEng1Out", _eng1Powered];
_vehicle animate ["CautionEng2Out", _eng2Powered];

private _rotor = if (((rotorsRpmRTD vehicle player) # 1) < 1000) then [{0},{1}];

_vehicle animate ["Caution_lowrpm", _rotor];
