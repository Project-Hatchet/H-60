TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
	source = "static";
	text = "STORED LOCATION";
}; // HEADER_TEXT

TEXT_FMS_C(LOC_NAME,0.5,FMS_Y1)
	source="userText";
	sourceIndex=20;
	sourceScale=1;
}; // L1
TEXT_FMS_C(LOC_POSITION,0.5,FMS_Y12)
	source = "userText";
  sourceIndex=21;
  sourceScale=1;
	text = "";
}; // HEADER_TEXT
TEXT_FMS_C(LOC_BRG_DIST,0.5,FMS_Y2)
	source = "userText";
  sourceIndex=22;
  sourceScale=1;
	text = "";
}; // HEADER_TEXT

class DIVIDER_BAR {
  type="line";
  width = 10;
  points[] ={
    {{0.1, FMS_Y22 + 0.05},1},
    {{0.9, FMS_Y22 + 0.05},1}
  };
}; // DIVIDER_BAR

TEXT_FMS_R(R3,FMS_MARGIN_R,FMS_Y3)
	source = "static";
	text = "SLEW FLIR >";
}; // L4

TEXT_FMS_R(R4,FMS_MARGIN_R,FMS_Y4 - 0.02)
	source = "static";
	text = "ADD TO WAYPOINTS >";
}; // L4

TEXT_FMS_L(L5,FMS_MARGIN_L,FMS_Y5)
	source = "static";
	text = "< LOCATIONS";
}; // L5
