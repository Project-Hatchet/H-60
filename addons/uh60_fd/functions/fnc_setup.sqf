/*
 * vtx_uh60_fd_fnc_setup
 *
 * starts up the flight director module, managing the autopilot
 *
 * params (array)[(object) vehicle]
 */

#include "defines.hpp"

params ["_vehicle"];
if (!vtx_uh60m_enabled_fd) exitWith {false};

[_vehicle] call vtx_uh60_fd_fnc_updatePanel;
vtx_uh60_fd_lastAltMatch = true;
vtx_uh60_fd_lastAltChangeTime = cba_missionTime;
vtx_uh60_fd_lastTerrainAlt = ((getPosASL _vehicle) # 2) - ((getPos _vehicle) # 2);
vtx_uh60_fd_terrainSlope = 0;
vtx_uh60_fd_collectiveHeld = 0;

[_vehicle, "collective", 0.3, 0.2, 0] call htf_util_fnc_pidCreate;
[_vehicle, "collectiveSFM", 2000, 20, 0] call htf_util_fnc_pidCreate;
[_vehicle, "ias", 1, 0, 0] call htf_util_fnc_pidCreate;
[_vehicle, "pitch", 500, 0, 0] call htf_util_fnc_pidCreate;
[_vehicle, "hdg", 30, 0, 0] call htf_util_fnc_pidCreate;
[_vehicle, "roll", 10, 0, 0] call htf_util_fnc_pidCreate;
[_vehicle, "drift", 1, 0, 0] call htf_util_fnc_pidCreate;
vs_max_collectiveForce = 3000;
ias_max_pitchTorque = 2000;
ias_max_rudderTorque = 800;
vtx_uh60_lastRotorAnim = vehicle player animationPhase "hrotor";
vtx_uh60_rotorRPM = 0;

true
