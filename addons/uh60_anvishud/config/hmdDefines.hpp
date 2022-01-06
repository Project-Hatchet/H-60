//START OUT WITH COLOURS
#define RGBA256(R,G,B,A) {R/256,G/256,B/256,A}
#define common_green RGBA256(110,150,65,1.0)
#define common_yellow RGBA256(230,230,40,1.0)
#define common_red RGBA256(160,30,30,1.0)
#define common_blue RGBA256(40,140,180,1.0)
#define common_purple RGBA256(200,31,120,1.0)

#define TEXT_FMS_L(CLASS,X,Y) \
    class CLASS { \
        type = "text"; \
        align = "right"; \
        scale = 1; \
        pos[] = {{X-0.002*0.8, Y-0.003*0.8}, 1}; \
        right[] = {{X + 0.06*0.8, Y-0.003*0.8}, 1}; \
        down[] = {{X-0.002*0.8, Y + 0.05*0.8}, 1};

#define TEXT_FMS_C(CLASS,X,Y) \
    class CLASS { \
        type = "text"; \
        align = "center"; \
        scale = 1; \
        pos[] = {{X-0.002*0.8, Y-0.003*0.8}, 1}; \
        right[] = {{X + 0.06*0.8, Y-0.003*0.8}, 1}; \
        down[] = {{X-0.002*0.8, Y + 0.05*0.8}, 1};

#define TEXT_FMS_R(CLASS,X,Y) \
    class CLASS { \
        type = "text"; \
        align = "left"; \
        scale = 1; \
        pos[] = {{X-0.002*0.8, Y-0.003*0.8}, 1}; \
        right[] = {{X + 0.06*0.8, Y-0.003*0.8}, 1}; \
        down[] = {{X-0.002*0.8, Y + 0.05*0.8}, 1};

#define TEXT_HMD_L(CLASS,X,Y) \
    class CLASS { \
        type = "text"; \
        align = "right"; \
        scale = 1; \
        pos[] = {{X-0.002*0.8, Y-0.003*0.8}, 1}; \
        right[] = {{X + 0.06*0.8, Y-0.003*0.8}, 1}; \
        down[] = {{X-0.002*0.8, Y + 0.05*0.8}, 1};

#define TEXT_HMD_R(CLASS,X,Y) \
    class CLASS { \
        type = "text"; \
        align = "left"; \
        scale = 1; \
        pos[] = {{X-0.002*0.8, Y-0.003*0.8}, 1}; \
        right[] = {{X + 0.06*0.8, Y-0.003*0.8}, 1}; \
        down[] = {{X-0.002*0.8, Y + 0.05*0.8}, 1};


#define TEXT_HMD_R_SCALE(CLASS,X,Y,SIZE) \
    class CLASS { \
        type = "text"; \
        align = "left"; \
        scale = 1; \
        pos[] = {{X-0.002*SIZE, Y-0.003*SIZE}, 1}; \
        right[] = {{X + 0.06*SIZE, Y-0.003*SIZE}, 1}; \
        down[] = {{X-0.002*SIZE, Y + 0.05*SIZE}, 1};

#define TEXT_SIZE_SMALL 0.8
#define SMALL_LINEHEIGHT 0.035

#define COND_ISNUMBER(INDEX,VALUE) (user##INDEX>(VALUE-1))*(user##INDEX<(VALUE+1))
#define COND_PYLON_ISNUMBER(INDEX,VALUE) (pylonAmmo##INDEX>(VALUE-1))*(pylonAmmo##INDEX<(VALUE+1))
#define PYLON_VAL(INDEX) (pylonAmmo##INDEX)

/*
    modes:
     0 - off
     1 - imperial
     2 - imperial dclt
     3 - metric
     4 - metric dclt
*/

#define COND_METRIC_FULL_ONLY COND_PYLON_ISNUMBER(HMDPylon,3)
#define COND_IMPERIAL_FULL_ONLY COND_PYLON_ISNUMBER(HMDPylon,1)
#define COND_METRIC ((PYLON_VAL(HMDPylon)>2)*(PYLON_VAL(HMDPylon)<5))
#define COND_IMPERIAL ((PYLON_VAL(HMDPylon)>=0)*(PYLON_VAL(HMDPylon)<3))
#define COND_FULL_ONLY (COND_PYLON_ISNUMBER(HMDPylon,1)+COND_PYLON_ISNUMBER(HMDPylon,3))

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

#define LINE(CLASS, WIDTH,X1,Y1,X2,Y2) \
    class CLASS { \
        type="line"; \
        width = WIDTH; \
        points[] = { \
            {{X1, Y1}, 1}, \
            {{X2, Y2}, 1} \
        }; \
    };
