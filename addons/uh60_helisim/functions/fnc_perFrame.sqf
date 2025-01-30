//#include "defines.hpp"

params ["_vehicle", "_frameTime"];

if (!local _vehicle) exitWith {};

if !(
	alive _vehicle &&
	{player == driver _vehicle || {_vehicle turretUnit [0] == player}} &&
	{_vehicle isKindOf "vtx_h60_base"}
) exitwith { systemChat format ["Exiting!"];};

[_vehicle] call bmkhs_fnc_fixedUpdate;

true