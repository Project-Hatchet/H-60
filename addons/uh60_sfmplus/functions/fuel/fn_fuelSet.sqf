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
	_fwdFuelMass = _fuelMass select 0;
	_aftFuelMass = _fuelMass select 1;

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
private _fwdFuelMass = [_totFuelMass / 2, 0, _maxTank1FuelMass] call BIS_fnc_clamp;
private _aftFuelMass = _totFuelMass - _fwdFuelMass;

[_fwdFuelMass, _aftFuelMass];