/*
 * vtx_uh60_fms_fnc_perFrame
 *
 * handles per frame updates of data for FMS
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

params ["_vehicle", "_frameTime"];

#include "..\config\fmsDefines.hpp"
#define HELP_LABEL(MEMPOINT,LABEL) drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",[0,1,0,1],_vehicle modelToWorldVisual (_vehicle selectionPosition MEMPOINT),1,1,0,LABEL,2,0.045];
#define HELP_LABEL_COND(MEMPOINT,LABEL,COND) drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selected_ca.paa",(if(COND)then{[0,1,0,1]}else{[1,0,0,1]}),_vehicle modelToWorldVisual (_vehicle selectionPosition MEMPOINT),1,1,0,LABEL,2,0.045,"RobotoCondensed","center",true];

if (missionNamespace getVariable ["vtx_uh60m_enabled_waypts", false]) then {
    _this call vtx_uh60_fms_fnc_updateWaypointInfo;
};

private _fms = if (player == driver _vehicle) then [{ FMS_R_PAGE_INDEX }, { FMS_L_PAGE_INDEX }];
private _strings = switch ((getUserMFDValue _vehicle) # _fms) do {
    case FMS_LISTS_STARTUP_1: {
        HELP_LABEL_COND("b_gen1","1",(_vehicle animationPhase "Switch_gen1" < 0.1))
        HELP_LABEL_COND("b_gen2","1",(_vehicle animationPhase "Switch_gen2" < 0.1))
        HELP_LABEL_COND("b_batt1","2",(_vehicle animationPhase "Switch_batt1" < 0.1))
        HELP_LABEL_COND("b_batt2","2",(_vehicle animationPhase "Switch_batt2" < 0.1))

        HELP_LABEL_COND("b_fuelpump","3",(_vehicle animationPhase "Switch_fuelpump" < 0.1))
        HELP_LABEL_COND("b_apucont","4",(_vehicle animationPhase "Switch_apucont" < 0.1))
        HELP_LABEL_COND("b_apugen","5",(_vehicle getVariable "APU_POWER"))
        HELP_LABEL_COND("b_stbyinst","6",(_vehicle animationPhase "Switch_stbyinst" < 0.1))
    };
    case FMS_LISTS_STARTUP_2: {
        HELP_LABEL_COND("b_ignition","7",(_vehicle animationPhase "Switch_ignition" > 0.5))
        HELP_LABEL_COND("b_airsce","8",(_vehicle animationPhase "Switch_airsce" < 0.1))
        HELP_LABEL_COND("b_fuelsys1","9",(_vehicle animationPhase "Lever_fuelsys1" > 0.5))
        HELP_LABEL_COND("b_fuelsys2","9",(_vehicle animationPhase "Lever_fuelsys2" > 0.5))

        HELP_LABEL_COND("b_starter1","10",(_vehicle getVariable "ENG_START1"))
        HELP_LABEL_COND("b_starter2","10",(_vehicle getVariable "ENG_START2"))
        HELP_LABEL_COND("b_engpowercont1","11-12",(_vehicle animationPhase "Lever_engpower1" > 0.8))
        HELP_LABEL_COND("b_engpowercont2","11-12",(_vehicle animationPhase "Lever_engpower2" > 0.8))
        HELP_LABEL_COND("b_apucont","13",(_vehicle animationPhase "Switch_apucont" > 0.1))
    };
    case FMS_LISTS_SHUTDOWN_1: {
        HELP_LABEL("handle_wheelbrake","1")
        HELP_LABEL("b_fuelboostpump1","2")
        HELP_LABEL("b_fuelboostpump2","2")
        HELP_LABEL("b_apucont","3")
        HELP_LABEL("b_gen1","4")
        HELP_LABEL("b_gen2","4")
        HELP_LABEL("b_engpowercont1","5")
        HELP_LABEL("b_engpowercont2","5")
        HELP_LABEL("b_fuelsys1","6")
        HELP_LABEL("b_fuelsys2","6")
        HELP_LABEL("b_ignition","7")
    };
    case FMS_LISTS_SHUTDOWN_2: {
        HELP_LABEL("b_apugen","8")
        HELP_LABEL("b_fuelpump","9")
        HELP_LABEL("b_apucont","10")
        HELP_LABEL("b_batt1","11")
        HELP_LABEL("b_batt2","11")
    };
};


if ((count customWaypointPosition) > 0) then {
    _vehicle setUserMFDvalue [1, _vehicle distance2D customWaypointPosition];
} else {
    private _wayPoint = [group player, currentWaypoint group player];
    private _position = waypointPosition _wayPoint;
    _vehicle setUserMFDvalue [1, _vehicle distance2D _position];
};