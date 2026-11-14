
alpha = BACKGROUND_ALPHA;
class overlayWrapper {
	class PolygonJet {
		type        = "polygon";
		texture = "z\vtx\addons\uh60_mfd\data\EICAS.paa";
		points[] ={
			{
				{{0, 0},1},
				{{1, 0},1},
				{{1, 1},1},
				{{0, 1},1}
			}
		};
	};
}; // overlayWrapper

#define TITLEHEIGHT 0.08
#define LABELHEIGHT 0.12
#define VALUEHEIGHT 0.16

#undef BARTOP
#define BARTOP 0.209
#undef BARBOTTOM
#define BARBOTTOM 0.417

#undef FUEL_BARS_Y1
#define FUEL_BARS_Y1 0.635
#undef FUEL_BARS_Y2
#define FUEL_BARS_Y2 0.775

#define EICAS_LABEL_VAL(CLASS,X,LABEL,USERVAL) \
    TEXT_MID_SMALL(CLASS,X,LABELHEIGHT,LABEL) \
	TEXT_MID_MID_SRC(DOUBLES(CLASS,V),X,VALUEHEIGHT) \
		source="user"; \
		sourceIndex=USERVAL; \

//static left
//EICAS_LABEL_VAL(T1,0.04,"",21)
//	sourceScale = 1;
//};
//EICAS_LABEL_VAL(AFM_RPM1,0.105,"",20)
//	sourceScale=1;
//};
EICAS_LABEL_VAL(NG1,0.19,"",19)
	sourceScale = 1;
};
EICAS_LABEL_VAL(TGT1,0.27,"",21)
	sourceScale = 1;
};
EICAS_LABEL_VAL(Q1,0.35,"",22)
	sourceScale = 1;
};

//static right
EICAS_LABEL_VAL(Q2,0.65,"",48)
	sourceScale = 1;
};
EICAS_LABEL_VAL(TGT2,0.72,"",47)
	sourceScale = 1;
};
EICAS_LABEL_VAL(NG2,0.81,"",45)
	sourceScale = 1;
};
//EICAS_LABEL_VAL(AFM_RPM2,0.89,"",46)
//	sourceScale=1;
//};
//EICAS_LABEL_VAL(T2,0.96,"",22)
//	sourceScale = 1;
//};

TEXT_MID_SMALL(NP1,0.42,LABELHEIGHT,"")
TEXT_MID_MID_SRC(NP1_V,0.42,VALUEHEIGHT)
	sourceScale = 1;
	source = "user";
	sourceIndex = 20;
};

TEXT_MID_SMALL(RPM,(0.5),LABELHEIGHT,"")
TEXT_MID_MID_SRC(RPM_V,(0.5),VALUEHEIGHT)
	sourceScale = 1;
	source = "user";
	sourceIndex = 17;
};

TEXT_MID_SMALL(NP2,0.59,LABELHEIGHT,"")
TEXT_MID_MID_SRC(NP2_V,0.58,VALUEHEIGHT)
	sourceScale = 1;
	source = "user";
	sourceIndex = 46;
};


class barsWrapper {
    color[] = common_green;
	#define BAR_WIDTH 0.012

    //BAR(T1BAR,   "T1",0.042,BARBOTTOM,BAR_WIDTH)
    //BAR(RPM1BAR, "EICAS_RPM1",0.11,BARBOTTOM,BAR_WIDTH)

    //BAR(RPM2BAR, "EICAS_RPM2",0.893,BARBOTTOM,BAR_WIDTH)
	//BAR(T2BAR,   "T2",0.962,BARBOTTOM,BAR_WIDTH)

	BAR(FUEL1,   "EICAS_Fuel1",0.459,FUEL_BARS_Y2,BAR_WIDTH)
	BAR(FUEL2,   "EICAS_Fuel2",0.545,FUEL_BARS_Y2,BAR_WIDTH)
}; // barsWrapper

class limitBars {
	BAR_LIMITS(NG1BAR,  "NG1",       0.191, BARBOTTOM,BAR_WIDTH,LIM_NG_G(19), LIM_NG_Y(19), LIM_NG_R(19))
	BAR_LIMITS(TGT1BAR, "TGT1",      0.2775,BARBOTTOM,BAR_WIDTH,LIM_TGT_G(21),LIM_TGT_Y(21),LIM_TGT_R(21))
	BAR_LIMITS(Q1BAR,   "Q1",        0.353, BARBOTTOM,BAR_WIDTH,LIM_TQ_G(22), LIM_TQ_Y(22), LIM_TQ_R(22))
	BAR_LIMITS(RPM1BAR, "EICAS_RPM1",0.422, BARBOTTOM,BAR_WIDTH,LIM_NP_G(20), LIM_NP_Y(20), LIM_NP_R(20))
	BAR_LIMITS(RPMBAR,  "EICAS_RPM", 0.502, BARBOTTOM,BAR_WIDTH,LIM_NR_G,     LIM_NR_Y,     LIM_NR_R)
	BAR_LIMITS(RPM2BAR, "EICAS_RPM2",0.581, BARBOTTOM,BAR_WIDTH,LIM_NP_G(46), LIM_NP_Y(46), LIM_NP_R(46))
	BAR_LIMITS(Q2BAR,   "Q2",        0.651, BARBOTTOM,BAR_WIDTH,LIM_TQ_G(48), LIM_TQ_Y(48), LIM_TQ_R(48))
	BAR_LIMITS(TGT2BAR, "TGT2",      0.725, BARBOTTOM,BAR_WIDTH,LIM_TGT_G(47),LIM_TGT_Y(47),LIM_TGT_R(47))
	BAR_LIMITS(NG2BAR,  "NG2",       0.813, BARBOTTOM,BAR_WIDTH,LIM_NG_G(45), LIM_NG_Y(45), LIM_NG_R(45))
};

