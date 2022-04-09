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
	private _phase    = _heli animationSourcePhase _x;
	private _partMass = getNumber (_cfgAnimationSources >> _x >> "mass");
	_partsMass        = _partsMass + _partMass * _phase;
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

_heli setVariable["fza_sfmplus_emptyMass", _emptyMass];

private _tank1Mass = [_heli] call vtx_uh60_sfmplus_fnc_fuelSet select 0;
private _tank2Mass = [_heli] call vtx_uh60_sfmplus_fnc_fuelSet select 1;
private _tank3Mass = [_heli] call vtx_uh60_sfmplus_fnc_fuelSet select 2;

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
private _crewAndPaxMass = _numPers * 113.4;	//250lbs per person

private _totalMass = _emptyMass + _tank1Mass + _tank2Mass + _tank3Mass + _pylonMass + _partsMass + _crewAndPaxMass;

_heli setMass _totalMass;