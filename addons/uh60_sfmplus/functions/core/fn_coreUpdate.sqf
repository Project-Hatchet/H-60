/* ----------------------------------------------------------------------------
Function: vtx_sfmplus_fnc_coreUpdate

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
[_heli] call vtx_sfmplus_fnc_getInput;

//Weight
private _emptyMass = 0;
if (_heli animationPhase "fcr_enable" == 1) then {
	_emptyMass = _heli getVariable "vtx_sfmplus_emptyMassFCR";
} else {
	_emptyMass = _heli getVariable "vtx_sfmplus_emptyMassNonFCR";
};
private _maxTotFuelMass = _heli getVariable "vtx_sfmplus_maxTotFuelMass";
private _fwdFuelMass    = [_heli] call vtx_sfmplus_fnc_fuelSet select 0;
private _aftFuelMass    = [_heli] call vtx_sfmplus_fnc_fuelSet select 1;

//Engines
[_heli, _deltaTime] call vtx_sfmplus_fnc_engineController;

//Fuel
private _apuFF  = 0;
private _eng1FF = _heli getVariable "vtx_sfmplus_engFF" select 0;
private _eng2FF = _heli getVariable "vtx_sfmplus_engFF" select 1;
private _curFuelFlow = 0;

if (_heli animationphase "plt_apu" > 0.5) then {
	_apuFF = 0.0220;	//175pph
};
_curFuelFlow    = (_apuFF + _eng1FF + _eng2FF) * _deltaTime;

private _totFuelMass  = _fwdFuelMass + _aftFuelMass;
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

private _curMass = _emptyMass + _totFuelMass + _pylonMass;
if (local _heli) then {
	_heli setMass _curMass;
};

//Damage
[_heli, _deltaTime] call vtx_sfmplus_fnc_damageApply;

//Stabilator
if(vtx_uh60_sfmPlusStabilatorEnabled == STABILTOR_MODE_ALWAYSENABLED 
	|| vtx_uh60_sfmPlusStabilatorEnabled == STABILTOR_MODE_JOYSTICKONLY && !vtx_uh60_sfmPlusKeyboardOnly) then {
	[_heli, _deltaTime] call vtx_sfmplus_fnc_aeroStabilator;
};

#ifdef __A3_DEBUG_
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
					\nEng Clutch State = %10
					\nEng Start Switch = %11
					\nEng Power Lever = %12;
					\n-------------------
					\nColl Pos = %13
					\nEng FF = %14
					\nEngine Base NG = %15", 		
					_heli getVariable "vtx_sfmplus_engPctNG" select 0, 
					_heli getVariable "vtx_sfmplus_engPctTQ" select 0, 
					_heli getVariable "vtx_sfmplus_engTGT" select 0,
					_heli getVariable "vtx_sfmplus_engPctNG" select 1, 
					_heli getVariable "vtx_sfmplus_engPctTQ" select 1, 
					_heli getVariable "vtx_sfmplus_engTGT" select 1,
					_heli getVariable "vtx_sfmplus_engState",
					_heli getVariable "vtx_sfmplus_isSingleEng",
					_heli getVariable "vtx_sfmplus_engPctNP",
					_heli getVariable "vtx_sfmplus_engPowerLeverState",
					vtx_sfmplus_collectiveOutput,
					_heli getVariable "vtx_sfmplus_engFF",
					_heli getVariable "vtx_sfmplus_engBaseNG"];
*/
#endif