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
		texture = "z\vtx\addons\uh60_mfd\data\TAC_MINIMAL.paa";
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
    	width = 6;
    	points[] ={
    		{"TAC_CENTER", 1},
    		{"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1}
    	};
    }; // WP1_Line
    class white {
        color[]={0,1,0,1};
        class WP1_Line_back {
        	type="line";
        	width = 2;
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
    	width = 6;
    	points[] ={
    		{"TAC_WP1_DIST", 1, "TAC_WP1_Dir", 1},
    		{"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1}
    	};
    }; // WP1_Line
    class white {
        color[]={0,1,0,1};
        class WP1_Line_back {
        	type="line";
        	width = 2;
        	points[] ={
        		{"TAC_WP1_DIST", 1, "TAC_WP1_Dir", 1},
        		{"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1}
        	};
        }; // WP1_Line
    }; // color
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
    color[] = {0,0,0,1};
    class textBackground {
        type        = "polygon";
        points[] ={
            {
                {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{-0.08, 0.015},1},
                {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{ 0.08, 0.015},1},
                {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{ 0.08, 0.055},1},
                {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{-0.08, 0.055},1},
            }
        };
    }; // textBackground
    class green {
        color[]={0,1,0,1};
        class WP_Circle
        {
            type = "line";
            width = 2;
            points[]={
                SHAPE_SQUARE("TAC_WP2_DIST","TAC_WP2_Dir")
            };
        }; // WP_Circle
        class WP_TEXT {
            type="text";
            source="userText";
            sourceIndex=7;
            scale=1;
            sourceScale=1;
            align = "center";
            text="0";
            pos[]= {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0, 0+0.015}, 1};
            right[]= {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0.035, 0+0.015}, 1};
            down[]= {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1,{0, 0.035+0.015}, 1};
        };
    };
}; // HAS_CUR_WP
class HAS_WP2_3 {
    condition = ((user4 > -1) * (user6 > -1));
    color[]={0,0,0,1};
    class WP2_Line_back {
    	type="line";
    	width = 6;
    	points[] ={
            {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1},
    		{"TAC_WP3_DIST", 1, "TAC_WP3_Dir", 1},{},
            SHAPE_SQUARE("TAC_WP3_DIST","TAC_WP3_Dir")
    	};
    }; // WP2_Line
    class white {
        color[]={0,1,0,1};
        class WP2_Line {
        	type="line";
        	width = 2;
        	points[] ={
                {"TAC_WP2_DIST", 1, "TAC_WP2_Dir", 1},
        		{"TAC_WP3_DIST", 1, "TAC_WP3_Dir", 1},{},
                SHAPE_SQUARE("TAC_WP3_DIST","TAC_WP3_Dir")
        	};
        }; // WP2_Line
    }; // color
}; // cond
class HAS_WP3 {
    condition = ((user6 > -1) * (user8 > -1));
    color[]={0,0,0,1};
    class WP3_Line_back {
    	type="line";
    	width = 6;
    	points[] ={
            {"TAC_WP3_DIST", 1, "TAC_WP3_Dir", 1},
    		{"TAC_WP4_DIST", 1, "TAC_WP4_Dir", 1},{},
            SHAPE_SQUARE("TAC_WP4_DIST","TAC_WP4_Dir")
    	};
    }; // WP3_Line
    class black {
        color[]={0,1,0,1};
        class WP3_Line {
        	type="line";
        	width = 2;
        	points[] ={
                {"TAC_WP3_DIST", 1, "TAC_WP3_Dir", 1},
        		{"TAC_WP4_DIST", 1, "TAC_WP4_Dir", 1},{},
            SHAPE_SQUARE("TAC_WP4_DIST","TAC_WP4_Dir")
        	};
        }; // WP3_Line
    }; // black
}; // cond
class HAS_WP4 {
    condition = ((user8 > -1) * (user33 > -1));
    color[]={0,0,0,1};
    class WP4_Line_back {
    	type="line";
    	width = 6;
    	points[] ={
            {"TAC_WP4_DIST", 1, "TAC_WP4_Dir", 1},
    		{"TAC_WP5_DIST", 1, "TAC_WP5_Dir", 1},{},
            SHAPE_SQUARE("TAC_WP5_DIST","TAC_WP5_Dir")
    	};
    }; // WP4_Line
    class black {
        color[]={0,1,0,1};
        class WP4_Line {
        	type="line";
        	width = 2;
        	points[] ={
                {"TAC_WP4_DIST", 1, "TAC_WP4_Dir", 1},
        		{"TAC_WP5_DIST", 1, "TAC_WP5_Dir", 1},{},
            SHAPE_SQUARE("TAC_WP5_DIST","TAC_WP5_Dir")
        	};
        }; // WP4_Line
    }; // black
}; // cond
class HAS_WP5 {
    condition = ((user33 > -1) * (user35 > -1));
    color[]={0,0,0,1};
    class WP5_Line_back {
    	type="line";
    	width = 6;
    	points[] ={
            {"TAC_WP5_DIST", 1, "TAC_WP5_Dir", 1},
    		{"TAC_WP6_DIST", 1, "TAC_WP6_Dir", 1},{},
            SHAPE_SQUARE("TAC_WP6_DIST","TAC_WP6_Dir")
    	};
    }; // WP5_Line
    class black {
        color[]={0,1,0,1};
        class WP5_Line {
        	type="line";
        	width = 2;
        	points[] ={
                {"TAC_WP5_DIST", 1, "TAC_WP5_Dir", 1},
        		{"TAC_WP6_DIST", 1, "TAC_WP6_Dir", 1},{},
                SHAPE_SQUARE("TAC_WP6_DIST","TAC_WP6_Dir")
        	};
        }; // WP5_Line
    }; // black
}; // cond

