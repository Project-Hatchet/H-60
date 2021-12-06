/*
 * vtx_uh60_fms_fnc_setup
 *
 * initial setup of FMS
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
if (!vtx_uh60m_enabled_fms) exitWith {false};

_vehicle setUserMFDValue [31, 0];
_vehicle setUserMFDValue [32, 0];
_vehicle setUserMFDText [8, "--:--:--"];

fms_locations_page_index = 0;
fms_locations_page_open = false;
fms_locations_page_list = [];
fms_locations_selected = nil;
fms_markpoint = nil;
vtx_uh60_fms_mapSize = [] call BIS_fnc_mapSize;
vtx_uh60_fms_nearestLocation = nil;

true
