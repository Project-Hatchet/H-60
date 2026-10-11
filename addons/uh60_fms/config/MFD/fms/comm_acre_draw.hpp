TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
  source = "static";
  text = "COMMUNICATIONS";
}; // HEADER_TEXT

TEXT_FMS_L(RADIO_ONE_L1,FMS_MARGIN_L,FMS_Y1-FMS_HALF_LINE)
  source = "static";
  text = "FM1";
}; // Radio1_Line1
TEXT_FMS_L(RADIO_ONE_L2,FMS_MARGIN_L,FMS_Y1+FMS_HALF_LINE)
  source = "userText";
  sourceIndex=20;
  sourceScale=1;
}; // Radio1_Line2

TEXT_FMS_L(RADIO_TWO_L1,FMS_MARGIN_L,FMS_Y2-FMS_HALF_LINE)
  source = "static";
  text = "UHF";
}; // Radio2_Line1
TEXT_FMS_L(RADIO_TWO_L2,FMS_MARGIN_L,FMS_Y2+FMS_HALF_LINE)
  source = "userText";
  sourceIndex=21;
  sourceScale=1;
}; // Radio2_Line2

TEXT_FMS_L(RADIO_THREE_L1,FMS_MARGIN_L,FMS_Y3-FMS_HALF_LINE)
  source = "static";
  text = "VHF";
}; // Radio3_Line1
TEXT_FMS_L(RADIO_THREE_L2,FMS_MARGIN_L,FMS_Y3+FMS_HALF_LINE)
  source = "userText";
  sourceIndex=22;
  sourceScale=1;
}; // Radio3_Line2

TEXT_FMS_L(RADIO_FOUR_L1,FMS_MARGIN_L,FMS_Y4-FMS_HALF_LINE)
  source = "static";
  text = "FM2";
}; // Radio4_Line1
TEXT_FMS_L(RADIO_FOUR_L2,FMS_MARGIN_L,FMS_Y4+FMS_HALF_LINE)
  source = "userText";
  sourceIndex=23;
  sourceScale=1;
}; // Radio4_Line2

TEXT_FMS_L(MENU_Text,FMS_MARGIN_L,FMS_Y5)
  source = "static";
  text = "< MENU";
}; // Menu_Text
