TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
  source = "static";
  text = "WEAPON SYSTEMS";
}; // HEADER_TEXT

TEXT_FMS_C(STORES,0.5,FMS_Y1)
  source = "static";
  text = "STORES";
}; // STA1_LBL
TEXT_FMS_C(STA1_LBL,0.3,FMS_Y12)
  source = "pylonMagazineNameShort";
  sourceIndex = 1;
  sourceScale = 1;
  //text = "STA1";
}; // STA1_LBL
TEXT_FMS_C(STA2_LBL,0.7,FMS_Y12)
  source = "pylonMagazineNameShort";
  sourceIndex = 2;
  sourceScale = 1;
  //text = "STA2";
}; // STA2_LBL

TEXT_FMS_C(STA1_AMMO,0.3,FMS_Y2)
  source = "pylonAmmo";
  sourceIndex = 1;
  sourceScale = 1;
  text = "";
}; // STA1_AMMO
TEXT_FMS_C(STA2_AMMO,0.7,FMS_Y2)
  source = "pylonAmmo";
  sourceIndex = 2;
  sourceScale = 1;
  text = "";
}; // STA2_AMMO

TEXT_FMS_R(CM_LBL,0.5,FMS_Y22)
  source = "cmWeapon";
  sourceIndex = 0;
  sourceScale = 1;
  text = "";
}; // STA2_LBL
TEXT_FMS_L(CM_AMMO,0.55,FMS_Y22)
  source = "cmAmmo";
  sourceIndex = 0;
  sourceScale = 1;
  text = "";
}; // STA2_AMMO
TEXT_FMS_R(CM_2_LBL,0.5,FMS_Y3)
  source = "cmWeapon";
  sourceIndex = 1;
  sourceScale = 1;
  text = "";
}; // STA2_LBL
TEXT_FMS_L(CM_2_AMMO,0.55,FMS_Y3)
  source = "cmAmmo";
  sourceIndex = 1;
  sourceScale = 1;
  text = "";
}; // STA2_AMMO
TEXT_FMS_R(CM_3_LBL,0.5,FMS_Y32)
  source = "cmWeapon";
  sourceIndex = 2;
  sourceScale = 1;
  text = "";
}; // STA2_LBL
TEXT_FMS_L(CM_3_AMMO,0.55,FMS_Y32)
  source = "cmAmmo";
  sourceIndex = 2;
  sourceScale = 1;
  text = "";
}; // STA2_AMMO

TEXT_FMS_L(BACK,FMS_MARGIN_L,FMS_Y5)
  source = "static";
  text = "MENU";
}; // BACK
