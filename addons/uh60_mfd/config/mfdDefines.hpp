//START OUT WITH COLOURS
#define RGBA256(R,G,B,A) {R/256,G/256,B/256,A}
#define RGB256(R,G,B) {R/256,G/256,B/256}

#define BACKGROUND_ALPHA 1

//common colours
#define common_white RGBA256(200,200,200,1.0)
#define common_blue RGBA256(40,140,180,1.0)
#define common_green RGBA256(20,200,20,1.0)
#define common_purple RGBA256(200,31,120,1.0)
#define common_yellow RGBA256(255,255,0,0.1)
#define common_red RGBA256(160,30,30,1.0)
#define common_black RGBA256(0,0,0,1.0)
#define danger_red RGBA256(240,00,00,1.0)

//pitch-attitude scale
#define pitch_att_blue RGBA256(5,60,140,1)
#define pitch_att_orange RGBA256(70,30,15,1)
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

#define COND_ISNUMBER(INDEX,VALUE) (user##INDEX>(VALUE-0.01))*(user##INDEX<(VALUE+0.99))
#define COND_ISNUMPYLON(INDEX,VALUE) (pylonAmmo##INDEX>(VALUE-0.01))*(pylonAmmo##INDEX<(VALUE+0.99))
#define MFD_PAGE_EICAS 0
#define MFD_PAGE_PFD 1
#define MFD_PAGE_TAC 2
#define MFD_PAGE_ND 3
#define MFD_PAGE_JVMF 4
#define MFD_PAGE_FLIR 5
#define MFD_PAGE_IVHMS 6
#define MFD_PAGE_CCFS_MENU 7
#define MFD_PAGE_CCFS 8
#define MFD_PAGE_IVHMS_NUMS 9

#define COND_ISMFD(INDEX,VALUE) (INDEX>(VALUE-0.01))*(INDEX<(VALUE+0.99))
#define MFD_OR_MFD(CURINDEX,IDX1,IDX2) (COND_ISMFD(CURINDEX,IDX1) + COND_ISMFD(CURINDEX,IDX2))

// ND SUBPAGES
#define ND_MODE_ALL (MFD_PAGE_ND+0.0)
#define ND_MODE_NAV (MFD_PAGE_ND+0.1)
#define ND_MODE_CMWS (MFD_PAGE_ND+0.2)
#define ND_MODE_HOVER (MFD_PAGE_ND+0.3)

// PFD SUBPAGES
#define PFD_MODE_HSI (MFD_PAGE_PFD+0.0)
#define PFD_MODE_ARC (MFD_PAGE_PFD+0.1)
#define PFD_MODE_HVR (MFD_PAGE_PFD+0.2)

// TAC SUBPAGES
#define TAC_MODE_LEGEND (MFD_PAGE_TAC+0.1)
#define TAC_MODE_MAPCONF (MFD_PAGE_TAC+0.2)

#define COND_SUBPAGE(INDEX,VALUE) (user##INDEX>(VALUE-0.1))*(user##INDEX<(VALUE+0.1))
#define COND_SUBPAGE_OR_SUBPAGE(INDEX,VALUE1,VALUE2) (COND_SUBPAGE(INDEX,VALUE1)+COND_SUBPAGE(INDEX,VALUE2))


//HELPERS
#define GLUE(A,B) A##B
#define LEVELP(x) LevelP##x
#define LEVELM(x) LevelM##x
#define STR(A) #A


#define BFT_ANGLEX(DEG,RADIUS) (sin DEG * (BFT_ICON_W*RADIUS))
#define BFT_ANGLEY(DEG,RADIUS) (cos DEG * (BFT_ICON_H*RADIUS))
#define BFT_ANGLE(DEG,RADIUS) {BFT_ANGLEX(DEG,RADIUS), BFT_ANGLEY(DEG,RADIUS)}

#define ANGLEX(DEG,RADIUS) (0.75*(sin DEG * (RADIUS)))
#define ANGLEY(DEG,RADIUS) (cos DEG * (RADIUS))
#define ANGLE(DEG,RADIUS) {ANGLEX(DEG,RADIUS), ANGLEY(DEG,RADIUS)}


