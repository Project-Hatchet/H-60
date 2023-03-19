class textRight {
  TEXT_RIGHT_SCALED(MSL,0.98,0.025+0.00,"    B",0.05)

  TEXT_LEFT_SCALED_SOURCE(NAV1,0.87,0.77+0.00,0.05,"user",0,1,0)
  class imperial {
    condition = hud_is_imperial;
    TEXT_RIGHT_SCALED_SOURCE(MSL_VAL,0.96,0.025+0.00,0.05,"altitudeASL",0,M_TO_FT,0)
    TEXT_RIGHT_SCALED_SOURCE(AGL,0.96,0.025+0.05,0.05,"altitudeAGL",0,M_TO_FT,0)
    TEXT_LEFT_SCALED_SOURCE(NAV2,0.87,0.77+0.05,0.05,"user",1,M_TO_NM,1)
  };
  class metric {
    condition = hud_is_metric;
    TEXT_RIGHT_SCALED_SOURCE(MSL_VAL,0.96,0.025+0.00,0.05,"altitudeASL",0,M_TO_M,0)
    TEXT_RIGHT_SCALED_SOURCE(AGL,0.96,0.025+0.05,0.05,"altitudeAGL",0,M_TO_M,0)
    TEXT_LEFT_SCALED_SOURCE(NAV2,0.87,0.77+0.05,0.05,"user",1,M_TO_KM,1)
  };
  TEXT_MID_SCALED_USERTEXT(NAV3,0.87,0.77+0.10,8,0.05)
  
  TEXT_MID_SCALED_SRC(CLOCK,0.87,0.77+0.15,0.05)
    source = "time";
        sourceIndex = "1";
    sourceScale = "1";
        sourcePrecision = "1";
    text = "%H:%M:%S";
  };
};