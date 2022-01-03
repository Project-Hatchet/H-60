/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_fuelSet

Description:
	Sets the initial fuel state of the aircraft.

Parameters:
	_heli - The helicopter to get information from [Unit].

Returns:
	The mass of the forward and aft fuel cells.

Examples:
	...
	_fuelMass = [_heli] call vtx_fnc_setFuel;
	_tank1Mass = _fuelMass select 0;
	_tank2Mass = _fuelMass select 1;

Author:
	BradMick
---------------------------------------------------------------------------- */
params ["_heli"];

private _percentFuel    = fuel _heli;
private _maxTank1FuelMass = _heli getVariable "vtx_uh60_sfmplus_maxTank1FuelMass";
private _maxTank2FuelMass = _heli getVariable "vtx_uh60_sfmplus_maxTank2FuelMass";
private _maxTotFuelMass = _maxTank1FuelMass + _maxTank2FuelMass;
_heli setVariable ["vtx_uh60_sfmplus_maxTotFuelMass", _maxTotFuelMass];

private _totFuelMass = _maxTotFuelMass * _percentFuel;
private _tank1Mass = [_totFuelMass / 2, 0, _maxTank1FuelMass] call BIS_fnc_clamp;
private _tank2Mass = _totFuelMass - _tank1Mass;

[_tank1Mass, _tank2Mass];