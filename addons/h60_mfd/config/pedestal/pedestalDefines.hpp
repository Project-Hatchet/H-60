// Macros for the pedestal screens (ESIS, clock, flight-director panels).
// Moved with the screens from uh60_config's config/defines/mfdDefines.hpp, values
// unchanged, under a PED_ prefix: uh60_mfd's own mfdDefines.hpp defines macros of
// the same names with different geometry (e.g. LEVEL_BACKGROUND).

#define PED_RGBA256(R,G,B,A) {R/256,G/256,B/256,A}

#define PED_RGB256(R,G,B) {R/256,G/256,B/256}

#define PED_common_white PED_RGBA256(200,200,200,1.0)

#define PED_common_green PED_RGBA256(110,150,65,1.0)

#define PED_pitch_att_blue PED_RGBA256(5,60,140,0.2)

#define PED_pitch_esis_grey PED_RGB256(60,60,60)

#define PED_LEVELP(x) LevelP##x

#define PED_LEVELM(x) LevelM##x

#define PED_TEXT_LEFT_OPEN(CLASS) \
    class CLASS { \
        type = "text"; \
        source = "static"; \
        align = "left"; \
        scale = 1; \
        sourceScale = 1;

    #define PED_PITCH_BONES(X1,X2,Y1,Y2) \
        class Level0 \
        { \
            pos0[] = {X1, Y1}; \
            pos10[] = {X2, Y2}; \
            type = "horizon"; \
            angle = 0; \
        };class LevelP5:Level0{angle=5;};class LevelM5:Level0{angle=-5;};class LevelP10:Level0{angle=10;};class LevelM10:Level0{angle=-10;};class LevelP15:Level0{angle=15;};class LevelM15:Level0{angle=-15;};class LevelP20:Level0{angle=20;};class LevelM20:Level0{angle=-20;};class LevelP25:Level0{angle=25;};class LevelM25:Level0{angle=-25;};class LevelP30:Level0{angle=30;};class LevelM30:Level0{angle=-30;};class LevelP35:Level0{angle=35;};class LevelM35:Level0{angle=-35;};class LevelP40:Level0{angle=40;};class LevelM40:Level0{angle=-40;};class LevelP45:Level0{angle=45;};class LevelM45:Level0{angle=-45;};class LevelP50:Level0{angle=50;};class LevelM50:Level0{angle=-50;};class LevelP55:Level0{angle=55;};class LevelM55:Level0{angle=-55;};class LevelP60:Level0{angle=60;};class LevelM60:Level0{angle=-60;};class LevelP65:Level0{angle=65;};class LevelM65:Level0{angle=-65;};class LevelP70:Level0{angle=70;};class LevelM70:Level0{angle=-70;};class LevelP75:Level0{angle=75;};class LevelM75:Level0{angle=-75;};class LevelP80:Level0{angle=80;};class LevelM80:Level0{angle=-80;};class LevelP85:Level0{angle=85;};class LevelM85:Level0{angle=-85;};class LevelP90:Level0{angle=90;};class LevelM90:Level0{angle=-90;};

    #define PED_LEVEL0(WIDTH) \
        class Level0 \
        { \
            type = "line"; \
            width = 4; \
            points[] = {{"Level0", {WIDTH, 0}, 1}, {"Level0", {-WIDTH, 0}, 1}}; \
        };

    #define PED_LEVEL_BACKGROUND(COLORTOP,COLORBOTTOM,WIDTH) \
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

    #define PED_LEVEL_NARROW(NAME,WIDTH) \
        class NAME : Level0 { \
            type = "line"; \
            points[] = {{#NAME, {WIDTH, 0}, 1}, {#NAME, {-WIDTH, 0}, 1}}; \
        };

    #define PED_LEVEL_WIDE(NAME,WIDTH) \
        class NAME : Level0 { \
            type = "line"; \
            points[] = {{#NAME, {WIDTH, 0}, 1}, {#NAME, {-WIDTH, 0}, 1}}; \
        };

    #define PED_LEVEL_TEXT(LEVEL,BONE,WIDTH) \
            PED_TEXT_LEFT_OPEN(DOUBLES(VAL_L,BONE)) \
                text = LEVEL; \
                pos[] = {QUOTE(BONE), {-WIDTH, -0.032}, 1}; \
                right[] = {QUOTE(BONE), {-(WIDTH-0.06), -0.032}, 1}; \
                down[] = {QUOTE(BONE), {-WIDTH, 0.01}, 1}; \
            }; \
            PED_TEXT_LEFT_OPEN(DOUBLES(VAL_R,BONE)) \
                text = LEVEL; \
                pos[] = {QUOTE(BONE), {(WIDTH+0.03), -0.032}, 1}; \
                right[] = {QUOTE(BONE), {(WIDTH+0.09), -0.032}, 1}; \
                down[] = {QUOTE(BONE), {(WIDTH+0.03), 0.01}, 1}; \
            };

    #define PED_LEVEL_SET(HALF,WHOLE,NARROW,WIDE,TEXT) \
        PED_LEVEL_NARROW(PED_LEVELP(HALF),NARROW) \
        PED_LEVEL_NARROW(PED_LEVELM(HALF),NARROW) \
        PED_LEVEL_TEXT(WHOLE,PED_LEVELM(WHOLE),TEXT) \
        PED_LEVEL_TEXT(WHOLE,PED_LEVELP(WHOLE),TEXT) \
        PED_LEVEL_WIDE(PED_LEVELM(WHOLE),WIDE) \
        PED_LEVEL_WIDE(PED_LEVELP(WHOLE),WIDE)
