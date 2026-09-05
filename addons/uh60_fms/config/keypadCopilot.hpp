#define KEYPAD_BTN(NAME,X,Y,Z,LABEL) \
  class NAME { \
    positionType = "coordinates"; \
    position[] = {X,Y,Z}; \
    label = LABEL; \
    radius = 0.025; \
  };

class FMS_Keypad {
  condition = "true";
  KEYPAD_BTN(FMS_BTN_SPC,-0.092285,4.82902,-0.620863,"SPC")
  class FMS_BTN_MSN {
    positionType = "coordinates";
    position[] = {-0.0825189,4.81517,-0.629442};
    label = "MSN";
    radius = 0.025;
    buttonUp = [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_MSN)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  KEYPAD_BTN(FMS_BTN_CLR,-0.2006832,4.79955,-0.629442,"CLR")
  class FMS_BTN_CLC {
    positionType = "coordinates";
    position[] = {-0.132324,4.81418,-0.629442};
    label = "CLC";
    radius = 0.025;
    buttonUp = [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_PERFORMANCE)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  class FMS_BTN_NAV {
    positionType = "coordinates";
    position[] = {-0.1870113,4.81419,-0.629442};
    label = "NAV";
    radius = 0.025;
    buttonUp = [(_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT)], true] call vtx_uh60_fms_fnc_interaction_pageChange;
  };
  KEYPAD_BTN(FMS_BTN_EGI,-0.1733399,4.81369,-0.629442,"EGI")
  KEYPAD_BTN(FMS_BTN_FPN,-0.1621089,4.8142,-0.629442,"FPN")
  KEYPAD_BTN(FMS_BTN_DAT,-0.1469719,4.81418,-0.629442,"DAT")
  KEYPAD_BTN(FMS_BTN_LT,-0.1918941,4.82786,-0.629442,"<")
  KEYPAD_BTN(FMS_BTN_GT,-0.1772459,4.82688,-0.629442,">")
  KEYPAD_BTN(FMS_BTN_ENT,-0.0825189,4.8034,-0.629442,"ENT")
};
