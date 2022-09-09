#undef BARTOP
#undef BARBOTTOM
#define BARTOP 0.65
#define BARBOTTOM 0.905

alpha = BACKGROUND_ALPHA;

class overlayWrapper {
	class PolygonJet {
		type        = "polygon";
		texture = "z\vtx\addons\uh60_mfd\data\PFD_Back.paa";
		points[] ={
			{
				{{0, 0},1},
				{{1, 0},1},
				{{1, 1},1},
				{{0, 1},1}
			}
		};
	};
	class RaltEnabledGroup {
		condition = RALT_ENABLED;
		class Polygon {
			type        = "polygon";
			texture = "z\vtx\addons\uh60_mfd\data\PFD_Ralt_Back.paa";
			points[] ={
				{
					{{0, 0},1},
					{{1, 0},1},
					{{1, 1},1},
					{{0, 1},1}
				}
			};
		};
		class CoveringText {
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
			TEXT_MID_MID_SRC(RALT_TXT,0.87,0.59)
				source="altitudeAGL";
				sourceScale = 3.2808399;
				sourceLength = 4;
			};
			class FlightDirectorPurple {
				color[]={0.3,0.065,0.140,0.002};
				alpha=0.9;
				TEXT_MID_MID_SRC(FDRALT_TXT,0.899,0.827)
					source="user";
					sourceIndex=12;
					sourceScale = 1;
				};
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
			}; // FlightDirectorPurple
		}; // CoveringText
	}; // RaltEnabledGroup
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
// TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
// TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
// TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

// TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
// TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
// TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")


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
	class pitchBackground {
		clipTL[] = {0, 0.05};
		clipBR[] = {1, 1};
		LEVEL_BACKGROUND(pitch_att_blue,pitch_att_orange,0.5)
		class newPitchLadderLines {
			clipTL[] = {0, 0.15};
			clipBR[] = {1, 1};
			class ladderLinesWhite {
				type="line";
				width=2;
				points[]={
					{"Level0", {-0.22, 0}, 1},{"Level0", { 0.22, 0}, 1},{},

					POINTS_LEVEL_N(P2D5),
					POINTS_LEVEL_M(P5),
					POINTS_LEVEL_N(P7D5),
					POINTS_LEVEL_W(P10),
					POINTS_LEVEL_N(P12D5),
					POINTS_LEVEL_M(P15),
					POINTS_LEVEL_N(P17D5),
					POINTS_LEVEL_W(P20),
					POINTS_LEVEL_N(P22D5),
					POINTS_LEVEL_M(P25),
					POINTS_LEVEL_N(P27D5),
					POINTS_LEVEL_W(P30),
					POINTS_LEVEL_W(P40),

					{P32D5_pos, {0.01, 0}, 1}, {P32D5_pos, {-0.01, 0}, 1},{},
					{P35_pos, {0.03, 0}, 1}, {P35_pos, {-0.03, 0}, 1},{},
					{P37D5_pos, {0.01, 0}, 1}, {P37D5_pos, {-0.01, 0}, 1},{},
					{P50_pos, {0.08, 0}, 1}, {P50_pos, {-0.08, 0}, 1},{},
					
					{P55_neg, {0.08, 0}, 1}, {P55_neg, {-0.08, 0}, 1},{},

					POINTS_LEVEL_W(P70),
					POINTS_LEVEL_W(P90)
				};
			};
			LEVEL_TEXT(L10p,P10_pos,0.05,"10")
			LEVEL_TEXT(L10n,P10_neg,0.05,"10")
			LEVEL_TEXT(L20p,P20_pos,0.05,"20")
			LEVEL_TEXT(L20n,P20_neg,0.05,"20")
			LEVEL_TEXT(L30p,P30_pos,0.05,"30")
			LEVEL_TEXT(L30n,P30_neg,0.05,"30")
			LEVEL_TEXT(L40p,P40_pos,0.05,"40")
			LEVEL_TEXT(L40n,P40_neg,0.05,"40")
			LEVEL_TEXT(L50p,P50_pos,0.05,"50")
			LEVEL_TEXT(L70n,P70_neg,0.05,"70")
			LEVEL_TEXT(L90p,P90_pos,0.05,"90")
			LEVEL_TEXT(L90n,P90_neg,0.05,"90")
			class redColor {
				color[] = {1,0,0,1};
				class ladderLinesWhite {
					type="line";
					width=6;
					points[]={
						{"P60_pos", {-0.06,0.01}, 1},
						{"P50_pos", {0, 0}, 1},
						{"P60_pos", {0.06, 0.01}, 1},{},

						{"P55_neg", {-0.04,-0.01}, 1},
						{"P40_neg", {0, 0.01}, 1},
						{"P55_neg", {0.04, -0.01}, 1},{},
						
						{"P70_neg", {-0.06,-0.01}, 1},
						{"P55_neg", {0, 0.01}, 1},
						{"P70_neg", {0.06, -0.01}, 1},{},
						
						{"P90_neg", {-0.06,-0.01}, 1},
						{"P90_neg", {-0.08,-0.01}, 1},
						{"P70_neg", {0, 0.01}, 1},
						{"P90_neg", {0.08, -0.01}, 1},
						{"P90_neg", {0.06, -0.01}, 1},{},

						{"P90_pos", {-0.06,0.01}, 1},
						{"P90_pos", {-0.08,0.01}, 1},
						{"P70_pos", {0, -0.01}, 1},
						{"P90_pos", {0.08, 0.01}, 1},
						{"P90_pos", {0.06, 0.01}, 1},{}
					};
				};
			};
		}; // newPitchLadderLines
	}; // background
}; // pitchLadderWrapper

