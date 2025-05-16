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

//_vehicle getCargoIndex player

//Configure pylons based on CBA settings
if(((driver _vehicle) isEqualTo player) && (_vehicle getCargoIndex player == -1)) then {
  //Set driver pylon values
  _vehicle setUserMFDValue [
    USERMFDV_RHMD_R, _r * 1000,
    USERMFDV_RHMD_G, _g * 1000,
    USERMFDV_RHMD_B, _b * 1000,
    USERMFDV_RHMD_A, _brightness * 1000
  ];
};

if(!((driver _vehicle) isEqualTo player) && (_vehicle getCargoIndex player == -1)) then {
  //Set Copilot pylon values
  _vehicle setUserMFDValue [
    USERMFDV_LHMD_R, _r * 1000,
    USERMFDV_LHMD_G, _g * 1000,
    USERMFDV_LHMD_B, _b * 1000,
    USERMFDV_LHMD_A, _brightness * 1000
  ];
};
