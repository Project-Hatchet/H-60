/*
 * vtx_uh60_anvishud_fnc_setup
 *
 * initial setup of ANVIS/HUD-24T
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

if (!(typeOf _vehicle in ["vtx_MH60S_Pylons_GAU21L","vtx_MH60S_GAU21L","vtx_MH60S_Pylons","vtx_MH60S","vtx_MH60M_DAP","vtx_MH60M"])) exitWith { false };

//set pylon 16, 17 value based on CBA setting for default HMD modes
if((driver _vehicle) isEqualTo player) then {
  //Set driver pylon values
  [_vehicle, 17, vtx_uh60_anvishud_defaultMode] call vtx_uh60_mfd_fnc_setPylonValue;
}else{
  //Set Copilot pylon values
  [_vehicle, 16, vtx_uh60_anvishud_defaultMode] call vtx_uh60_mfd_fnc_setPylonValue;
};

[_vehicle] call vtx_uh60_anvishud_fnc_configureHMD;

true
