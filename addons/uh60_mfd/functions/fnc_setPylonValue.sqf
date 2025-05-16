/*
 * vtx_uh60_mfd_fnc_setPylonValue
 *
 * Writes an individual pylon value and stores the value so that it's not disrupted during reload events (i.e. MFD fluid issues)
 *
 * params (array)[(object) vehicle, (integer or string) pylon index or name, (integer or string pylon value]
 */

params ["_vehicle", "_index", "_value", ["_eicasCaution", false]];

private _changedPylon = -1;
private _weaponAdded = false;

private _pylons = getPylonMagazines _vehicle;
if (_pylons isEqualTo [] || _index == 0 || _index > count _pylons) exitWith {_changedPylon};
if (_pylons # (_index - 1) != "vtx_1000rnd_dummy") then {
//  if (local _vehicle) then { _vehicle setPylonLoadout [_index, "vtx_1000rnd_dummy", true] };
  _weaponAdded = true;
};
//private _ammo = _vehicle ammoOnPylon _index;
private _userMFDValue = getuserMFDValue _vehicle select _index;
if (_eicasCaution) then {
  //if ((_ammo < 1 && _value == 1) || (_ammo == 2 && _value == 1) || (_ammo > 2 && _value > 0)) then {
  if ((_userMFDValue < 1 && _value == 1) || (_userMFDValue == 2 && _value == 1) || (_userMFDValue > 2 && _value > 0)) then {
    _value = 2;
    [_vehicle] call vtx_uh60_cas_fnc_setMasterCaution;
  };
};
if (_userMFDValue != _value)  then {
  //if (local _vehicle) then { _vehicle setAmmoOnPylon [_index, _value] };
  if (local _vehicle) then {_vehicle setUserMFDValue [_index, _value]; };
  _changedPylon = _value;
};

if (!local _vehicle && (_weaponAdded || _changedPylon > -1)) then {
  _this remoteExecCall ["vtx_uh60_mfd_fnc_setPylonValue", _vehicle, false];
};

_changedPylon
