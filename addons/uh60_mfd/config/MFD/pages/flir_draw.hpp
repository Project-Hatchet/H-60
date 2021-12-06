class FLIR {
    condition = "1";
    class noTrack {
        condition = "pilotcameralock<1";
    	class polygon {
    		type        = "polygon";
    		texture = "z\vtx\addons\uh60_mfd\data\FLIR_noTrack.paa";
    		points[] ={
    			{
    				{{0, 0},1},
    				{{1, 0},1},
    				{{1, 1},1},
    				{{0, 1},1}
    			}
    		};
    	};
    }; // noTrack
    class trackNoLock {
            condition = "(pilotcameralock>0) * (pilotcameralock<2)";
    	class polygon {
    		type        = "polygon";
    		texture = "z\vtx\addons\uh60_mfd\data\FLIR_noLock.paa";
    		points[] ={
    			{
    				{{0, 0},1},
    				{{1, 0},1},
    				{{1, 1},1},
    				{{0, 1},1}
    			}
    		};
    	};
    }; // trackNoLock

    class trackAndLock {
            condition = "pilotcameralock>1 ";
    	class polygon {
    		type        = "polygon";
    		texture = "z\vtx\addons\uh60_mfd\data\FLIR_lock.paa";
    		points[] ={
    			{
    				{{0, 0},1},
    				{{1, 0},1},
    				{{1, 1},1},
    				{{0, 1},1}
    			}
    		};
    	};
    }; // trackAndLock

    class RotX{
        type="text";
        source="[x]pilotcamera";
        scale=1;
        sourceScale=1;
        sourcePrecision=1;
        align = "center";
        pos[]= {{0.5, "0.08"}, 1};
        right[]= {{0.57, "0.08"}, 1};
        down[]= {{0.5, "0.14"}, 1};
    };
    class RotY{
        type="text";
        source="[y]pilotcamera";
        scale=1;
        sourceScale=1;
        sourcePrecision=1;
        align = "center";
        pos[]= {{0.15, "0.4"}, 1};
        right[]= {{0.22, "0.4"}, 1};
        down[]= {{0.15, "0.46"}, 1};
    };
    class MissileSelected {
        condition = "missile";
        TEXT_MID_MID(TOF_LBL,0.25,0.6,"TOF")
        TEXT_MID_MID_SRC(TOF_VAL,0.25,0.66)
            source="MissileFlightTime";
            sourceScale = 1;
            sourceLength = 2;
        }; // TOF_VAL
    }; // MissileSelected


    TEXT_LEFT_MID(WPN_SEL_LBL,0.35,0.7,"WPN SEL")
    TEXT_LEFT_MID_SRC(WPN_SEL_VAL,0.5,0.7)
        source="weapon";
        sourceScale = 1;
    }; // WPN_SEL_VAL
    class SHOW_AMMO {
        condition = "mgun+missile+aamissile+atmissile+rocket+bomb";
        TEXT_LEFT_MID(AMMO_LBL,0.35,0.76,"AMMO")
        TEXT_LEFT_MID_SRC(AMMO_VAL,0.5,0.76)
            source="ammo";
            sourceScale = 1;
    }; // AMMO_VAL
};

#define RIGHT_LIST_Y 0.3
TEXT_RIGHT_MID(BRG_LBL,0.9,RIGHT_LIST_Y + (0.06 * 0),"BRG")
TEXT_RIGHT_MID(RNG_LBL,0.9,RIGHT_LIST_Y + (0.06 * 1),"RNG")

TEXT_LEFT_MID_SRC(BRG_VAL,0.92,RIGHT_LIST_Y + (0.06 * 0))
 source = "weaponHeading"; sourceScale = 1;
};
TEXT_LEFT_MID_SRC(RNG_VAL,0.92,RIGHT_LIST_Y + (0.06 * 1))
 source = "laserDist"; sourceScale = 1;
};
};
class IsNav {
    condition = "0";
    #include "flir_nav_draw.hpp"
};

class LaserOn {
    condition = "laseron";
    TEXT_MID_MID(LRD_LASE_TXT,0.5,0.2,"LRD LASE DES")
    class Border {
    	type="line";
    	width = 7;
    	points[] ={
    		{{0.5 - 0.13, 0.2 - 0.01},1},
            {{0.5 + 0.13, 0.2 - 0.01},1},
            {{0.5 + 0.13, 0.2 + 0.06},1},
            {{0.5 - 0.13, 0.2 + 0.06},1},
    		{{0.5 - 0.13, 0.2 - 0.01},1}
    	};
    }; // Border
}; // LaserOn

TEXT_MID_MID(FLIR_WPT,0.63,0.06 * 0.2,"WPT")
TEXT_MID_MID(FLIR_FWD,0.74,0.06 * 0.2,"NAV")
TEXT_MID_MID(FLIR_SLG,0.85,0.06 * 0.2,"SLG")

#define BOTTOM_TEXT_Y 0.96
TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"FLIR")
TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")