class TGP_STABILIZED {
    condition = (user10 > -1);
    color[]={0,0,0,1};
    class Mark_Circle
    {
        type = "line";
        width = 6;
        points[]={
            SHAPE_DIAMOND("TAC_TGP_DIST","TAC_TGP_Dir")
        };
    }; // Mark_Circle
    class green {
        color[]={0,1,0,1};
        class Mark_Circle
        {
            type = "line";
            width = 2;
            points[]={
                SHAPE_DIAMOND("TAC_TGP_DIST","TAC_TGP_Dir")
            };
        }; // Mark_Circle
    };
}; // Mark_TEXT


class NEAREST_LOCATION {
    condition = (user41 > -1);
    color[]={0,0,0,1};
    class Mark_Circle
    {
        type = "line";
        width = 6;
        points[]={
            SHAPE_DIAMOND("TAC_LOC_DIST","TAC_LOC_Dir")
        };
    }; // Mark_Circle
    class PolygonJet {
		type        = "polygon";
		points[] ={
			{
                {"TAC_LOC_DIST", 1, "TAC_LOC_Dir", 1,{0.01, 0.0},1},
                {"TAC_LOC_DIST", 1, "TAC_LOC_Dir", 1,{0.165, 0.0},1},
                {"TAC_LOC_DIST", 1, "TAC_LOC_Dir", 1,{0.165, 0.045},1},
                {"TAC_LOC_DIST", 1, "TAC_LOC_Dir", 1,{0.01, 0.045},1},
			}
		};
    };
    class green {
        color[]=RGBA256(220,40,220,1);
        class Mark_Circle
        {
            type = "line";
            width = 2;
            points[]={
                SHAPE_DIAMOND("TAC_LOC_DIST","TAC_LOC_Dir")
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
            pos[]= {"TAC_LOC_DIST", 1, "TAC_LOC_Dir", 1,{0.04 - 0.02, 0.0}, 1};
            right[]= {"TAC_LOC_DIST", 1, "TAC_LOC_Dir", 1,{0.085 - 0.02, 0.00}, 1};
            down[]= {"TAC_LOC_DIST", 1, "TAC_LOC_Dir", 1,{0.04 - 0.02, 0.045}, 1};
        };
    }; // green
}; // Mark_TEXT


class JVMF_STABILIZED {
    condition = (user43 > -1);
    color[]={0,0,0,0.05};
    class Mark_Circle
    {
        type = "line";
        width = 6;
        points[]={
            SHAPE_SQUARE("TAC_JVMF_DIST","TAC_JVMF_Dir")
        };
    }; // Mark_Circle
    class textBackground {
		type        = "polygon";
		points[] ={
			{
                {"TAC_JVMF_DIST", 1, "TAC_JVMF_Dir", 1,{-0.08, 0.015},1},
                {"TAC_JVMF_DIST", 1, "TAC_JVMF_Dir", 1,{ 0.08, 0.015},1},
                {"TAC_JVMF_DIST", 1, "TAC_JVMF_Dir", 1,{ 0.08, 0.055},1},
                {"TAC_JVMF_DIST", 1, "TAC_JVMF_Dir", 1,{-0.08, 0.055},1},
			}
		};
    }; // textBackground
    class blue {
        color[] = common_blue;
        class Mark_Circle
        {
            type = "line";
            width = 2;
            points[]={
                SHAPE_SQUARE("TAC_JVMF_DIST","TAC_JVMF_Dir")
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
            pos[]= {"TAC_JVMF_DIST", 1, "TAC_JVMF_Dir", 1,{0, 0+0.015}, 1};
            right[]= {"TAC_JVMF_DIST", 1, "TAC_JVMF_Dir", 1,{0.035, 0+0.015}, 1};
            down[]= {"TAC_JVMF_DIST", 1, "TAC_JVMF_Dir", 1,{0, 0.035+0.015}, 1};
        };
    };
}; // Mark_TEXT


class BFT_COND {
    condition=((user27 > -1)*(user18<1));
    #include "bft.hpp"
};
class NO_BFT_COND {
    condition=(user27 < 0);
    TEXT_LEFT_SMALL(OVERLAY_WARN,0.6,0.85,"NO BFT OVERLAY")
};

class CURSOR_CENTERED {
    condition = ((user18 > 1) * (user18 < 3));
    TEXT_LEFT_SMALL_SRC_CUSTOM(CENTER_MODE,0.665,0.025) source="static"; text="CURS"; sourceScale = 1;};
    class cursor
    {
        type = "line";
        width = 4;
        points[]={
            {"BFT_CENTER", 1, {0,-0.01}, 1},
            {"BFT_CENTER", 1, {0, 0.01}, 1},{},
            {"BFT_CENTER", 1, {-0.01,0}, 1},
            {"BFT_CENTER", 1, { 0.01,0}, 1}
        };
    }; // cursor
};
class FIXED_CENTERED {
    condition = ((user18 > 2) * (user18 < 4));
    TEXT_LEFT_SMALL_SRC_CUSTOM(CENTER_MODE,0.665,0.025) source="static"; text="FIXED"; sourceScale = 1;};
    class cursor
    {
        type = "line";
        width = 4;
        points[]={
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {0,-0.01}, 1},
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {0, 0.01}, 1},{},
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {-0.01,0}, 1},
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, { 0.01,0}, 1}
        };
    }; // cursor
};
class AIRCRAFT_CENTERED {
    condition = ((user18 > -1) * (user18 < 1));
    TEXT_LEFT_SMALL_SRC_CUSTOM(CENTER_MODE,0.665,0.025) source="static"; text="SELF"; sourceScale = 1;};
    class cursor
    {
        type = "line";
        width = 4;
        points[]={
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {0,-0.01},1},
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {0, 0.01},1},{},
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {-0.01,0},1},
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, { 0.01,0},1}
        };
    }; // cursor
    class CIRCLE {
        color[]={0,0,0,1};
        class Mark_Circle
        {
            type = "line";
            width = 6;
            points[]={
                { {0, 0.5}, "0.5", "BFT_CENTER", 1,},{ {0.0469999625866141, 0.49605735065723894}, "0.5", "BFT_CENTER", 1,},{ {0.09325870768682054, 0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {0.13804670725675422, 0.46488824294412573}, "0.5", "BFT_CENTER", 1,},{ {0.18065762778814326, 0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {0.22041946960967743, 0.4045084971874737}, "0.5", "BFT_CENTER", 1,},{ {0.2567051647232582, 0.3644843137107058}, "0.5", "BFT_CENTER", 1,},{ {0.28894246604092094, 0.31871199487434493}, "0.5", "BFT_CENTER", 1,},{ {0.3166229720632556, 0.2679133974894983}, "0.5", "BFT_CENTER", 1,},{ {0.3393101446747573, 0.2128896457825364}, "0.5", "BFT_CENTER", 1,},{ {0.35664619361068256, 0.15450849718747373}, "0.5", "BFT_CENTER", 1,},{ {0.36835771902325826, 0.09369065729286226}, "0.5", "BFT_CENTER", 1,},{ {0.3742600231606018, 0.03139525976465676}, "0.5", "BFT_CENTER", 1,},{ {0.3742600231606018, -0.0313952597646567}, "0.5", "BFT_CENTER", 1,},{ {0.36835771902325826, -0.09369065729286219}, "0.5", "BFT_CENTER", 1,},{ {0.3566461936106826, -0.15450849718747367}, "0.5", "BFT_CENTER", 1,},{ {0.3393101446747573, -0.21288964578253636}, "0.5", "BFT_CENTER", 1,},{ {0.3166229720632557, -0.2679133974894982}, "0.5", "BFT_CENTER", 1,},{ {0.28894246604092105, -0.3187119948743447}, "0.5", "BFT_CENTER", 1,},{ {0.2567051647232582, -0.36448431371070583}, "0.5", "BFT_CENTER", 1,},{ {0.22041946960967745, -0.40450849718747367}, "0.5", "BFT_CENTER", 1,},{ {0.1806576277881432, -0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {0.13804670725675416, -0.46488824294412573}, "0.5", "BFT_CENTER", 1,},{ {0.09325870768682056, -0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {0.0469999625866142, -0.4960573506572389}, "0.5", "BFT_CENTER", 1,},{ {0, -0.5}, "0.5", "BFT_CENTER", 1,},{ {-0.04699996258661411, -0.49605735065723894}, "0.5", "BFT_CENTER", 1,},{ {-0.09325870768682062, -0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {-0.13804670725675405, -0.4648882429441258}, "0.5", "BFT_CENTER", 1,},{ {-0.18065762778814326, -0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {-0.2204194696096774, -0.4045084971874737}, "0.5", "BFT_CENTER", 1,},{ {-0.25670516472325833, -0.3644843137107056}, "0.5", "BFT_CENTER", 1,},{ {-0.288942466040921, -0.31871199487434476}, "0.5", "BFT_CENTER", 1,},{ {-0.31662297206325557, -0.26791339748949855}, "0.5", "BFT_CENTER", 1,},{ {-0.3393101446747573, -0.21288964578253647}, "0.5", "BFT_CENTER", 1,},{ {-0.35664619361068256, -0.15450849718747378}, "0.5", "BFT_CENTER", 1,},{ {-0.3683577190232582, -0.09369065729286274}, "0.5", "BFT_CENTER", 1,},{ {-0.3742600231606018, -0.031395259764656604}, "0.5", "BFT_CENTER", 1,},{ {-0.3742600231606018, 0.03139525976465686}, "0.5", "BFT_CENTER", 1,},{ {-0.36835771902325826, 0.09369065729286213}, "0.5", "BFT_CENTER", 1,},{ {-0.3566461936106826, 0.15450849718747361}, "0.5", "BFT_CENTER", 1,},{ {-0.33931014467475734, 0.2128896457825363}, "0.5", "BFT_CENTER", 1,},{ {-0.3166229720632556, 0.2679133974894984}, "0.5", "BFT_CENTER", 1,},{ {-0.2889424660409209, 0.318711994874345}, "0.5", "BFT_CENTER", 1,},{ {-0.2567051647232581, 0.36448431371070594}, "0.5", "BFT_CENTER", 1,},{ {-0.2204194696096775, 0.40450849718747367}, "0.5", "BFT_CENTER", 1,},{ {-0.18065762778814326, 0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {-0.1380467072567539, 0.4648882429441259}, "0.5", "BFT_CENTER", 1,},{ {-0.09325870768682076, 0.4842915805643155}, "0.5", "BFT_CENTER", 1,},{ {-0.04699996258661424, 0.4960573506572389}, "0.5", "BFT_CENTER", 1,},{ {0, 0.5}, "0.5", "BFT_CENTER", 1,}
            };
        }; // Mark_Circle
        class NorthIndicator
        {
            type = "line";
            width = 6;
            lineType = 0;
            points[] = {
                {"TAC_North", {0.0-0.01, 0.18}, 1},
                {"TAC_North", {0.0, 0.18+0.01}, 1},
                {"TAC_North", {0.0+0.01, 0.18}, 1}
            };
        };
        class green {
            color[]={0,1,0,1};
            class Mark_Circle
            {
                type = "line";
                width = 2;
                points[]={
                    { {0, 0.5}, "0.5", "BFT_CENTER", 1,},{ {0.0469999625866141, 0.49605735065723894}, "0.5", "BFT_CENTER", 1,},{ {0.09325870768682054, 0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {0.13804670725675422, 0.46488824294412573}, "0.5", "BFT_CENTER", 1,},{ {0.18065762778814326, 0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {0.22041946960967743, 0.4045084971874737}, "0.5", "BFT_CENTER", 1,},{ {0.2567051647232582, 0.3644843137107058}, "0.5", "BFT_CENTER", 1,},{ {0.28894246604092094, 0.31871199487434493}, "0.5", "BFT_CENTER", 1,},{ {0.3166229720632556, 0.2679133974894983}, "0.5", "BFT_CENTER", 1,},{ {0.3393101446747573, 0.2128896457825364}, "0.5", "BFT_CENTER", 1,},{ {0.35664619361068256, 0.15450849718747373}, "0.5", "BFT_CENTER", 1,},{ {0.36835771902325826, 0.09369065729286226}, "0.5", "BFT_CENTER", 1,},{ {0.3742600231606018, 0.03139525976465676}, "0.5", "BFT_CENTER", 1,},{ {0.3742600231606018, -0.0313952597646567}, "0.5", "BFT_CENTER", 1,},{ {0.36835771902325826, -0.09369065729286219}, "0.5", "BFT_CENTER", 1,},{ {0.3566461936106826, -0.15450849718747367}, "0.5", "BFT_CENTER", 1,},{ {0.3393101446747573, -0.21288964578253636}, "0.5", "BFT_CENTER", 1,},{ {0.3166229720632557, -0.2679133974894982}, "0.5", "BFT_CENTER", 1,},{ {0.28894246604092105, -0.3187119948743447}, "0.5", "BFT_CENTER", 1,},{ {0.2567051647232582, -0.36448431371070583}, "0.5", "BFT_CENTER", 1,},{ {0.22041946960967745, -0.40450849718747367}, "0.5", "BFT_CENTER", 1,},{ {0.1806576277881432, -0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {0.13804670725675416, -0.46488824294412573}, "0.5", "BFT_CENTER", 1,},{ {0.09325870768682056, -0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {0.0469999625866142, -0.4960573506572389}, "0.5", "BFT_CENTER", 1,},{ {0, -0.5}, "0.5", "BFT_CENTER", 1,},{ {-0.04699996258661411, -0.49605735065723894}, "0.5", "BFT_CENTER", 1,},{ {-0.09325870768682062, -0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {-0.13804670725675405, -0.4648882429441258}, "0.5", "BFT_CENTER", 1,},{ {-0.18065762778814326, -0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {-0.2204194696096774, -0.4045084971874737}, "0.5", "BFT_CENTER", 1,},{ {-0.25670516472325833, -0.3644843137107056}, "0.5", "BFT_CENTER", 1,},{ {-0.288942466040921, -0.31871199487434476}, "0.5", "BFT_CENTER", 1,},{ {-0.31662297206325557, -0.26791339748949855}, "0.5", "BFT_CENTER", 1,},{ {-0.3393101446747573, -0.21288964578253647}, "0.5", "BFT_CENTER", 1,},{ {-0.35664619361068256, -0.15450849718747378}, "0.5", "BFT_CENTER", 1,},{ {-0.3683577190232582, -0.09369065729286274}, "0.5", "BFT_CENTER", 1,},{ {-0.3742600231606018, -0.031395259764656604}, "0.5", "BFT_CENTER", 1,},{ {-0.3742600231606018, 0.03139525976465686}, "0.5", "BFT_CENTER", 1,},{ {-0.36835771902325826, 0.09369065729286213}, "0.5", "BFT_CENTER", 1,},{ {-0.3566461936106826, 0.15450849718747361}, "0.5", "BFT_CENTER", 1,},{ {-0.33931014467475734, 0.2128896457825363}, "0.5", "BFT_CENTER", 1,},{ {-0.3166229720632556, 0.2679133974894984}, "0.5", "BFT_CENTER", 1,},{ {-0.2889424660409209, 0.318711994874345}, "0.5", "BFT_CENTER", 1,},{ {-0.2567051647232581, 0.36448431371070594}, "0.5", "BFT_CENTER", 1,},{ {-0.2204194696096775, 0.40450849718747367}, "0.5", "BFT_CENTER", 1,},{ {-0.18065762778814326, 0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {-0.1380467072567539, 0.4648882429441259}, "0.5", "BFT_CENTER", 1,},{ {-0.09325870768682076, 0.4842915805643155}, "0.5", "BFT_CENTER", 1,},{ {-0.04699996258661424, 0.4960573506572389}, "0.5", "BFT_CENTER", 1,},{ {0, 0.5}, "0.5", "BFT_CENTER", 1,}
                };
            }; // Mark_Circle
            class NorthIndicator
            {
                type = "line";
                width = 2;
                lineType = 0;
                points[] = {
                    {"TAC_North", {0.0-0.01, 0.18}, 1},
                    {"TAC_North", {0.0, 0.18+0.01}, 1},
                    {"TAC_North", {0.0+0.01, 0.18}, 1}
                };
            };
        };
    }; // Mark_TEXT
    class Center {
        type = "line";
        width = 2;
        points[] = {
            {"BFT_CENTER", 1, {-0.01*1.5, -0.01*1.5}, 1},
            {"BFT_CENTER", 1, { 0.01*1.5,  0.01*1.5}, 1}, {},
            {"BFT_CENTER", 1, { 0.01*1.5, -0.01*1.5}, 1},
            {"BFT_CENTER", 1, {-0.01*1.5,  0.01*1.5}, 1}, {},
            {"BFT_CENTER", 1, { 0.00*1.5, -0.01*1.0}, 1},
            {"BFT_CENTER", 1, { 0.00*1.5,  0.02*1.5}, 1},
            {"BFT_CENTER", 1, {-0.01*1.0,  0.02*1.5}, 1}
        };
    };
};
class AIRCRAFT_CENTERED_NORTH {
    condition = ((user18 > 0) * (user18 < 2));
    TEXT_LEFT_SMALL_SRC_CUSTOM(CENTER_MODE,0.665,0.025) source="static"; text="SELF"; sourceScale = 1;};
    class cursor
    {
        type = "line";
        width = 4;
        points[]={
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {0,-0.01},1},
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {0, 0.01},1},{},
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {-0.01,0},1},
            {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, { 0.01,0},1}
        };
    }; // cursor
    class CIRCLE {
        color[]={0,0,0,1};
        class Mark_Circle
        {
            type = "line";
            width = 6;
            points[]={
                { {0, 0.5}, "0.5", "BFT_CENTER", 1,},{ {0.0469999625866141, 0.49605735065723894}, "0.5", "BFT_CENTER", 1,},{ {0.09325870768682054, 0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {0.13804670725675422, 0.46488824294412573}, "0.5", "BFT_CENTER", 1,},{ {0.18065762778814326, 0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {0.22041946960967743, 0.4045084971874737}, "0.5", "BFT_CENTER", 1,},{ {0.2567051647232582, 0.3644843137107058}, "0.5", "BFT_CENTER", 1,},{ {0.28894246604092094, 0.31871199487434493}, "0.5", "BFT_CENTER", 1,},{ {0.3166229720632556, 0.2679133974894983}, "0.5", "BFT_CENTER", 1,},{ {0.3393101446747573, 0.2128896457825364}, "0.5", "BFT_CENTER", 1,},{ {0.35664619361068256, 0.15450849718747373}, "0.5", "BFT_CENTER", 1,},{ {0.36835771902325826, 0.09369065729286226}, "0.5", "BFT_CENTER", 1,},{ {0.3742600231606018, 0.03139525976465676}, "0.5", "BFT_CENTER", 1,},{ {0.3742600231606018, -0.0313952597646567}, "0.5", "BFT_CENTER", 1,},{ {0.36835771902325826, -0.09369065729286219}, "0.5", "BFT_CENTER", 1,},{ {0.3566461936106826, -0.15450849718747367}, "0.5", "BFT_CENTER", 1,},{ {0.3393101446747573, -0.21288964578253636}, "0.5", "BFT_CENTER", 1,},{ {0.3166229720632557, -0.2679133974894982}, "0.5", "BFT_CENTER", 1,},{ {0.28894246604092105, -0.3187119948743447}, "0.5", "BFT_CENTER", 1,},{ {0.2567051647232582, -0.36448431371070583}, "0.5", "BFT_CENTER", 1,},{ {0.22041946960967745, -0.40450849718747367}, "0.5", "BFT_CENTER", 1,},{ {0.1806576277881432, -0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {0.13804670725675416, -0.46488824294412573}, "0.5", "BFT_CENTER", 1,},{ {0.09325870768682056, -0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {0.0469999625866142, -0.4960573506572389}, "0.5", "BFT_CENTER", 1,},{ {0, -0.5}, "0.5", "BFT_CENTER", 1,},{ {-0.04699996258661411, -0.49605735065723894}, "0.5", "BFT_CENTER", 1,},{ {-0.09325870768682062, -0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {-0.13804670725675405, -0.4648882429441258}, "0.5", "BFT_CENTER", 1,},{ {-0.18065762778814326, -0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {-0.2204194696096774, -0.4045084971874737}, "0.5", "BFT_CENTER", 1,},{ {-0.25670516472325833, -0.3644843137107056}, "0.5", "BFT_CENTER", 1,},{ {-0.288942466040921, -0.31871199487434476}, "0.5", "BFT_CENTER", 1,},{ {-0.31662297206325557, -0.26791339748949855}, "0.5", "BFT_CENTER", 1,},{ {-0.3393101446747573, -0.21288964578253647}, "0.5", "BFT_CENTER", 1,},{ {-0.35664619361068256, -0.15450849718747378}, "0.5", "BFT_CENTER", 1,},{ {-0.3683577190232582, -0.09369065729286274}, "0.5", "BFT_CENTER", 1,},{ {-0.3742600231606018, -0.031395259764656604}, "0.5", "BFT_CENTER", 1,},{ {-0.3742600231606018, 0.03139525976465686}, "0.5", "BFT_CENTER", 1,},{ {-0.36835771902325826, 0.09369065729286213}, "0.5", "BFT_CENTER", 1,},{ {-0.3566461936106826, 0.15450849718747361}, "0.5", "BFT_CENTER", 1,},{ {-0.33931014467475734, 0.2128896457825363}, "0.5", "BFT_CENTER", 1,},{ {-0.3166229720632556, 0.2679133974894984}, "0.5", "BFT_CENTER", 1,},{ {-0.2889424660409209, 0.318711994874345}, "0.5", "BFT_CENTER", 1,},{ {-0.2567051647232581, 0.36448431371070594}, "0.5", "BFT_CENTER", 1,},{ {-0.2204194696096775, 0.40450849718747367}, "0.5", "BFT_CENTER", 1,},{ {-0.18065762778814326, 0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {-0.1380467072567539, 0.4648882429441259}, "0.5", "BFT_CENTER", 1,},{ {-0.09325870768682076, 0.4842915805643155}, "0.5", "BFT_CENTER", 1,},{ {-0.04699996258661424, 0.4960573506572389}, "0.5", "BFT_CENTER", 1,},{ {0, 0.5}, "0.5", "BFT_CENTER", 1,}
            };
        }; // Mark_Circle
        class green {
            color[]={0,1,0,1};
            class Mark_Circle
            {
                type = "line";
                width = 2;
                points[]={
                    { {0, 0.5}, "0.5", "BFT_CENTER", 1,},{ {0.0469999625866141, 0.49605735065723894}, "0.5", "BFT_CENTER", 1,},{ {0.09325870768682054, 0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {0.13804670725675422, 0.46488824294412573}, "0.5", "BFT_CENTER", 1,},{ {0.18065762778814326, 0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {0.22041946960967743, 0.4045084971874737}, "0.5", "BFT_CENTER", 1,},{ {0.2567051647232582, 0.3644843137107058}, "0.5", "BFT_CENTER", 1,},{ {0.28894246604092094, 0.31871199487434493}, "0.5", "BFT_CENTER", 1,},{ {0.3166229720632556, 0.2679133974894983}, "0.5", "BFT_CENTER", 1,},{ {0.3393101446747573, 0.2128896457825364}, "0.5", "BFT_CENTER", 1,},{ {0.35664619361068256, 0.15450849718747373}, "0.5", "BFT_CENTER", 1,},{ {0.36835771902325826, 0.09369065729286226}, "0.5", "BFT_CENTER", 1,},{ {0.3742600231606018, 0.03139525976465676}, "0.5", "BFT_CENTER", 1,},{ {0.3742600231606018, -0.0313952597646567}, "0.5", "BFT_CENTER", 1,},{ {0.36835771902325826, -0.09369065729286219}, "0.5", "BFT_CENTER", 1,},{ {0.3566461936106826, -0.15450849718747367}, "0.5", "BFT_CENTER", 1,},{ {0.3393101446747573, -0.21288964578253636}, "0.5", "BFT_CENTER", 1,},{ {0.3166229720632557, -0.2679133974894982}, "0.5", "BFT_CENTER", 1,},{ {0.28894246604092105, -0.3187119948743447}, "0.5", "BFT_CENTER", 1,},{ {0.2567051647232582, -0.36448431371070583}, "0.5", "BFT_CENTER", 1,},{ {0.22041946960967745, -0.40450849718747367}, "0.5", "BFT_CENTER", 1,},{ {0.1806576277881432, -0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {0.13804670725675416, -0.46488824294412573}, "0.5", "BFT_CENTER", 1,},{ {0.09325870768682056, -0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {0.0469999625866142, -0.4960573506572389}, "0.5", "BFT_CENTER", 1,},{ {0, -0.5}, "0.5", "BFT_CENTER", 1,},{ {-0.04699996258661411, -0.49605735065723894}, "0.5", "BFT_CENTER", 1,},{ {-0.09325870768682062, -0.48429158056431554}, "0.5", "BFT_CENTER", 1,},{ {-0.13804670725675405, -0.4648882429441258}, "0.5", "BFT_CENTER", 1,},{ {-0.18065762778814326, -0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {-0.2204194696096774, -0.4045084971874737}, "0.5", "BFT_CENTER", 1,},{ {-0.25670516472325833, -0.3644843137107056}, "0.5", "BFT_CENTER", 1,},{ {-0.288942466040921, -0.31871199487434476}, "0.5", "BFT_CENTER", 1,},{ {-0.31662297206325557, -0.26791339748949855}, "0.5", "BFT_CENTER", 1,},{ {-0.3393101446747573, -0.21288964578253647}, "0.5", "BFT_CENTER", 1,},{ {-0.35664619361068256, -0.15450849718747378}, "0.5", "BFT_CENTER", 1,},{ {-0.3683577190232582, -0.09369065729286274}, "0.5", "BFT_CENTER", 1,},{ {-0.3742600231606018, -0.031395259764656604}, "0.5", "BFT_CENTER", 1,},{ {-0.3742600231606018, 0.03139525976465686}, "0.5", "BFT_CENTER", 1,},{ {-0.36835771902325826, 0.09369065729286213}, "0.5", "BFT_CENTER", 1,},{ {-0.3566461936106826, 0.15450849718747361}, "0.5", "BFT_CENTER", 1,},{ {-0.33931014467475734, 0.2128896457825363}, "0.5", "BFT_CENTER", 1,},{ {-0.3166229720632556, 0.2679133974894984}, "0.5", "BFT_CENTER", 1,},{ {-0.2889424660409209, 0.318711994874345}, "0.5", "BFT_CENTER", 1,},{ {-0.2567051647232581, 0.36448431371070594}, "0.5", "BFT_CENTER", 1,},{ {-0.2204194696096775, 0.40450849718747367}, "0.5", "BFT_CENTER", 1,},{ {-0.18065762778814326, 0.4381533400219318}, "0.5", "BFT_CENTER", 1,},{ {-0.1380467072567539, 0.4648882429441259}, "0.5", "BFT_CENTER", 1,},{ {-0.09325870768682076, 0.4842915805643155}, "0.5", "BFT_CENTER", 1,},{ {-0.04699996258661424, 0.4960573506572389}, "0.5", "BFT_CENTER", 1,},{ {0, 0.5}, "0.5", "BFT_CENTER", 1,}
                };
            }; // Mark_Circle
        };
    }; // Mark_TEXT
    class Center {
        type = "line";
        width = 2;
        points[] = {
            {"BFT_CENTER", 1, {"TAC_HeadingRotationHeli", -0.01*1.5, -0.01*1.5}, 1},
            {"BFT_CENTER", 1, {"TAC_HeadingRotationHeli",  0.01*1.5,  0.01*1.5}, 1}, {},
            {"BFT_CENTER", 1, {"TAC_HeadingRotationHeli",  0.01*1.5, -0.01*1.5}, 1},
            {"BFT_CENTER", 1, {"TAC_HeadingRotationHeli", -0.01*1.5,  0.01*1.5}, 1}, {},
            {"BFT_CENTER", 1, {"TAC_HeadingRotationHeli",  0.00*1.5,  0.01*1.0}, 1},
            {"BFT_CENTER", 1, {"TAC_HeadingRotationHeli",  0.00*1.5, -0.02*1.5}, 1},
            {"BFT_CENTER", 1, {"TAC_HeadingRotationHeli", -0.01*1.0, -0.02*1.5}, 1}
        };
    };
};

#define SELECTORPOLY(USERVALUE,Y) \
    class conditionWrapper_##Y { \
        color[] = {1,1,1,1}; \
        condition=COND_ISNUMBER(39,USERVALUE); \
        class selectedArrow { \
            type        = "polygon"; \
            points[] ={ \
                { \
                    {{0.31-0.005, 0.25+(Y*0.05)-0.01},1}, \
                    {{0.31+0.005, 0.25+(Y*0.05)},1}, \
                    {{0.31-0.005, 0.25+(Y*0.05)+0.01},1} \
                } \
            }; \
        }; \
    };

class contextMenu {
    condition = "(user39>-1)";
    class black {
        color[] = {0,0,0,1};
        class Background {
            type        = "polygon";
            points[] ={
                {
                    {{0+0.3, 0+0.22},1},
                    {{1-0.3, 0+0.22},1},
                    {{1-0.3, 1-0.47},1},
                    {{0+0.3, 1-0.47},1}
                }
            };
        };
        class whiteOverlay {
            color[] = {1,1,1,1};
            class BackgroundBorder {
                type  = "line";
                width = 2;
                points[] ={
                    {{0+0.3, 0.48},1},{{1-0.3, 0.48},1}
                    //,{},{{0+0.3, 0.74},1},{{1-0.3, 0.74},1}
                };
            };
        };
    };
    class BackgroundBorder {
        type  = "line";
        width = 2;
        points[] ={
            {{0+0.3, 0+0.22},1},
            {{1-0.3, 0+0.22},1},
            {{1-0.3, 1-0.47},1},
            {{0+0.3, 1-0.47},1},
            {{0+0.3, 0+0.22},1}
        };
    };
    SELECTORPOLY(0,0)
    SELECTORPOLY(1,1)
    SELECTORPOLY(2,2)
    SELECTORPOLY(3,3)
    SELECTORPOLY(4,4)
    SELECTORPOLY(5,5)
    TEXT_MFD_SCALE_STATIC(LINE0,0.32,0.25+(0*000.05),0.8,"right","Create waypoint")
    TEXT_MFD_SCALE_STATIC(LINE1,0.32,0.25+(1*000.05),0.8,"right","Slew FLIR")
    //TEXT_MFD_SCALE_STATIC(LINE2,0.32,0.25+(2*000.05),0.8,"right","Cycle symbology")
    TEXT_MFD_SCALE_STATIC(LINE3,0.32,0.25+(2*000.05),0.8,"right","Zoom in")
    TEXT_MFD_SCALE_STATIC(LINE4,0.32,0.25+(3*000.05),0.8,"right","Zoom out")
    TEXT_MFD_SCALE_STATIC(LINE5,0.32,0.25+(4*000.05),0.8,"right","Cyle center mode")
    //TEXT_MFD_SCALE_STATIC(LINE6,0.32,0.26+(6*000.05),0.8,"right","PFD")
    //TEXT_MFD_SCALE_STATIC(LINE7,0.32,0.26+(7*000.05),0.8,"right","EICAS")
    //TEXT_MFD_SCALE_STATIC(LINE8,0.32,0.26+(8*000.05),0.8,"right","FLIR")
    //TEXT_MFD_SCALE_STATIC(LINE9,0.32,0.26+(9*000.05),0.8,"right","JVMF")
    TEXT_MFD_SCALE_STATIC(LINE10,0.32,0.25+(5*0.05),0.8,"right","Exit")
};