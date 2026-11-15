#include "script_component.hpp"
/*
 * hct_h60_weapons_fnc_setup
 *
 * Hatchet module hook: weapons-system defaults on the vehicle and its MFD slots.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];

_vehicle setVariable ["hct_h60_hellfire_laserCodeIndex", _vehicle getVariable ["hct_h60_hellfire_laserCodeIndex", 0], true];

_vehicle setVariable ["hct_h60_hellfire_lastLaunchTime", 0];
_vehicle setVariable ["hct_h60_hellfire_impactTime", -1];

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

private _lrfdCode = [_vehicle, "LRFD"] call hct_h60_weapons_fnc_getLaserCode;
_vehicle setVariable ["ace_laser_code", _lrfdCode, true];

true
