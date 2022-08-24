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