borderLeft=0;
borderRight=0.25;
borderTop=0;
borderBottom=0;
color[]=common_white;
enableParallax=0;
font="EtelkaMonospacePro";
class material {
	ambient[] = {1, 1, 1, 1};
	diffuse[] = {0.5, 0.5, 0.5, 1};
	emissive[] = {100, 100, 100, 1};
};

class Bones {
        class TAC_CMWS_Offset
        {
            type	= fixed;
            pos[]	= {0.285, 0.757};
        };
};

#define SQUARE_SCALE 1.3
#define BLACK_BACKGROUND \
    class BlackOverlay { \
        color[] = {0.05,0.05,0.05,1}; \
        class BlackPoly \
        { \
            type = "polygon"; \
            width = 2; \
            points[] = { \
                { \
                    {{SQUARE_SCALE*-0.02, SQUARE_SCALE*0.02}, 1}, \
                    {{SQUARE_SCALE*0.02,  SQUARE_SCALE*0.02}, 1}, \
                    {{SQUARE_SCALE*0.02,  SQUARE_SCALE*-0.02}, 1}, \
                    {{SQUARE_SCALE*-0.02, SQUARE_SCALE*-0.02}, 1} \
                } \
            }; \
        };

#define SQUARE_POINTS \
    {{SQUARE_SCALE*-0.02, SQUARE_SCALE*0.02}, 1}, \
    {{SQUARE_SCALE*0.02,  SQUARE_SCALE*0.02}, 1}, \
    {{SQUARE_SCALE*0.02,  SQUARE_SCALE*-0.02}, 1}, \
    {{SQUARE_SCALE*-0.02, SQUARE_SCALE*-0.02}, 1}, \
    {{SQUARE_SCALE*-0.02, SQUARE_SCALE*0.02}, 1},{}

#define TRIANGLE_POINTS \
    {{0.8* 0.00, 0.8*-0.02}, 1}, \
    {{0.8*-0.02, 0.8* 0.02}, 1}, \
    {{0.8* 0.02, 0.8* 0.02}, 1}, \
    {{0.8* 0.00, 0.8*-0.02}, 1}

#define BLACK_BACKGROUND_RADAR \
    BLACK_BACKGROUND \
        class white { \
            color[] = common_white; \
            class TargetLines \
            { \
                type = "line"; \
                width = 3; \
                points[] = { \
                    SQUARE_POINTS, \
                    {{0.8* 0.00, 0.8*-0.02}, 1}, \
                    {{0.8*-0.02, 0.8* 0.02}, 1}, \
                    {{0.8* 0.02, 0.8* 0.02}, 1}, \
                    {{0.8* 0.00, 0.8*-0.02}, 1} \
                }; \
            }; \
        }; \
    };

class Draw {
    condition = COND_SUBPAGE_OR_SUBPAGE(MFD_PAGE_INDEX,ND_MODE_ALL,ND_MODE_CMWS);
    //condition = "1";
    class ND_ALL {
        condition = ASE_DISABLED_NONE;
        #include "nd_cmws_sensor.hpp"
    };
    class ND_NONE {
        condition = ASE_DISABLED;
        TEXT_MID_SCALED(TEXT1,0.5,0.35,"CMWS FAIL",0.04)
        TEXT_MID_SCALED(TEXT2,0.5,0.65,"CMWS FAIL",0.04)
    };
};