#define TOP_TEXT_Y 0.03

class eng1_out {
	condition = "user19<55";
	color[] = {1,0,0,1};
    class cross {
    	type="line";
		width = 7;
    	points[] ={
    		{{0.013, 0.2},1},
            {{0.383, 0.418},1},{},
    		{{0.015, 0.418},1},
            {{0.385, 0.2},1}
    	};
    }; // Cross
};
class eng2_out {
	condition = "user45<55";
	color[] = {1,0,0,1};
    class cross {
    	type="line";
		width = 7;
    	points[] ={
    		{{1.005-0.013, 0.2},1},
            {{1.005-0.383, 0.418},1},{},
    		{{1.005-0.015, 0.418},1},
            {{1.005-0.385, 0.2},1}
    	};
    }; // Cross
};


// TEXT_MID_SMALL(FUEL_MAIN1,0.45,0.55,"1")
// TEXT_MID_SMALL(FUEL_MAIN2,0.55,0.55,"2")



//TEXT_MID_SMALL(FUEL_FLIGHTTIME_LABEL,0.5,0.83,"TIME")
//TEXT_MID_MID_SRC(FUEL_FLIGHTTIME_VAL,0.5,0.87)
//	source="userText";
//	sourceIndex = 10;
//	sourceScale = 1;
//};

class noAuxTanks {
  condition = USER_LT(USERMFDV_FUELTANK,1);
	TEXT_MID_MID_SRC(FUEL_VAL,0.5,0.85)
		source="user";
		sourceIndex = USERMFDV_FUELTOTAL;
		sourceScale = 1;
		sourceLength = 4;
	};
};
class hasInternalAux {
  condition = USER_GT(USERMFDV_FUELTANK,0);
	TEXT_MID_MID_SRC(FUEL_VAL,0.5,0.85)
		source="user";
		sourceIndex = USERMFDV_FUELTOTAL;
		sourceScale = 1;
		sourceLength = 4;
	};
	class aux_fuel_boxes {
		type="line";
		width = 3;
		points[] ={
			{{0.34,0.81}, 1},
			{{0.41,0.81}, 1},
			{{0.41,0.90}, 1},
			{{0.34,0.90}, 1},
			{{0.34,0.81}, 1}
		};
	}; // aux_fuel_boxes
	TEXT_MID_SCALED(FUEL_INT_L_INDICATOR,0.37,0.81,"INT",0.05)
	TEXT_MID_SMALL_SRC(FUEL_VALUE_AUX_INT,0.37,0.85) source="user"; sourceIndex = USERMFDV_FUELERFS; sourceScale = 1;};
};

TEXT_MID_SMALL_SRC(FUEL_VALUE_L,0.459,0.78) source="user"; sourceIndex = USERMFDV_FUEL1; sourceScale = 1;};
TEXT_MID_SMALL_SRC(FUEL_VALUE_R,0.545,0.78) source="user"; sourceIndex = USERMFDV_FUEL2; sourceScale = 1;};
//checklist?
TEXT_RIGHT_SMALL_SRC(CAS1,0.043,0.745 - 0.05-0.006) source="userText"; sourceIndex = 0; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS2,0.043,0.775 - 0.05-0.005) source="userText"; sourceIndex = 1; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS3,0.043,0.805 - 0.05-0.004) source="userText"; sourceIndex = 2; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS4,0.043,0.835 - 0.05-0.003)    source="userText"; sourceIndex = 3; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS5,0.043,0.865 - 0.05-0.002)    source="userText"; sourceIndex = 4; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS6,0.043,0.895 - 0.05-0.001)    source="userText"; sourceIndex = 5; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS7,0.043,0.925 - 0.05) source="userText"; sourceIndex = 6; sourceScale = 1;};

class SHOW_CCFS_CONDITION {
	condition = SHOW_CCFS;
	TEXT_LEFT_SMALL(CCFS,0.67,0.02,"CCFS")
};

TEXT_LEFT_SMALL(TEST,0.38,0.02,"TEST")

#define BOTTOM_TEXT_Y 0.96
#define TOP_TEXT_Y 0.03
#define DEFAULT_TEXT_SIZE 0.65
// TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
// TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
// TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

// TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"IVHMS")
// TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
// TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")
