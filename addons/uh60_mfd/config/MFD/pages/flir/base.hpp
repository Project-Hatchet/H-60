COLORED_POLYGON(TopEdge,0,0,1,0.05,common_black)
COLORED_POLYGON(leftEdge,0,0,(0.05*3/4),1,common_black)
COLORED_POLYGON(bottomEdge,0,1,1,-0.05,common_black)
COLORED_POLYGON(rightEdge,1,0,(-0.05*3/4),1,common_black)
class flirPage {

	class DirElevTapeBackground {
		color[] = common_black;
		COLORED_POLYGON(HeadingBG,0.2,0.01,0.59,0.13,common_black)
		COLORED_POLYGON(ElevBG,0.01,0.40,0.13,0.3,common_black)
		class white {
			color[] = common_white;
			class HeadingTape {
				type="line";
				width = 2;
				points[] ={
					// base line
					{{0.25,  0.08},1},
					{{0.75,  0.08},1},{},
					// big notches at ends
					{{0.25, 0.08},1},
					{{0.25, 0.04},1},{},
					{{0.75, 0.08},1},
					{{0.75, 0.04},1},{},
					// halfway notches
					{{0.5-0.125, 0.08},1},
					{{0.5-0.125, 0.04},1},{},
					{{0.5+0.125, 0.08},1},
					{{0.5+0.125, 0.04},1},{},
					// small notches first set
					{{0.5-(0.125*0.33), 0.08},1},
					{{0.5-(0.125*0.33), 0.06},1},{},
					{{0.5-(0.125*0.66), 0.08},1},
					{{0.5-(0.125*0.66), 0.06},1},{},
					{{0.5+(0.125*0.33), 0.08},1},
					{{0.5+(0.125*0.33), 0.06},1},{},
					{{0.5+(0.125*0.66), 0.08},1},
					{{0.5+(0.125*0.66), 0.06},1},{},
					// small notches second set
					{{0.5-0.125-(0.125*0.33), 0.08},1},
					{{0.5-0.125-(0.125*0.33), 0.06},1},{},
					{{0.5-0.125-(0.125*0.66), 0.08},1},
					{{0.5-0.125-(0.125*0.66), 0.06},1},{},
					{{0.5+0.125+(0.125*0.33), 0.08},1},
					{{0.5+0.125+(0.125*0.33), 0.06},1},{},
					{{0.5+0.125+(0.125*0.66), 0.08},1},
					{{0.5+0.125+(0.125*0.66), 0.06},1},{},
					// heading box
					{{0.5-0.027, 0.02},1},
					{{0.5+0.027, 0.02},1},
					{{0.5+0.027, 0.06},1},
					{{0.5-0.027, 0.06},1},
					{{0.5-0.027, 0.02},1}
				};
			};
			class right_bounds {
				condition="[x]pilotcamera > 90";
				TEXT_MID_SCALED_SRC(HEADING,0.7,0.08,0.04)
						source="[x]pilotcamera";
						sourceScale = 1;
				}; // HEADING
				TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_6,0.5,0.5,0.04)
					source="static";
					text="TEST";
					sourceScale = 1;
				};
			};
			class left_bounds {
				condition="[x]pilotcamera < -90";
				TEXT_MID_SCALED_SRC(HEADING,0.3,0.08,0.04)
						source="[x]pilotcamera";
						sourceScale = 1;
				}; // HEADING
			};

			TEXT_MID_SCALED(LEFT_FLIR_90,0.23,0.05,"-90",0.04)
			TEXT_MID_SCALED(RIGHT_FLIR_90,0.77,0.05,"+90",0.04)
			class headingArrow {
				type        = "polygon";
				points[] ={
					{
						{{0.5-0.01,0.06},1},
						{{0.5+0.00,0.08},1},
						{{0.5+0.01,0.06},1}
					}
				};
			};

			TEXT_MID_SCALED_SRC(HEADING,0.5,0.02,0.04)
					source="heading";
					sourceScale = 1;
			}; // HEADING


			TEXT_MID_SCALED(FLIR_ELEV_TOP,0.04,0.43-0.02,"+40",0.04)
			TEXT_MID_SCALED(FLIR_ELEV_MID,0.04,0.50-0.02,"0",0.04)
			TEXT_MID_SCALED(FLIR_ELEV_BOT,0.04,0.67-0.02,"-90",0.04)
			class ElevationTape {
				type="line";
				width = 2;
				points[] ={
					// base line
					{{0.08,  0.43},1},
					{{0.08,  0.67},1},{},
					// notches
					{{0.06, 0.43},1},
					{{0.08, 0.43},1},{},
					{{0.06, 0.5},1},
					{{0.08, 0.5},1},{},
					{{0.06, 0.5+(0.0425*1)},1},
					{{0.08, 0.5+(0.0425*1)},1},{},
					{{0.06, 0.5+(0.0425*2)},1},
					{{0.08, 0.5+(0.0425*2)},1},{},
					{{0.06, 0.5+(0.0425*3)},1},
					{{0.08, 0.5+(0.0425*3)},1},{},
					{{0.06, 0.67},1},
					{{0.08, 0.67},1},{}
				};
			};
			class RotX{
				type="text";
				source="[x]pilotcamera";
				scale=1;
				sourceScale=1;
				sourcePrecision=0;
				align = "center";
				pos[]= {"FLIR_DIR_BONE", {0.0, "0.0"}, 1};
				right[]= {"FLIR_DIR_BONE", {0.04*3/4, "0.0"}, 1};
				down[]= {"FLIR_DIR_BONE", {0.0, 0.04}, 1};
			};
			class RotY{
				type="text";
				source="[y]pilotcamera";
				scale=1;
				sourceScale=1;
				sourcePrecision=0;
				align = "center";
				pos[]= {"FLIR_ELEV_BONE", {0.0+(0.04*3/4), 0.0-0.02}, 1};
				right[]= {"FLIR_ELEV_BONE", {0.04+(0.04*3/4), 0.0-0.02}, 1};
				down[]= {"FLIR_ELEV_BONE", {0.0+(0.04*3/4), 0.04-0.02}, 1};
			};

			class TargetDirMarker {
				type="line";
				width = 2;
				points[] ={
					{"FLIR_DIR_BONE", {-0.02, 0+0.0},1},
					{"FLIR_DIR_BONE", {0.00, 0-0.02},1},
					{"FLIR_DIR_BONE", {0.02, 0+0.0},1}
				};
			};
			class TargetElevMarker {
				type="line";
				width = 2;
				points[] ={
					{"FLIR_ELEV_BONE", {0.02*0.75,  0-0.02},1},
					{"FLIR_ELEV_BONE", {0.0, 0-0.00},1},
					{"FLIR_ELEV_BONE", {0.02*0.75,  0+0.02},1}
				};
			};
		}; // white
	}; // DirElevTapeBackground


	class crossBackground {
		color[] = common_black;
		class TargetCross {
			type="line";
			width = 5;
			points[] ={
				{{0.5-(0.10*0.75), 0.5},1},
				{{0.5-(0.02*0.75), 0.5},1},{},
				{{0.5+(0.10*0.75), 0.5},1},
				{{0.5+(0.02*0.75), 0.5},1},{},
				{{0.5, 0.5-0.10},1},
				{{0.5, 0.5-0.02},1},{},
				{{0.5, 0.5+0.10},1},
				{{0.5, 0.5+0.02},1},{}
			};
		};
		class white {
			color[] = common_white;
			class TargetCross {
				type="line";
				width = 2;
				points[] ={
					{{0.5-(0.10*0.75), 0.5},1},
					{{0.5-(0.02*0.75), 0.5},1},{},
					{{0.5+(0.10*0.75), 0.5},1},
					{{0.5+(0.02*0.75), 0.5},1},{},
					{{0.5, 0.5-0.10},1},
					{{0.5, 0.5-0.02},1},{},
					{{0.5, 0.5+0.10},1},
					{{0.5, 0.5+0.02},1},{}
				};
			};
		};
	};

	class flirDamage {
		condition = FLIR_DISABLED;
		class PolygonJet {
			type        = "polygon";
			texture = "z\vtx\addons\uh60_mfd\data\FLIR_Cracked.paa";
			points[] ={
				{
					{{-1, -1},1},
					{{ 2, -1},1},
					{{ 2,  2},1},
					{{-1,  2},1}
				}
			};
		};
		class blackBackground {
			color[] = common_black;
			class bottomPoly {
				type        = "polygon";
				points[] ={
					{
						{{0, 0.95},1},
						{{1, 0.95},1},
						{{1, 1},1},
						{{0, 1},1}
					}
				};
			};
			class errorPoly {
				type        = "polygon";
				points[] ={
					{
						{{0.5 - 0.10, 0.4 - 0.00},1},
						{{0.5 + 0.10, 0.4 - 0.00},1},
						{{0.5 + 0.10, 0.4 + 0.04},1},
						{{0.5 - 0.10, 0.4 + 0.04},1}
					}
				};
			};
			class whiteOverlay {
				color[] = common_white;
				class outline {
					type="line";
					width = 2;
					points[] ={
						{{0.5 - 0.10, 0.4 - 0.00},1},
						{{0.5 + 0.10, 0.4 - 0.00},1},
						{{0.5 + 0.10, 0.4 + 0.04},1},
						{{0.5 - 0.10, 0.4 + 0.04},1},
						{{0.5 - 0.10, 0.4 - 0.00},1}
					};
				};
				TEXT_MID_SCALED(FLIR_FAIL,0.5,0.4,"FLIR FAIL",0.04)
				TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
				TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
				TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

				TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
				TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"IVHMS")
				TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
				TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")
			};
		};
	}; // overlayWrapper


	class GndStab {
		condition = "pilotcameralock";
		color[] = common_black;
		COLORED_POLYGON(PB1,0.2,0.2,0.2,0.04,common_black)
		BOXEDTEXT_USER(TEXT_TAPE,0.5,0.17,0.5,0.04,10,"1")
		class white {
			color[] = common_white;
			TEXT_MID_SCALED(LRD_LASE_TXT,0.3,0.2,"GND STAB",0.04)
			class Border {
				type="line";
				width = 2;
				points[] ={
					{{0.3 - 0.10, 0.2 - 0.00},1},
					{{0.3 + 0.10, 0.2 - 0.00},1},
					{{0.3 + 0.10, 0.2 + 0.04},1},
					{{0.3 - 0.10, 0.2 + 0.04},1},
					{{0.3 - 0.10, 0.2 - 0.00},1}
				};
			}; // Border
		}; // whtie
	}; // GndStab
	class PntTrk {
		condition = "pilotcameralock>1";
		color[] = common_black;
		COLORED_POLYGON(PB1,0.6,0.2,0.2,0.04,common_black)
		class white {
			color[] = common_white;
			TEXT_MID_SCALED(LRD_LASE_TXT,0.7,0.2,"PNT TRK",0.04)
			class Border {
				type="line";
				width = 2;
				points[] ={
					{{0.7 - 0.10, 0.2 - 0.00},1},
					{{0.7 + 0.10, 0.2 - 0.00},1},
					{{0.7 + 0.10, 0.2 + 0.04},1},
					{{0.7 - 0.10, 0.2 + 0.04},1},
					{{0.7 - 0.10, 0.2 - 0.00},1}
				};
			}; // Border
		}; // whtie
	}; // GndStab

	// BOXEDTEXT(STA1,0.06,BEZEL_Y5,0.1,0.04,"STA 1","1")
	// BOXEDTEXT(STA2,0.93,BEZEL_Y5,0.1,0.04,"STA 2","1")
	// BOXEDTEXT(STA3,0.06,BEZEL_Y6,0.1,0.04,"STA 3","1")
	// BOXEDTEXT(STA4,0.93,BEZEL_Y6,0.1,0.04,"STA 4","1")
	
	// BOXEDTEXT(LSR_SEL,BEZEL_XT1,0.05,0.1,0.04,"LSR","1")
	// BOXEDTEXT(GUN_SEL,BEZEL_XT6,0.05,0.1,0.04,"GUNS","1")
	
	BOXEDTEXT(LSR_SEL,BEZEL_XT1,0.05,0.1,0.04,"LSR","1")
	BOXEDTEXT(GUN_SEL,0.06,BEZEL_Y1,0.1,0.04,"GUN","1")
	BOXEDTEXT(RKT_SEL,0.06,BEZEL_Y2,0.1,0.04,"RKT","1")
	BOXEDTEXT(MSL_SEL,0.06,BEZEL_Y5,0.1,0.04,"MSL","1")

	#define BOTTOM_TEXT_Y 0.96

	#include "sidebar.hpp"
	#include "weapons.hpp"

	class bottom {
		COLORED_POLYGON(PB1,(BEZEL_XB1-0.02),0.995-TAC_LINE_HEIGHT,0.04,0.04,common_black)
		COLORED_POLYGON(PB2,(BEZEL_XB2-0.015),0.995-TAC_LINE_HEIGHT,0.03,0.04,common_black)
		COLORED_POLYGON(PB3,(BEZEL_XB3-0.03),0.995-TAC_LINE_HEIGHT,0.06,0.04,common_black)
		COLORED_POLYGON(PB4,(BEZEL_XB4-0.025),0.995-TAC_LINE_HEIGHT,0.05,0.04,common_black)
		COLORED_POLYGON(PB5,(BEZEL_XB5-0.02),0.995-TAC_LINE_HEIGHT,0.04,0.04,common_black)
		COLORED_POLYGON(PB6,(BEZEL_XB6-0.03),0.995-TAC_LINE_HEIGHT,0.06,0.04,common_black)

		class white {
			color[] = common_white;
			TEXT_LEFT_SCALED(B1,(BEZEL_XB1-0.02+0.005),BOTTOM_TEXT_Y,"PFD",TAC_LINE_HEIGHT)
			TEXT_LEFT_SCALED(B2,(BEZEL_XB2-0.015+0.005),BOTTOM_TEXT_Y,"ND",TAC_LINE_HEIGHT)
			TEXT_LEFT_SCALED(B3,(BEZEL_XB3-0.03+0.005),BOTTOM_TEXT_Y,"EICAS",TAC_LINE_HEIGHT)
			TEXT_LEFT_SCALED(B6,(BEZEL_XB4-0.025+0.005),BOTTOM_TEXT_Y,"FLIR",TAC_LINE_HEIGHT)
			TEXT_LEFT_SCALED(B7,(BEZEL_XB5-0.02+0.005),BOTTOM_TEXT_Y,"TAC",TAC_LINE_HEIGHT)
			TEXT_LEFT_SCALED(B8,(BEZEL_XB6-0.03+0.005),BOTTOM_TEXT_Y,"JVMF",TAC_LINE_HEIGHT)
		};
	};
};