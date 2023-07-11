TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
	source = "static";
	text = "PERFORMANCE DATA";
}; // HEADER_TEXT

TEXT_FMS_L(FUEL_QTY_LABEL,FMS_MARGIN_L,FMS_Y1)
	source = "static";
	text = "FUEL QTY";
}; // FUEL_QTY_LABEL
TEXT_FMS_L(FUEL_QTY,FMS_MARGIN_L,FMS_Y12)
  source="fuel";
  sourceScale = 3506;
  sourceLength = 4;
}; // FUEL_QTY

TEXT_FMS_L(FUEL_QTY_UNIT,0.2,FMS_Y12)
	source = "static";
	text = "LBS";
}; // FUEL_QTY_UNIT

TEXT_FMS_L(FUEL_CONSUMPTION_LABEL,FMS_MARGIN_L,FMS_Y2)
	source = "static";
	text = "FUEL CONSUMPTION";
}; // FUEL_CONSUMPTION_LABEL
TEXT_FMS_L(FUEL_CONSUMPTION,FMS_MARGIN_L,FMS_Y22)
	source = "userText";
  sourceIndex=20;
  sourceScale=1;
}; // FUEL_CONSUMPTION
TEXT_FMS_L(FUEL_CONSUMPTION_UNIT,0.2,FMS_Y22)
	source = "static";
	text = "LBS/min";
};

TEXT_FMS_L(FUEL_TIME_LABEL,FMS_MARGIN_L,FMS_Y3)
	source = "static";
	text = "TIME REMAINING";
}; // FUEL_CONSUMPTION_LABEL
TEXT_FMS_L(FUEL_TIME,FMS_MARGIN_L,FMS_Y32)
	source = "userText";
  sourceIndex=21;
  sourceScale=1;
}; // FUEL_CONSUMPTION

TEXT_FMS_L(FUEL_RANGE_LABEL,FMS_MARGIN_L,FMS_Y4)
	source = "static";
	text = "RANGE";
}; // FUEL_RANGE_LABEL
TEXT_FMS_L(FUEL_RANGE,FMS_MARGIN_L,FMS_Y42)
	source = "userText";
  sourceIndex=22;
  sourceScale=1;
}; // FUEL_RANGE
TEXT_FMS_L(FUEL_RANGE_UNIT,0.2,FMS_Y42)
	source = "static";
	text = "NM";
}; // FUEL_RANGE_UNIT

TEXT_FMS_R(PROBE_LBL,FMS_MARGIN_R,FMS_Y1-FMS_HALF_LINE)
	source = "static";
	text = "PROBE";
}; // WEIGHT_LABEL
TEXT_FMS_R(PROBE_STATE,FMS_MARGIN_R,FMS_Y1+FMS_HALF_LINE)
	source = "userText";
  sourceIndex=24;
  sourceScale=1;
}; // WEIGHT

TEXT_FMS_L(BACK,FMS_MARGIN_L,FMS_Y5)
	source = "static";
	text = "< MENU";
}; // BACK
