#define FMS_BTN(BTN_VAL,LABEL) \
  class BTN_VAL { \
    positionType="static"; \
    position= BTN_VAL; \
    label=LABEL; \
    radius=0.025; \
    clickSound="vxf_Switch_Sound_2";

#define USERVAL(INDEX,VAL) QUOTE(((getUserMFDValue _this) select INDEX) == VAL)

class menu {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_MENU);
  // THE BUTTON UP CODE CAUSES LIVELOADING THIS CONFIG TO CRASH ARMA
  FMS_BTN(FMS_1,"Checklists")
    buttonUp= QUOTE([ARR_3((_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_LISTS_MENU)], true)] call vtx_uh60_fms_fnc_interaction_pageChange);
  };
  FMS_BTN(FMS_2,"Navigation System")
    buttonUp= QUOTE([ARR_3((_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT)], true)] call vtx_uh60_fms_fnc_interaction_pageChange);
  };
  FMS_BTN(FMS_3,"Fuel Data")
    buttonUp= QUOTE([ARR_3((_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_PERFORMANCE)], true)] call vtx_uh60_fms_fnc_interaction_pageChange);
  };
  FMS_BTN(FMS_4,"Mission Systems")
    buttonUp= QUOTE([ARR_3((_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MSN)], true)] call vtx_uh60_fms_fnc_interaction_pageChange);
  };
  //FMS_BTN(FMS_4,"Weapon Systems","") buttonUp=""; };
};

class checklists {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_LISTS_MENU);
  FMS_BTN(FMS_6,"Startup Checklist")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_LISTS_STARTUP_1)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_7,"Shutdown Checklist")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_1)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_10,"Main Menu")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MENU)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class startup_1 {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_LISTS_STARTUP_1);
  FMS_BTN(FMS_5,"Engine startup")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_LISTS_STARTUP_2)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_10,"Checklists")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_LISTS_MENU)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class startup_2 {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_LISTS_STARTUP_2);
  FMS_BTN(FMS_10,"Checklists")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_LISTS_STARTUP_1)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class shutdown_1 {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_1);
  FMS_BTN(FMS_5,"Power down")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_2)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_10,"Checklists")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_LISTS_MENU)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class shutdown_2 {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_2);
  FMS_BTN(FMS_10,"Checklists")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_1)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class nav {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT);
  FMS_BTN(FMS_1,"Next Waypoint") buttonUp="[vehicle player,""cycle"", 1] call vtx_uh60_fms_fnc_interaction_waypoint;"; };
  FMS_BTN(FMS_2,"Previous waypoint") buttonUp="[vehicle player,""cycle"", -1] call vtx_uh60_fms_fnc_interaction_waypoint;"; };
  FMS_BTN(FMS_3,"Delete Waypoint") buttonUp="[player] call vtx_uh60_fms_fnc_deleteWaypoint;"; };
  FMS_BTN(FMS_4,"Location Stores")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_LIST)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_5,"Microdagr Import")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_IMPORT)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_8,"Slew FLIR") buttonUp="[vehicle player,""slew_flir_waypt""] call vtx_uh60_fms_fnc_interaction_waypoint;"; };
  FMS_BTN(FMS_9,"Send WP") buttonUp="[vehicle player,""send""] call vtx_uh60_fms_fnc_interaction_waypoint;"; };
  FMS_BTN(FMS_10,"Main Menu")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MENU)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class nav_import {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_NAV_IMPORT);
  FMS_BTN(FMS_5,"Microdagr Import")
    buttonUp= [vehicle player,"import", [ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT)]] call vtx_uh60_fms_fnc_interaction_waypoint;
  };
  FMS_BTN(FMS_10,"Navigation System")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_9,"Toggle Auto-Next")
    buttonUp= "vehicle player setVariable [""vtx_uh60_fms_import_autoCycle"", !(vehicle player getVariable [""vtx_uh60_fms_import_autoCycle"",false])];";
  };
};

