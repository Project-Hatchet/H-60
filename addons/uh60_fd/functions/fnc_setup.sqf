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
SET("lastAltMatch", true);
SET("lastAltChangeTime", cba_missionTime);
SET("lastTerrainAlt", ((getPosASL _vehicle) # 2) - ((getPos _vehicle) # 2));
SET("terrainSlope", 0);
SET("collectiveHeld", 0);

[_vehicle, "collective", 0.3, 0.2, 0] call hct_util_fnc_pidCreate;
[_vehicle, "collectiveSFM", 2000, 20, 0] call hct_util_fnc_pidCreate;
[_vehicle, "ias", 1, 0, 0] call hct_util_fnc_pidCreate;
[_vehicle, "pitch", 500, 0, 0] call hct_util_fnc_pidCreate;
[_vehicle, "hdg", 30, 0, 0] call hct_util_fnc_pidCreate;
[_vehicle, "roll", 10, 0, 0] call hct_util_fnc_pidCreate;
[_vehicle, "drift", 1, 0, 0] call hct_util_fnc_pidCreate;
SET("maxCollectiveForce", 3000);
SET("maxPitchTorque", 2000);
SET("maxRudderTorque", 800);
SET("lastRotorAnim", vehicle player animationPhase "hrotor");
SET("rotorRPM", 0);
SET("autoHoverKeyDown", false);

SET("flightTime", 0);
SET("poweredTime", 0);

_vehicle setObjectTextureGlobal ["emmisive_cpld", "#(rgb,8,8,3)color(0,1,0,1)"];

true
