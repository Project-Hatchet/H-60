TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
	source = "static";
	text = "NAVIGATION SYSTEM";
}; // HEADER_TEXT


class PGUP
{
  type    = "polygon";
  points[] =
  {
    // space where texture should be drawn
    {
      {{FMS_MARGIN_R + 0.0, FMS_Y1},1},
      {{FMS_MARGIN_R + 0.05, FMS_Y1 + 0.05},1},
      {{FMS_MARGIN_R - 0.05, FMS_Y1 + 0.05},1}
    }
  }; // points
}; // PGUP

TEXT_FMS_R(C1,FMS_MARGIN_R+0.03,FMS_Y12-0.01)
	source="userText";
	sourceIndex=21;
	sourceScale=1;
}; // L1

class PGDOWN
{
  type    = "polygon";
  points[] =
  {
    // space where texture should be drawn
    {
      {{FMS_MARGIN_R + 0.0, FMS_Y2 + 0.05},1},
      {{FMS_MARGIN_R + 0.05, FMS_Y2},1},
      {{FMS_MARGIN_R - 0.05, FMS_Y2},1}
    }
  }; // points
}; // PGDOWN

TEXT_FMS_C(CENTER_WAYPT,0.5,FMS_Y3)
	source = "static";
	text = "WAYPT";
}; // HEADER_TEXT
TEXT_FMS_L(L3,FMS_MARGIN_L,FMS_Y3)
	source = "static";
	text = "TGT";
}; // R3
TEXT_FMS_L(L4,FMS_MARGIN_L,FMS_Y4)
	source = "static";
	text = "SEND";
}; // R3
TEXT_FMS_R(R3,FMS_MARGIN_R, FMS_Y3)
	source = "static";
	text = "DEL";
}; //DEL WP
TEXT_FMS_R(R32,FMS_MARGIN_R,FMS_Y4-FMS_Y_HALF)
	source = "static";
	text = "LOCATION";
}; // L32
TEXT_FMS_R(R4,FMS_MARGIN_R+FMS_MARGIN_ARR,FMS_Y4)
	source = "static";
	text = ">";
}; // L4
TEXT_FMS_R(STORES,FMS_MARGIN_R,FMS_Y4+FMS_Y_HALF)
	source = "static";
	text = "STORES";
}; // L32
TEXT_FMS_R(R42,FMS_MARGIN_R,FMS_Y5-FMS_Y_HALF)
	source = "static";
	text = "M-DAGR";
}; // L32
TEXT_FMS_R(R5,FMS_MARGIN_R+FMS_MARGIN_ARR,FMS_Y5)
	source = "static";
	text = ">";
}; // L4
TEXT_FMS_R(IMPORT,FMS_MARGIN_R,FMS_Y5+FMS_Y_HALF)
	source = "static";
	text = "IMPORT";
}; // L32
TEXT_FMS_L(L5,FMS_MARGIN_L,FMS_Y5)
	source = "static";
	text = "< MENU";
}; // L5

TEXT_FMS_L(WAYPOINT_NAME,FMS_MARGIN_L,FMS_Y1)
	source = "userText";
  sourceIndex=7;
  sourceScale=1;
	text = "";
}; // HEADER_TEXT
TEXT_FMS_L(WAYPOINT_TOF,FMS_MARGIN_L,FMS_Y12)
	source = "static";
	text = "TOF ";
}; // WAYPOINT_TOF
TEXT_FMS_L(WAYPOINT_TOF_TEXT,(FMS_MARGIN_L+0.2),FMS_Y12)
	source = "userText";
  sourceIndex=8;
  sourceScale=1;
	text = "";
}; // WAYPOINT_TOF
TEXT_FMS_L(WAYPOINT_POS,FMS_MARGIN_L,FMS_Y2)
	source="userText";
	sourceIndex=20;
	sourceScale=1;
}; // HEADER_TEXT
TEXT_FMS_L(WAYPOINT_DIR_LABEL,FMS_MARGIN_L,FMS_Y22)
	source = "static";
	text = "HDG";
}; // WAYPOINT_DIR_LABEL
TEXT_FMS_L(WAYPOINT_DIR,FMS_MARGIN_L+0.14,FMS_Y22)
	source="user";
	sourceIndex=0;
	sourceScale=1;
}; // WAYPOINT_DIR
TEXT_FMS_L(WAYPOINT_DIRDIST,FMS_MARGIN_L+0.25,FMS_Y22)
	source = "static";
	text = "/";
}; // WAYPOINT_DIRDIST
TEXT_FMS_L(WAYPOINT_DIST,FMS_MARGIN_L+0.3,FMS_Y22)
	source="WPDist";
	sourceScale=0.000539957;
	sourceLength=3;
	sourcePrecision=1;
}; // WAYPOINT_DIST
TEXT_FMS_L(WAYPOINT_DIST_LABEL,(FMS_MARGIN_L+0.5),FMS_Y22)
	source = "static";
	text = "NM";
}; // WAYPOINT_DIST_LABEL

class DIVIDER_BAR {
  type="line";
  width = 10;
  points[] ={
    {{0.0, FMS_Y3},1},
    {{1.0, FMS_Y3},1},{},
	{{0.78, 0.215}, 1},
	{{0.78, FMS_Y3}, 1}
  };
}; // DIVIDER_BAR
