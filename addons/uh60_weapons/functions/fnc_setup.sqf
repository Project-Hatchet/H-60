params ["_vehicle"];

_vehicle setVariable ["vtx_uh60_hellfire_laserCodeIndex", _vehicle getVariable ["vtx_uh60_hellfire_laserCodeIndex", 0], true];

vtx_uh60_hellfire_lastLaunchTime = 0;
vtx_uh60_hellfire_currentTof = -1;

{
	if (_vehicle ammoOnPylon _x == 1000) then {[_vehicle, _x, 0] call vtx_uh60_mfd_fnc_setPylonValue;};
} forEach [
	40, 41, 42, 43, 44, 45, 46, 47
];

true