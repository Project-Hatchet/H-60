#include "script_component.hpp"
params ["_vehicle"];

_vehicle setVariable ["vtx_uh60_hellfire_laserCodeIndex", _vehicle getVariable ["vtx_uh60_hellfire_laserCodeIndex", 0], true];

vtx_uh60_hellfire_lastLaunchTime = 0;
vtx_uh60_hellfire_currentTof = -1;

{
  _vehicle setUserMFDValue [_x, 0];
} forEach [
	USERMFDV_HELLFIRE_BOX,
  USERMFDV_HELLFIRE_TRA,
  USERMFDV_PRI_CH,
  USERMFDV_ALT_CH,
  USERMFDV_LST,
  USERMFDV_LRFD,
  USERMFDV_ADVISORIES,
  USERMFDV_LST_MODE
];

_lrfdCode = [_vehicle, "LRFD"] call vtx_uh60_weapons_fnc_getLaserCode;
_vehicle setVariable ["ace_laser_code", _lrfdCode, true];

true
