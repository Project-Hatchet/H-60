
alpha = 0.65;
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
		sourceIndex=USERVAL;

//static left
EICAS_LABEL_VAL(T1,0.04,"",21)
	sourceScale = 1;
};
EICAS_LABEL_VAL(AFM_RPM1,0.105,"",21)
	sourceScale=1;
};
EICAS_LABEL_VAL(NG1,0.19,"",21)
	sourceScale = 1;
};
EICAS_LABEL_VAL(AFM_PWR1,0.27,"",21)
	sourceScale = 4.82;
};
EICAS_LABEL_VAL(Q1,0.35,"",21)
	sourceScale = 1;
};

//static right
EICAS_LABEL_VAL(Q2,0.65,"",22)
	sourceScale = 1;
};
EICAS_LABEL_VAL(AFM_PWR2,0.72,"",22)
	sourceScale = 4.76;
};
EICAS_LABEL_VAL(NG2,0.81,"",22)
	sourceScale = 1;
};
EICAS_LABEL_VAL(AFM_RPM2,0.89,"",22)
	sourceScale=1;
};
EICAS_LABEL_VAL(T2,0.96,"",22)
	sourceScale = 1.4;
};

TEXT_MID_SMALL(AFM_TRQ,0.42,LABELHEIGHT,"")
TEXT_MID_MID_SRC(AFM_TRQ_V,0.42,VALUEHEIGHT)
	sourceScale = 1000;
	source="rtdRotorTorque";
};
TEXT_MID_SMALL(AFM_COL,0.59,LABELHEIGHT,"")
TEXT_MID_MID_SRC(AFM_COL_V,0.58,VALUEHEIGHT)
	sourceScale = 100;
	source="rtdCollective";
};

TEXT_MID_SMALL(RPM,(0.5),LABELHEIGHT,"")
TEXT_MID_MID_SRC(RPM_V,(0.5),VALUEHEIGHT)
	sourceScale = 10;
	source="rpm";
};

class barsWrapper {
    color[] = common_green;
	#define BAR_WIDTH 0.012

    BAR(T1BAR,"T1",0.042,BARBOTTOM,BAR_WIDTH)
    BAR(RPM1BAR,"EICAS_RPM1",0.11,BARBOTTOM,BAR_WIDTH)

    BAR(NG1BAR,"NG1",0.191,BARBOTTOM,BAR_WIDTH)
    BAR(TGT1BAR,"TGT1",0.2775,BARBOTTOM,BAR_WIDTH)
	BAR(Q1BAR,"Q1",0.353,BARBOTTOM,BAR_WIDTH)

    BAR(TRQBAR,"TRQ",0.422,BARBOTTOM,BAR_WIDTH)
    BAR(RPMBAR,"EICAS_RPM",0.502,BARBOTTOM,BAR_WIDTH)
    BAR(COLLBAR,"COLL",0.581,BARBOTTOM,BAR_WIDTH)

	BAR(Q2BAR,"Q2",0.651,BARBOTTOM,BAR_WIDTH)
	BAR(TGT2BAR,"TGT2",0.725,BARBOTTOM,BAR_WIDTH)
	BAR(NG2BAR,"NG2",0.813,BARBOTTOM,BAR_WIDTH)

    BAR(RPM2BAR,"EICAS_RPM2",0.893,BARBOTTOM,BAR_WIDTH)
	BAR(T2BAR,"T2",0.962,BARBOTTOM,BAR_WIDTH)

	BAR(FUEL1,"EICAS_Fuel",0.459,FUEL_BARS_Y2,BAR_WIDTH)
	BAR(FUEL2,"EICAS_Fuel",0.545,FUEL_BARS_Y2,BAR_WIDTH)
}; // barsWrapper

#define TOP_TEXT_Y 0.03

