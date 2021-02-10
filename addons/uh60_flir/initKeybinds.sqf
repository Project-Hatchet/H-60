[
    "UH-60M Blackhawk","vtx_uh60m_flir_c_up","FLIR Up", // Control + W
    {CHK_FLIR; vtx_uh60_flir_up = 1;},{vtx_uh60_flir_up = 0;},
    [17, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60m_flir_c_down","FLIR Down", // Control + S
    {CHK_FLIR; vtx_uh60_flir_down = 1;},{vtx_uh60_flir_down = 0;},
    [31, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60m_flir_c_left","FLIR Left", // Control + A
    {CHK_FLIR; vtx_uh60_flir_left = 1;},{vtx_uh60_flir_left = 0;},
    [30, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60m_flir_c_right","FLIR Right", // Control + D
    {CHK_FLIR; vtx_uh60_flir_right = 1;},{vtx_uh60_flir_right = 0;},
    [32, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60m_flir_c_slew","FLIR Slew Analog", // Unbound
    {CHK_FLIR; vtx_uh60_flir_slew = 1;},{vtx_uh60_flir_slew = 0;}//,
    //[32, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60m_flir_c_slewHMD","FLIR Slew To HMD", // Shift + T
    vtx_uh60_flir_fnc_keyFLIRSlewToHMD,{},
    [20, [true, false, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60m_flir_c_stabilize","FLIR Stabilize", // Alt + T
    vtx_uh60_flir_fnc_keyFLIRStabilize,{},
    [20, [false, false, true]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60m_flir_c_zoom_inc","FLIR Zoom In", // PLUS
    {
        CHK_FLIR;
        private _zoom = vtx_uh60_flir_fovLevels findIf {_x == vtx_uh60_flir_fov};
        if (_zoom < 4) then {
            vtx_uh60_flir_fov = vtx_uh60_flir_fovLevels # (_zoom + 1);
            [vtx_uh60_flir_fov] call vtx_uh60_flir_fnc_syncFOV;
        };
    },{},
    [13, [false, false, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60m_flir_c_zoom_desc","FLIR Zoom Out", // MIN
    {
        CHK_FLIR;
        private _zoom = vtx_uh60_flir_fovLevels findIf {_x == vtx_uh60_flir_fov};
        if (_zoom > 0) then {
            vtx_uh60_flir_fov = vtx_uh60_flir_fovLevels # (_zoom - 1);
            [vtx_uh60_flir_fov] call vtx_uh60_flir_fnc_syncFOV;
        };
    },{},
    [12, [false, false, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60m_flir_c_cameraMode","FLIR Camera Mode", // T
    {
        CHK_FLIR;
        //systemChat str vtx_uh60m_flir_c_cameraMode;
        switch(vtx_uh60m_flir_c_cameraMode) do {
            case 0: {vtx_uh60m_flir_c_cameraMode = 2};
            case 2: {vtx_uh60m_flir_c_cameraMode = 7};
            case 7: {vtx_uh60m_flir_c_cameraMode = 1};
            case 1: {vtx_uh60m_flir_c_cameraMode = 0};
        };
        "vtx_uh60_flir_feed" setPiPEffect [vtx_uh60m_flir_c_cameraMode];
        [vtx_uh60m_flir_c_cameraMode] call vtx_uh60_flir_fnc_syncCameraMode;
    },{},
    [20, [false, false, false]],false
] call CBA_fnc_addKeybind;
