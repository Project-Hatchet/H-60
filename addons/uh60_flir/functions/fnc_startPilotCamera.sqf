params ["_vehicle"];
vtx_uh60_flir_camera = "camera" camCreate [0,0,0];
private _initFovStep = ((_vehicle getVariable "vtx_flir_fovObjects") # (_vehicle getVariable ["vtx_flir_initFovMode",0]));
vtx_uh60_flir_camera camSetFov (_initFovStep # 0);
vtx_uh60_flir_fov = _initFovStep;
vtx_uh60_flir_camera cameraEffect ["internal", "BACK"];
vtx_uh60_flir_camera camSetFocus [-1,-1];
15 cutRsc ["vtx_uh60_flir_cameraOverlay", "PLAIN"];
showCinemaBorder false;

"filmGrain" ppEffectAdjust [0.5, 2, 1, 1, 1];
"filmGrain" ppEffectCommit 0;
"filmGrain" ppEffectEnable true;
