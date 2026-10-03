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
  condition = "pylonSelected1";
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
  condition = "pylonSelected2";
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
