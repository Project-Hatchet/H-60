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

//Configure pylons based on CBA setting

if((driver _vehicle) isEqualTo player) then {
  //Set driver pylon values
  _vehicle setPylonLoadout ["dummy12", "vtx_1000rnd_dummy", true];
  _vehicle setPylonLoadout ["dummy13", "vtx_1000rnd_dummy", true];
  _vehicle setPylonLoadout ["dummy14", "vtx_1000rnd_dummy", true];
  _vehicle setPylonLoadout ["dummy15", "vtx_1000rnd_dummy", true];
  _vehicle setAmmoOnPylon ["dummy12", _r * 1000];
  _vehicle setAmmoOnPylon ["dummy13", _g * 1000];
  _vehicle setAmmoOnPylon ["dummy14", _b * 1000];
  _vehicle setAmmoOnPylon ["dummy15", _brightness * 1000];
}else{
  //Set Copilot pylon values
  _vehicle setPylonLoadout ["dummy8", "vtx_1000rnd_dummy", true];
  _vehicle setPylonLoadout ["dummy9", "vtx_1000rnd_dummy", true];
  _vehicle setPylonLoadout ["dummy10", "vtx_1000rnd_dummy", true];
  _vehicle setPylonLoadout ["dummy11", "vtx_1000rnd_dummy", true];
  _vehicle setAmmoOnPylon ["dummy8", _r * 1000];
  _vehicle setAmmoOnPylon ["dummy9", _g * 1000];
  _vehicle setAmmoOnPylon ["dummy10", _b * 1000];
  _vehicle setAmmoOnPylon ["dummy11", _brightness * 1000];
};
