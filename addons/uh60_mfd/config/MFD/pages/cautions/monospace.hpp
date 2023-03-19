class cautions_overlay {
  color[] = common_yellow;
  condition = "pylonAmmo3 > 0";
  // EICAS_LINE_TEXT_USERTEXT(Right_2_0,0.69,0.70+(EICAS_LINE_SPACING*0),14)
  // EICAS_LINE_TEXT_USERTEXT(Right_2_1,0.69,0.70+(EICAS_LINE_SPACING*1),15)
  // EICAS_LINE_TEXT_USERTEXT(Right_2_2,0.69,0.70+(EICAS_LINE_SPACING*2),16)
  // EICAS_LINE_TEXT_USERTEXT(Right_2_3,0.69,0.70+(EICAS_LINE_SPACING*3),17)
  // EICAS_LINE_TEXT_USERTEXT(Right_2_4,0.69,0.70+(EICAS_LINE_SPACING*4),18)
  // EICAS_LINE_TEXT_USERTEXT(Right_2_5,0.69,0.70+(EICAS_LINE_SPACING*5),19)
  class caution1 {
    condition = "pylonAmmo46 > 0";
    EICAS_LINE_TEXT_USERTEXT(Right_2_0,0.69,0.70+(EICAS_LINE_SPACING*0),14,1)
  };
  class caution2 {
    condition = "pylonAmmo46 > 1";
    EICAS_LINE_TEXT_USERTEXT(Right_2_1,0.69,0.70+(EICAS_LINE_SPACING*1),15,2)
  };
  class caution3 {
    condition = "pylonAmmo46 > 2";
    EICAS_LINE_TEXT_USERTEXT(Right_2_2,0.69,0.70+(EICAS_LINE_SPACING*2),16,3)
  };
  class caution4 {
    condition = "pylonAmmo46 > 3";
    EICAS_LINE_TEXT_USERTEXT(Right_2_3,0.69,0.70+(EICAS_LINE_SPACING*3),17,4)
  };
  class caution5 {
    condition = "pylonAmmo46 > 4";
    EICAS_LINE_TEXT_USERTEXT(Right_2_4,0.69,0.70+(EICAS_LINE_SPACING*4),18,5)
  };
  class caution6 {
    condition = "pylonAmmo46 > 5";
    EICAS_LINE_TEXT_USERTEXT(Right_2_5,0.69,0.70+(EICAS_LINE_SPACING*5),19,6)
  };

  class advisories {
    color[] = common_white;
    class caution1 {
      condition = "pylonAmmo46 < 1";
      EICAS_LINE_TEXT_USERTEXT(Right_2_0,0.69,0.70+(EICAS_LINE_SPACING*0),14,1)
    };
    class caution2 {
      condition = "pylonAmmo46 < 2";
      EICAS_LINE_TEXT_USERTEXT(Right_2_1,0.69,0.70+(EICAS_LINE_SPACING*1),15,2)
    };
    class caution3 {
      condition = "pylonAmmo46 < 3";
      EICAS_LINE_TEXT_USERTEXT(Right_2_2,0.69,0.70+(EICAS_LINE_SPACING*2),16,3)
    };
    class caution4 {
      condition = "pylonAmmo46 < 4";
      EICAS_LINE_TEXT_USERTEXT(Right_2_3,0.69,0.70+(EICAS_LINE_SPACING*3),17,4)
    };
    class caution5 {
      condition = "pylonAmmo46 < 5";
      EICAS_LINE_TEXT_USERTEXT(Right_2_4,0.69,0.70+(EICAS_LINE_SPACING*4),18,5)
    };
    class caution6 {
      condition = "pylonAmmo46 < 6";
      EICAS_LINE_TEXT_USERTEXT(Right_2_5,0.69,0.70+(EICAS_LINE_SPACING*5),19,6)
    };
  };
};