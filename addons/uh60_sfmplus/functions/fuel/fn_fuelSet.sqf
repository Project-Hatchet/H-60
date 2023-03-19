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

private _percentFuel      = fuel _heli;
private _maxTank1FuelMass = _heli getVariable "vtx_uh60_sfmplus_maxTank1FuelMass";
private _maxTank2FuelMass = _heli getVariable "vtx_uh60_sfmplus_maxTank2FuelMass";
private _maxTank3FuelMass = 0.0;
private _maxTotFuelMass   = 0.0;

if ((_heli animationSourcePhase "ERFS_show") == 0) then { 
  _maxTotFuelMass   = _maxTank1FuelMass + _maxTank2FuelMass;
} else {
  _maxTank3FuelMass = _heli getVariable "vtx_uh60_sfmplus_maxTank3FuelMass";
  _maxTotFuelMass   = _maxTank1FuelMass + _maxTank2FuelMass + _maxTank3FuelMass;
};
_heli setVariable ["vtx_uh60_sfmplus_maxTotFuelMass", _maxTotFuelMass];

private _totFuelMass = _maxTotFuelMass * _percentFuel;
private _intTankMass = _maxTank1FuelMass + _maxTank2FuelMass;

private _tank1Mass = 0.0;
private _tank2Mass = 0.0;
private _tank3Mass = 0.0;

if (_totFuelMass > _intTankMass) then {
  _tank1Mass = _maxTank1FuelMass;
  _tank2Mass = _maxTank2FuelMass;
  _tank3Mass = _totFuelMass - _intTankMass;
} else {
  _tank1Mass = _totFuelMass / 2;
  _tank2Mass = _totFuelMass / 2;
  _tank3Mass = 0.0;
};

[_tank1Mass, _tank2Mass, _tank3Mass]