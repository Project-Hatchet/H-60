// vtx_uh60_sfmplus_fnc_perFrame
params ["_vehicle", "_frameTime"];

if !(
	alive _vehicle &&
	{player == driver _vehicle || {_vehicle turretUnit [0] == player}} &&
	{_vehicle isKindOf "vtx_h60_base"}
) exitwith {};

[_vehicle] call vtx_uh60_sfmplus_fnc_coreUpdate;

true