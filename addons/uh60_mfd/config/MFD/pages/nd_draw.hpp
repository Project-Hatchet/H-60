
alpha = 0.65;
class overlayWrapper {
	class PolygonJet {
		type        = "polygon";
		texture = "z\vtx\addons\uh60_mfd\data\ND.paa";
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


TEXT_MID_MID_SRC(HDG_TXT,0.396,0.05)
	sourceScale = 1;
	source="heading";
};
#define ND_HSI_SIZE 0.28
class PolygonHeading {
	type        = "polygon";
	texture = "z\vtx\addons\uh60_mfd\data\HSI.paa";
	points[] ={
		{
			{"ND_HeadingRotation",{-ND_HSI_SIZE * 1, ND_HSI_SIZE},1},
			{"ND_HeadingRotation",{ND_HSI_SIZE * 1, ND_HSI_SIZE},1},
			{"ND_HeadingRotation",{ND_HSI_SIZE * 1, -ND_HSI_SIZE},1},
			{"ND_HeadingRotation",{-ND_HSI_SIZE * 1, -ND_HSI_SIZE},1}
		}
	}; // points
}; // PolygonHeading


TEXT_MID_MID_SRC(RALT_TXT,0.87,0.12)
	source="altitudeAGL";
	sourceScale = 3.2808399;
	sourceLength = 4;
};

class flightdirector_purple {
	color[]={0.3,0.065,0.140,0.002};
	alpha=0.9;
	TEXT_DEFAULT_PFD(FDRALT_TXT,0.899,0.353)
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
					{"FD_ND_RALTRotation1",{0, "0.107-0.016"},1},
					{"FD_ND_RALTRotation1",{-0.016, "0.107-0.016"},1},
					{"FD_ND_RALTRotation1",{-0.016, "0.118-0.016"},1},
					{"FD_ND_RALTRotation1",{-0.009, "0.118-0.016"},1}
				}
			};
		}; // FD_RALTArm1
		class FD_RALTArm2 {
			type="polygon";
			points[] ={
				{
					{"FD_ND_RALTRotation1",{0, "0.107-0.016"},1},
					{"FD_ND_RALTRotation1",{0.016, "0.107-0.016"},1},
					{"FD_ND_RALTRotation1",{0.016, "0.118-0.016"},1},
					{"FD_ND_RALTRotation1",{0.009, "0.118-0.016"},1}
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
					{"FD_ND_RALTRotation2",{0, "0.107-0.016"},1},
					{"FD_ND_RALTRotation2",{-0.016, "0.107-0.016"},1},
					{"FD_ND_RALTRotation2",{-0.016, "0.118-0.016"},1},
					{"FD_ND_RALTRotation2",{-0.009, "0.118-0.016"},1}
				}
			};
		}; // FD_RALTArm1
		class FD_RALTArm2 {
			type="polygon";
			points[] ={
				{
					{"FD_ND_RALTRotation2",{0, "0.107-0.016"},1},
					{"FD_ND_RALTRotation2",{0.016, "0.107-0.016"},1},
					{"FD_ND_RALTRotation2",{0.016, "0.118-0.016"},1},
					{"FD_ND_RALTRotation2",{0.009, "0.118-0.016"},1}
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
					{"FD_ND_RALTRotation3",{0, "0.107-0.016"},1},
					{"FD_ND_RALTRotation3",{-0.016, "0.107-0.016"},1},
					{"FD_ND_RALTRotation3",{-0.016, "0.118-0.016"},1},
					{"FD_ND_RALTRotation3",{-0.009, "0.118-0.016"},1}
				}
			};
		}; // FD_RALTArm1
		class FD_RALTArm2 {
			type="polygon";
			points[] ={
				{
					{"FD_ND_RALTRotation3",{0, "0.107-0.016"},1},
					{"FD_ND_RALTRotation3",{0.016, "0.107-0.016"},1},
					{"FD_ND_RALTRotation3",{0.016, "0.118-0.016"},1},
					{"FD_ND_RALTRotation3",{0.009, "0.118-0.016"},1}
				}
			};
		}; // FD_RALTArm2
	}; // FD_RALTRotation3Cond
}; // flightdirector_purple


