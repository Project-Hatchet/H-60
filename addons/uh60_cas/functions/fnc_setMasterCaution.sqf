#include "script_component.hpp"
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
	for "_i" from USERMFDV_L00 to USERMFDV_R25 do {
    _vehicle setUserMFDValue [_i, 0];
	};
};
for "_i" from USERMFDV_L00 to USERMFDV_R25 do {
	//private _ammo = _vehicle ammoOnPylon _i;
  private _value = getuserMFDValue _vehicle select _i;
	//if (_ammo == 2) then {
  if (_value == 2) then {
    _vehicle setUserMFDValue [_i, 1];
	};
};
