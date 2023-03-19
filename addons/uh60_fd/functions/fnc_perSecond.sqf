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
vtx_uh60_fd_terrainSlope = _alt - vtx_uh60_fd_lastTerrainAlt;
vtx_uh60_fd_lastTerrainAlt = _alt;

if (isEngineOn _vehicle) then {
  vtx_uh60_poweredTime = vtx_uh60_poweredTime + 1;
};
if (!isTouchingGround _vehicle) then {
  vtx_uh60_flightTime = vtx_uh60_flightTime + 1;
};