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

private _master = _vehicle animationPhase "CautionMasterCaution";
private _eng1Powered = if (_np1 > 0.6) then [{0},{1}];
private _eng2Powered = if (_np2 > 0.6) then [{0},{1}];

_vehicle animate ["CautionEng1Out", _eng1Powered]; 
_vehicle animate ["CautionEng2Out", _eng2Powered];

private _battPower = ((_vehicle getVariable ["vtx_uh60_acft_battBusState", "OFF"]) == "ON");
private _battPowerSoundMod = if (_battPower) then { 1 } else { 0 };
private _WOWSoundMod = if (isTouchingGround _vehicle) then { 0 } else { 1 };

setCustomSoundController [_vehicle, "CustomSoundController7", _battPowerSoundMod * _WOWSoundMod * (_eng1Powered + _eng2Powered)];

private _realRotorRPM = (_vehicle animationPhase "rotortilt") * 1.025 / 10;
private _rpmWarn = if (_realRotorRPM < 0.9) then [{1}, {0}];
_vehicle animate ["CautionLowRpm", _rpmWarn];
setCustomSoundController [_vehicle, "CustomSoundController6", _battPowerSoundMod * _WOWSoundMod* _rpmWarn];
