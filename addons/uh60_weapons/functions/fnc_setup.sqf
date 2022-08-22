params ["_vehicle"];

_vehicle setVariable ["vtx_uh60_hellfire_laserCodeIndex", _vehicle getVariable ["vtx_uh60_hellfire_laserCodeIndex", 0], true];

vtx_uh60_hellfire_lastLaunchTime = 0;
vtx_uh60_hellfire_currentTof = -1;

true