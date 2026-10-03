/*
 * align searchlight to view direction
 */

_v = cameraOn vectorWorldToModelVisual getCameraViewDirection player;
_v call CBA_fnc_vect2polar params ["", "_az", "_el"];
cameraOn animateSource ["searchlight_turn", rad _az];
cameraOn animateSource ["searchlight_elev", rad _el];
[_az, _el]
