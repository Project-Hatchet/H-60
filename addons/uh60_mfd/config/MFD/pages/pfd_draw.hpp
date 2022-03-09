#undef BARTOP
#undef BARBOTTOM
#define BARTOP 0.65
#define BARBOTTOM 0.905

alpha = 0.65;
class overlayWrapper {
	class PolygonJet {
		type        = "polygon";
		texture = "z\vtx\addons\uh60_mfd\data\PFD.paa";
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
#define TEXT_DEFAULT_PFD(CLASS,X,Y) \
	class CLASS { \
		type = "text"; \
		align = "left"; \
		scale = 1; \
		pos[] = {{X, Y}, 1}; \
		right[] = {{X + 0.0386, Y}, 1}; \
		down[] = {{X, Y + 0.0442}, 1}; \



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

TEXT_LEFT_SMALL(IVHMS,0.78,0.02,"IVHMS")
TEXT_LEFT_SMALL(CCFS,0.87,0.02,"CCFS")


TEXT_LEFT_SMALL(STB,0.08,0.05,"STB")
TEXT_MID_MID_SRC(STB_NUM,0.06,0.08)
	source="userText";
	sourceIndex = 11;
	sourceScale = 1;
};

TEXT_LEFT_SMALL(T2,0.15,TOP_TEXT_Y,"ALT")
TEXT_LEFT_SMALL(T3,0.26,TOP_TEXT_Y,"IAS")

TEXT_MID_MID_SRC(HDG_TXT,0.5,0.51)
	sourceScale = 1;
	source="heading";
};

TEXT_MID_SMALL_SRC(BALT_TXT,0.812,0.262)
	source="altitudeASL";
	sourceScale = 3.2808399;
	sourceLength = 4;
};
TEXT_MID_MID_SRC(RALT_TXT,0.87,0.59)
	source="altitudeAGL";
	sourceScale = 3.2808399;
	sourceLength = 4;
};
class SpeedArm {
	type="line";
	width = 7;
	points[] ={
		{"speedRotation",{0, 0.04},1},{"speedRotation",{0, 0.07},1}
	};
}; // speedArm
class SpeedArm2 {
	type="line";
	width = 3;
	points[] ={
		{"speedRotation",{0, 0.04},1},{"speedRotation",{0, 0.1},1}
	};
}; // speedArm2
class FlightDirector{
	color[]={0.3,0.065,0.140,0.002};
	alpha=0.9;
	TEXT_DEFAULT_PFD(FDALT_TXT,0.825,0.0476)
		source="user";
		sourceIndex=14;
		sourceScale = 1;
	};
	TEXT_DEFAULT_PFD(FDRALT_TXT,0.899,0.827)
		source="user";
		sourceIndex=12;
		sourceScale = 1;
	};
	class FD_AltArm1 {
		type="polygon";
		points[] ={
			{
				{"FD_ALTRotation",{0, 0.107},1},
				{"FD_ALTRotation",{-0.016, 0.107},1},
				{"FD_ALTRotation",{-0.016, 0.118},1},
				{"FD_ALTRotation",{-0.009, 0.118},1}
			}
		};
	}; // FDspeedArm1
	class FD_AltArm2 {
		type="polygon";
		points[] ={
			{
				{"FD_ALTRotation",{0, 0.107},1},
				{"FD_ALTRotation",{0.016, 0.107},1},
				{"FD_ALTRotation",{0.016, 0.118},1},
				{"FD_ALTRotation",{0.009, 0.118},1}
			}
		};
	}; // FDspeedArm2
	class FD_SpeedArm1 {
		type="polygon";
		points[] ={
			{
				{"FD_speedRotation",{0, 0.107},1},
				{"FD_speedRotation",{-0.016, 0.107},1},
				{"FD_speedRotation",{-0.016, 0.118},1},
				{"FD_speedRotation",{-0.009, 0.118},1}
			}
		};
	}; // FDspeedArm1
	class FD_SpeedArm2 {
		type="polygon";
		points[] ={
			{
				{"FD_speedRotation",{0, 0.107},1},
				{"FD_speedRotation",{0.016, 0.107},1},
				{"FD_speedRotation",{0.016, 0.118},1},
				{"FD_speedRotation",{0.009, 0.118},1}
			}
		};
	}; // FDspeedArm2
	class FD_RALTRotation1Cond {
		condition="(user12) < 100.1";
		class FD_RALTArm1 {
			type="polygon";
			points[] ={
				{
					{"FD_RALTRotation1",{0, "0.107-0.016"},1},
					{"FD_RALTRotation1",{-0.016, "0.107-0.016"},1},
					{"FD_RALTRotation1",{-0.016, "0.118-0.016"},1},
					{"FD_RALTRotation1",{-0.009, "0.118-0.016"},1}
				}
			};
		}; // FD_RALTArm1
		class FD_RALTArm2 {
			type="polygon";
			points[] ={
				{
					{"FD_RALTRotation1",{0, "0.107-0.016"},1},
					{"FD_RALTRotation1",{0.016, "0.107-0.016"},1},
					{"FD_RALTRotation1",{0.016, "0.118-0.016"},1},
					{"FD_RALTRotation1",{0.009, "0.118-0.016"},1}
				}
			};
		}; // FD_RALTArm2
	}; // FD_RALTRotation1Cond
	class FD_RALTRotation2Cond {
		condition="((user12) > 100) * ( user12 < 400 )";
		class FD_RALTArm1 {
			type="polygon";
			points[] ={
				{
					{"FD_RALTRotation2",{0, "0.107-0.016"},1},
					{"FD_RALTRotation2",{-0.016, "0.107-0.016"},1},
					{"FD_RALTRotation2",{-0.016, "0.118-0.016"},1},
					{"FD_RALTRotation2",{-0.009, "0.118-0.016"},1}
				}
			};
		}; // FD_RALTArm1
		class FD_RALTArm2 {
			type="polygon";
			points[] ={
				{
					{"FD_RALTRotation2",{0, "0.107-0.016"},1},
					{"FD_RALTRotation2",{0.016, "0.107-0.016"},1},
					{"FD_RALTRotation2",{0.016, "0.118-0.016"},1},
					{"FD_RALTRotation2",{0.009, "0.118-0.016"},1}
				}
			};
		}; // FD_RALTArm2
	}; // FD_RALTRotation2Cond
	class FD_RALTRotation3Cond {
		condition="(user12) > 400";
		class FD_RALTArm1 {
			type="polygon";
			points[] ={
				{
					{"FD_RALTRotation3",{0, "0.107-0.016"},1},
					{"FD_RALTRotation3",{-0.016, "0.107-0.016"},1},
					{"FD_RALTRotation3",{-0.016, "0.118-0.016"},1},
					{"FD_RALTRotation3",{-0.009, "0.118-0.016"},1}
				}
			};
		}; // FD_RALTArm1
		class FD_RALTArm2 {
			type="polygon";
			points[] ={
				{
					{"FD_RALTRotation3",{0, "0.107-0.016"},1},
					{"FD_RALTRotation3",{0.016, "0.107-0.016"},1},
					{"FD_RALTRotation3",{0.016, "0.118-0.016"},1},
					{"FD_RALTRotation3",{0.009, "0.118-0.016"},1}
				}
			};
		}; // FD_RALTArm2
	}; // FD_RALTRotation3Cond
};//FlightDirector