class chipBackgroundWrapper {
	condition="0";
	color[] = {0,0,0,0};
	POLYGON(chipBackgroundLeft,0.191,0.47,0.12,0.025)
	POLYGON(chipBackgroundRight,1-0.191,0.47,0.12,0.025)
	POLYGON(chipTail,1-0.191,0.47+(MID_LINE_HEIGHT*1),0.18,0.025)
	POLYGON(chipXmsn,1-0.191,0.47+(MID_LINE_HEIGHT*2),0.14,0.025)
};
class blackTextWrapper {
	color[] = common_yellow;
	// ZONE 1
	class gen1 {
		condition = "rpm<9";
		TEXT_RIGHT_SMALL(TEXT,0.05,TOP_TEXT_Y,"GEN 1 FAIL")
	};
	class hyd1 {
		condition = "rpm<3";
		TEXT_RIGHT_SMALL(TEXT,0.05,TOP_TEXT_Y+(SMALL_LINE_HEIGHT),"HYD PUMP 1 FAIL")
	};
	// ZONE 2
	class gen2 {
		condition = "rpm<9";
		TEXT_RIGHT_SMALL(TEXT,1-0.25,TOP_TEXT_Y,"GEN 2 FAIL")
	};
	class hyd2 {
		condition = "rpm<3";
		TEXT_RIGHT_SMALL(TEXT,1-0.25,TOP_TEXT_Y+(SMALL_LINE_HEIGHT),"HYD PUMP 2 FAIL")
	};
	// ZONE 3
	class engine1 {
		condition = "(pylonammo6>2.5)+((pylonammo6>0.9)*(pylonammo6<1.1))";
		TEXT_RIGHT_SMALL(TEXT,0.05,0.47-0.025,"CHIP ENG 1")
	};
	class chipXmsn {
		condition = "pylonammo3>5";
		TEXT_RIGHT_SMALL(TEXT,0.05,0.47-0.025+(SMALL_LINE_HEIGHT*1),"CHIP TAIL XMSN")
	};
	class starter1 {
		condition = "(pylonammo5>2.5)+((pylonammo5>0.9)*(pylonammo5<1.1))";
		TEXT_RIGHT_SMALL(TEXT,0.05,0.47-0.025+(SMALL_LINE_HEIGHT*2),"STARTER ENG 1")
	};
	class trquad {
		condition = "(pylonammo3>8)";
		TEXT_RIGHT_SMALL(TEXT,0.05,0.47-0.025+(SMALL_LINE_HEIGHT*3),"T/R QUAD FAIL")
	};
	class trservo {
		condition = "(pylonammo3>2)";
		TEXT_RIGHT_SMALL(TEXT,0.05,0.47-0.025+(SMALL_LINE_HEIGHT*4),"T/R SERVO 1 FAIL")
	};
	// ZONE 4
	class engine2 {
		condition = "(pylonammo6>2.5)+((pylonammo6>1.9)*(pylonammo6<2.1))";
		TEXT_RIGHT_SMALL(TEXT,0.65,0.47-0.025,"CHIP ENG 2")
	};
	class chipTail {
		condition = "(pylonammo4>4)";
		TEXT_RIGHT_SMALL(TEXT,0.65,0.47-0.025+(SMALL_LINE_HEIGHT*1),"CHIP MAIN MDL SUMP")
	};
	class starter2 {
		condition = "(pylonammo5>2.5)+((pylonammo5>1.9)*(pylonammo5<2.1))";
		TEXT_RIGHT_SMALL(TEXT,0.65,0.47-0.025+(SMALL_LINE_HEIGHT*2),"STARTER ENG 2")
	};
	// ZONE 5
	class eicasCheck {
		condition = "(pylonammo3>0)";
		TEXT_RIGHT_SMALL(TEXT,0.7,0.7,"CHECK EICAS")
	};
	class stbyOff {
		condition = "(pylonammo3>0)";
		TEXT_RIGHT_SMALL(TEXT,0.7,0.7+SMALL_LINE_HEIGHT,"STBY INST NOT ARMD")
	};
	// ZONE 6
	class fuel1 {
		condition = "fuel < 0.2";
		TEXT_RIGHT_SMALL(TEXT,0.35,0.90,"FUEL 1 LOW")
	};
	class fuel2 {
		condition = "fuel < 0.2";
		TEXT_RIGHT_SMALL(TEXT,0.35,0.90+(SMALL_LINE_HEIGHT*1),"FUEL 2 LOW")
	};
	class fuelpress1 {
		condition = "pylonammo7>0";
		TEXT_RIGHT_SMALL(TEXT,0.50,0.90,"PRESS 1 LOW")
	};
	class fuelpress2 {
		condition = "pylonammo7>0";
		TEXT_RIGHT_SMALL(TEXT,0.50,0.90+(SMALL_LINE_HEIGHT*1),"PRESS 2 LOW")
	};

};

class eng1_out {
	condition = "simulRTD*(user21<40)";
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
	condition = "simulRTD*(user22<40)";
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


TEXT_MID_SMALL(FUEL_MAIN1,0.45,0.55,"1")
TEXT_MID_SMALL(FUEL_MAIN2,0.55,0.55,"2")

TEXT_MID_MID_SRC(FUEL_VAL,0.5,0.85)
	source="fuel";
	sourceScale = 2040;
	sourceLength = 4;
};
//TEXT_MID_SMALL(FUEL_FLIGHTTIME_LABEL,0.5,0.83,"TIME")
//TEXT_MID_MID_SRC(FUEL_FLIGHTTIME_VAL,0.5,0.87)
//	source="userText";
//	sourceIndex = 10;
//	sourceScale = 1;
//};

TEXT_MID_SMALL_SRC(FUEL_VALUE_L,0.459,0.78) source="fuel";    sourceScale = 1020;};
TEXT_MID_SMALL_SRC(FUEL_VALUE_R,0.545,0.78) source="fuel";    sourceScale = 1020;};
//checklist?
TEXT_RIGHT_SMALL_SRC(CAS1,0.043,0.745 - 0.05-0.006) source="userText"; sourceIndex = 0; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS2,0.043,0.775 - 0.05-0.005) source="userText"; sourceIndex = 1; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS3,0.043,0.805 - 0.05-0.004) source="userText"; sourceIndex = 2; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS4,0.043,0.835 - 0.05-0.003)    source="userText"; sourceIndex = 3; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS5,0.043,0.865 - 0.05-0.002)    source="userText"; sourceIndex = 4; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS6,0.043,0.895 - 0.05-0.001)    source="userText"; sourceIndex = 5; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC(CAS7,0.043,0.925 - 0.05) source="userText"; sourceIndex = 6; sourceScale = 1;};

#define BOTTOM_TEXT_Y 0.96
#define TOP_TEXT_Y 0.03
#define DEFAULT_TEXT_SIZE 0.65
TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"FLIR")
TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")
