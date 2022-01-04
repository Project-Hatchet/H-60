/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_coreUpdate

Description:
	Updates all of the modules core functions.
	
Parameters:
	_heli - The helicopter to get information from [Unit].

Returns:
	...

Examples:
	...

Author:
	BradMick
---------------------------------------------------------------------------- */
params ["_heli"];
#include "\z\vtx\addons\uh60_sfmplus\headers\core.hpp"
private _deltaTime = ["sfmplus_deltaTime"] call BIS_fnc_deltaTime;

//Input
[_heli] call vtx_uh60_sfmplus_fnc_getInput;

//Weight
private _emptyMass = 0;
private _partsMass = 0;
_emptyMass = _heli getVariable "vtx_uh60_sfmplus_emptyMass";

private _cfgAnimationSources = configOf _heli >> "AnimationSources";
{
	private _phase = _heli animationSourcePhase _x;
	private _partMass = getNumber (_cfgAnimationSources >> _x >> "mass");
	_partsMass = _partsMass + _partMass * _phase;
} forEach [
	"CabinSeats_1_Hide",
	"CabinSeats_2_Hide",
	"CabinSeats_3_Hide",
	"Cockpitdoors_Hide",
	"FLIR_HIDE",
	"Fuelprobe_show",
	"GunnerSeats_Hide",
	"GAU21_L_Hide",
	"HH60Flares_show",
	"hoist_hide",
	"ERFS_show",
	"ESSS_show",
	"LASS_show",
	"Minigun_Mount_L_hide",
	"Minigun_Mount_R_hide",
	"Minigun_L_hide",
	"Minigun_R_hide",
	"RADAR_HIDE",
	"Skis_show"
];

//Add ViV
//Add passengers

private _maxTotFuelMass = _heli getVariable "vtx_uh60_sfmplus_maxTotFuelMass";
private _tank1Mass    = [_heli] call vtx_uh60_sfmplus_fnc_fuelSet select 0;
private _tank2Mass    = [_heli] call vtx_uh60_sfmplus_fnc_fuelSet select 1;

//Engines
[_heli, _deltaTime] call vtx_uh60_sfmplus_fnc_engineController;

//Fuel
private _apuFF  = 0;
private _eng1FF = _heli getVariable "vtx_uh60_sfmplus_engFF" select 0;
private _eng2FF = _heli getVariable "vtx_uh60_sfmplus_engFF" select 1;
private _curFuelFlow = 0;

if (_heli getVariable "APU_POWER" == true) then {
	_apuFF = 0.0151;	//120pph
};
_curFuelFlow    = (_apuFF + _eng1FF + _eng2FF) * _deltaTime;

private _totFuelMass  = _tank1Mass + _tank2Mass;
_totFuelMass          = _totFuelMass - _curFuelFlow;
private _armaFuelFrac = _totFuelMass / _maxTotFuelMass;
if (local _heli) then {
	_heli setFuel _armaFuelFrac;
};

//Pylons
private _pylonMass = 0;
{
	_x params ["_magName","", "_magAmmo"];
	private _magConfig    = configFile >> "cfgMagazines" >> _magName;
	private _magMaxWeight = getNumber (_magConfig >> "weight");
	private _magMaxAmmo   = getNumber (_magConfig >> "count");
	_pylonMass = _pylonMass + linearConversion [0, _magMaxAmmo, _magAmmo, 0, _magMaxWeight];
} foreach magazinesAllTurrets _heli;

private _curMass = _emptyMass + _totFuelMass + _pylonMass + _partsMass;
if (local _heli) then {
	_heli setMass _curMass;
};

//Damage
[_heli, _deltaTime] call vtx_uh60_sfmplus_fnc_damageApply;

//Stabilator
if(vtx_uh60_sfmPlusStabilatorEnabled == STABILTOR_MODE_ALWAYSENABLED 
	|| vtx_uh60_sfmPlusStabilatorEnabled == STABILTOR_MODE_JOYSTICKONLY && !vtx_uh60_sfmPlusKeyboardOnly) then {
	[_heli, _deltaTime] call vtx_uh60_sfmplus_fnc_aeroStabilator;
};

#ifdef __A3_DEBUG__
hintsilent format ["v0.11
					\nEngine 1 Ng = %1
					\nEngine 1 TQ = %2
					\nEngine 1 TGT = %3
					\n------------------
					\nEngine 2 Ng = %4
					\nEngine 2 TQ = %5
					\nEngine 2 TGT = %6
					\n------------------
					\nEng State = %7
					\nIs Single Engine? = %8
					\nPercent NP = %9
					\nEng Power Lever = %10;
					\n-------------------
					\nColl Pos = %11
					\nEng FF = %12
					\nEngine Base NG = %13", 		
					_heli getVariable "vtx_uh60_sfmplus_engPctNG" select 0,	 //1 
					_heli getVariable "vtx_uh60_sfmplus_engPctTQ" select 0,  //2
					_heli getVariable "vtx_uh60_sfmplus_engTGT" select 0,	 //3
					_heli getVariable "vtx_uh60_sfmplus_engPctNG" select 1,  //4
					_heli getVariable "vtx_uh60_sfmplus_engPctTQ" select 1,  //5
					_heli getVariable "vtx_uh60_sfmplus_engTGT" select 1,	 //6
					_heli getVariable "vtx_uh60_sfmplus_engState",			 //7
					_heli getVariable "vtx_uh60_sfmplus_isSingleEng",		 //8
					_heli getVariable "vtx_uh60_sfmplus_engPctNP",			 //9
					_heli getVariable "vtx_uh60_sfmplus_engPowerLeverState", //10
					vtx_uh60_sfmplus_collectiveOutput,						 //11
					_heli getVariable "vtx_uh60_sfmplus_engFF",			     //12
					_heli getVariable "vtx_uh60_sfmplus_engBaseNG"];         //13

#endif