class RALTRotation1Cond {
	condition="(altitudeAGL*3.2808399) < 100";
	class RaltArm {
		type="line";
		width = 7;
		points[] ={
			{"ND_RALTRotation1",{0, 0.04},1},{"ND_RALTRotation1",{0, 0.06},1}
		};
	}; // RaltArm
	class RaltArm2 {
		type="line";
		width = 3;
		points[] ={
			{"ND_RALTRotation1",{0, 0.04},1},{"ND_RALTRotation1",{0, 0.08},1}
		};
	}; // RaltArm2
}; // RALTRotation1Cond
class RALTRotation2Cond {
	condition="((altitudeAGL*3.2808399) > 100) * ( (altitudeAGL*3.2808399) < 400 )";
	class RaltArm {
		type="line";
		width = 7;
		points[] ={
			{"ND_RALTRotation2",{0, 0.04},1},{"ND_RALTRotation2",{0, 0.06},1}
		};
	}; // RaltArm
	class RaltArm2 {
		type="line";
		width = 3;
		points[] ={
			{"ND_RALTRotation2",{0, 0.04},1},{"ND_RALTRotation2",{0, 0.08},1}
		};
	}; // RaltArm2
}; // RALTRotation2Cond
class RALTRotation3Cond {
	condition="(altitudeAGL*3.2808399) > 400";
	class RaltArm {
		type="line";
		width = 7;
		points[] ={
			{"ND_RALTRotation3",{0, 0.04},1},{"ND_RALTRotation3",{0, 0.06},1}
		};
	}; // RaltArm
	class RaltArm2 {
		type="line";
		width = 3;
		points[] ={
			{"ND_RALTRotation3",{0, 0.04},1},{"ND_RALTRotation3",{0, 0.08},1}
		};
	}; // RaltArm2
}; // RALTRotation3Cond


//wind
TEXT_LEFT_SMALL(GS_TXT,0.08,0.05+0.015,"GS")
TEXT_MID_MID_SRC(GS_VAL,0.08+0.035,0.05)
	source="speed";
	sourceScale = 1.94384;
	sourceLength = 3;
};
TEXT_MID_MID_SRC(WIND_VAL,0.1,0.1)
	source="userText";
	sourceScale=1;
	sourceIndex=9;
};
class windArm {
	type="line";
	width = 3;
	points[] ={
		{"ND_HeadingRotationWind",{"ND_RotationWind",0, 0.015},1},
		{"ND_HeadingRotationWind",{"ND_RotationWind",0, -0.015},1}
	};
}; // windArm
class windArrow {
	type="polygon";
	points[] ={
		{
			{"ND_HeadingRotationWind",{"ND_RotationWind",0, -0.016},1},
			{"ND_HeadingRotationWind",{"ND_RotationWind",0.008, -0.007},1},
			{"ND_HeadingRotationWind",{"ND_RotationWind",-0.008, -0.007},1}
		}
	};
}; // windArrow

#define MOVE_X 0.087
#define MOVE_Y -0.276
//FMS stuff
TEXT_MID_MID(NAV_FMS_LABEL,MOVE_X+0.72,MOVE_Y+0.72,"FMS1")
TEXT_LEFT_MID_SRC(NAV_FMS_WP_LABEL,MOVE_X+0.685,MOVE_Y+0.76)
	source="userText";
	sourceScale=1;
	sourceIndex=7;
};
TEXT_LEFT_MID_SRC(NAV_FMS_WP_DIR,MOVE_X+0.75,MOVE_Y+0.80)
	source="user";
	sourceIndex=0;
	sourceScale=1;
};
TEXT_MID_MID_SRC(NAV_FMS_WP_DIST,MOVE_X+0.705,MOVE_Y+0.833)
	source="WPDist";
	sourceScale=0.000539957;
	sourceLength=3;
	sourcePrecision=1;
};
TEXT_LEFT_MID_SRC(NAV_FMS_WP_TOF,MOVE_X+0.75,MOVE_Y+0.87)
	source="userText";
	sourceScale=1;
	sourceIndex=8;
};


