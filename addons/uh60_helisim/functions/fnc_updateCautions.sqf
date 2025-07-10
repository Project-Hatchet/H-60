/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_updateCautions

Description:
    ...

Parameters:
    ...

Returns:
    ...

Examples:
    ...

Author:
    BradMick
---------------------------------------------------------------------------- */
params ["_vehicle"];

if (!(local _vehicle) || _vehicle != vehicle player) exitWith {};

(_vehicle getVariable ["bmkhs_engPctNg", [0,0]]) params ["_ng1", "_ng2"];

private _master = _vehicle animationPhase "CautionMasterCaution";
private _eng1Powered = if (_ng1 > 55.0) then [{0},{1}];
private _eng2Powered = if (_ng2 > 55.0) then [{0},{1}];

_vehicle animate ["CautionEng1Out", _eng1Powered];
_vehicle animate ["CautionEng2Out", _eng2Powered];

private _battPower = _vehicle getVariable "bmkhs_batteryBusOn";
private _battPowerSoundMod = if (_battPower) then { 1 } else { 0 };
private _WOWSoundMod = if (isTouchingGround _vehicle) then { 0 } else { 1 };

setCustomSoundController [_vehicle, "CustomSoundController7", _battPowerSoundMod * _WOWSoundMod * (_eng1Powered + _eng2Powered)];

private _realRotorRPM = (_vehicle animationPhase "rotorCollectiveBlade1") * 1.025 / 10;
private _rpmWarn = if (_realRotorRPM < 0.96) then [{1}, {0}];
_vehicle animate ["CautionLowRpm", _rpmWarn];
setCustomSoundController [_vehicle, "CustomSoundController6", _battPowerSoundMod * _WOWSoundMod* _rpmWarn];