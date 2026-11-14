TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
	source = "static";
	text = "PRESET STORES";
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

TEXT_FMS_R(C1,FMS_MARGIN_R,FMS_Y12)
	source="userText";
	sourceIndex=20;
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

TEXT_FMS_L(PRESET1,FMS_MARGIN_L,FMS_Y1)
	source = "userText";
	sourceIndex=21;
	sourceScale=1;
}; // PRESET1

TEXT_FMS_L(PRESET2,FMS_MARGIN_L,FMS_Y2)
	source = "userText";
	sourceIndex=22;
	sourceScale=1;
}; // PRESET2

TEXT_FMS_L(PRESET3,FMS_MARGIN_L,FMS_Y3)
	source = "userText";
	sourceIndex=23;
	sourceScale=1;
}; // PRESET3

TEXT_FMS_L(PRESET4,FMS_MARGIN_L,FMS_Y4)
	source = "userText";
	sourceIndex=24;
	sourceScale=1;
}; // PRESET4

TEXT_FMS_L(L5,FMS_MARGIN_L,FMS_Y5)
	source = "static";
	text = "< RTN";
}; // L5
