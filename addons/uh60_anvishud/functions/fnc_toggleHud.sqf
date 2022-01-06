/*
 * vtx_uh60_anvishud_fnc_toggleHud
 *
 * Toggles your HMD
 *
 * params ["_value"]
 */

params ["_value"];

if((driver _vehicle) isEqualTo player) then {
  //Set driver pylon values
  [_vehicle, 17, _value] call vtx_uh60_mfd_fnc_setPylonValue;
}else{
  //Set Copilot pylon values
  [_vehicle, 16, _value] call vtx_uh60_mfd_fnc_setPylonValue;
};

[vehicle player] call vtx_uh60_anvishud_fnc_configureHMD;
