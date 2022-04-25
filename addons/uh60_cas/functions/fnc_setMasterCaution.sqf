/*
 * vtx_uh60_cas_fnc_setMasterCaution
 *
 */

params ["_vehicle", ["_on", true], ["_reset", false]];

// if we're enabling it then do this
if (_on) exitWith {
	_vehicle animate ["CautionMasterCaution",1];
};

// otherwise we're clearing it

_vehicle animate ["CautionMasterCaution",0];
vtx_uh60_cas_cautionsUnacked = 0;
[_vehicle,false] call vtx_uh60_cas_fnc_updateOverlayList;
if (_reset) exitWith {
	vtx_uh60_cas_cautionsLog = [];
	for "_i" from 16 to 39 do {
		[_vehicle, _i, 0] call vtx_uh60_mfd_fnc_setPylonValue;
	};
};
for "_i" from 16 to 39 do {
	private _ammo = _vehicle ammoOnPylon _i;
	if (_ammo == 2) then {
		[_vehicle, _i, 1] call vtx_uh60_mfd_fnc_setPylonValue;
	};
};