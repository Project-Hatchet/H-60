/*
 * vtx_uh60_fd_fnc_perSecond
 *
 * runs the per second updates of the flight director, this tracks some data used by the autpilot
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

#include "defines.hpp"

params ["_vehicle", "_frameTime"];

private _alt = (getPosASL _vehicle) # 2 - ((getPos _vehicle) # 2);
SET("terrainSlope", _alt - GET("lastTerrainAlt",_alt));
SET("lastTerrainAlt", _alt);

if (isEngineOn _vehicle) then {
	SET("poweredTime", GET("poweredTime",0) + 1);
};
if (!isTouchingGround _vehicle) then {
	SET("flightTime", GET("flightTime",0) + 1);
};

if (vtx_uh60_ui_showDebugMessages) then {
	private _pidDump = ["collective", "collectiveSFM", "ias", "pitch", "hdg", "roll", "drift"] apply {
		private _pid = _vehicle getVariable [format ["hct_pid_%1", _x], []];
		format ["%1 e:%2 i:%3", _x, (_pid param [3, 0]) toFixed 4, (_pid param [4, 0]) toFixed 4]
	};
	diag_log format [
		"VTX FD PID | %1 | local:%2 wow:%3 eng:%4 | %5",
		_vehicle, local _vehicle, isTouchingGround _vehicle, isEngineOn _vehicle,
		_pidDump joinString " | "
	];
};
