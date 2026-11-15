/*
 * Author: Yax
 * Start the pip camera
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call hct_h60_flir_fnc_pipStart
 */

if (isNil "hct_h60_flir_camera") then {
  hct_h60_flir_camera = "camera" camCreate [0,0,0];
};

// placed now, not on the next frame's fnc_updateCamera: a new camera starts at the map origin
if (!isNil "hct_vehicle" && {!isNull hct_vehicle}) then {
  [hct_vehicle] call hct_h60_flir_fnc_updateCamera;
};
hct_h60_flir_camera cameraEffect ["internal", "BACK", "hct_h60_flir_feed"];
hct_h60_flir_camera camSetFocus [-1,-1];
hct_h60_flir_camera camCommit 0;
// the selected vision mode - a fixed colour effect here overrode it, so returning from a
// feature camera (fnc_setup) came back in the wrong mode until the next toggle
"hct_h60_flir_feed" setPiPEffect (missionNamespace getVariable ["hct_h60_flir_pipEffect", [0]]);

call hct_h60_flir_fnc_setIsPipHidden;

true