class nav_location_stores {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_LIST);
  FMS_BTN(FMS_1,"Prev Page") buttonUp="fms_locations_page_index = fms_locations_page_index - 1;[vehicle player] call vtx_uh60_fms_fnc_perSecond;"; };
  FMS_BTN(FMS_2,"Next Page") buttonUp="fms_locations_page_index = fms_locations_page_index + 1;[vehicle player] call vtx_uh60_fms_fnc_perSecond;"; };
  FMS_BTN(FMS_6,"View") buttonUp=[vehicle player,"location", 0, [ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL)]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_7,"View") buttonUp=[vehicle player,"location", 1, [ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL)]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_8,"View") buttonUp=[vehicle player,"location", 2, [ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL)]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_9,"View") buttonUp=[vehicle player,"location", 3, [ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL)]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_10,"Navigation System")
      buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};
class nav_location_sel {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL);
  FMS_BTN(FMS_3,"Slew FLIR") buttonUp=[vehicle player,"slew_flir", nil, [ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT)]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_4,"Add to waypoints") buttonUp=[vehicle player,"store_save_waypoint", nil, [ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT)]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_10,"Location Stores")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_LIST], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class performance {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_PERFORMANCE);
  FMS_BTN(FMS_10,"Main Menu")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MENU)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_1,"Move Probe") buttonUp=[vehicle player] call vtx_uh60_aar_fnc_probe; };
};

class MSN {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_MSN);
  FMS_BTN(FMS_6,"Weapons Systems")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_WPN)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_7,"AN/APQ-187 Radar")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_RDR)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_8,"HUD")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_HMD)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_10,"Main Menu")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MENU)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class wpn {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_WPN);
  FMS_BTN(FMS_10,"Mission Systems")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MSN)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class radar {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_RDR);
  FMS_BTN(FMS_10,"Mission Systems")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MSN)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class FLIR {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_FLIR);
  FMS_BTN(FMS_10,"Mission Systems")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MSN)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class hmd {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_HMD);
  FMS_BTN(FMS_6,"OFF")
    buttonUp = "[-1] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_7,"IMPERIAL ON")
    buttonUp = "[1] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_8,"IMPERIAL DCLT")
    buttonUp = "[2] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_2,"METRIC ON")
    buttonUp = "[3] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_3,"METRIC DCLT")
    buttonUp = "[4] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_4,"BRT")
    buttonUp = [(_this select 0), 1] call vtx_uh60_anvishud_fnc_changeBrightness;
  };
  FMS_BTN(FMS_9,"DIM")
    buttonUp = [(_this select 0), -1] call vtx_uh60_anvishud_fnc_changeBrightness;
  };
  FMS_BTN(FMS_10,"Mission Systems")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MSN)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class hud {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_HUD);
  FMS_BTN(FMS_6,"OFF")
    buttonUp = "[-1] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_7,"IMPERIAL ON")
    buttonUp = "[5] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_2,"METRIC ON")
    buttonUp = "[6] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_4,"BRT")
    buttonUp = [(_this select 0), 1] call vtx_uh60_anvishud_fnc_changeBrightness;
  };
  FMS_BTN(FMS_9,"DIM")
    buttonUp = [(_this select 0), -1] call vtx_uh60_anvishud_fnc_changeBrightness;
  };
  FMS_BTN(FMS_10,"Mission Systems")
    buttonUp= [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MSN)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class menu_comm_acre {
  condition = QUOTE((((getUserMFDValue _this) select FMS_PAGE_INDEX) == FMS_PAGE_MENU) && (isClass (configFile >> ""cfgPatches"" >> ""acre_main"")));
  FMS_BTN(FMS_6,"Radio Page") 
    buttonUp=[(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_COMM_ACRE)], true] call vtx_uh60_fms_fnc_interaction_pageChange; 
  };
};

