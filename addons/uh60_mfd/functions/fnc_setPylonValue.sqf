/*
 * vtx_uh60_mfd_fnc_setPylonValue
 *
 * Writes an individual pylon value and stores the value so that it's not disrupted during reload events (i.e. MFD fluid issues)
 *
 * params (array)[(object) vehicle, (integer or string) pylon index or name, (integer or string pylon value]
 */

params ["_vehicle", "_index", "_value", ["_eicasCaution", false]];

private _changedPylon = -1;

private _pylons = getPylonMagazines _vehicle;
if (_pylons isEqualTo [] || _index == 0 || _index > count _pylons) exitWith {_changedPylon};
if (_pylons # (_index - 1) != "vtx_1000rnd_dummy") then {
  _vehicle setPylonLoadout [_index, "vtx_1000rnd_dummy", true];
};
private _ammo = _vehicle ammoOnPylon _index;
if (_eicasCaution) then {
  if ((_ammo < 1 && _value == 1) || (_ammo == 2 && _value == 1) || (_ammo > 2 && _value > 0)) then {
    _value = 2;
    [_vehicle] call vtx_uh60_cas_fnc_setMasterCaution;
  };
};
if (_ammo != _value)  then {
  _vehicle setAmmoOnPylon [_index, _value];
  _changedPylon = _value;
};

// Weapon vtx_pylon_mfd was added to stop rpt spam from MFD dummy pylons
if (local _vehicle && {"vtx_pylon_mfd" in weapons _vehicle}) then {
  _vehicle removeWeapon "vtx_pylon_mfd";
};

if (_changedPylon > -1) then {
  [_vehicle] call vtx_uh60_mfd_fnc_storePylons;
};

_changedPylon