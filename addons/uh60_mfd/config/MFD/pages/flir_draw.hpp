class FLIR {
    // condition = "1";
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
    class MissileSelected {
        condition = "missile";
        class LOBL {
            type="line";
            width = 2;
            points[] ={
                {"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1},
                {"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0+0.025},1},
                {"FLIR_HELLFIRE_REF", {00.025*(3/4), 0+0.025},1},
                {"FLIR_HELLFIRE_REF", {00.025*(3/4), 0-0.025},1},
                {"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1}
            };
        };
    }; // MissileSelected


    TEXT_MID_SCALED_SRC(WPN_SEL_VAL,0.5,0.7,0.04)
        source="weapon";
        sourceScale = 1;
    }; // WPN_SEL_VAL
    class SHOW_AMMO {
        condition = "mgun+missile+aamissile+atmissile+rocket+bomb";
        TEXT_LEFT_SCALED_SRC(AMMO_VAL,0.4,0.7,0.04)
            source="ammo";
            sourceScale = 1;
        }; // AMMO_VAL
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
};


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

TEXT_LEFT_SCALED_SRC(FLIR_TYPE,0.05,0.1,0.04)
        source="flirMode";
        sourceScale = 1;
}; // FLIR_TYPE
TEXT_LEFT_SCALED_SRC(VISMODE,0.05,0.15,0.04)
        source="visionMode";
        sourceScale = 1;
}; // VISMODE


TEXT_RIGHT_SCALED_SRC(DATE,0.95,0.1,0.04)
        source="time";
        text="%x";
        sourceScale = 1;
}; // DATE
TEXT_RIGHT_SCALED_SRC(TIME,0.95,0.15,0.04)
        source="time";
        text="%X";
        sourceScale = 1;
}; // TIME

TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_1,0.95,0.3,0.04)
    source="static";
    text="MODE[DIR]";
    sourceScale = 1;
};
TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_2,0.95,0.35,0.04)
    source="static";
    text="NEXT MSL";
    sourceScale = 1;
};
TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_6,0.95,0.40,0.04)
    source="static";
    text="DES[AUT]:A";
    sourceScale = 1;
};
TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_7,0.95,0.45,0.04)
    source="static";
    text="TRK[ PNT ]";
    sourceScale = 1;
};
TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_8,0.95,0.55,0.04)
    source="static";
    text="WPN ARM";
    sourceScale = 1;
};

TEXT_RIGHT_SCALED_SRC(LASERDIST,0.95,0.9,0.04)
        source="laserDist";
        sourceScale = 1;
}; // LASERDIST


class LaserOn {
    condition = "laseron";
    blinkingPattern[] = {0.5, 0.5};
    TEXT_MID_SCALED(LRD_LASE_TXT,0.5,0.2,"LRD LASE DES",0.04)
    class Border {
    	type="line";
    	width = 2;
    	points[] ={
    		{{0.5 - 0.10, 0.2 - 0.00},1},
            {{0.5 + 0.10, 0.2 - 0.00},1},
            {{0.5 + 0.10, 0.2 + 0.04},1},
            {{0.5 - 0.10, 0.2 + 0.04},1},
    		{{0.5 - 0.10, 0.2 - 0.00},1}
    	};
    }; // Border
}; // LaserOn


class Pylon1
{
    type = "pylonicon";
    pos[] = {{0.4,0.8},1};
    pylon = 1;
    name = "VTX_H60";
};
class Pylon2
{
    type = "pylonicon";
    pos[] = {{0.6,0.8},1};
    pylon = 2;
    name = "VTX_H60";
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
            // TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
            // TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
            // TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

            // TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
            TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"IVHMS")
            // TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
            // TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")
        };
    };
}; // overlayWrapper

#define BOTTOM_TEXT_Y 0.96
// TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
// TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
// TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

// TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"IVHMS")
// TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
// TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")