// CMWS
class ND_CMWS
{
	type = "sensor";
	pos[]	= {{0,0},1};
	down[]	= {{0,0},1};
	// pos[]	= {ND_CMWS_Offset,{(0+SIZE)*0.725, 0+SIZE}, 1};
	// down[]	= {ND_CMWS_Offset,{(0-SIZE)*0.725, 0-SIZE}, 1};

	showTargetTypes = 1+2+8+64+1024;    // RWR only
	//showTargetTypes = 1+2+4+8+16+32+64+128+256+512+1024;
	width = 1; // default width of lines can by different in case of class XXXX used instead of arrays
	range=4000;
	sensorLineType = 2; // same as "lineType"
	sensorLineWidth = 3;
	class MissileThreat
	{
		color[] = {1,0,0};
		class MissleText{
			type="text";
			source="static";
			text="M";
			scale=1;
			sourceScale=1;
			align = "center";
			pos[]= {{0.00, -0.015}, 1};
			right[]= {{0.06, -0.015}, 1};
			down[]= {{0.00, 0.015}, 1};
		};
		class MissileBox
		{
			type = "line";
			width = 5.0000;
			points[] ={
				{{-0.015, -0.015},1},
				{{0.015, -0.015},1},
				{{0.015, 0.015},1},
				{{-0.015, 0.015},1},
				{{-0.015, -0.015},1}
			};
		};
	};
	class markingThreat
	{
		color[] = {1,1,0}; // radar is tracking you actively
		class background {
			type        = "polygon";
			points[] ={
				{
					{{-0.015, 0.015},1},
					{{0.015, 0.015},1},
					{{0.015, -0.015},1},
					{{-0.015, -0.015},1}
				}
			}; // points
		}; // background
		class unknownTarget
		{
			type = "line";
			width = 5.0000;
			points[] ={
				{{-0.015, -0.015},1},
				{{0.015, -0.015},1},
				{{0.015, 0.015},1},
				{{-0.015, 0.015},1},
				{{-0.015, -0.015},1},{},
				{{-0.002, -0.002},1},
				{{0.002, 0.002},1},{},
				{{-0.002, 0.002},1},
				{{0.002, -0.002},1}
			};
		};
	};
	class lockingThreat
	{
		color[] = {1,0,0};
		class background {
			type        = "polygon";
			points[] ={
				{
					{{-0.015, 0.015},1},
					{{0.015, 0.015},1},
					{{0.015, -0.015},1},
					{{-0.015, -0.015},1}
				}
			}; // points
		}; // background
		class TargetBox
		{
			type = "line"; // locking, you're in for a bad time
			width = 5.0000;
			points[] ={
				{{-0.015,0},1},
				{{0, -0.015 },1},
				{{0.015,0 },1},
				{{0, 0.015 },1},
				{{-0.015,0},1},{},
				{{-0.005,0.005},1},
				{{0,-0.005},1},
				{{0.005,0.005},1}
			};
		};
	};
	//rwr
	class rwr
	{
		class TargetBox
		{
			type = "line"; // there's a radar, but stuff isn't happening yet
			width = 5.0000;
			points[] ={
				{{-0.015, -0.015},1},
				{{0.015, -0.015},1},
				{{0.015, 0.015},1},
				{{-0.015, 0.015},1},
				{{-0.015, -0.015},1},{},
				{{-0.005,0.005},1},
				{{0,-0.005},1},
				{{0.005,0.005},1}
			};
		};
	};
	class rwrFriendly: rwr
	{
		color[]	= common_green;
	};
	class rwrEnemy: rwr
	{
		color[]	= common_red;
	};
	//ground
	class targetGround
	{
		class TargetBox { };
	};
	class targetAir
	{
	};
}; // CMWS

// Waypoints

class NOT_AIRCRAFT_CENTERED {
    condition = (user18 > 0);
	TEXT_MID_SMALL(GS_TXT,0.4,0.9,"ALIGN TAC TO SELF TO SEE WAYPOINTS")
};

