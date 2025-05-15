TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
	source = "static";
	text = "WEAPON SYSTEMS";
}; // HEADER_TEXT

class STORES {
    source = "static";
    text = "";};

#define GROUP_STATION_SELECTED_BLINK type = "group"; \
  blinkingPattern[] = {0.2, 0.2}; \
  blinkingStartsOn = 1; \
  color[] = {0, 0, 0, 1}

TEXT_FMS_L(STA1_LBL,FMS_MARGIN_L,FMS_Y1)
	source = "pylonMagazineNameShort";
  sourceIndex = 1;
  sourceScale = 1;
}; // STA1_LBL
TEXT_FMS_L(STA1_AMMO,FMS_MARGIN_L,FMS_Y12)
	source = "pylonAmmo";
  sourceIndex = 1;
  sourceScale = 1;
}; // STA1_AMMO
class Sta1_sel {
  condition = "pylonSelected1>0";
  GROUP_STATION_SELECTED_BLINK;

  TEXT_FMS_L(STA1_LBL,FMS_MARGIN_L,FMS_Y1)
    source = "pylonMagazineNameShort";
    sourceIndex = 1;
    sourceScale = 1;
  }; // STA1_LBL
  TEXT_FMS_L(STA1_AMMO,FMS_MARGIN_L,FMS_Y12)
    source = "pylonAmmo";
    sourceIndex = 1;
    sourceScale = 1;
  }; // STA1_AMMO
};

TEXT_FMS_R(STA2_LBL,FMS_MARGIN_R,FMS_Y1)
	source = "pylonMagazineNameShort";
  sourceIndex = 2;
  sourceScale = 1;
}; // STA2_LBL
TEXT_FMS_R(STA2_AMMO,FMS_MARGIN_R,FMS_Y12)
	source = "pylonAmmo";
  sourceIndex = 2;
  sourceScale = 1;
}; // STA2_AMMO
class Sta2_sel {
  condition = "pylonSelected2>0";
  GROUP_STATION_SELECTED_BLINK;
  TEXT_FMS_R(STA2_LBL,FMS_MARGIN_R,FMS_Y1)
    source = "pylonMagazineNameShort";
    sourceIndex = 2;
    sourceScale = 1;
  }; // STA2_LBL
  TEXT_FMS_R(STA2_AMMO,FMS_MARGIN_R,FMS_Y12)
    source = "pylonAmmo";
    sourceIndex = 2;
    sourceScale = 1;
  }; // STA2_AMMO
};

#define SOURCEINDEX 48
TEXT_FMS_L(STA3_LBL,FMS_MARGIN_L,FMS_Y2)
	source = "pylonMagazineNameShort";
  sourceIndex = SOURCEINDEX;
  sourceScale = 1;
}; // STA3_LBL
TEXT_FMS_L(STA3_AMMO,FMS_MARGIN_L,FMS_Y22)
	source = "pylonAmmo";
  sourceIndex = SOURCEINDEX;
  sourceScale = 1;
}; // STA3_AMMO
class Sta3_sel {
  condition = "pylonSelected51>0";
  GROUP_STATION_SELECTED_BLINK;
  TEXT_FMS_L(STA3_LBL,FMS_MARGIN_L,FMS_Y2)
    source = "pylonMagazineNameShort";
    sourceIndex = SOURCEINDEX;
    sourceScale = 1;
  }; // STA3_LBL
  TEXT_FMS_L(STA3_AMMO,FMS_MARGIN_L,FMS_Y22)
    source = "pylonAmmo";
    sourceIndex = SOURCEINDEX;
    sourceScale = 1;
  }; // STA3_AMMO
};

#define SOURCEINDEX 49
TEXT_FMS_R(STA4_LBL,FMS_MARGIN_R,FMS_Y2)
	source = "pylonMagazineNameShort";
  sourceIndex = SOURCEINDEX;
  sourceScale = 1;
}; // STA4_LBL
TEXT_FMS_R(STA4_AMMO,FMS_MARGIN_R,FMS_Y22)
	source = "pylonAmmo";
  sourceIndex = SOURCEINDEX;
  sourceScale = 1;
}; // STA4_AMMO
class Sta4_sel {
  condition = "pylonSelected50>0";
  GROUP_STATION_SELECTED_BLINK;
  TEXT_FMS_R(STA4_LBL,FMS_MARGIN_R,FMS_Y2)
    source = "pylonMagazineNameShort";
    sourceIndex = SOURCEINDEX;
    sourceScale = 1;
  }; // STA4_LBL
  TEXT_FMS_R(STA4_AMMO,FMS_MARGIN_R,FMS_Y22)
    source = "pylonAmmo";
    sourceIndex = SOURCEINDEX;
    sourceScale = 1;
  }; // STA4_AMMO
};

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
class CMW2_sel {condition = "0";};

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
  condition = "mgun * (1 - pylonSelected1) * (1 - pylonSelected2)";
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
