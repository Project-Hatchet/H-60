// vtx_uh60_sfmplus_fnc_perSecond
params ["_vehicle", "_frameTime"];

if (!local _vehicle) exitWith {};

if !(
	alive _vehicle &&
	{player == driver _vehicle || {_vehicle turretUnit [0] == player}} &&
	{_vehicle isKindOf "vtx_h60_base"}
) exitwith {};

[_vehicle] call vtx_uh60_sfmplus_fnc_coreUpdate;

true