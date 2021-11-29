TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
	source = "static";
	text = "NAVIGATION SYSTEM";
}; // HEADER_TEXT

TEXT_FMS_C(C1,0.5,FMS_Y1)
	source="userText";
	sourceIndex=21;
	sourceScale=1;
}; // L1

TEXT_FMS_L(L1,FMS_MARGIN_L,FMS_Y1)
	source = "static";
	text = "< PRV";
}; // L1

TEXT_FMS_L(L4,FMS_MARGIN_L,FMS_Y4)
	source = "static";
	text = "< FLIR";
}; // L4

TEXT_FMS_R(R1,FMS_MARGIN_R,FMS_Y1)
	source = "static";
	text = "NXT >";
}; // R1

TEXT_FMS_R(R32,FMS_MARGIN_R,FMS_Y32)
	source = "static";
	text = "LOCATION";
}; // L32
TEXT_FMS_R(R4,FMS_MARGIN_R,FMS_Y4 - 0.02)
	source = "static";
	text = "STORES >";
}; // L4
TEXT_FMS_R(R42,FMS_MARGIN_R,FMS_Y42)
	source = "static";
	text = "M-DAGR";
}; // L32
TEXT_FMS_R(R5,FMS_MARGIN_R,FMS_Y5)
	source = "static";
	text = "IMPORT >";
}; // L4
TEXT_FMS_L(L5,FMS_MARGIN_L,FMS_Y5)
	source = "static";
	text = "< MENU";
}; // L5

TEXT_FMS_C(WAYPOINT_NAME,0.5,FMS_Y12)
	source = "userText";
  sourceIndex=7;
  sourceScale=1;
	text = "";
}; // HEADER_TEXT
TEXT_FMS_R(WAYPOINT_TOF,0.44,FMS_Y2)
	source = "static";
	text = "TOF ";
}; // WAYPOINT_TOF
TEXT_FMS_L(WAYPOINT_TOF_TEXT,0.5,FMS_Y2)
	source = "userText";
  sourceIndex=8;
  sourceScale=1;
	text = "";
}; // WAYPOINT_TOF
TEXT_FMS_C(WAYPOINT_POS,0.5,FMS_Y22)
	source="userText";
	sourceIndex=20;
	sourceScale=1;
}; // HEADER_TEXT
TEXT_FMS_C(WAYPOINT_DIRDIST,0.5,FMS_Y3)
	source = "static";
	text = "/";
}; // WAYPOINT_DIRDIST
TEXT_FMS_L(WAYPOINT_DIST_LABEL,0.62,FMS_Y3)
	source = "static";
	text = "NM";
}; // WAYPOINT_DIST_LABEL
TEXT_FMS_L(WAYPOINT_DIST,0.48,FMS_Y3)
	source="WPDist";
	sourceScale=0.000539957;
	sourceLength=3;
	sourcePrecision=1;
}; // WAYPOINT_DIST
TEXT_FMS_R(WAYPOINT_DIR,0.41,FMS_Y3)
	source="user";
	sourceIndex=0;
	sourceScale=1;
}; // WAYPOINT_DIR
TEXT_FMS_R(WAYPOINT_DIR_LABEL,0.27,FMS_Y3)
	source = "static";
	text = "HDG";
}; // WAYPOINT_DIR_LABEL

class DIVIDER_BAR {
  type="line";
  width = 10;
  points[] ={
    {{0.1, FMS_Y32},1},
    {{0.9, FMS_Y32},1}
  };
}; // DIVIDER_BAR
