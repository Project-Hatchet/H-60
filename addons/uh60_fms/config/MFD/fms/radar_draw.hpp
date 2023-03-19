TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
  source = "static";
  text = "AN/APQ-187 RADAR";
}; // HEADER_TEXT

TEXT_FMS_L(L1T,FMS_MARGIN_L,FMS_Y1-FMS_HALF_LINE)
  source = "static";
  text = "STATUS";
}; // LOC_Text4
class radarOn {
  condition="activeSensorsOn";
  TEXT_FMS_L(STATUS,FMS_MARGIN_L,FMS_Y1+FMS_HALF_LINE)
    source = "static";
    text = "ACTIVE";
  }; // L5
};
class radarOff {
  condition="activeSensorsOn<1";
  TEXT_FMS_L(STATUS,FMS_MARGIN_L,FMS_Y1+FMS_HALF_LINE)
    source = "static";
    text = "STBY";
  }; // L5
};

TEXT_FMS_L(L2T,FMS_MARGIN_L,FMS_Y2-FMS_HALF_LINE)
  source = "static";
  text = "AUTO RECOVER";
}; // LOC_Text4
TEXT_FMS_L(L2B,FMS_MARGIN_L,FMS_Y2+FMS_HALF_LINE)
  source = "static";
  text = "ON";
}; // LOC_Text4

TEXT_FMS_L(L3T,FMS_MARGIN_L,FMS_Y3-FMS_HALF_LINE)
  source = "static";
  text = "TERRAIN FOLLOW HUD";
}; // LOC_Text4
TEXT_FMS_L(L3B,FMS_MARGIN_L,FMS_Y3+FMS_HALF_LINE)
  source = "static";
  text = "ON";
}; // LOC_Text4

TEXT_FMS_L(MSN_Text,FMS_MARGIN_L,FMS_Y5)
  source = "static";
  text = "< MSN SYS";
}; // WPN_Text
