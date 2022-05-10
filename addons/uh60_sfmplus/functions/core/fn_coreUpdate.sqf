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
params ["_heli", "_deltaTime"];
#include "\z\vtx\addons\uh60_sfmplus\headers\core.hpp"

private _colorRed = [1,0,0,1]; private _colorGreen = [0,1,0,1]; private _colorBlue = [0,0,1,1]; private _colorWhite = [1,1,1,1];

DRAW_LINE = {
	params ["_heli", "_p1", "_p2", "_col"];
	drawLine3D [_heli modelToWorldVisual _p1, _heli modelToWorldVisual _p2, _col];
};

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
	"GunnerSeats_Hide",
	"CabinSeats_Hide",
	"CabinSeats_1_Hide",
	"CabinSeats_2_Hide",
	"CabinSeats_3_Hide",
	"Minigun_Mount_L_hide",
	"Minigun_Mount_R_hide",
	"Minigun_L_hide",
	"Minigun_R_hide",
	"RADAR_HIDE",
	"FLIR_HIDE",
	"Fuelprobe_show",
	"Cockpitdoors_Hide",
	"ERFS_show",
	"MAWS_Tubes_Show",
	"LASS_show",
	"ESSS_show",
	"EGMS_show",
	"GAU21_L_Hide",
	"GAU21_R_Hide",
	"Skis_show",
	"HH60Flares_show"
];

//Add ViV

private _maxTotFuelMass = _heli getVariable "vtx_uh60_sfmplus_maxTotFuelMass";
private _tank1Mass    = [_heli] call vtx_uh60_sfmplus_fnc_fuelSet select 0;
private _tank2Mass    = [_heli] call vtx_uh60_sfmplus_fnc_fuelSet select 1;
private _tank3Mass    = [_heli] call vtx_uh60_sfmplus_fnc_fuelSet select 2;

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

private _totFuelMass  = _tank1Mass + _tank2Mass + _tank3Mass;
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

//Crew and pax
private _numPers       = count (fullCrew _heli);
private _crewAndPaxMass = _numPers * 113.4;

private _curMass = _emptyMass + _totFuelMass + _pylonMass + _partsMass + _crewAndPaxMass;
//private _curMass = 7257;
if (local _heli) then {
	vtx_uh60_sfmplus_mass = _curMass;
};

//Damage
[_heli, _deltaTime] call vtx_uh60_sfmplus_fnc_damageApply;

//Stabilator
if(vtx_uh60_sfmPlusStabilatorEnabled == STABILTOR_MODE_ALWAYSENABLED 
	|| vtx_uh60_sfmPlusStabilatorEnabled == STABILTOR_MODE_JOYSTICKONLY && !vtx_uh60_sfmPlusKeyboardOnly) then {
	if (!difficultyEnabledRTD) then {
		[_heli, _deltaTime] call vtx_uh60_sfmplus_fnc_aeroStabilator;
	};
};

//Apply a negative force to prevent the helicopter from taking off until the power levers are at fly
[_heli, _deltaTime] call vtx_uh60_sfmplus_fnc_antiLift;

#ifdef __A3_DEBUG__
/*
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
*/
#endif