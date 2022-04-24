/*
 * vtx_uh60_cas_fnc_setMasterCaution
 *
 */

params ["_vehicle", ["_on", true]];

// if we're enabling it then do this
if (_on) exitWith {
	_vehicle animate ["CautionMasterCaution",1];
};

// otherwise we're clearing it

_vehicle animate ["CautionMasterCaution",0];
for "_i" from 16 to 39 do {
	private _ammo = _vehicle ammoOnPylon _i;
	if (_ammo == 2) then {
		[_vehicle, _i, 1] call vtx_uh60_mfd_fnc_setPylonValue;
	};
};