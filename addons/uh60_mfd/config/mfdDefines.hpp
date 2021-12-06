//START OUT WITH COLOURS
#define RGBA256(R,G,B,A) {R/256,G/256,B/256,A}
#define RGB256(R,G,B) {R/256,G/256,B/256}

//common colours
#define common_white RGBA256(200,200,200,1.0)
#define common_blue RGBA256(40,140,180,1.0)
#define common_green RGBA256(110,150,65,1.0)
#define common_purple RGBA256(200,31,120,1.0)
#define common_yellow RGBA256(230,230,40,0.1)
#define common_red RGBA256(160,30,30,1.0)
#define common_black RGBA256(0,0,0,1.0)

//pitch-attitude scale
#define pitch_att_blue RGBA256(5,60,140,0.2)
#define pitch_att_orange RGBA256(70,30,15,0.2)
#define pitch_esis_grey RGB256(60,60,60)

#define START_MAP_INDEX 8
#define START_OVERLAY_INDEX 12
#define MAP_SELECTION(MFDINDEX) (MFDINDEX - (MFD_1_PAGE_INDEX - START_MAP_INDEX))
#define MFD_OVERLAY(MFDINDEX) (MFDINDEX - (MFD_1_PAGE_INDEX - START_OVERLAY_INDEX))
#define MFD_1_PAGE_INDEX 23
#define MFD_2_PAGE_INDEX 24
#define MFD_3_PAGE_INDEX 25
#define MFD_4_PAGE_INDEX 26

#define JVMF_TYPE 16
#define WARN_INDEX 1

#define COND_ISNUMBER(INDEX,VALUE) (user##INDEX>(VALUE-1))*(user##INDEX<(VALUE+1))
#define MFD_PAGE_EICAS 0
#define MFD_PAGE_PFD 1
#define MFD_PAGE_TAC 2
#define MFD_PAGE_ND 3
#define MFD_PAGE_JVMF 4
#define MFD_PAGE_FLIR 5


//HELPERS
//#define GLUE(A,B) A##B
#define LEVELP(x) LevelP##x
#define LEVELM(x) LevelM##x
#define STR(A) #A

//ELEMENTS


#define TEXT_MID_SCALED_SRC(CLASS,X,Y,SCALE) \
	class CLASS { \
		type = "text"; \
		align = "center"; \
		scale = 1; \
		pos[] = {{X, Y}, 1}; \
		right[] = {{X + SCALE, Y}, 1}; \
		down[] = {{X, Y + SCALE}, 1};

#define TEXT_MID_SCALED(CLASS,X,Y,TEXT,SCALE) \
	TEXT_MID_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "static"; \
		text = TEXT; \
	};

#define TEXT_LEFT_SCALED_SRC(CLASS,X,Y,SCALE) \
	class CLASS { \
		type = "text"; \
		align = "right"; \
		scale = 1; \
		pos[] = {{X, Y}, 1}; \
		right[] = {{X + SCALE, Y}, 1}; \
		down[] = {{X, Y + SCALE}, 1};

#define TEXT_LEFT_SCALED(CLASS,X,Y,TEXT,SCALE) \
	TEXT_LEFT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "static"; \
		text = TEXT; \
	};

#define TEXT_LEFT_SCALED_USERTEXT(CLASS,X,Y,IDX,SCALE) \
	TEXT_LEFT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "userText"; \
        sourceIndex = IDX; \
        sourceScale = 1; \
		text = ""; \
	};