TEXT_MID_SMALL_SRC(IAS_VAL,0.1715,0.258)
	source="speed";
	sourceScale = 1.94384;
	sourceLength = 3;
};

TEXT_LEFT_SMALL(GS_TXT,0.24,0.465,"GS")
TEXT_MID_MID_SRC(GS_VAL,0.275,0.45)
	source="speed";
	sourceScale = 1.94384;
	sourceLength = 3;
};
TEXT_MID_MID_SRC(WIND_VAL,0.27,0.485)
	source="userText";
	sourceScale=1;
	sourceIndex=9;
};
class windArm {
	type="line";
	width = 3;
	points[] ={
		{"HeadingRotationWind",{"RotationWind",0, 0.015},1},
		{"HeadingRotationWind",{"RotationWind",0, -0.015},1}
	};
}; // windArm
class windArrow {
	type="polygon";
	points[] ={
		{
			{"HeadingRotationWind",{"RotationWind",0, -0.016},1},
			{"HeadingRotationWind",{"RotationWind",0.008, -0.007},1},
			{"HeadingRotationWind",{"RotationWind",-0.008, -0.007},1}
		}
	};
}; // windArrow

//FMS stuff
TEXT_MID_MID(NAV_FMS_LABEL,0.72,0.72,"FMS1")
TEXT_LEFT_MID_SRC(NAV_FMS_WP_LABEL,0.685,0.76)
	source="userText";
	sourceScale=1;
	sourceIndex=7;
};
TEXT_LEFT_MID_SRC(NAV_FMS_WP_DIR,0.75,0.80)
	source="user";
	sourceIndex=0;
	sourceScale=1;
};
TEXT_MID_MID_SRC(NAV_FMS_WP_DIST,0.705,0.833)
	source="WPDist";
	sourceScale=0.000539957;
	sourceLength=3;
	sourcePrecision=1;
};
TEXT_LEFT_MID_SRC(NAV_FMS_WP_TOF,0.75,0.87)
	source="userText";
	sourceScale=1;
	sourceIndex=8;
};

