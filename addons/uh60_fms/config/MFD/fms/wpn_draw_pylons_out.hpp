#ifdef SOURCEINDEX
  #undef SOURCEINDEX
#endif
#define SOURCEINDEX 3
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
  condition = "pylonSelected3";
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

#ifdef SOURCEINDEX
  #undef SOURCEINDEX
#endif
#define SOURCEINDEX 4
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
  condition = "pylonSelected4";
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