class AIRCRAFT_CENTERED {
    condition = ((user18 > -1) * (user18 < 1));
	clipTL[] = {0.1,0.1};
	clipBR[] = {0.7,0.9};
	class HAS_NO_PREVWP {
		condition = ((user2 < 0) * (user4 > -1));
		color[]={0,1,0,1};
		class WP1_Line_back {
			type="line";
			width = 2;
			points[] ={
				{"ND_CENTER", 1},
				{"ND_WP2_DIST", 1, "ND_WP2_Dir", 1},{},
				SHAPE_SQUARE("ND_WP1_DIST","ND_WP1_Dir"),{},
				SHAPE_SQUARE("ND_WP2_DIST","ND_WP2_Dir")
			};
		}; // WP1_Line
	};

	class HAS_WP1_2 {
		condition = ((user2 > -1) * (user4 > -1));
		color[]=common_purple;
		class WP1_Line_back {
			type="line";
			width = 2;
			points[] ={
				{"ND_WP1_DIST", 1, "ND_WP1_Dir", 1},
				{"ND_WP2_DIST", 1, "ND_WP2_Dir", 1},{},
				SHAPE_SQUARE("ND_WP1_DIST","ND_WP1_Dir"),{},
				SHAPE_SQUARE("ND_WP2_DIST","ND_WP2_Dir")
			};
		}; // WP1_Line
	}; // cond

	#define SHAPE_WAYPT(DIST,DIR) \
		{DIST, 1, DIR, 1, { 0   , -0.001},1}, \
		{DIST, 1, DIR, 1, { 0   ,  0.001},1},{}, \
		{DIST, 1, DIR, 1, { 0   , -0.025},1}, \
		{DIST, 1, DIR, 1, { 0.025, 0.0},1}, \
		{DIST, 1, DIR, 1, { 0.015, 0.015},1}, \
		{DIST, 1, DIR, 1, {-0.015, 0.015},1}, \
		{DIST, 1, DIR, 1, {-0.025, 0.0},1}, \
		{DIST, 1, DIR, 1, { 0   , -0.025},1}

	#define SHAPE_DIAMOND(DIST,DIR) \
		{DIST, 1, DIR, 1,{0, 0.02},1}, \
		{DIST, 1, DIR, 1,{0.02, 0},1}, \
		{DIST, 1, DIR, 1,{0, -0.02},1}, \
		{DIST, 1, DIR, 1,{-0.02, 0},1}, \
		{DIST, 1, DIR, 1,{0, 0.02},1}

	#define SHAPE_SQUARE(DIST,DIR) \
		{DIST, 1, DIR, 1,{-0.015, -0.015},1}, \
		{DIST, 1, DIR, 1,{0.015, -0.015},1}, \
		{DIST, 1, DIR, 1,{0.015, 0.015},1}, \
		{DIST, 1, DIR, 1,{-0.015, 0.015},1}, \
		{DIST, 1, DIR, 1,{-0.015, -0.015},1}