class COMM_ACRE {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_COMM_ACRE);
  FMS_BTN(FMS_10, "Main Menu")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_MENU], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  /*FMS_BTN(FMS_5, "Initialize")
    buttonUp= [(_this select 0)] call vtx_uh60_acre_fnc_initComms;
  };*/
  FMS_BTN(FMS_6, "Radio 1 Settings")
    buttonUp= QUOTE([ARR_3((_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_COMM_INFO_ACRE)], true)] call vtx_uh60_fms_fnc_interaction_pageChange; fms_radio_index = 0; [vehicle player] call vtx_uh60_fms_fnc_perSecond;);
  };
  FMS_BTN(FMS_7, "Radio 2 Settings")
    buttonUp= QUOTE([ARR_3((_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_COMM_INFO_ACRE)], true)] call vtx_uh60_fms_fnc_interaction_pageChange; fms_radio_index = 1; [vehicle player] call vtx_uh60_fms_fnc_perSecond;);
  };
  FMS_BTN(FMS_8, "Radio 3 Settings")
    buttonUp= QUOTE([ARR_3((_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_COMM_INFO_ACRE)], true)] call vtx_uh60_fms_fnc_interaction_pageChange; fms_radio_index = 2; [vehicle player] call vtx_uh60_fms_fnc_perSecond;);
  };
  FMS_BTN(FMS_9, "Radio 4 Settings")
    buttonUp= QUOTE([ARR_3((_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_COMM_INFO_ACRE)], true)] call vtx_uh60_fms_fnc_interaction_pageChange; fms_radio_index = 3; [vehicle player] call vtx_uh60_fms_fnc_perSecond;);
  };
};

class COMM_INFO_ACRE {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_COMM_INFO_ACRE);
  FMS_BTN(FMS_10, "Return")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_COMM_ACRE], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_1, "Preset Selection")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_COMM_PRESETS_ACRE], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_5, "On/Off")
    buttonUp= [(_this select 0),fms_radio_index] call vtx_uh60_acre_fnc_radioStatusUpdate;
  };
  FMS_BTN(FMS_6, "Channel Up")
    buttonUp= "[(_this select 0),fms_radio_index, 1] call vtx_uh60_acre_fnc_cycleRadioChannel; [vehicle player] call vtx_uh60_fms_fnc_perSecond;";
  };
  FMS_BTN(FMS_7, "Channel Down")
    buttonUp= "[(_this select 0),fms_radio_index, -1] call vtx_uh60_acre_fnc_cycleRadioChannel; [vehicle player] call vtx_uh60_fms_fnc_perSecond;";
  };
  FMS_BTN(FMS_8, "Spatial Next")
    buttonUp= "[(_this select 0),fms_radio_index, 1] call vtx_uh60_acre_fnc_cycleSpatial; [vehicle player] call vtx_uh60_fms_fnc_perSecond;";
  };
  FMS_BTN(FMS_9, "Spatial Prev")
    buttonUp= "[(_this select 0),fms_radio_index, -1] call vtx_uh60_acre_fnc_cycleSpatial; [vehicle player] call vtx_uh60_fms_fnc_perSecond;";
  };
};

class COMM_PRESETS_ACRE {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_COMM_PRESETS_ACRE);
  FMS_BTN(FMS_10, "Return")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_COMM_INFO_ACRE], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_1,"Prev Page") buttonUp="fms_comm_presets_page_index = fms_comm_presets_page_index - 1;[vehicle player] call vtx_uh60_fms_fnc_perSecond;"; };
  FMS_BTN(FMS_2,"Next Page") buttonUp="fms_comm_presets_page_index = fms_comm_presets_page_index + 1;[vehicle player] call vtx_uh60_fms_fnc_perSecond;"; };
  FMS_BTN(FMS_6,"Set to Preset") buttonUp=[(_this select 0),fms_radio_index, 1, [FMS_PAGE_INDEX,FMS_PAGE_COMM_INFO_ACRE]] call vtx_uh60_acre_fnc_fmsSetPreset;};
  FMS_BTN(FMS_7,"Set to Preset") buttonUp=[(_this select 0),fms_radio_index, 2, [FMS_PAGE_INDEX,FMS_PAGE_COMM_INFO_ACRE]] call vtx_uh60_acre_fnc_fmsSetPreset;};
  FMS_BTN(FMS_8,"Set to Preset") buttonUp=[(_this select 0),fms_radio_index, 3, [FMS_PAGE_INDEX,FMS_PAGE_COMM_INFO_ACRE]] call vtx_uh60_acre_fnc_fmsSetPreset;};
  FMS_BTN(FMS_9,"Set to Preset") buttonUp=[(_this select 0),fms_radio_index, 4, [FMS_PAGE_INDEX,FMS_PAGE_COMM_INFO_ACRE]] call vtx_uh60_acre_fnc_fmsSetPreset;};
};