// CONDITIONS
#define RALT_ENABLED "altitudeAGL < 304"
#define RALT_DISABLED "altitudeAGL > 304"
#define EGI_DISABLED "1"
#define ASE_DISABLED_NONE "pylonAmmo36 < 1"
#define ASE_DISABLED "pylonAmmo36 > 0"
#define FLIR_FUNCTIONAL "pylonAmmo37 > 0"
#define FLIR_DISABLED "pylonAmmo37 > 0"

#define C_WP1_EXISTS "user2 > -1"
#define C_WP2_EXISTS "user4 > -1"
#define C_WP3_EXISTS "user6 > -1"
#define C_WP4_EXISTS "user8 > -1"
#define C_WP5_EXISTS "user33 > -1"
#define C_WP6_EXISTS "user35 > -1"

#define DTS_LOAD_FAIL "0"
#define RAD_ALT_FAIL "0"
#define TAC_CENTERED "pylonAmmo4 < 1"
#define TAC_SELF_ORIENT "pylonAmmo5 < 1"
#define TAC_STATIC "pylonAmmo6 > 0"
#define TAC_DYNAMIC "pylonAmmo6 < 1"

#define SOI_IDX 39

//ELEMENTS
#define STAR_INNER_SCALE 0.3
#define SHAPE_STAR(DIST,DIR) \
    {DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*-0.015,STAR_INNER_SCALE*-0.015},1}, \
    {DIST, 1, DIR, 1,{0.75*0     ,-0.020},1}, \
    {DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*0.015, STAR_INNER_SCALE*-0.015},1}, \
    {DIST, 1, DIR, 1,{0.75*0.020,  0},1}, \
    {DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*0.015,  STAR_INNER_SCALE*0.015},1}, \
    {DIST, 1, DIR, 1,{0.75*0     , 0.020},1}, \
    {DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*-0.015, STAR_INNER_SCALE*0.015},1}, \
    {DIST, 1, DIR, 1,{0.75*-0.020,  0},1}, \
    {DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*-0.015, STAR_INNER_SCALE*-0.015},1}

#define SHAPE_STAR2(OFFSET1,OFFSET2,DIST,DIR) \
    {OFFSET1, 1, OFFSET2, 1, DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*-0.015,STAR_INNER_SCALE*-0.015},1}, \
    {OFFSET1, 1, OFFSET2, 1, DIST, 1, DIR, 1,{0.75*0     ,-0.020},1}, \
    {OFFSET1, 1, OFFSET2, 1, DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*0.015, STAR_INNER_SCALE*-0.015},1}, \
    {OFFSET1, 1, OFFSET2, 1, DIST, 1, DIR, 1,{0.75*0.020,  0},1}, \
    {OFFSET1, 1, OFFSET2, 1, DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*0.015,  STAR_INNER_SCALE*0.015},1}, \
    {OFFSET1, 1, OFFSET2, 1, DIST, 1, DIR, 1,{0.75*0     , 0.020},1}, \
    {OFFSET1, 1, OFFSET2, 1, DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*-0.015, STAR_INNER_SCALE*0.015},1}, \
    {OFFSET1, 1, OFFSET2, 1, DIST, 1, DIR, 1,{0.75*-0.020,  0},1}, \
    {OFFSET1, 1, OFFSET2, 1, DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*-0.015, STAR_INNER_SCALE*-0.015},1}

#define SHAPE_STAR3(OFFSET1,DIST,DIR) \
    {OFFSET1, 1, DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*-0.015,STAR_INNER_SCALE*-0.015},1}, \
    {OFFSET1, 1, DIST, 1, DIR, 1,{0.75*0     ,-0.020},1}, \
    {OFFSET1, 1, DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*0.015, STAR_INNER_SCALE*-0.015},1}, \
    {OFFSET1, 1, DIST, 1, DIR, 1,{0.75*0.020,  0},1}, \
    {OFFSET1, 1, DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*0.015,  STAR_INNER_SCALE*0.015},1}, \
    {OFFSET1, 1, DIST, 1, DIR, 1,{0.75*0     , 0.020},1}, \
    {OFFSET1, 1, DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*-0.015, STAR_INNER_SCALE*0.015},1}, \
    {OFFSET1, 1, DIST, 1, DIR, 1,{0.75*-0.020,  0},1}, \
    {OFFSET1, 1, DIST, 1, DIR, 1,{0.75*STAR_INNER_SCALE*-0.015, STAR_INNER_SCALE*-0.015},1}