#define FUEL_BAR_WIDTH 0.004
class fuelBarsWrapper {
	color[] = common_green;
	class fuelBar1 {
		type="polygon";
		points[] ={
			{
				{"Fuel",{-FUEL_BAR_WIDTH, 0},1},
				{"Fuel",{FUEL_BAR_WIDTH, 0},1},
				{{FUEL_BARS_X + FUEL_BAR_WIDTH,FUEL_BARS_Y2},1},
				{{FUEL_BARS_X - FUEL_BAR_WIDTH,FUEL_BARS_Y2},1}
			}
		}; // points
	}; // fuelBar1
	class fuelBar2 {
		type="polygon";
		points[] ={
			{
				{"Fuel",{(FUEL_BAR_WIDTH * 3) + (-FUEL_BAR_WIDTH), 0},1},
				{"Fuel",{(FUEL_BAR_WIDTH * 3) + (FUEL_BAR_WIDTH), 0},1},
				{{(FUEL_BAR_WIDTH * 3) + (FUEL_BARS_X + FUEL_BAR_WIDTH),FUEL_BARS_Y2},1},
				{{(FUEL_BAR_WIDTH * 3) + (FUEL_BARS_X - FUEL_BAR_WIDTH),FUEL_BARS_Y2},1}
			}
		}; // points
	}; // fuelBar2
	TEXT_MID_MID_SRC(FUEL_VAL,0.2864,0.8)
		source="fuel";
		sourceScale = 2040;
		sourceLength = 4;
	};
}; // fuelBarsWrapper

class RALTRotation1Cond {
	condition="(altitudeAGL*3.2808399) < 100";
	class RaltArm {
		type="line";
		width = 7;
		points[] ={
			{"RALTRotation1",{0, 0.04},1},{"RALTRotation1",{0, 0.06},1}
		};
	}; // RaltArm
	class RaltArm2 {
		type="line";
		width = 3;
		points[] ={
			{"RALTRotation1",{0, 0.04},1},{"RALTRotation1",{0, 0.08},1}
		};
	}; // RaltArm2
}; // RALTRotation1Cond
class RALTRotation2Cond {
	condition="((altitudeAGL*3.2808399) > 100) * ( (altitudeAGL*3.2808399) < 400 )";
	class RaltArm {
		type="line";
		width = 7;
		points[] ={
			{"RALTRotation2",{0, 0.04},1},{"RALTRotation2",{0, 0.06},1}
		};
	}; // RaltArm
	class RaltArm2 {
		type="line";
		width = 3;
		points[] ={
			{"RALTRotation2",{0, 0.04},1},{"RALTRotation2",{0, 0.08},1}
		};
	}; // RaltArm2
}; // RALTRotation2Cond
class RALTRotation3Cond {
	condition="(altitudeAGL*3.2808399) > 400";
	class RaltArm {
		type="line";
		width = 7;
		points[] ={
			{"RALTRotation3",{0, 0.04},1},{"RALTRotation3",{0, 0.06},1}
		};
	}; // RaltArm
	class RaltArm2 {
		type="line";
		width = 3;
		points[] ={
			{"RALTRotation3",{0, 0.04},1},{"RALTRotation3",{0, 0.08},1}
		};
	}; // RaltArm2
}; // RALTRotation3Cond

