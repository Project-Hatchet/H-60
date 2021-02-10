#undef BARTOP
#undef BARBOTTOM
#define BARTOP 0.65
#define BARBOTTOM 0.905
#define TEXT_LEFT_SMALL_SRC_CUSTOM(CLASS,X,Y) \
        class CLASS { \
            type = "text"; \
            align = "left"; \
            scale = 1; \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.041, Y}, 1}; \
            down[] = {{X, Y + 0.035}, 1}; \

#define TEXT_RIGHT_SMALL_SRC_CUSTOM(CLASS,X,Y) \
class CLASS { \
    type = "text"; \
    align = "right"; \
    scale = 1; \
    pos[] = {{X, Y}, 1}; \
    right[] = {{X + 0.041, Y}, 1}; \
    down[] = {{X, Y + 0.035}, 1}; \


alpha = 1;
class overlayWrapper {
	class PolygonJet {
		type        = "polygon";
		texture = "z\vtx\addons\uh60_mfd\data\TAC.paa";
		points[] ={
			{
				{{0, 0},1},
				{{1, 0},1},
				{{1, 1},1},
				{{0, 1},1}
			}
		};
	};
	class Center {
		type        = "polygon";
		texture = "z\vtx\addons\uh60_mfd\data\Center.paa";
		points[] ={
			{
				{{0.48, 0.475},1},
				{{0.52, 0.475},1},
				{{0.52, 0.525},1},
				{{0.48, 0.525},1}
			}
		};
	};
}; // overlayWrapper

//zoom
TEXT_LEFT_SMALL_SRC_CUSTOM(ZOOM_VAL,0.04,0.675) source="static"; text="1.0"; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC_CUSTOM(ZOOM_X,0.045,0.675) source="static"; text="X"; sourceScale = 1;};

//scale
TEXT_LEFT_SMALL_SRC_CUSTOM(SCALE_VAL,0.062,0.403) source="static"; text="1:250"; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC_CUSTOM(SCALE_K,0.067,0.403) source="static"; text="K"; sourceScale = 1;};

//currentPos
TEXT_LEFT_SMALL_SRC_CUSTOM(COORDX,0.495,0.89+0.005) source="coordinateX"; sourceScale = 1;refreshRate=0.5;};
TEXT_LEFT_SMALL_SRC_CUSTOM(COORD_SLASH,0.518,0.89+0.005) source="static"; text=" / "; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC_CUSTOM(COORDY,0.525,0.89+0.005) source="coordinateY"; sourceScale = 1;refreshRate=0.5;};

//currentWPT
TEXT_LEFT_SMALL_SRC_CUSTOM(WPDistance,0.46,0.922+0.005) source="wpdist"; sourceScale = 0.000539957; sourceLength = 3;};
TEXT_LEFT_SMALL_SRC_CUSTOM(WP_SLASH,0.52,0.922+0.005) source="static"; text="NM/ "; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC_CUSTOM(WPIndex,0.525,0.922+0.005) source="WPIndex"; sourceScale = 1;};

//currentALT
TEXT_LEFT_SMALL_SRC_CUSTOM(ALT_FEET,0.475,0.954+0.005) source="altitudeASL"; sourceScale = 3.28084; sourceLength = 4;};
TEXT_LEFT_SMALL_SRC_CUSTOM(ALT_SLASH,0.52,0.954+0.005) source="static"; text="ft / "; sourceScale = 1;};
TEXT_RIGHT_SMALL_SRC_CUSTOM(ALT_METER,0.525,0.954+0.005) source="altitudeASL"; sourceScale = 1; sourceLength = 4;};
TEXT_LEFT_SMALL_SRC_CUSTOM(ALT_m,0.605,0.954+0.005) source="static"; text="m"; sourceScale = 1;};

//static
TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"FLIR")
TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")

