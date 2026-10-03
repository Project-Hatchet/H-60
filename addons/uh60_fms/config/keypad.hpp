#define KEYPAD_BTN(NAME,X,Y,Z,LABEL) \
  class NAME { \
    positionType = "coordinates"; \
    position[] = {X,Y,Z}; \
    label = LABEL; \
    radius = 0.025; \
  };

class FMS_Keypad {
  condition = "true";
  KEYPAD_BTN(FMS_BTN_SPC,0.175781,4.8311,-0.620863,"SPC")
  class FMS_BTN_MSN {
    positionType = "coordinates";
    position[] = {0.1855471,4.81725,-0.629442};
    label = "MSN";
    radius = 0.025;
    buttonUp = [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MSN)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  KEYPAD_BTN(FMS_BTN_CLR,0.0673828,4.80163,-0.629442,"CLR")
  class FMS_BTN_CLC {
    positionType = "coordinates";
    position[] = {0.135742,4.81626,-0.629442};
    label = "CLC";
    radius = 0.025;
    buttonUp = [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_PERFORMANCE)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  class FMS_BTN_NAV {
    positionType = "coordinates";
    position[] = {0.0810547,4.81627,-0.629442};
    label = "NAV";
    radius = 0.025;
    buttonUp = [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  KEYPAD_BTN(FMS_BTN_EGI,0.0947261,4.81577,-0.629442,"EGI")
  KEYPAD_BTN(FMS_BTN_FPN,0.1059571,4.81628,-0.629442,"FPN")
  KEYPAD_BTN(FMS_BTN_DAT,0.1210941,4.81626,-0.629442,"DAT")
  KEYPAD_BTN(FMS_BTN_LT,0.0761719,4.82994,-0.629442,"<")
  KEYPAD_BTN(FMS_BTN_GT,0.0908201,4.82896,-0.629442,">")
  KEYPAD_BTN(FMS_BTN_ENT,0.1855471,4.80548,-0.629442,"ENT")
};