#define TEXT_RIGHT_SCALED_SRC(CLASS,X,Y,SCALE) \
	class CLASS { \
		type = "text"; \
		align = "left"; \
		scale = 1; \
		pos[] = {{X, Y}, 1}; \
		right[] = {{X + (SCALE*0.75), Y}, 1}; \
		down[] = {{X, Y + SCALE}, 1};

#define TEXT_RIGHT_SCALED(CLASS,X,Y,TEXT,SCALE) \
	TEXT_RIGHT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "static"; \
		text = TEXT; \
	};

#define TEXT_RIGHT_SCALED_USERTEXT(CLASS,X,Y,IDX,SCALE) \
	TEXT_RIGHT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "userText"; \
        sourceIndex = IDX; \
        sourceScale = 1; \
		text = ""; \
	};

#define TEXT_MID_SCALED_SRC(CLASS,X,Y,SCALE) \
	class CLASS { \
		type = "text"; \
		align = "center"; \
		scale = 1; \
		pos[] = {{X, Y}, 1}; \
		right[] = {{X + (SCALE*0.75), Y}, 1}; \
		down[] = {{X, Y + SCALE}, 1};

#define TEXT_MID_SCALED(CLASS,X,Y,TEXT,SCALE) \
	TEXT_MID_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "static"; \
		text = TEXT; \
	};


#define TEXT_MID_SCALED_SOURCE(CLASS,X,Y,SCALE,SOURCE,SOURCEINDEX,SOURCESCALE,DECIMALS) \
	TEXT_MID_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = SOURCE; \
        sourceIndex = SOURCEINDEX; \
		sourceScale = SOURCESCALE; \
        sourcePrecision = DECIMALS; \
	};


#define TEXT_LEFT_SCALED_SOURCE(CLASS,X,Y,SCALE,SOURCE,SOURCEINDEX,SOURCESCALE,DECIMALS) \
	TEXT_LEFT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = SOURCE; \
        sourceIndex = SOURCEINDEX; \
		sourceScale = SOURCESCALE; \
        sourcePrecision = DECIMALS; \
	};

#define TEXT_MID_SCALED_USERTEXT(CLASS,X,Y,IDX,SCALE) \
	TEXT_MID_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "userText"; \
        sourceIndex = IDX; \
        sourceScale = 1; \
		text = ""; \
	};