class HAS_NO_PREVWP {
    condition = ((user2 < 0) * (user4 > -1));
    color[]={0,0,0,1};
    class WP1_Line_back {
    	type="line";
    	width = 8;
    	points[] ={
    		{"TAC_CENTER", 1},
    		{"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1}
    	};
    }; // WP1_Line
    class white {
        color[]={1,1,1,1};
        class WP1_Line_back {
        	type="line";
        	width = 4;
        	points[] ={
        		{"TAC_CENTER", 1},
        		{"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1}
        	};
        }; // WP1_Line
    }; // color
};

class HAS_WP1_2 {
    condition = ((user2 > -1) * (user4 > -1));
    color[]={0,0,0,1};
    class WP1_Line_back {
    	type="line";
    	width = 8;
    	points[] ={
    		{"TAC_WP1_DIST", 1, "TAC_WP1_Dir", 1},
    		{"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1}
    	};
    }; // WP1_Line
    class white {
        color[]={1,1,1,1};
        class WP1_Line_back {
        	type="line";
        	width = 4;
        	points[] ={
        		{"TAC_WP1_DIST", 1, "TAC_WP1_Dir", 1},
        		{"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1}
        	};
        }; // WP1_Line
    }; // color
}; // cond
class HAS_CUR_WP {
    condition = (user4 > -1);
    color[]={1,1,1,1};
    class WP_Circle
    {
        type = "line";
        width = 4;
        points[]={
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0, 0.02},1},
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0.011755705045849463, 0.016180339887498948},1},
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0.019021130325903073, 0.006180339887498949},1},
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0.019021130325903073, -0.006180339887498947},1},
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0.011755705045849465, -0.016180339887498948},1},
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0, -0.02},1},
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{-0.011755705045849461, -0.016180339887498948},1},
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{-0.019021130325903073, -0.006180339887498951},1},
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{-0.019021130325903073, 0.006180339887498945},1},
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{-0.011755705045849468, 0.016180339887498948},1},
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0, 0.02},1}
        };
    }; // WP_Circle
    class WP_TEXT {
        type="text";
        source="userText";
        sourceIndex=7;
        scale=1;
        sourceScale=1;
        align = "right";
        text="0";
        pos[]= {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0.04 - 0.02, 0.0}, 1};
        right[]= {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0.085 - 0.02, 0.00}, 1};
        down[]= {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0.04 - 0.02, 0.045}, 1};
    };
}; // HAS_CUR_WP
class HAS_WP2_3 {
    condition = ((user4 > -1) * (user6 > -1));
    color[]={0,0,0,1};
    class WP2_Line_back {
    	type="line";
    	width = 8;
    	points[] ={
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1},
    		{"TAC_WP3_DIST", 1, "TAC_WP3_Dir", 1}
    	};
    }; // WP2_Line
    class white {
        color[]={1,1,1,1};
        class WP2_Line {
        	type="line";
        	width = 4;
        	points[] ={
                {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1},
        		{"TAC_WP3_DIST", 1, "TAC_WP3_Dir", 1}
        	};
        }; // WP2_Line
    }; // color
}; // cond
class HAS_WP3 {
    condition = ((user6 > -1) * (user8 > -1));
    color[]={0,0,0,1};
    class WP3_Line_back {
    	type="line";
    	width = 8;
    	points[] ={
            {"TAC_WP3_DIST", 1, "TAC_WP3_Dir", 1},
    		{"TAC_WP4_DIST", 1, "TAC_WP4_Dir", 1}
    	};
    }; // WP3_Line
    class black {
        color[]={1,1,1,1};
        class WP3_Line {
        	type="line";
        	width = 4;
        	points[] ={
                {"TAC_WP3_DIST", 1, "TAC_WP3_Dir", 1},
        		{"TAC_WP4_DIST", 1, "TAC_WP4_Dir", 1}
        	};
        }; // WP3_Line
    }; // black
}; // cond
class HAS_WP4 {
    condition = ((user8 > -1) * (user33 > -1));
    color[]={0,0,0,1};
    class WP4_Line_back {
    	type="line";
    	width = 8;
    	points[] ={
            {"TAC_WP4_DIST", 1, "TAC_WP4_Dir", 1},
    		{"TAC_WP5_DIST", 1, "TAC_WP5_Dir", 1}
    	};
    }; // WP4_Line
    class black {
        color[]={1,1,1,1};
        class WP4_Line {
        	type="line";
        	width = 4;
        	points[] ={
                {"TAC_WP4_DIST", 1, "TAC_WP4_Dir", 1},
        		{"TAC_WP5_DIST", 1, "TAC_WP5_Dir", 1}
        	};
        }; // WP4_Line
    }; // black
}; // cond
class HAS_WP5 {
    condition = ((user33 > -1) * (user35 > -1));
    color[]={0,0,0,1};
    class WP5_Line_back {
    	type="line";
    	width = 8;
    	points[] ={
            {"TAC_WP5_DIST", 1, "TAC_WP5_Dir", 1},
    		{"TAC_WP6_DIST", 1, "TAC_WP6_Dir", 1}
    	};
    }; // WP5_Line
    class black {
        color[]={1,1,1,1};
        class WP5_Line {
        	type="line";
        	width = 4;
        	points[] ={
                {"TAC_WP5_DIST", 1, "TAC_WP5_Dir", 1},
        		{"TAC_WP6_DIST", 1, "TAC_WP6_Dir", 1}
        	};
        }; // WP5_Line
    }; // black
}; // cond

class HAS_MARK {
    condition = (user10 > -1);
    color[]={0,1,0,1};
    class Mark_Circle
    {
        type = "line";
        width = 4;
        points[]={
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{0, 0.02},1},
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{0.011755705045849463, 0.016180339887498948},1},
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{0.019021130325903073, 0.006180339887498949},1},
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{0.019021130325903073, -0.006180339887498947},1},
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{0.011755705045849465, -0.016180339887498948},1},
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{0, -0.02},1},
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{-0.011755705045849461, -0.016180339887498948},1},
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{-0.019021130325903073, -0.006180339887498951},1},
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{-0.019021130325903073, 0.006180339887498945},1},
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{-0.011755705045849468, 0.016180339887498948},1},
            {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{0, 0.02},1}
        };
    }; // Mark_Circle
    class Mark_TEXT {
        type="text";
        source="userText";
        sourceIndex=10;
        scale=1;
        sourceScale=1;
        align = "right";
        text="0";
        pos[]= {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{0.04 - 0.02, 0.0}, 1};
        right[]= {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{0.085 - 0.02, 0.00}, 1};
        down[]= {"TAC_MARK_DIST", 1, "TAC_MARK_Dir", 1,{0.04 - 0.02, 0.045}, 1};
    };
}; // Mark_TEXT

class BFT_COND {
    condition=(user27 > -1);
    #include "bft.hpp"
};
class NO_BFT_COND {
    condition=(user27 < 0);
    TEXT_LEFT_SMALL(OVERLAY_WARN,0.6,0.85,"NO BFT OVERLAY")
};
