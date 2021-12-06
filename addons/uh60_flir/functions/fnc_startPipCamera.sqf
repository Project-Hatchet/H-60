params ["_vehicle"];
vtx_uh60_flir_pip_camera = "camera" camCreate [0,0,0];
private _initFovStep = ((_vehicle getVariable "vtx_flir_fovObjects") # (_vehicle getVariable ["vtx_flir_initFovMode",0]));
vtx_uh60_flir_pip_camera camSetFov (_initFovStep # 0);
vtx_uh60_flir_fov = _initFovStep;
vtx_uh60_flir_pip_camera cameraEffect ["internal", "BACK", "vtx_uh60_flir_feed"];
vtx_uh60_flir_pip_camera camSetFocus [-1,-1];

showCinemaBorder false;