params ["_vehicle"];

#define HELP_LABEL(MEMPOINT,LABEL) drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",[0,1,0,1],_vehicle modelToWorldVisual (_vehicle selectionPosition MEMPOINT),1,1,0,LABEL,2,0.045,"RobotoCondensed","center",true];
#define HELP_LABEL_COND(MEMPOINT,LABEL,COND) drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",(if(COND)then{[0,1,0,1]}else{[1,0,0,1]}),_vehicle modelToWorldVisual (_vehicle selectionPosition MEMPOINT),1,1,0,LABEL,2,0.045,"RobotoCondensed","center",true];

if (vtx_uh60_ui_helpEnabled) then {
    private _turretIndex = [player] call ace_common_fnc_getTurretIndex;
    if (_turretIndex # 0 == 1) then {
        drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",[1,1,1,1],(_vehicle modelToWorldVisual [-0.8,3.8,-1]),1,1,0,"Ammo Count Check",2,0.045,"RobotoCondensed","right",true];
        HELP_LABEL_COND("b_minigun_safe_cover_l","Safety cover",(_vehicle animationPhase "Switch_minigun_safe_cover_l" > 0.5))
        if (_vehicle animationPhase "Switch_minigun_safe_cover_l" > 0.5) then {
            HELP_LABEL_COND("b_minigun_safe_l","Power switch",(_vehicle animationPhase "Switch_minigun_safe_l" > 0.5))
        };
    };
    if (_turretIndex # 0 == 2) then {
        drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",[1,1,1,1],(_vehicle modelToWorldVisual [0.8,3.8,-1]),1,1,0,"Ammo Count Check",2,0.045,"RobotoCondensed","right",true];
        HELP_LABEL_COND("b_minigun_safe_cover_r","Safety cover",(_vehicle animationPhase "Switch_minigun_safe_cover_r" > 0.5))
        if (_vehicle animationPhase "Switch_minigun_safe_cover_r" > 0.5) then {
            HELP_LABEL_COND("b_minigun_safe_r","Power switch",(_vehicle animationPhase "Switch_minigun_safe_r" > 0.5))
        };
    };
};