	class HAS_CUR_WP {
		condition = (user4 > -1);
		color[] = common_purple;
		class WP_TEXT {
			type="text";
			source="userText";
			sourceIndex=7;
			scale=1;
			sourceScale=1;
			align = "center";
			text="0";
			pos[]= {"ND_WP2_DIST", 1, "ND_WP2_Dir", 1,{0, 0+0.015}, 1};
			right[]= {"ND_WP2_DIST", 1, "ND_WP2_Dir", 1,{0.035, 0+0.015}, 1};
			down[]= {"ND_WP2_DIST", 1, "ND_WP2_Dir", 1,{0, 0.035+0.015}, 1};
		};
	}; // HAS_CUR_WP
	class HAS_WP2_3 {
		condition = ((user4 > -1) * (user6 > -1));
		color[]=common_purple;
		class WP2_Line {
			type="line";
			width = 2;
			points[] ={
				{"ND_WP2_DIST", 1, "ND_WP2_Dir", 1},
				{"ND_WP3_DIST", 1, "ND_WP3_Dir", 1},{},
				SHAPE_SQUARE("ND_WP3_DIST","ND_WP3_Dir")
			};
		}; // WP2_Line
	}; // cond
	class HAS_WP3 {
		condition = ((user6 > -1) * (user8 > -1));
		color[]=common_purple;
		class WP3_Line {
			type="line";
			width = 2;
			points[] ={
				{"ND_WP3_DIST", 1, "ND_WP3_Dir", 1},
				{"ND_WP4_DIST", 1, "ND_WP4_Dir", 1},{},
			SHAPE_SQUARE("ND_WP4_DIST","ND_WP4_Dir")
			};
		}; // WP3_Line
	}; // cond
	class HAS_WP4 {
		condition = ((user8 > -1) * (user33 > -1));
		color[]=common_purple;
		class WP4_Line {
			type="line";
			width = 2;
			points[] ={
				{"ND_WP4_DIST", 1, "ND_WP4_Dir", 1},
				{"ND_WP5_DIST", 1, "ND_WP5_Dir", 1},{},
			SHAPE_SQUARE("ND_WP5_DIST","ND_WP5_Dir")
			};
		}; // WP4_Line
	}; // cond
	class HAS_WP5 {
		condition = ((user33 > -1) * (user35 > -1));
		color[]=common_purple;
		class WP5_Line {
			type="line";
			width = 2;
			points[] ={
				{"ND_WP5_DIST", 1, "ND_WP5_Dir", 1},
				{"ND_WP6_DIST", 1, "ND_WP6_Dir", 1},{},
				SHAPE_SQUARE("ND_WP6_DIST","ND_WP6_Dir")
			};
		}; // WP5_Line
	}; // cond

	class TGP_STABILIZED {
		condition = (user10 > -1);
		color[]={0,1,0,1};
		class Mark_Circle
		{
			type = "line";
			width = 2;
			points[]={
				SHAPE_DIAMOND("ND_TGP_DIST","ND_TGP_Dir")
			};
		}; // Mark_Circle
	}; // Mark_TEXT


	class NEAREST_LOCATION {
		condition = (user41 > -1);
		color[]=RGBA256(220,40,220,1);
		class Mark_Circle
		{
			type = "line";
			width = 2;
			points[]={
				SHAPE_DIAMOND("ND_LOC_DIST","ND_LOC_Dir")
			};
		}; // Mark_Circle
		
		class LOC_TEXT {
			type="text";
			source="userText";
			sourceIndex=12;
			scale=1;
			sourceScale=1;
			align = "right";
			text="0";
			pos[]= {"ND_LOC_DIST", 1, "ND_LOC_Dir", 1,{0.04 - 0.02, 0.0}, 1};
			right[]= {"ND_LOC_DIST", 1, "ND_LOC_Dir", 1,{0.085 - 0.02, 0.00}, 1};
			down[]= {"ND_LOC_DIST", 1, "ND_LOC_Dir", 1,{0.04 - 0.02, 0.045}, 1};
		};
	}; // Mark_TEXT


	class JVMF_STABILIZED {
		condition = (user43 > -1);
		color[] = common_blue;
		class Mark_Circle
		{
			type = "line";
			width = 2;
			points[]={
				SHAPE_SQUARE("ND_JVMF_DIST","ND_JVMF_Dir")
			};
		}; // Mark_Circle
		class LOC_TEXT {
			type="text";
			source="userText";
			sourceIndex=39;
			scale=1;
			sourceScale=1;
			align = "center";
			text="";
			pos[]= {"ND_JVMF_DIST", 1, "ND_JVMF_Dir", 1,{0, 0+0.015}, 1};
			right[]= {"ND_JVMF_DIST", 1, "ND_JVMF_Dir", 1,{0.035, 0+0.015}, 1};
			down[]= {"ND_JVMF_DIST", 1, "ND_JVMF_Dir", 1,{0, 0.035+0.015}, 1};
		};
	}; // JVMF_STABILIZED

};

#define BOTTOM_TEXT_Y 0.96
TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"FLIR")
TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")