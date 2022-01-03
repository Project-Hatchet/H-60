/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_massSet

Description:
	Sets the initial mass of the helicopter.

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

_heli setVariable["fza_sfmplus_emptyMass", _emptyMass];

private _tank1Mass = [_heli] call vtx_uh60_sfmplus_fnc_fuelSet select 0;
private _tank2Mass = [_heli] call vtx_uh60_sfmplus_fnc_fuelSet select 1;

private _pylonMass = 0;
{
	_x params ["_magName","", "_magAmmo"];
	private _magConfig    = configFile >> "cfgMagazines" >> _magName;
	private _magMaxWeight = getNumber (_magConfig >> "weight");
	private _magMaxAmmo   = getNumber (_magConfig >> "count");
	_pylonMass = _pylonMass + linearConversion [0, _magMaxAmmo, _magAmmo, 0, _magMaxWeight];
} foreach magazinesAllTurrets _heli;

private _totalMass = _emptyMass + _tank1Mass + _tank2Mass + _pylonMass + _partsMass;

_heli setMass _totalMass;