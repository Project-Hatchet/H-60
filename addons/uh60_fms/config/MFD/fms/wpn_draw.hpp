TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
	source = "static";
	text = "WEAPON SYSTEMS";
}; // HEADER_TEXT

class STORES {
    source = "static";
    text = "";
};

#define GROUP_STATION_SELECTED_BLINK type = "group"; \
  blinkingPattern[] = {0.2, 0.2}; \
  blinkingStartsOn = 1; \
  color[] = {0, 0, 0, 1}

#ifdef FMS_PYLONS_2
  #include "wpn_draw_pylons_in.hpp"
#endif

#ifdef FMS_PYLONS_4
  #include "wpn_draw_pylons_in.hpp"
  #include "wpn_draw_pylons_out.hpp"
#endif

#define FMS_X_AMMO 0.6
TEXT_FMS_R(CM_LBL,0.5,FMS_Y32)
	source = "cmWeapon";
  sourceIndex = 0;
  sourceScale = 1;
  text = "";
}; // CMW1_LBL
TEXT_FMS_L(CM_AMMO,FMS_X_AMMO,FMS_Y32)
	source = "cmAmmo";
  sourceIndex = 0;
  sourceScale = 1;
  text = "";
}; // CMW1_AMMO

TEXT_FMS_R(CM_2_LBL,0.5,FMS_Y4)
	source = "cmWeapon";
  sourceIndex = 1;
  sourceScale = 1;
  text = "";
}; // CMW2_LBL
TEXT_FMS_L(CM_2_AMMO,FMS_X_AMMO,FMS_Y4)
	source = "cmAmmo";
  sourceIndex = 1;
  sourceScale = 1;
  text = "";
}; // CMW2_AMMO
class CMW2_sel {
  #ifdef FMS_PYLONS_2
    condition = "1 - pylonSelected1 - pylonSelected2 - mgun";
  #endif
  #ifdef FMS_PYLONS_4
    condition = "1 - pylonSelected1 - pylonSelected2 - pylonSelected3 - pylonSelected4 - mgun";
  #endif
  #ifdef FMS_PYLONS_0
    condition = "0";
  #endif
  GROUP_STATION_SELECTED_BLINK;
  TEXT_FMS_R(CM_2_LBL,0.5,FMS_Y4)
    source = "cmWeapon";
    sourceIndex = 1;
    sourceScale = 1;
    text = "";
  }; // CMW3_LBL
  TEXT_FMS_L(CM_2_AMMO,FMS_X_AMMO,FMS_Y4)
    source = "cmAmmo";
    sourceIndex = 1;
    sourceScale = 1;
    text = "";
  }; // CMW3_AMMO
};

TEXT_FMS_R(CM_3_LBL,0.5,FMS_Y42)
	source = "cmWeapon";
  sourceIndex = 2;
  sourceScale = 1;
  text = "";
}; // CMW3_LBL
TEXT_FMS_L(CM_3_AMMO,FMS_X_AMMO,FMS_Y42)
	source = "cmAmmo";
  sourceIndex = 2;
  sourceScale = 1;
  text = "";
}; // CMW3_AMMO
class CMW3_sel {
  #ifdef FMS_PYLONS_2
    condition = "1 - pylonSelected1 - pylonSelected2 - mgun";
  #endif
  #ifdef FMS_PYLONS_4
    condition = "1 - pylonSelected1 - pylonSelected2 - pylonSelected3 - pylonSelected4 - mgun";
  #endif
  #ifdef FMS_PYLONS_0
    condition = "0";
  #endif
  GROUP_STATION_SELECTED_BLINK;
  TEXT_FMS_R(CM_3_LBL,0.5,FMS_Y42)
    source = "cmWeapon";
    sourceIndex = 2;
    sourceScale = 1;
    text = "";
  }; // CMW3_LBL
  TEXT_FMS_L(CM_3_AMMO,FMS_X_AMMO,FMS_Y42)
    source = "cmAmmo";
    sourceIndex = 2;
    sourceScale = 1;
    text = "";
  }; // CMW3_AMMO
};

TEXT_FMS_L(BACK,FMS_MARGIN_L,FMS_Y5)
	source = "static";
	text = "MENU";
}; // BACK

TEXT_FMS_R(MASTERARM,FMS_MARGIN_R,FMS_Y5)
	source = "static";
	text = "MASTER ARM";
}; // BACK
