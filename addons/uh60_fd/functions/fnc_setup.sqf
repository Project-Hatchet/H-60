/*
 * vtx_uh60_fd_fnc_setup
 *
 * starts up the flight director module, managing the autopilot
 *
 * params (array)[(object) vehicle]
 */

#include "defines.hpp"

params ["_vehicle"];
if (vtx_uh60m_disabled_fd) exitWith {false};

[_vehicle] call vtx_uh60_fd_fnc_updatePanel;
vtx_uh60_fd_lastAltMatch = true;
vtx_uh60_fd_lastAltChangeTime = cba_missionTime;
vtx_uh60_fd_lastTerrainAlt = ((getPosASL _vehicle) # 2) - ((getPos _vehicle) # 2);
vtx_uh60_fd_terrainSlope = 0;
vtx_uh60_fd_collectiveHeld = 0;

[_vehicle, "collective", 0.3, 0.2, 0] call vxf_util_fnc_pidCreate;

true
