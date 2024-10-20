/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_coreConfig

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

_heli setVariable ["vtx_uh60_sfmplus_emptyMass",    	getNumber (_config >> "emptyMass")]; //kg

_heli setVariable ["vtx_uh60_sfmplus_stabPos", 			getArray (_config >> "stabPos")];
_heli setVariable ["vtx_uh60_sfmplus_stabWidth", 		getNumber (_config >> "stabWidth")];  //m
_heli setVariable ["vtx_uh60_sfmplus_stabLength", 		getNumber (_config >> "stabLength")]; //m

_heli setVariable ["vtx_uh60_sfmplus_forcePos", 	 	getArray (_config >> "forcePos")];

_heli setVariable ["vtx_uh60_sfmplus_maxTank1FuelMass", getNumber (_config >> "maxTank1FuelMass")];	//1206lbs in kg	
_heli setVariable ["vtx_uh60_sfmplus_maxTank2FuelMass", getNumber (_config >> "maxTank2FuelMass")]; //1206bs in kg
_heli setVariable ["vtx_uh60_sfmplus_maxTank3FuelMass", getNumber (_config >> "maxTank3FuelMass")];	//1094lbs in kg, center robbie
//_heli setVariable ["vtx_uh60_sfmplus_maxExtFuelMass", getNumber (_config >> "maxExtFuelMass")];     //1541lbs in kg, not yet implemented, 230gal external tank

[_heli] call vtx_uh60_sfmplus_fnc_fuelSet;
[_heli] call vtx_uh60_sfmplus_fnc_massSet;
if ((_heli animationPhase "ERFS_show") > 0) then {
	[_heli, 50, 1] call vtx_uh60_mfd_fnc_setPylonValue;
} else {
	[_heli, 50, 0] call vtx_uh60_mfd_fnc_setPylonValue;
};

_heli setVariable ["vtx_uh60_sfmplus_totRtrDmg",     0];
_heli setVariable ["vtx_uh60_sfmplus_dmgTimerCont",  0];
_heli setVariable ["vtx_uh60_sfmplus_dmgTimerTrans", 0];
[_heli] call vtx_uh60_sfmplus_fnc_engineVariables;