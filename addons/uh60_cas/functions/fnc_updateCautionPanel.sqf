/*
 * vtx_uh60_cas_fnc_updateCautionPanel
 *
 * Updates the caution list, called from various eventhandlers.
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

if (!(local _vehicle) || _vehicle != vehicle player) exitWith {};

(_vehicle getVariable ["vtx_uh60_sfmplus_engPctNP", [0,0]]) params ["_np1", "_np2"];

private _eng1Powered = if (_np1 > 0.6) then [{0},{1}];
private _eng2Powered = if (_np2 > 0.6) then [{0},{1}];

_vehicle animate ["CautionEng1Out", _eng1Powered];
_vehicle animate ["CautionEng2Out", _eng2Powered];

private _rpmWarn = if ((_np1 max _np2) > 0.9) then [{0}, {1}];
_vehicle animate ["CautionLowRpm", _rpmWarn];