#define TEXT_LEFT_OPEN(CLASS) \
    class CLASS { \
        type = "text"; \
        source = "static"; \
        align = "left"; \
        scale = 1; \
        sourceScale = 1;


#define TEXT_RIGHT_OPEN(CLASS) \
    class CLASS { \
        type = "text"; \
        source = "static"; \
        align = "right"; \
        scale = 1; \
        sourceScale = 1;

    #define TEXT_MID_SMALL_SRC(CLASS,X,Y) \
        class CLASS { \
            type = "text"; \
            align = "center"; \
            scale = 1; \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.043, Y}, 1}; \
            down[] = {{X, Y + 0.048}, 1}; \

    #define TEXT_LEFT_SMALL_SRC(CLASS,X,Y) \
        class CLASS { \
            type = "text"; \
            align = "left"; \
            scale = 1; \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.043, Y}, 1}; \
            down[] = {{X, Y + 0.048}, 1}; \

    #define TEXT_RIGHT_SMALL_SRC(CLASS,X,Y) \
        class CLASS { \
            type = "text"; \
            align = "right"; \
            scale = 1; \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.043, Y}, 1}; \
            down[] = {{X, Y + 0.048}, 1}; \

    #define TEXT_MID_SMALL(CLASS,X,Y,TEXT) \
        class CLASS { \
            type = "text"; \
            source = "static"; \
            align = "center"; \
            scale = 1; \
            sourceScale = 1; \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.04, Y}, 1}; \
            down[] = {{X, Y + 0.033}, 1}; \
            text = TEXT; \
        };

    //ELEMENTS
    #define TEXT_LEFT_SMALL(CLASS,X,Y,TEXT) \
        TEXT_LEFT_OPEN(CLASS) \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.04, Y}, 1}; \
            down[] = {{X, Y + 0.033}, 1}; \
            text = TEXT; \
        };

    //ELEMENTS
    #define TEXT_RIGHT_SMALL(CLASS,X,Y,TEXT) \
        TEXT_RIGHT_OPEN(CLASS) \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.04, Y}, 1}; \
            down[] = {{X, Y + 0.033}, 1}; \
            text = TEXT; \
        };

    #define TEXT_MID_MID_SRC(CLASS,X,Y) \
        class CLASS { \
            type = "text"; \
            align = "center"; \
            scale = 1; \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.0466, Y}, 1}; \
            down[] = {{X, Y + 0.052}, 1};

    #define TEXT_LEFT_MID_SRC(CLASS,X,Y) \
        class CLASS { \
            type = "text"; \
            align = "right"; \
            scale = 1; \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.0466, Y}, 1}; \
            down[] = {{X, Y + 0.052}, 1};


    #define TEXT_LEFT_MID(CLASS,X,Y,TEXT) \
        class CLASS { \
            type = "text"; \
            source = "static"; \
            align = "right"; \
            scale = 1; \
            sourceScale = 1; \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.0466, Y}, 1}; \
            down[] = {{X, Y + 0.052}, 1};\
            text = TEXT; \
        };

    #define TEXT_RIGHT_MID(CLASS,X,Y,TEXT) \
        class CLASS { \
            type = "text"; \
            source = "static"; \
            align = "left"; \
            scale = 1; \
            sourceScale = 1; \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.0466, Y}, 1}; \
            down[] = {{X, Y + 0.052}, 1};\
            text = TEXT; \
        };

    #define TEXT_LEFT_MID_USERTEXT(CLASS,X,Y,IDX) \
        class CLASS { \
            type = "text"; \
            source = "userText"; \
            sourceIndex = IDX; \
            align = "right"; \
            scale = 1; \
            sourceScale = 1; \
            pos[] = {{X, Y}, 1}; \
            right[] = {{X + 0.0466, Y}, 1}; \
            down[] = {{X, Y + 0.052}, 1};\
            text = TEXT; \
        };
    
    #define TEXT_MFD_SCALE(CLASS,X,Y,SIZE,ALIGN) \
        class CLASS { \
            type = "text"; \
            align = ALIGN; \
            scale = 1; \
            pos[] = {{X-0.002*SIZE, Y-0.035*SIZE}, 1}; \
            right[] = {{X + 0.06*SIZE, Y-0.035*SIZE}, 1}; \
            down[] = {{X-0.002*SIZE, Y + 0.035*SIZE}, 1};

    #define TEXT_MFD_SCALE_STATIC(CLASS,X,Y,SIZE,ALIGN,TEXT) \
        class CLASS { \
            type = "text"; \
            source = "static"; \
            text = TEXT; \
            align = ALIGN; \
            scale = 1; \
            pos[] = {{X-0.002*SIZE, Y-0.035*SIZE}, 1}; \
            right[] = {{X + 0.06*SIZE, Y-0.035*SIZE}, 1}; \
            down[] = {{X-0.002*SIZE, Y + 0.035*SIZE}, 1}; \
        };

    #define TEXT_MID_MID(CLASS,X,Y,TEXT) \
        TEXT_MID_MID_SRC(CLASS,X,Y) \
            source = "static"; \
            text = TEXT; \
        };

    #define PITCH_BONES(X1,X2,Y1,Y2) \
        class Level0 \
        { \
            pos0[] = {X1, Y1}; \
            pos10[] = {X2, Y2}; \
            type = "horizon"; \
            angle = 0; \
        };class LevelP5:Level0{angle=5;};class LevelM5:Level0{angle=-5;};class LevelP10:Level0{angle=10;};class LevelM10:Level0{angle=-10;};class LevelP15:Level0{angle=15;};class LevelM15:Level0{angle=-15;};class LevelP20:Level0{angle=20;};class LevelM20:Level0{angle=-20;};class LevelP25:Level0{angle=25;};class LevelM25:Level0{angle=-25;};class LevelP30:Level0{angle=30;};class LevelM30:Level0{angle=-30;};class LevelP35:Level0{angle=35;};class LevelM35:Level0{angle=-35;};class LevelP40:Level0{angle=40;};class LevelM40:Level0{angle=-40;};class LevelP45:Level0{angle=45;};class LevelM45:Level0{angle=-45;};class LevelP50:Level0{angle=50;};class LevelM50:Level0{angle=-50;};class LevelP55:Level0{angle=55;};class LevelM55:Level0{angle=-55;};class LevelP60:Level0{angle=60;};class LevelM60:Level0{angle=-60;};class LevelP65:Level0{angle=65;};class LevelM65:Level0{angle=-65;};class LevelP70:Level0{angle=70;};class LevelM70:Level0{angle=-70;};class LevelP75:Level0{angle=75;};class LevelM75:Level0{angle=-75;};class LevelP80:Level0{angle=80;};class LevelM80:Level0{angle=-80;};class LevelP85:Level0{angle=85;};class LevelM85:Level0{angle=-85;};class LevelP90:Level0{angle=90;};class LevelM90:Level0{angle=-90;};

    #define LEVEL0(WIDTH) \
        class Level0 \
        { \
            type = "line"; \
            width = 4; \
            points[] = {{"Level0", {WIDTH, 0}, 1}, {"Level0", {-WIDTH, 0}, 1}}; \
        };

    #define LEVEL_BACKGROUND(COLORTOP,COLORBOTTOM,WIDTH) \
        class polygon_top { \
            color[] = COLORTOP; \
            class background { \
                type = "polygon"; \
                points[] ={ \
                    { \
                        {"Levelp90",{-WIDTH, 0},1}, \
                        {"Levelp90",{WIDTH, 0},1}, \
                        {"Level0",{WIDTH, 0},1}, \
                        {"Level0",{-WIDTH, 0},1} \
                    } \
                }; \
            }; \
        }; \
        class polygon_bottom { \
            color[] = COLORBOTTOM; \
            class background { \
                type = "polygon"; \
                points[] ={ \
                    { \
                        {"Level0",{-WIDTH, 0},1}, \
                        {"Level0",{WIDTH, 0},1}, \
                        {"LevelM90",{WIDTH, 0},1}, \
                        {"LevelM90",{-WIDTH, 0},1} \
                    } \
                }; \
            }; \
        };

    #define LEVEL_NARROW(NAME,WIDTH) \
        class NAME : level0 { \
            type = "line"; \
            points[] = {{#NAME, {WIDTH, 0}, 1}, {#NAME, {-WIDTH, 0}, 1}}; \
        };

    #define LEVEL_WIDE(NAME,WIDTH) \
        class NAME : level0 { \
            type = "line"; \
            points[] = {{#NAME, {WIDTH, 0}, 1}, {#NAME, {-WIDTH, 0}, 1}}; \
        };


    #define LEVEL_TEXT(LEVEL,BONE,WIDTH) \
            TEXT_LEFT_OPEN(DOUBLES(VAL_L,BONE)) \
                text = LEVEL; \
                pos[] = {BONE, {-WIDTH, -0.032}, 1}; \
                right[] = {BONE, {-(WIDTH-0.06), -0.032}, 1}; \
                down[] = {BONE, {-WIDTH, 0.01}, 1}; \
            }; \
            TEXT_LEFT_OPEN(DOUBLES(VAL_R,BONE)) \
                text = LEVEL; \
                pos[] = {BONE, {(WIDTH+0.03), -0.032}, 1}; \
                right[] = {BONE, {(WIDTH+0.09), -0.032}, 1}; \
                down[] = {BONE, {(WIDTH+0.03), 0.01}, 1}; \
            };

    #define LEVEL_SET(HALF,WHOLE,NARROW,WIDE,TEXT) \
        LEVEL_NARROW(LEVELP(HALF),NARROW) \
        LEVEL_NARROW(LEVELM(HALF),NARROW) \
        LEVEL_TEXT(WHOLE,LEVELM(WHOLE),TEXT) \
        LEVEL_TEXT(WHOLE,LEVELP(WHOLE),TEXT) \
        LEVEL_WIDE(LEVELM(WHOLE),WIDE) \
        LEVEL_WIDE(LEVELP(WHOLE),WIDE)


    #define BAR(CLASS,BONE,X,Y,W) \
        class CLASS { \
            type="polygon"; \
            points[] ={ \
                { \
                    {BONE,{X + -W, 0},1}, \
                    {BONE,{X + W, 0},1}, \
                    {{X + W,Y},1}, \
                    {{X - W,Y},1} \
                } \
            }; \
        };

    #define POLYGON(CLASS,X,Y,W,H) \
    	class CLASS { \
		type="polygon"; \
		points[] ={ \
			{ \
				{{X +-W, Y-H},1}, \
				{{X + W, Y-H},1}, \
				{{X + W, Y+H},1}, \
				{{X - W, Y+H},1} \
			} \
		}; \
	};

#define MID_LINE_HEIGHT 0.06
#define SMALL_LINE_HEIGHT 0.03