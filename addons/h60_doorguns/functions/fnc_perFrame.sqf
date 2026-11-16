/*
 * hct_h60_doorguns_fnc_perFrame
 *
 * Hatchet module hook: draws the door-gun help labels for the gunner when help is enabled.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];

#define HELP_LABEL(MEMPOINT,LABEL) drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",[0,1,0,1],_vehicle modelToWorldVisual (_vehicle selectionPosition MEMPOINT),1,1,0,LABEL,2,0.045,"RobotoCondensed","center",true];
#define HELP_LABEL_COND(MEMPOINT,LABEL,COND) drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",(if(COND)then{[0,1,0,1]}else{[1,0,0,1]}),_vehicle modelToWorldVisual (_vehicle selectionPosition MEMPOINT),1,1,0,LABEL,2,0.045,"RobotoCondensed","center",true];

if (hct_h60_ui_helpEnabled) then {
    private _seat = ([player] call ace_common_fnc_getTurretIndex) param [0, -1]; // [] for a non-turret seat
    if (_seat == 1) then {
        drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",[1,1,1,1],(_vehicle modelToWorldVisual [-0.8,3.8,-1]),1,1,0,localize "STR_hct_h60_doorguns_AmmoCountCheck",2,0.045,"RobotoCondensed","right",true];
        HELP_LABEL_COND("b_minigun_safe_cover_l",localize "STR_hct_h60_doorguns_SafetyCover",(_vehicle animationPhase "Switch_minigun_safe_cover_l" > 0.5))
        if (_vehicle animationPhase "Switch_minigun_safe_cover_l" > 0.5) then {
            HELP_LABEL_COND("b_minigun_safe_l",localize "STR_hct_h60_doorguns_PowerSwitch",(_vehicle animationPhase "Switch_minigun_safe_l" > 0.5))
        };
    };
    if (_seat == 2) then {
        drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",[1,1,1,1],(_vehicle modelToWorldVisual [0.8,3.8,-1]),1,1,0,localize "STR_hct_h60_doorguns_AmmoCountCheck",2,0.045,"RobotoCondensed","right",true];
        HELP_LABEL_COND("b_minigun_safe_cover_r",localize "STR_hct_h60_doorguns_SafetyCover",(_vehicle animationPhase "Switch_minigun_safe_cover_r" > 0.5))
        if (_vehicle animationPhase "Switch_minigun_safe_cover_r" > 0.5) then {
            HELP_LABEL_COND("b_minigun_safe_r",localize "STR_hct_h60_doorguns_PowerSwitch",(_vehicle animationPhase "Switch_minigun_safe_r" > 0.5))
        };
    };
};
