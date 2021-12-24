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
  //FMS_BTN(FMS_6,"COMM 1","") buttonUp=""; };
  //FMS_BTN(FMS_7,"COMM 2","") buttonUp=""; };
  //FMS_BTN(FMS_8,"COMM 3","") buttonUp=""; };
  //FMS_BTN(FMS_9,"COMM 4","") buttonUp=""; };

  FMS_BTN(FMS_1,"Checklists","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_LISTS_MENU], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_2,"Navigation System","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_3,"Fuel Data","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_PERFORMANCE], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_4,"Mission Systems","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_MSN], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  //FMS_BTN(FMS_4,"Weapon Systems","") buttonUp=""; };
};

class checklists {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_LISTS_MENU);
  FMS_BTN(FMS_6,"Startup Checklist","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_LISTS_STARTUP_1], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_7,"Shutdown Checklist","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_1], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_10,"Main Menu","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_MENU], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class startup_1 {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_LISTS_STARTUP_1);
  FMS_BTN(FMS_5,"Engine startup","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_LISTS_STARTUP_2], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_10,"Checklists","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_LISTS_MENU], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class startup_2 {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_LISTS_STARTUP_2);
  FMS_BTN(FMS_10,"Checklists","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_LISTS_STARTUP_1], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class shutdown_1 {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_1);
  FMS_BTN(FMS_5,"Power down","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_2], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_10,"Checklists","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_LISTS_MENU], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class shutdown_2 {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_2);
  FMS_BTN(FMS_10,"Checklists","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_1], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class nav {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT);
  FMS_BTN(FMS_1,"Next Waypoint","") buttonUp="[vehicle player,""cycle"", 1] call vtx_uh60_fms_fnc_interaction_waypoint;"; };
  FMS_BTN(FMS_2,"Previous waypoint","") buttonUp="[vehicle player,""cycle"", -1] call vtx_uh60_fms_fnc_interaction_waypoint;"; };
  FMS_BTN(FMS_4,"Location Stores","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_LIST], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_5,"Microdagr Import","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_NAV_IMPORT], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_8,"Slew FLIR","") buttonUp="[vehicle player,""slew_flir_waypt""] call vtx_uh60_fms_fnc_interaction_waypoint;"; };
  FMS_BTN(FMS_9,"Send WP","") buttonUp="[vehicle player,""send""] call vtx_uh60_fms_fnc_interaction_waypoint;"; };
  FMS_BTN(FMS_10,"Main Menu","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_MENU], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class nav_import {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_NAV_IMPORT);
  FMS_BTN(FMS_5,"Microdagr Import","")
    buttonUp= [vehicle player,"import", [FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT]] call vtx_uh60_fms_fnc_interaction_waypoint;
  };
  FMS_BTN(FMS_10,"Navigation System","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_9,"Toggle Auto-Next","")
    buttonUp= "vehicle player setVariable [""vtx_uh60_fms_import_autoCycle"", !(vehicle player getVariable [""vtx_uh60_fms_import_autoCycle"",false])];";
  };
};

class nav_location_stores {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_LIST);
  FMS_BTN(FMS_1,"Prev Page","") buttonUp="fms_locations_page_index = fms_locations_page_index - 1;[vehicle player] call vtx_uh60_fms_fnc_perSecond;"; };
  FMS_BTN(FMS_2,"Next Page","") buttonUp="fms_locations_page_index = fms_locations_page_index + 1;[vehicle player] call vtx_uh60_fms_fnc_perSecond;"; };
  FMS_BTN(FMS_6,"View","") buttonUp=[vehicle player,"location", 0, [FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_7,"View","") buttonUp=[vehicle player,"location", 1, [FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_8,"View","") buttonUp=[vehicle player,"location", 2, [FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_9,"View","") buttonUp=[vehicle player,"location", 3, [FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_10,"Navigation System","")
      buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};
class nav_location_sel {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL);
  FMS_BTN(FMS_3,"Slew FLIR","") buttonUp=[vehicle player,"slew_flir", nil, [FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_4,"Add to waypoints","") buttonUp=[vehicle player,"store_save_waypoint", nil, [FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT]] call vtx_uh60_fms_fnc_interaction_waypoint; };
  FMS_BTN(FMS_10,"Location Stores","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_LIST], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class performance {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_PERFORMANCE);
  FMS_BTN(FMS_10,"Main Menu","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_MENU], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_1,"Move Probe","") buttonUp=[vehicle player] call vtx_uh60_aar_fnc_probe; };
};

class MSN {
  condition= USERVAL(FMS_PAGE_INDEX,FMS_PAGE_MSN);
  FMS_BTN(FMS_6,"Weapons Systems","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_WPN], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_7,"AN/APQ-187 Radar","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_RDR], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_8,"ANVIS/HUD-24T","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_HMD], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  FMS_BTN(FMS_10,"Main Menu","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_MENU], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class wpn {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_WPN);
  FMS_BTN(FMS_10,"Mission Systems","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_MSN], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class radar {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_RDR);
  FMS_BTN(FMS_10,"Mission Systems","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_MSN], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class FLIR {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_FLIR);
  FMS_BTN(FMS_10,"Mission Systems","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_MSN], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};

class hmd {
  condition=USERVAL(FMS_PAGE_INDEX,FMS_PAGE_HMD);
  FMS_BTN(FMS_6,"OFF","")
    buttonUp = "[-1] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_7,"IMPERIAL ON","")
    buttonUp = "[1] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_8,"IMPERIAL DCLT","")
    buttonUp = "[2] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_2,"METRIC ON","")
    buttonUp = "[3] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_3,"METRIC DCLT","")
    buttonUp = "[4] call vtx_uh60_anvishud_fnc_toggleHud;";
  };
  FMS_BTN(FMS_10,"Mission Systems","")
    buttonUp= [(_this select 0),[FMS_PAGE_INDEX,FMS_PAGE_MSN], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
};
