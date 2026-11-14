#include "script_component.hpp"
/*
 * vtx_uh60_cas_fnc_setMasterCaution
 *
 */

params ["_vehicle", ["_on", true], ["_reset", false]];

//Every EICAS caution line - L20-L22 sit below the L00-R25 run
private _lines = [USERMFDV_L20, USERMFDV_L21, USERMFDV_L22];
for "_i" from USERMFDV_L00 to USERMFDV_R25 do {_lines pushBack _i};

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
	{
    _vehicle setUserMFDValue [_x, 0];
	} forEach _lines;
};
{
  if ((getUserMFDValue _vehicle select _x) == 2) then {
    _vehicle setUserMFDValue [_x, 1];
	};
} forEach _lines;