class BAltArm {
	type="line";
	width = 7;
	points[] ={
		{"BALTRotation",{0, 0.04},1},{"BALTRotation",{0, 0.07},1}
	};
}; // BAltArm
class BAltArm2 {
	type="line";
	width = 3;
	points[] ={
		{"BALTRotation",{0, 0.04},1},{"BALTRotation",{0, 0.1},1}
	};
}; // BAltArm2

#define HSI_SIZE 0.155
class PolygonHeading {
	type        = "polygon";
	texture = "z\vtx\addons\uh60_mfd\data\HSI.paa";
	points[] ={
		{
			{"HeadingRotation",{-HSI_SIZE * 1, HSI_SIZE},1},
			{"HeadingRotation",{HSI_SIZE * 1, HSI_SIZE},1},
			{"HeadingRotation",{HSI_SIZE * 1, -HSI_SIZE},1},
			{"HeadingRotation",{-HSI_SIZE * 1, -HSI_SIZE},1}
		}
	}; // points
}; // PolygonHeading
class HSI_FMS {
	color[] = common_green;
	class Line {
		type="line";
		width = 3;
		points[] ={
			{"HeadingRotation",{"WaypointDirection",0, 0.1},1},
			{"HeadingRotation",{"WaypointDirection",0, 0.04},1},{},

			{"HeadingRotation",{"WaypointDirection",-0.01, 0.05},1},
			{"HeadingRotation",{"WaypointDirection", 0.00, 0.040},1},
			{"HeadingRotation",{"WaypointDirection", 0.01, 0.05},1},{},

			{"HeadingRotation",{"WaypointDirection",0, -0.1},1},
			{"HeadingRotation",{"WaypointDirection",0, -0.05},1},{},

			{"HeadingRotation",{"WaypointDirection",-0.01, -0.040},1},
			{"HeadingRotation",{"WaypointDirection", 0.00, -0.05},1},
			{"HeadingRotation",{"WaypointDirection", 0.01, -0.040},1},{},

			{"HeadingRotation",{"WaypointDirection", 0.005,-0.045},1},
			{"HeadingRotation",{"WaypointDirection", 0.005,-0.030},1},{},
			{"HeadingRotation",{"WaypointDirection",-0.005,-0.045},1},
			{"HeadingRotation",{"WaypointDirection",-0.005,-0.030},1},{},

			{"HeadingRotation",{"WaypointDirection", 0.005,0.045},1},
			{"HeadingRotation",{"WaypointDirection", 0.005,0.030},1},{},
			{"HeadingRotation",{"WaypointDirection",-0.005,0.045},1},
			{"HeadingRotation",{"WaypointDirection",-0.005,0.030},1},
		};
	};
}; // HSI_FMS

class VSI_Polygon {
	color[]=common_blue;
	class VSI_PolygonBlue {
		type="polygon";
		points[] ={
			{
				{"VSI_L_Polygon",{0, 0},1},
				{"VSI_R_Polygon",{0, 0},1},
				{{0.99, 0.287},1},
				{{0.975, 0.287},1}
			}
		};
	};
};//VSI_Polygon
class VSI_Line {
	type="line";
	width=5;
	points[] =
	{
		{"VSI_L",1,{0,0},1},
		{"VSI_R",1,{0,0},1}
	};
}; // VSI_Line
TEXT_MID_MID_SRC(VSPEED,0.94,0.05)
	sourceScale = 196.85;
	source="vspeed";
	sourceLength = 4;
};