#define TEXT_LEFT_SCALED_SRC(CLASS,X,Y,SCALE) \
	class CLASS { \
		type = "text"; \
		align = "right"; \
		scale = 1; \
		pos[] = {{X, Y}, 1}; \
		right[] = {{X + (SCALE*0.75), Y}, 1}; \
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

#define TEXT_LEFT_SCALED_USERVAL(CLASS,X,Y,IDX,SCALE) \
	TEXT_LEFT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "user"; \
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


#define TEXT_SMALL_SIZE 0.048
#define TEXT_MID_SIZE 0.052

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
        right[] = {{X + (TEXT_SMALL_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_SMALL_SIZE}, 1};

#define TEXT_LEFT_SMALL_SRC(CLASS,X,Y) \
    class CLASS { \
        type = "text"; \
        align = "left"; \
        scale = 1; \
        pos[] = {{X, Y}, 1}; \
        right[] = {{X + (TEXT_SMALL_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_SMALL_SIZE}, 1};

#define TEXT_RIGHT_SMALL_SRC(CLASS,X,Y) \
    class CLASS { \
        type = "text"; \
        align = "right"; \
        scale = 1; \
        pos[] = {{X, Y}, 1}; \
        right[] = {{X + (TEXT_SMALL_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_SMALL_SIZE}, 1};

#define TEXT_MID_SMALL(CLASS,X,Y,TEXT) \
    class CLASS { \
        type = "text"; \
        source = "static"; \
        align = "center"; \
        scale = 1; \
        sourceScale = 1; \
        pos[] = {{X, Y}, 1}; \
        right[] = {{X + (TEXT_SMALL_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_SMALL_SIZE}, 1}; \
        text = TEXT; \
    };

//ELEMENTS
#define TEXT_LEFT_SMALL(CLASS,X,Y,TEXT) \
    TEXT_LEFT_OPEN(CLASS) \
        pos[] = {{X, Y}, 1}; \
        right[] = {{X + (TEXT_SMALL_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_SMALL_SIZE}, 1}; \
        text = TEXT; \
    };

//ELEMENTS
#define TEXT_RIGHT_SMALL(CLASS,X,Y,TEXT) \
    TEXT_RIGHT_OPEN(CLASS) \
        pos[] = {{X, Y}, 1}; \
        right[] = {{X + (TEXT_SMALL_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_SMALL_SIZE}, 1}; \
        text = TEXT; \
    };

#define TEXT_MID_MID_SRC(CLASS,X,Y) \
    class CLASS { \
        type = "text"; \
        align = "center"; \
        scale = 1; \
        pos[] = {{X, Y}, 1}; \
        right[] = {{X + (TEXT_MID_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_MID_SIZE}, 1};

#define TEXT_LEFT_MID_SRC(CLASS,X,Y) \
    class CLASS { \
        type = "text"; \
        align = "right"; \
        scale = 1; \
        pos[] = {{X, Y}, 1}; \
        right[] = {{X + (TEXT_MID_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_MID_SIZE}, 1};


#define TEXT_LEFT_MID(CLASS,X,Y,TEXT) \
    class CLASS { \
        type = "text"; \
        source = "static"; \
        align = "right"; \
        scale = 1; \
        sourceScale = 1; \
        pos[] = {{X, Y}, 1}; \
        right[] = {{X + (TEXT_MID_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_MID_SIZE}, 1}; \
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
        right[] = {{X + (TEXT_MID_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_MID_SIZE}, 1}; \
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
        right[] = {{X + (TEXT_MID_SIZE*0.75), Y}, 1}; \
        down[] = {{X, Y + TEXT_MID_SIZE}, 1}; \
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

#define PITCH_LEVEL(CNAME,ANG) \
    class CNAME##_pos: Level0 {angle=ANG;}; \
    class CNAME##_neg: Level0 {angle=-ANG;};

#define LEVEL0(WIDTH) \
    class Level0 \
    { \
        type = "line"; \
        width = 4; \
        points[] = {{"Level0", {WIDTH, 0}, 1}, {"Level0", {-WIDTH, 0}, 1}}; \
    };

#define POINTS_LEVEL_W(BONE) \
    {BONE##_pos, {0.035, 0}, 1}, {BONE##_pos, {-0.035, 0}, 1},{}, \
    {BONE##_neg, {0.035, 0}, 1}, {BONE##_neg, {-0.035, 0}, 1},{}

#define POINTS_LEVEL_M(BONE) \
    {BONE##_pos, {0.015, 0}, 1}, {BONE##_pos, {-0.015, 0}, 1},{}, \
    {BONE##_neg, {0.015, 0}, 1}, {BONE##_neg, {-0.015, 0}, 1},{}

#define POINTS_LEVEL_N(BONE) \
    {BONE##_pos, {0.007, 0}, 1}, {BONE##_pos, {-0.007, 0}, 1},{}, \
    {BONE##_neg, {0.007, 0}, 1}, {BONE##_neg, {-0.007, 0}, 1},{}

#define LEVEL_BACKGROUND(COLORTOP,COLORBOTTOM,WIDTH) \
    class polygon_top { \
        color[] = COLORTOP; \
        class background { \
            type = "polygon"; \
            points[] ={ \
                { \
                    {"Levelp90",{-WIDTH, -0.5},1}, \
                    {"Levelp90",{WIDTH, -0.5},1}, \
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
                    {"LevelM90",{WIDTH, 0.5},1}, \
                    {"LevelM90",{-WIDTH, 0.5},1} \
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


#define LEVEL_TEXT(LEVEL,BONE,WIDTH,TEXT) \
        TEXT_LEFT_OPEN(DOUBLES(VAL_L,BONE)) \
            text = TEXT; \
            pos[] = {BONE, {-WIDTH, -0.032+0.01}, 1}; \
            right[] = {BONE, {-(WIDTH-0.062), -0.032+0.01}, 1}; \
            down[] = {BONE, {-WIDTH, 0.01+0.01}, 1}; \
        }; \
        TEXT_LEFT_OPEN(DOUBLES(VAL_R,BONE)) \
            text = TEXT; \
            pos[] = {BONE, {(WIDTH+0.03), -0.032+0.01}, 1}; \
            right[] = {BONE, {(WIDTH+0.09), -0.032+0.01}, 1}; \
            down[] = {BONE, {(WIDTH+0.03), 0.01+0.01}, 1}; \
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

#define BAR_WARN(CLASS,BONE,X,Y,W,VAL,MAX) \
    class CLASS { \
        class greenWrap { \
            condition = QUOTE(GLUE(user,VAL) < MAX); \
            color[] = common_green; \
            class green { \
                type="polygon"; \
                points[] ={ \
                    { \
                        {BONE,{X + -W, 0},1}, \
                        {BONE,{X + W, 0},1}, \
                        {{X + W,Y},1}, \
                        {{X - W,Y},1} \
                    } \
                }; \
            }; \
        }; \
        class redWrap { \
            condition = QUOTE(GLUE(user,VAL) > MAX); \
            color[] = danger_red; \
            class green { \
                type="polygon"; \
                points[] ={ \
                    { \
                        {BONE,{X + -W, 0},1}, \
                        {BONE,{X + W, 0},1}, \
                        {{X + W,Y},1}, \
                        {{X - W,Y},1} \
                    } \
                }; \
            }; \
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

#define COLORED_POLYGON(CLASS,X,Y,W,H,COL) \
    class CLASS { \
        color[] = COL; \
        class poly { \
            type="polygon"; \
            points[] ={ \
                { \
                    {{X + 0, Y+0},1}, \
                    {{X + W, Y+0},1}, \
                    {{X + W, Y+H},1}, \
                    {{X + 0, Y+H},1} \
                } \
            }; \
        }; \
    };

#define BEZEL_SPACE_Y 0.14
#define BEZEL_Y1 0.2
#define BEZEL_Y2 0.34
#define BEZEL_Y3 0.49
#define BEZEL_Y4 0.62
#define BEZEL_Y5 0.76
#define BEZEL_Y6 0.89

#define BEZEL_SPACE_XT 0.105
#define BEZEL_XT1 (0.14)
#define BEZEL_XT2 (BEZEL_XT1+BEZEL_SPACE_XT*1)
#define BEZEL_XT3 (BEZEL_XT1+BEZEL_SPACE_XT*2)
#define BEZEL_XT4 (0.64)
#define BEZEL_XT5 (BEZEL_XT4+BEZEL_SPACE_XT*1)
#define BEZEL_XT6 (BEZEL_XT4+BEZEL_SPACE_XT*2)

#define BEZEL_SPACE_XB 0.112
#define BEZEL_XB1 (0.065)
#define BEZEL_XB2 (BEZEL_XB1+BEZEL_SPACE_XB*1)
#define BEZEL_XB3 (BEZEL_XB1+BEZEL_SPACE_XB*2)
#define BEZEL_XB4 (0.72)
#define BEZEL_XB5 (BEZEL_XB4+BEZEL_SPACE_XB*1)
#define BEZEL_XB6 (BEZEL_XB4+BEZEL_SPACE_XB*2)

#define MID_LINE_HEIGHT 0.06
#define SMALL_LINE_HEIGHT 0.03

#define NM_SCALE(SCALE) (1*0.75*0.000539957*SCALE) 

#define PT34(X,Y) X*0.75,Y