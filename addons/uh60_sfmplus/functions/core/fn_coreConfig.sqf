/* ----------------------------------------------------------------------------
Function: vtx_sfmplus_fnc_coreConfig

Description:
	Defines key values for the simulation.

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

private _config = configFile >> "CfgVehicles" >> typeof _heli >> "vtx_SfmPlus";

_heli setVariable ["vtx_sfmplus_emptyMassFCR",    	getNumber (_config >> "emptyMassFCR")]; //kg
_heli setVariable ["vtx_sfmplus_emptyMassNonFCR", 	getNumber (_config >> "emptyMassNonFCR")]; //kg

_heli setVariable ["vtx_sfmplus_stabPos", 			getArray (_config >> "stabPos")];
_heli setVariable ["vtx_sfmplus_stabWidth", 		getNumber (_config >> "stabWidth")];  //m
_heli setVariable ["vtx_sfmplus_stabLength", 		getNumber (_config >> "stabLength")]; //m

_heli setVariable ["vtx_sfmplus_maxFwdFuelMass", 	getNumber (_config >> "maxFwdFuelMass")];	    //1043lbs in kg
//_heli setVariable ["vtx_sfmplus_maxCtrFuelMass", getNumber (_config >> "maxCtrFuelMass")];	//663lbs in kg, net yet implemented, center robbie
_heli setVariable ["vtx_sfmplus_maxAftFuelMass", 	getNumber (_config >> "maxAftFuelMass")]; 	//1474lbs in kg
//_heli setVariable ["vtx_sfmplus_maxExtFuelMass", getNumber (_config >> "maxExtFuelMass")];     //1541lbs in kg, not yet implemented, 230gal external tank

[_heli] call vtx_sfmplus_fnc_fuelSet;
[_heli] call vtx_sfmplus_fnc_massSet;

_heli setVariable ["vtx_sfmplus_totRtrDmg",     0];
_heli setVariable ["vtx_sfmplus_dmgTimerCont",  0];
_heli setVariable ["vtx_sfmplus_dmgTimerTrans", 0];
[_heli] call vtx_sfmplus_fnc_engineVariables;