class pitchLadderWrapper {
	clipTL[] = {0.345, 0.0};
	clipBR[] = {0.657, 0.49};
	#define PFD_BANK_SCALE 0.5
	class Bank_Marks {
		type="line";
		width=0;
		points[]={
			{"Middle", {PFD_BANK_SCALE * 0.306418, PFD_BANK_SCALE * -0.257115},1},//40
			{"Middle", {PFD_BANK_SCALE * 0.260455, PFD_BANK_SCALE * -0.218548},1},{},
			{"Middle", {PFD_BANK_SCALE * 0.257115, PFD_BANK_SCALE * -0.306418},1},//50
			{"Middle", {PFD_BANK_SCALE * 0.218548, PFD_BANK_SCALE * -0.260455},1},{},
			{"Middle", {PFD_BANK_SCALE * 0.200000, PFD_BANK_SCALE * -0.346410},1},//60
			{"Middle", {PFD_BANK_SCALE * 0.170000, PFD_BANK_SCALE * -0.294449},1},{},
			{"Middle", {PFD_BANK_SCALE * 0.136808, PFD_BANK_SCALE * -0.375877},1},//70
			{"Middle", {PFD_BANK_SCALE * 0.116287, PFD_BANK_SCALE * -0.319495},1},{},
			{"Middle", {PFD_BANK_SCALE * 0.069459, PFD_BANK_SCALE * -0.393923},1},//80
			{"Middle", {PFD_BANK_SCALE * 0.059040, PFD_BANK_SCALE * -0.334835},1},{},
			{"Middle", {PFD_BANK_SCALE * 0.000000, PFD_BANK_SCALE * -0.400000},1},//90
			{"Middle", {PFD_BANK_SCALE * 0.000000, PFD_BANK_SCALE * -0.340000},1},{},
			{"Middle", {PFD_BANK_SCALE * -0.069459,PFD_BANK_SCALE *    -0.393923},1},//100
			{"Middle", {PFD_BANK_SCALE * -0.059040,PFD_BANK_SCALE *    -0.334835},1},{},
			{"Middle", {PFD_BANK_SCALE * -0.136808,PFD_BANK_SCALE *    -0.375877},1},//110
			{"Middle", {PFD_BANK_SCALE * -0.116287,PFD_BANK_SCALE *    -0.319495},1},{},
			{"Middle", {PFD_BANK_SCALE * -0.200000,PFD_BANK_SCALE *    -0.346410},1},//120
			{"Middle", {PFD_BANK_SCALE * -0.170000,PFD_BANK_SCALE *    -0.294449},1},{},
			{"Middle", {PFD_BANK_SCALE * -0.257115,PFD_BANK_SCALE *    -0.306418},1},//130
			{"Middle", {PFD_BANK_SCALE * -0.218548,PFD_BANK_SCALE *    -0.260455},1},{},
			{"Middle", {PFD_BANK_SCALE * -0.306418,PFD_BANK_SCALE *    -0.257115},1},//140
			{"Middle", {PFD_BANK_SCALE * -0.260455,PFD_BANK_SCALE *    -0.218548},1},{},
		};
	}; // Bank_Marks
	class pitchLadderLinesWrap {
		clipTL[] = {0, 0.05};
		clipBR[] = {1, 1};
		alpha = 1;
		LEVEL_BACKGROUND(pitch_att_blue,pitch_att_orange,0.5)
		LEVEL0(0.23)
		LEVEL_SET(5,10,0.02,0.05,0.08)
		LEVEL_SET(15,20,0.02,0.05,0.08)
		LEVEL_SET(25,30,0.02,0.05,0.08)
		LEVEL_SET(35,40,0.02,0.05,0.08)
		LEVEL_SET(45,50,0.02,0.05,0.08)
		LEVEL_SET(55,60,0.02,0.05,0.08)
		LEVEL_SET(65,70,0.02,0.05,0.08)
		LEVEL_SET(75,80,0.02,0.05,0.08)
		LEVEL_SET(85,90,0.02,0.05,0.08)
	}; // pitchLadderLinesWrap

	
	class pitchLadderLevelBackgroundWhite {
		color[] = common_white;
		class HorizonLeftHoriz {
			type = "polygon";
			points[] ={
				{
					{"PFD_LEVEL_MIDDLE", {-0.13, -0.01}, 1},{"PFD_LEVEL_MIDDLE", {-0.05, -0.01}, 1},{"PFD_LEVEL_MIDDLE", {-0.05,  0.01}, 1},
					{"PFD_LEVEL_MIDDLE", {-0.13,  0.01}, 1},
				}
			};
		};
		class HorizonLeftVert {
			type = "polygon";
			points[] ={
				{
					{"PFD_LEVEL_MIDDLE", {-0.05,  0.04}, 1},{"PFD_LEVEL_MIDDLE", {-0.03,  0.04}, 1},{"PFD_LEVEL_MIDDLE", {-0.03,  -0.01}, 1},
					{"PFD_LEVEL_MIDDLE", {-0.05,  -0.01}, 1},
				}
			};
		};
		class HorizonRightHoriz {
			type = "polygon";
			points[] ={
				{
					{"PFD_LEVEL_MIDDLE", {0.13, -0.01}, 1},{"PFD_LEVEL_MIDDLE", {0.05, -0.01}, 1},{"PFD_LEVEL_MIDDLE", {0.05,  0.01}, 1},
					{"PFD_LEVEL_MIDDLE", {0.13,  0.01}, 1},
				}
			};
		};
		class HorizonRightVert {
			type = "polygon";
			points[] ={
				{
					{"PFD_LEVEL_MIDDLE", {0.05,  0.04}, 1},{"PFD_LEVEL_MIDDLE", {0.03,  0.04}, 1},{"PFD_LEVEL_MIDDLE", {0.03,  -0.01}, 1},
					{"PFD_LEVEL_MIDDLE", {0.05,  -0.01}, 1},
				}
			};
		};
		#define LEVEL_SHRINK 0.005
		class pitchLadderLevelBlack {
			color[] = {0,0,0,1};
			class HorizonLeftHoriz {
				type = "polygon";
				points[] ={
					{
						{"PFD_LEVEL_MIDDLE", {-0.13+LEVEL_SHRINK, -0.01+LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {-0.05+LEVEL_SHRINK, -0.01+LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {-0.05+LEVEL_SHRINK,  0.01-LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {-0.13+LEVEL_SHRINK,  0.01-LEVEL_SHRINK}, 1},
					}
				};
			};
			class HorizonLeftVert {
				type = "polygon";
				points[] ={
					{
						{"PFD_LEVEL_MIDDLE", {-0.05+LEVEL_SHRINK,  0.04-LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {-0.03-LEVEL_SHRINK,  0.04-LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {-0.03-LEVEL_SHRINK,  -0.01+LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {-0.05+LEVEL_SHRINK,  -0.01+LEVEL_SHRINK}, 1},
					}
				};
			};
			class HorizonRightHoriz {
				type = "polygon";
				points[] ={
					{
						{"PFD_LEVEL_MIDDLE", {0.13-LEVEL_SHRINK, -0.01+LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {0.05-LEVEL_SHRINK, -0.01+LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {0.05-LEVEL_SHRINK,  0.01-LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {0.13-LEVEL_SHRINK,  0.01-LEVEL_SHRINK}, 1},
					}
				};
			};
			class HorizonRightVert {
				type = "polygon";
				points[] ={
					{
						{"PFD_LEVEL_MIDDLE", {0.05-LEVEL_SHRINK,  0.04-LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {0.03+LEVEL_SHRINK,  0.04-LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {0.03+LEVEL_SHRINK,  -0.01+LEVEL_SHRINK}, 1},
						{"PFD_LEVEL_MIDDLE", {0.05-LEVEL_SHRINK,  -0.01+LEVEL_SHRINK}, 1},
					}
				};
			};
		}; // pitchLadderBlack
	}; // pitchLadderBackgroundWhite

}; // pitchLadderWrapper

class powerPodBarWrap {
	color[] = common_green;
    BAR(RPMBAR,"RPM",0.136,BARBOTTOM,0.02)
    BAR(RPM1BAR,"RPM1",0.088,BARBOTTOM,0.01)
    BAR(RPM2BAR,"RPM2",0.185,BARBOTTOM,0.01)
}; // powerPodBarWrap
