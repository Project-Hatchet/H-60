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
  [_vehicle, 12, _r * 1000] call vtx_uh60_mfd_fnc_setPylonValue;
  [_vehicle, 13, _g * 1000] call vtx_uh60_mfd_fnc_setPylonValue;
  [_vehicle, 14, _b * 1000] call vtx_uh60_mfd_fnc_setPylonValue;
  [_vehicle, 15, _brightness * 1000] call vtx_uh60_mfd_fnc_setPylonValue;
};

if(!((driver _vehicle) isEqualTo player) && (_vehicle getCargoIndex player == -1)) then {
  //Set Copilot pylon values
  [_vehicle, 8, _r * 1000] call vtx_uh60_mfd_fnc_setPylonValue;
  [_vehicle, 9, _g * 1000] call vtx_uh60_mfd_fnc_setPylonValue;
  [_vehicle, 10, _b * 1000] call vtx_uh60_mfd_fnc_setPylonValue;
  [_vehicle, 11, _brightness * 1000] call vtx_uh60_mfd_fnc_setPylonValue;
};