class ADICenterBlack {
	color[] = common_black;
	class ladderLinesWhite {
		type="line";
		width=9;
		points[]={
			  {"PFD_LEVEL_MIDDLE", ANGLE(0,0.013), 1},
			 {"PFD_LEVEL_MIDDLE", ANGLE(30,0.013), 1},
			 {"PFD_LEVEL_MIDDLE", ANGLE(60,0.013), 1},
			 {"PFD_LEVEL_MIDDLE", ANGLE(90,0.013), 1},
			{"PFD_LEVEL_MIDDLE", ANGLE(120,0.013), 1},
			{"PFD_LEVEL_MIDDLE", ANGLE(150,0.013), 1},
			{"PFD_LEVEL_MIDDLE", ANGLE(180,0.013), 1},
			{"PFD_LEVEL_MIDDLE", ANGLE(210,0.013), 1},
			{"PFD_LEVEL_MIDDLE", ANGLE(240,0.013), 1},
			{"PFD_LEVEL_MIDDLE", ANGLE(270,0.013), 1},
			{"PFD_LEVEL_MIDDLE", ANGLE(300,0.013), 1},
			{"PFD_LEVEL_MIDDLE", ANGLE(330,0.013), 1},
			{"PFD_LEVEL_MIDDLE", ANGLE(360,0.013), 1}
		};
	};
	class white {
		color[] = common_white;
		class lines {
			type="line";
			width=3;
			points[]={
				{"PFD_LEVEL_MIDDLE", ANGLE(0,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(30,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(60,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(90,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(120,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(150,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(180,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(210,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(240,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(270,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(300,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(330,0.013), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(360,0.013), 1}
			};
		};
		#define ROLL_INDICATOR_START 0.20
		class Roll_indicator {
			type="line";
			width=2;
			points[]={
				// RIGHT SIDE
				{"PFD_LEVEL_MIDDLE", ANGLE(170,ROLL_INDICATOR_START+0.00), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(170,ROLL_INDICATOR_START+0.02), 1},{},
				{"PFD_LEVEL_MIDDLE", ANGLE(160,ROLL_INDICATOR_START+0.00), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(160,ROLL_INDICATOR_START+0.02), 1},{},
				{"PFD_LEVEL_MIDDLE", ANGLE(150,ROLL_INDICATOR_START+0.00), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(150,ROLL_INDICATOR_START+0.03), 1},{},

				
				{"PFD_LEVEL_MIDDLE", ANGLE(132,ROLL_INDICATOR_START+0.02), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(135,ROLL_INDICATOR_START+0.00), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(138,ROLL_INDICATOR_START+0.02), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(132,ROLL_INDICATOR_START+0.02), 1},{},

				{"PFD_LEVEL_MIDDLE", ANGLE(120,ROLL_INDICATOR_START+0.00), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(120,ROLL_INDICATOR_START+0.02), 1},{},
			
				// LEFT SIDE
				{"PFD_LEVEL_MIDDLE", ANGLE(190,ROLL_INDICATOR_START+0.00), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(190,ROLL_INDICATOR_START+0.02), 1},{},
				{"PFD_LEVEL_MIDDLE", ANGLE(200,ROLL_INDICATOR_START+0.00), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(200,ROLL_INDICATOR_START+0.02), 1},{},
				{"PFD_LEVEL_MIDDLE", ANGLE(210,ROLL_INDICATOR_START+0.00), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(210,ROLL_INDICATOR_START+0.03), 1},{},

				{"PFD_LEVEL_MIDDLE", ANGLE(222,ROLL_INDICATOR_START+0.02), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(225,ROLL_INDICATOR_START+0.00), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(228,ROLL_INDICATOR_START+0.02), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(222,ROLL_INDICATOR_START+0.02), 1},{},
				
				{"PFD_LEVEL_MIDDLE", ANGLE(240,ROLL_INDICATOR_START+0.00), 1},
				{"PFD_LEVEL_MIDDLE", ANGLE(240,ROLL_INDICATOR_START+0.02), 1},{}
			};
		}; // Roll_indicator
		class Roll_indicator_0 {
			type = "polygon";
			points[] ={
				{
					{"PFD_LEVEL_MIDDLE", {-0.01,-ROLL_INDICATOR_START-0.03}, 1},
					{"PFD_LEVEL_MIDDLE", {  0.0,-ROLL_INDICATOR_START-0.00}, 1},
					{"PFD_LEVEL_MIDDLE", { 0.01,-ROLL_INDICATOR_START-0.03}, 1},
				}
			};
		}; // Roll_indicator_0
		class Roll_indicator_current {
			type        = "polygon";
			points[] ={
				{
					{"ADI_HorizonBankRot",{-0.01,ROLL_INDICATOR_START-0.075},1},
					{"ADI_HorizonBankRot",{  0.0,ROLL_INDICATOR_START-0.05},1},
					{"ADI_HorizonBankRot",{ 0.01,ROLL_INDICATOR_START-0.075},1}
				}
			};
		};//Triangle
	};
};

class pitchLadderLevelBackgroundWhite {
	condition = "1";
	color[] = common_white;
	class HorizonLeftHoriz {
		type = "polygon";
		points[] ={
			{
				{"PFD_LEVEL_MIDDLE", {-0.13, -0.01}, 1},{"PFD_LEVEL_MIDDLE", {-0.05, -0.01}, 1},{"PFD_LEVEL_MIDDLE", {-0.05,  0.01}, 1},
				{"PFD_LEVEL_MIDDLE", {-0.13,  0.01}, 1}
			}
		};
	};
	class HorizonLeftVert {
		type = "polygon";
		points[] ={
			{
				{"PFD_LEVEL_MIDDLE", {-0.05,  0.04}, 1},{"PFD_LEVEL_MIDDLE", {-0.03,  0.04}, 1},{"PFD_LEVEL_MIDDLE", {-0.03,  -0.01}, 1},
				{"PFD_LEVEL_MIDDLE", {-0.05,  -0.01}, 1}
			}
		};
	};
	class HorizonRightHoriz {
		type = "polygon";
		points[] ={
			{
				{"PFD_LEVEL_MIDDLE", {0.13, -0.01}, 1},{"PFD_LEVEL_MIDDLE", {0.05, -0.01}, 1},{"PFD_LEVEL_MIDDLE", {0.05,  0.01}, 1},
				{"PFD_LEVEL_MIDDLE", {0.13,  0.01}, 1}
			}
		};
	};
	class HorizonRightVert {
		type = "polygon";
		points[] ={
			{
				{"PFD_LEVEL_MIDDLE", {0.05,  0.04}, 1},{"PFD_LEVEL_MIDDLE", {0.03,  0.04}, 1},{"PFD_LEVEL_MIDDLE", {0.03,  -0.01}, 1},
				{"PFD_LEVEL_MIDDLE", {0.05,  -0.01}, 1}
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

class powerPodTexWrap {
	color[] = common_green;
	TEXT_MID_MID_SRC(PFD_Q1_V,0.078,0.56)
		source="user";
		sourceIndex = 22;
		sourceScale = 1;
	};
	TEXT_MID_MID_SRC(PFD_RPM_V,0.136,0.47)
		source="user";
		sourceIndex = 17;
		sourceScale = 1;
	};
	TEXT_MID_MID_SRC(PFD_Q2_V,0.195,0.56)
		source="user";
		sourceIndex = 48;
		sourceScale = 1;
	};
};

class powerPodBarWrap {
	color[] = common_green;
	BAR(RPMBAR, "PFD_RPM",0.136,BARBOTTOM,0.01)
}; // powerPodBarWrap

class singleEngineTorque {
	condition = "((user22 > 5) + (user48 > 5)) < 1.5";
    BAR_WARN(RPM1BAR,"PFD_Q1", 0.088,BARBOTTOM,0.01,22,135)
    BAR_WARN(RPM2BAR,"PFD_Q2", 0.185,BARBOTTOM,0.01,48,135)
};
class twinEngineSlowTorque {
	condition = "(((user22 > 5) + (user48 > 5)) > 1.5) * (speed < 41)";
    BAR_WARN(RPM1BAR,"PFD_Q1", 0.088,BARBOTTOM,0.01,22,120)
    BAR_WARN(RPM2BAR,"PFD_Q2", 0.185,BARBOTTOM,0.01,48,120)
};
class twinEngineFastTorque {
	condition = "(((user22 > 5) + (user48 > 5)) > 1.5) * (speed > 41)";
    BAR_WARN(RPM1BAR,"PFD_Q1", 0.088,BARBOTTOM,0.01,22,100)
    BAR_WARN(RPM2BAR,"PFD_Q2", 0.185,BARBOTTOM,0.01,48,100)
};



class HSIPage {
	condition = COND_SUBPAGE(MFD_PAGE_INDEX,PFD_MODE_HSI);
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
	class PolygonBack {
		type        = "polygon";
		texture = "z\vtx\addons\uh60_mfd\data\PFD_HSI_Back.paa";
		points[] ={
			{
				{{0, 0},1},
				{{1, 0},1},
				{{1, 1},1},
				{{0, 1},1}
			}
		};
	};
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
	TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"ARC")
}; // HSIPage

class ARCPageText {
	condition = COND_SUBPAGE(MFD_PAGE_INDEX,PFD_MODE_ARC);
	TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"HOVER")
};

#define PFD_ARC_RADIUS 0.31
class ARCPage {
	clipTL[] = {0.347,0.581};
	clipBR[] = {0.657,1.000};
	condition = COND_SUBPAGE(MFD_PAGE_INDEX,PFD_MODE_ARC);
	class PolygonHeading {
		type        = "polygon";
		texture = "z\vtx\addons\uh60_mfd\data\HSI.paa";
		points[] ={
			{
				{"ARC_HeadingRotation",{-PFD_ARC_RADIUS * 1, PFD_ARC_RADIUS},1},
				{"ARC_HeadingRotation",{PFD_ARC_RADIUS * 1, PFD_ARC_RADIUS},1},
				{"ARC_HeadingRotation",{PFD_ARC_RADIUS * 1, -PFD_ARC_RADIUS},1},
				{"ARC_HeadingRotation",{-PFD_ARC_RADIUS * 1, -PFD_ARC_RADIUS},1}
			}
		}; // points
	}; // PolygonHeading
	class HSI_FMS {
		color[] = common_green;
		class Line {
			type="line";
			width = 3;
			points[] ={
				{"ARC_HeadingRotation",{"WaypointDirection",0,     -0.15+-0.1},1},
				{"ARC_HeadingRotation",{"WaypointDirection",0,     -0.15+-0.05},1},{},
				{"ARC_HeadingRotation",{"WaypointDirection",-0.01, -0.15+-0.040},1},
				{"ARC_HeadingRotation",{"WaypointDirection", 0.00, -0.15+-0.05},1},
				{"ARC_HeadingRotation",{"WaypointDirection", 0.01, -0.15+-0.040},1},{},
				{"ARC_HeadingRotation",{"WaypointDirection", 0.005,-0.15+-0.045},1},
				{"ARC_HeadingRotation",{"WaypointDirection", 0.005,-0.15+-0.030},1},{},
				{"ARC_HeadingRotation",{"WaypointDirection",-0.005,-0.15+-0.045},1},
				{"ARC_HeadingRotation",{"WaypointDirection",-0.005,-0.15+-0.030},1},{},
			};
		};
	}; // HSI_FMS
	class WhiteLine {
		type="line";
		width = 3;
		points[] ={
			{"PFD_ARC_CENTER", {-0.02, -0.00+0}, 1},
			{"PFD_ARC_CENTER", { 0.02, -0.00+0}, 1},{},
			{"PFD_ARC_CENTER", {0,     -0.00+-0.01}, 1},
			{"PFD_ARC_CENTER", {0,     -0.00+0.03}, 1},
			{"PFD_ARC_CENTER", {0.01,  -0.00+0.03}, 1}
		};
	};

	#include "waypoints.hpp"
};

class HVRPage {
	condition = COND_SUBPAGE(MFD_PAGE_INDEX,PFD_MODE_HVR);
	TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"HSI")
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
	class lineClip {
		clipTL[] = {0.347,0.581};
		clipBR[] = {0.657,0.994};
		class PolygonBack {
			type        = "polygon";
			texture = "z\vtx\addons\uh60_mfd\data\PFD_HSI_Back.paa";
			points[] ={
				{
					{{0, 0},1},
					{{1, 0},1},
					{{1, 1},1},
					{{0, 1},1}
				}
			};
		};
		class purple {
			color[]={0.3,0.065,0.140,0.002};
			class HoverLines {
				type="line";
				width = 3;
				points[] ={
					{"PFD_HSI_CENTER", {"PFD_HOVER_VEL_X", 0, -0.5}, 1},
					{"PFD_HSI_CENTER", {"PFD_HOVER_VEL_X", 0,  0.5}, 1},{},
					{"PFD_HSI_CENTER", {"PFD_HOVER_VEL_Y", -0.5, 0}, 1},
					{"PFD_HSI_CENTER", {"PFD_HOVER_VEL_Y",  0.5, 0}, 1},{}
				};
			};
		};
		class HoverPoint {
			type="line";
			width = 3;
			points[] ={
				{"PFD_WP_DIST",1,"PFD_WP_VEH_DIR",1,"PFD_WP_DIR", 1,{0.75*STAR_INNER_SCALE*-0.015,STAR_INNER_SCALE*-0.015},1},
				{"PFD_WP_DIST",1,"PFD_WP_VEH_DIR",1,"PFD_WP_DIR", 1,{0.75*0     ,-0.020},1},
				{"PFD_WP_DIST",1,"PFD_WP_VEH_DIR",1,"PFD_WP_DIR", 1,{0.75*STAR_INNER_SCALE*0.015, STAR_INNER_SCALE*-0.015},1},
				{"PFD_WP_DIST",1,"PFD_WP_VEH_DIR",1,"PFD_WP_DIR", 1,{0.75*0.020,  0},1},
				{"PFD_WP_DIST",1,"PFD_WP_VEH_DIR",1,"PFD_WP_DIR", 1,{0.75*STAR_INNER_SCALE*0.015,  STAR_INNER_SCALE*0.015},1},
				{"PFD_WP_DIST",1,"PFD_WP_VEH_DIR",1,"PFD_WP_DIR", 1,{0.75*0     , 0.020},1},
				{"PFD_WP_DIST",1,"PFD_WP_VEH_DIR",1,"PFD_WP_DIR", 1,{0.75*STAR_INNER_SCALE*-0.015, STAR_INNER_SCALE*0.015},1},
				{"PFD_WP_DIST",1,"PFD_WP_VEH_DIR",1,"PFD_WP_DIR", 1,{0.75*-0.020,  0},1},
				{"PFD_WP_DIST",1,"PFD_WP_VEH_DIR",1,"PFD_WP_DIR", 1,{0.75*STAR_INNER_SCALE*-0.015, STAR_INNER_SCALE*-0.015},1}
			};
		};
	};
};

class EGI_MASK {
	condition = "0";
	color[] = common_black;
	class Polygon {
		type        = "polygon";
		points[] ={
			{
				{{0.7, 0},1},
				{{0.9, 0},1},
				{{0.9, 0.4},1},
				{{0.7, 0.4},1}
			}
		};
	};
	class text {
		color[] = common_white;
        TEXT_MID_SCALED(TEXT,0.87,0.2,"RALT OFF",0.06)
	};
};
