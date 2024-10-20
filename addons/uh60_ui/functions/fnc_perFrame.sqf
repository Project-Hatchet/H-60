/*
 * vtx_uh60_ui_fnc_perFrame
 *
 * runs the per frame updates of the ui
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

params ["_vehicle", "_frameTime"];

#include "uiDefines.hpp"

if !(vtx_uh60_ui_isViewInternal) exitWith {
    CTRL(4001123) ctrlSetText "";
    CTRL(4001123) ctrlCommit 0;
};

#define HELP_LABEL(MEMPOINT,LABEL) drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",[0,1,0,1],_vehicle modelToWorldVisual (_vehicle selectionPosition MEMPOINT),1,1,0,LABEL,2,0.045,"RobotoCondensed","center",true];
#define HELP_LABEL_COND(MEMPOINT,LABEL,COND) drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",(if(COND)then{[0,1,0,1]}else{[1,0,0,1]}),_vehicle modelToWorldVisual (_vehicle selectionPosition MEMPOINT),1,1,0,LABEL,2,0.045,"RobotoCondensed","center",true];

if (vtx_uh60_ui_helpEnabled) then {
    private _hasDoorgun = [_vehicle, "doorguns"] call vxf_core_fnc_hasModule;
    if (!_hasDoorgun) then {
        drawIcon3D [
            "\z\ace\addons\interaction\ui\dot_ca.paa",
            [1,1,1,1],
            _vehicle modelToWorldVisual [0,5,-0.7],
            1,
            1,
            0,
            "",
            2,
            0.05
        ];

        HELP_LABEL_COND("b_batt1","Battery switches",(_vehicle animationPhase "Switch_batt1" < 0.1))
        HELP_LABEL_COND("b_batt2","",(_vehicle animationPhase "Switch_batt2" < 0.1))
        HELP_LABEL("FMS_L_1","FMS")
        HELP_LABEL("FMS_R_1","FMS")
    } else {
        HELPCTRL(5) ctrlShow ((!difficultyEnabledRTD) && !_hasDoorgun);
        HELPCTRL(6) ctrlShow ((!difficultyEnabledRTD) && !_hasDoorgun);
    };
};

if (vtx_uh60m_trackIR_interaction_cursor) then {
    private _y = (inputAction "aimDown") - (inputAction "aimUp");
    private _x = (inputAction "aimRight") - (inputAction "aimLeft");

    vxf_interaction_cursorPos params ["_curX", "_curY"];
    if (abs _x < 0.02) then { _x = 0; };
    if (abs _y < 0.02) then { _y = 0; };
    vxf_interaction_cursorPos = [
        (_curX + (_x * vtx_uh60m_trackIR_interaction_cursorSensitivity * (_frameTime / 4))) max safeZoneX min (safeZoneX + safeZoneW),
        (_curY + (_y * vtx_uh60m_trackIR_interaction_cursorSensitivity * (_frameTime / 4))) max safeZoneY min (safeZoneY + safeZoneH)
    ];
    CTRL(4001120) ctrlSetText "\A3\ui_f\data\igui\cfg\cursors\iconCursorSupport_ca.paa";
} else {
    CTRL(4001120) ctrlSetText "\A3\ui_f\data\igui\cfg\cursors\iconComplex_ca.paa";
};
CTRL(4001120) ctrlSetPosition [
    (vxf_interaction_cursorPos # 0) - 0.02,
    (vxf_interaction_cursorPos # 1) - 0.02
];
CTRL(4001120) ctrlCommit 0;

if !(getUserMFDValue _vehicle # 15 > -1) exitWith {
    CTRL(4001123) ctrlSetText "";
    CTRL(4001123) ctrlCommit 0;
};
if !(player == driver _vehicle || player == _vehicle turretUnit [0]) exitWith {};

if (currentVisionMode player == 0 && !(vtx_uh60_flir_isInScriptedCamera || cameraView == "GUNNER")) then {
    CTRL(4001123) ctrlSetText "\z\vtx\addons\uh60_ui\data\hudOverlay.paa";
} else {
    CTRL(4001123) ctrlSetText "";
};
CTRL(4001123) ctrlCommit 0;