#include "script_component.hpp"
/*
 * vtx_uh60_anvishud_fnc_configureHMD
 *
 * Applies user settings to ANVIS/HUD-24T from CBA options
 *
 * params (array)[(object) vehicle]
 */

params [["_vehicle", nil]];

if(isNil "_vehicle") exitWith {};

vtx_uh60_anvishud_settingColor params ["_r", "_g", "_b"];
vtx_uh60_anvishud_settingBrightness params ["_brightness"];
_vehicle setUserMFDValue [
  USERMFDV_HMD_R, _r, _g, _b, _brightness
  //USERMFDV_HMD_G, _g,
  //USERMFDV_HMD_B, _b,
  //USERMFDV_HMD_A, _brightness
];
