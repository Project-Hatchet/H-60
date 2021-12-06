[
    "UH-60M Blackhawk","vtx_uh60_flir_copilotCamera","Copilot Camera", // Control + Right click
    {
      if (
        !vtx_uh60_flir_playerIsCopilot ||
        {!vtx_uh60_flir_controllable} ||
        {vtx_uh60_flir_isVisibleMap} ||
        {vtx_uh60_flir_featureCamera != ""} ||
        {!isNull curatorCamera}
      ) exitWith {false};
      vtx_uh60_flir_isInScriptedCamera = !vtx_uh60_flir_isInScriptedCamera;
      [vtx_uh60_flir_isInScriptedCamera] call vtx_uh60_flir_fnc_scriptedCamera;
      false
    },{},
    [241, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60_flir_c_up","FLIR Up", // Control + W
    {if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_up = 1; false},{vtx_uh60_flir_up = 0;},
    [17, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60_flir_c_down","FLIR Down", // Control + S
    {if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_down = 1; false},{vtx_uh60_flir_down = 0;},
    [31, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60_flir_c_left","FLIR Left", // Control + A
    {if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_left = 1; false},{vtx_uh60_flir_left = 0;},
    [30, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60_flir_c_right","FLIR Right", // Control + D
    {if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_right = 1; false},{vtx_uh60_flir_right = 0;},
    [32, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60_flir_c_slew",
    ["FLIR Slew Aim", "Hold this key and use mouse or 'Aim <Up|Down|Left|Right>' input to slew the FLIR."], // Unbound
    {
      if (vtx_uh60_flir_isPipHidden || {vtx_uh60_flir_isInScriptedCamera}) exitWith {false};
      vtx_uh60_flir_slewAim = true;
      if (vtx_uh60_flir_setting_AimSlewBlockMouse && {!ace_interact_menu_keyDown}) then {
        if (!(uiNamespace getVariable ["vtx_uh60_flir_mouseBlocker", false])) then {
          (findDisplay 46) createDisplay "vtx_uh60_flir_mouseBlocker";
          (finddisplay 86005) displayAddEventHandler ["KeyUp", {[_this,'keyup'] call CBA_events_fnc_keyHandler}];
        };
      };
      false
    },{
      if (uiNamespace getVariable ["vtx_uh60_flir_mouseBlocker", false]) then {
        (findDisplay 86005) closeDisplay 0;
      };
      vtx_uh60_flir_slewAim = false;
    }//,
    //[32, [false, true, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60_flir_c_slewHMD","FLIR Slew To HMD", // Shift + T
    {
      if (vtx_uh60_flir_playerIsPilot || {vtx_uh60_flir_playerIsCopilot}) then {
        call vtx_uh60_flir_fnc_keyFLIRSlewToHMD;
      };
      false
    },{},
    [20, [true, false, false]],false
] call CBA_fnc_addKeybind;

/* Use base game keybind
[
    "UH-60M Blackhawk","vtx_uh60_flir_c_stabilize","FLIR Stabilize", // Ctrl + T
    vtx_uh60_flir_fnc_setStabilization,{},
    [20, [false, true, false]],false
] call CBA_fnc_addKeybind;
*/

[
    "UH-60M Blackhawk","vtx_uh60_flir_c_zoom_inc","FLIR Zoom In", // PLUS
    {
        if (vtx_uh60_flir_isPipHidden) exitWith {false};
        [1] call vtx_uh60_flir_fnc_keyZoom;
        false
    },{},
    [13, [false, false, false]],false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk","vtx_uh60_flir_c_zoom_desc","FLIR Zoom Out", // MIN
    {
        if (vtx_uh60_flir_isPipHidden) exitWith {false};
        [-1] call vtx_uh60_flir_fnc_keyZoom;
        false
    },{},
    [12, [false, false, false]],false
] call CBA_fnc_addKeybind;

/* moved to transportNightVision base game keybind
[
    "UH-60M Blackhawk","vtx_uh60_flir_pipEffect","FLIR Camera Mode", // T
    {
        if (vtx_uh60_flir_isPipHidden) exitWith {false};
        call vtx_uh60_flir_fnc_keyVisionMode
    },{},
    [20, [false, false, false]],false
] call CBA_fnc_addKeybind;
*/
