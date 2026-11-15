/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_updateCockpit

Description:
    MFD engine values, flight director knobs, door sound controllers and ESIS countdown, for
    the crew's machine.

Parameters:
    _heli - The helicopter [Object]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli"];
#include "\bmkhs_helisim\functions\core\core.hpp"

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

//HeliSim's state for the pages, in m, m/s, deg and g - each page scales it to what it shows.
//Where the aircraft is local, like the fuel. Slots: main\script_macros.hpp, USERMFDV_*.
if (local _heli) then {
    (_heli getVariable ["bmkhs_velModelSpaceNoWind", [0, 0, 0]]) params ["_velX", "_velY"];
    _heli setUserMFDvalue [37,  _velX];                                                    //VELOCITYX
    _heli setUserMFDvalue [38,  _velY];                                                    //VELOCITYY
    //The altimeters' own steps and range: baro in 10 ft, 0-20000 ft; radar in 10 ft above 50 ft,
    //to its 1420 ft ceiling. Core's values are exact.
    private _baro  = ((round ((_heli getVariable ["bmkhs_barAlt", 0]) / 10) * 10) max 0) min 20000;
    private _radFt = (_heli getVariable ["bmkhs_radAlt", 0]) * METERS_TO_FEET;
    if (_radFt > 50) then { _radFt = round (_radFt / 10) * 10 };
    _radFt = (_radFt max 0) min 1420;
    _heli setUserMFDvalue [100, _baro * FEET_TO_METERS];                                   //BARALT
    _heli setUserMFDvalue [101, _radFt * FEET_TO_METERS];                                  //RADALT
    _heli setUserMFDvalue [102, _heli getVariable ["bmkhs_vel2D", 0]];                     //IAS
    _heli setUserMFDvalue [103, _heli getVariable ["bmkhs_gndSpeed", 0]];                  //GS
    //The wind arrows point the way it blows; Core's is where it comes from
    _heli setUserMFDvalue [104, ((_heli getVariable ["bmkhs_windDirFrom", 0]) + 180) mod 360]; //WINDDIR
    _heli setUserMFDvalue [105, parseNumber ([_heli] call bmkhs_fnc_stateOnGround)];       //ONGROUND
    _heli setUserMFDvalue [106, _heli getVariable ["bmkhs_aero_beta_g", 0]];               //BALL
};

//Door sound controllers, as the engine comes on
private _engineOn = isEngineOn _heli;
if (_engineOn && {!(_heli getVariable ["vtx_uh60_helisim_engineWasOn", false])}) then {
    setCustomSoundController [_heli, "CustomSoundController9", ((1 - (_heli animationPhase "cabindoor_L")) / 2) + ((1 - (_heli animationPhase "cabindoor_R")) / 2)];
    setCustomSoundController [_heli, "CustomSoundController8", [((_heli animationSourcePhase "Door_RF") + (_heli animationSourcePhase "Door_LF")) / 2, 1] select ((_heli animationSourcePhase "Cockpitdoors_Hide") > 0)];
};
_heli setVariable ["vtx_uh60_helisim_engineWasOn", _engineOn];

//Flight director - Core's targets are m, m/s and deg; the panel is ft, kt and deg
private _fdUnits = createHashMapFromArray [["ralt", METERS_TO_FEET], ["alt", METERS_TO_FEET], ["altp", METERS_TO_FEET], ["ias", MPS_TO_KNOTS], ["hdg", 1]];
private _fdTgt   = { round ((_heli getVariable ["bmkhs_fdTgt_" + _this, 0]) * (_fdUnits get _this)) };
//The panel knobs follow the targets
{
    _y params ["_source", "_perPhase", "_range", "", "_step"];
    private _tgt  = _x call _fdTgt;
    private _diff = ((_heli animationSourcePhase _source) * _perPhase) - _tgt;
    if (_x == "hdg") then { _diff = [_diff] call CBA_fnc_simplifyAngle180 };
    private _dragged = time < (_heli getVariable ["vtx_uh60_helisim_fdKnobAt_" + _x, -1]) + 1;
    if (!_dragged && {abs _diff > (_step * 0.5) + 0.001}) then { _heli animateSource [_source, _tgt / _perPhase, true] };
} forEach vtx_uh60_helisim_fdKnobs;
//The FD panel readouts and the PFD / ND bugs: RALT, ALTP, ALT, IAS, HDG
{ _heli setUserMFDValue [_x select 0, (_x select 1) call _fdTgt] } forEach
    [[12, "ralt"], [13, "altp"], [14, "alt"], [41, "ias"], [42, "hdg"]];

if (time < (_heli getVariable ["vtx_uh60_helisim_cockpitSecond", -1]) + 1) exitWith {};
_heli setVariable ["vtx_uh60_helisim_cockpitSecond", time];

//Wind speed, from HeliSim, kt - the PFD / ND readout (its user text 9)
if (local _heli) then {
    [_heli, 9, str round ((_heli getVariable ["bmkhs_windSpeed", 0]) * MPS_TO_KNOTS)] call vtx_uh60_mfd_fnc_setUserText;
};

//ESIS boot countdown.
private _esisStartTime = _heli getVariable ["ESIS_START_TIME", CBA_missionTime];
_heli setUserMFDValue [49, (round (70 - (CBA_missionTime - _esisStartTime))) max -1];
