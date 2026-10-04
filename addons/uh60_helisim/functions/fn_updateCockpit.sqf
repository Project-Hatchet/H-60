/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_updateCockpit

Description:
    MFD engine values, door sound controllers and ESIS countdown, for the crew's machine.

Parameters:
    _heli - The helicopter [Object]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli"];

private _engNg  = _heli getVariable ["bmkhs_engPctNg", [0, 0]];
private _engNp  = _heli getVariable ["bmkhs_engPctNp", [0, 0]];
private _engTq  = _heli getVariable ["bmkhs_engPctTq", [0, 0]];
private _engTgt = _heli getVariable ["bmkhs_engTgt",   [0, 0]];

_heli setUserMFDvalue [19, (_engNg # 0) * 100];
_heli setUserMFDvalue [45, (_engNg # 1) * 100];
_heli setUserMFDvalue [20, (_engNp # 0) * 100];
_heli setUserMFDvalue [46, (_engNp # 1) * 100];
_heli setUserMFDvalue [21, _engTgt # 0];
_heli setUserMFDvalue [47, _engTgt # 1];
_heli setUserMFDvalue [22, (_engTq # 0) * 100];
_heli setUserMFDvalue [48, (_engTq # 1) * 100];
_heli setUserMFDvalue [17, (_heli getVariable ["bmkhs_rtrRpm", 0]) * 100];

//Fuel, lb, from HeliSim's tanks - they live where the aircraft is local
if (local _heli) then {
    private _lb   = 2.20462;
    private _no1  = (_heli getVariable ["bmkhs_no1TankMass", 0]) * _lb;
    private _no2  = (_heli getVariable ["bmkhs_no2TankMass", 0]) * _lb;
    private _erfs = (_heli getVariable ["bmkhs_erfsTankMass", 0]) * _lb;
    private _erfsIn = _heli getVariable ["bmkhs_erfsTankInstalled", false];
    _heli setUserMFDvalue [50, parseNumber _erfsIn];
    _heli setUserMFDvalue [51, _no1];
    _heli setUserMFDvalue [52, _no2];
    _heli setUserMFDvalue [98, [0, _erfs] select _erfsIn];
    _heli setUserMFDvalue [99, _no1 + _no2 + ([0, _erfs] select _erfsIn)];
};

//Door sound controllers, as the engine comes on
private _engineOn = isEngineOn _heli;
if (_engineOn && {!(_heli getVariable ["vtx_uh60_helisim_engineWasOn", false])}) then {
    setCustomSoundController [_heli, "CustomSoundController9", ((1 - (_heli animationPhase "cabindoor_L")) / 2) + ((1 - (_heli animationPhase "cabindoor_R")) / 2)];
    setCustomSoundController [_heli, "CustomSoundController8", [((_heli animationSourcePhase "Door_RF") + (_heli animationSourcePhase "Door_LF")) / 2, 1] select ((_heli animationSourcePhase "Cockpitdoors_Hide") > 0)];
};
_heli setVariable ["vtx_uh60_helisim_engineWasOn", _engineOn];

if (time < (_heli getVariable ["vtx_uh60_helisim_cockpitSecond", -1]) + 1) exitWith {};
_heli setVariable ["vtx_uh60_helisim_cockpitSecond", time];

//ESIS boot countdown.
private _esisStartTime = _heli getVariable ["ESIS_START_TIME", CBA_missionTime];
_heli setUserMFDValue [49, (round (70 - (CBA_missionTime - _esisStartTime))) max -1];
