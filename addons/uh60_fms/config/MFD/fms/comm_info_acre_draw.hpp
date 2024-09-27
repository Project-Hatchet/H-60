TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
  source = "userText";
  sourceIndex = 20;
  sourceScale = 1;
}; // HEADER_TEXT

TEXT_FMS_R(PRESET_SEL,FMS_MARGIN_R - 0.02, FMS_Y1-FMS_HALF_LINE)
  source = "static";
  text = "PRESET";
}; //PRESET_SEL
TEXT_FMS_C(PRESET_SEL_VAL,FMS_MARGIN_R - 0.17, FMS_Y1+FMS_HALF_LINE+0.012)
  source = "userText";
  sourceIndex = 22;
  sourceScale = 1;
}; //PRESET_VAL
class PRESET_box {
  type="line";
  width = 5;
  lineType = 2;
  points[] ={
    {{FMS_MARGIN_R + 0.02, FMS_Y1 + 0.10},1}, //BR
    {{FMS_MARGIN_R - 0.32, FMS_Y1 + 0.10},1}, //BL
    {{FMS_MARGIN_R - 0.32, FMS_Y1 + 0.045},1}, //TL
    {{FMS_MARGIN_R + 0.02, FMS_Y1 + 0.045},1}, //TR
    {{FMS_MARGIN_R + 0.02, FMS_Y1 + 0.10},1} //BR
  };
}; // PRESET_box
class PGUP_CH
{
  type    = "polygon";
  points[] =
  {
    // space where texture should be drawn
    {
      {{FMS_MARGIN_L + 0.06, FMS_Y1 + 0.01},1},
      {{FMS_MARGIN_L + 0.11, FMS_Y1 + 0.06},1},
      {{FMS_MARGIN_L + 0.02, FMS_Y1 + 0.06},1}
    }
  }; // points
}; // PGUP
TEXT_FMS_L(CH_ROCKER,FMS_MARGIN_L + 0.02,FMS_Y2-(0.07))
  source = "userText";
  sourceIndex = 21;
  sourceScale = 1;
}; // Radio2_Line1
class PGDOWN_CH
{
  type    = "polygon";
  points[] =
  {
    // space where texture should be drawn
    {
      {{FMS_MARGIN_L + 0.06, FMS_Y2 + 0.07},1},
      {{FMS_MARGIN_L + 0.11, FMS_Y2 + 0.02},1},
      {{FMS_MARGIN_L + 0.02, FMS_Y2 + 0.02},1}
    }
  }; // points
}; // PGDOWN

class PGUP_OPT
{
  type    = "polygon";
  points[] =
  {
    // space where texture should be drawn
    {
      {{FMS_MARGIN_L + 0.06, FMS_Y3 + 0.01},1},
      {{FMS_MARGIN_L + 0.11, FMS_Y3 + 0.06},1},
      {{FMS_MARGIN_L + 0.02, FMS_Y3 + 0.06},1}
    }
  }; // points
}; // PGUP
TEXT_FMS_L(OPT_ROCKER,FMS_MARGIN_L,FMS_Y4-(0.068))
  source = "UserText";
  sourceIndex = 23;
  sourceScale = 1;
}; // Radio2_Line1
class PGDOWN_OPT
{
  type    = "polygon";
  points[] =
  {
    // space where texture should be drawn
    {
      {{FMS_MARGIN_L + 0.06, FMS_Y4 + 0.07},1},
      {{FMS_MARGIN_L + 0.11, FMS_Y4 + 0.02},1},
      {{FMS_MARGIN_L + 0.02, FMS_Y4 + 0.02},1}
    }
  }; // points
}; // PGDOWN

TEXT_FMS_R(TUNE_Text,FMS_MARGIN_R,FMS_Y3-FMS_HALF_LINE)
  source = "static";
  text = "TUNE";
}; // TUNE_Text
TEXT_FMS_C(FREQ_Value,FMS_MARGIN_R - 0.19, FMS_Y3+FMS_HALF_LINE+0.012)
  source = "userText";
  sourceIndex = 24;
  sourceScale = 1;
}; //FREQ_Value
class FREQ_box {
  type="line";
  width = 5;
  lineType = 2;
  points[] ={
    {{FMS_MARGIN_R + 0.04, FMS_Y3 + 0.10},1}, //BR
    {{FMS_MARGIN_R - 0.36, FMS_Y3 + 0.10},1}, //BL
    {{FMS_MARGIN_R - 0.36, FMS_Y3 + 0.045},1}, //TL
    {{FMS_MARGIN_R + 0.04, FMS_Y3 + 0.045},1}, //TR
    {{FMS_MARGIN_R + 0.04, FMS_Y3 + 0.10},1} //BR
  };
}; // FREQ_box
TEXT_FMS_L(MENU_Text,FMS_MARGIN_L,FMS_Y5)
  source = "static";
  text = "< RTN";
}; // Menu_Text