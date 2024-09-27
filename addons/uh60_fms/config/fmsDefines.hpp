//START OUT WITH COLOURS
#define RGBA256(R,G,B,A) {R/256,G/256,B/256,A}
#define common_green RGBA256(20,256,20,1.0)

#define TEXT_FMS_SCALED(CLASS,X,Y,SCALE,ALIGN) \
  class CLASS { \
    type = "text"; \
    align = ALIGN; \
    scale = 1; \
    pos[] = {{X, Y}, 1}; \
    right[] = {{X + (SCALE*1.32), Y}, 1}; \
    down[] = {{X, Y + SCALE}, 1};


#define TEXT_FMS_L_SCALE(CLASS,X,Y,SCALE) \
  TEXT_FMS_SCALED(CLASS,X,Y,SCALE,"right")

#define TEXT_FMS_C_SCALE(CLASS,X,Y,SCALE) \
  TEXT_FMS_SCALED(CLASS,X,Y,SCALE,"center")

#define TEXT_FMS_R_SCALE(CLASS,X,Y,SCALE) \
  TEXT_FMS_SCALED(CLASS,X,Y,SCALE,"left")

#define TEXT_FMS_L(CLASS,X,Y) \
  TEXT_FMS_SCALED(CLASS,X,Y,0.065,"right")

#define TEXT_FMS_C(CLASS,X,Y) \
  TEXT_FMS_SCALED(CLASS,X,Y,0.065,"center")

#define TEXT_FMS_R(CLASS,X,Y) \
  TEXT_FMS_SCALED(CLASS,X,Y,0.065,"left")

#define TEXT_FMS_L_STATIC_SCALE(CLASS,X,Y,TEXT,SCALE) \
  TEXT_FMS_L_SCALE(CLASS,X,Y,SCALE) \
    source = "static"; \
    text = TEXT; \
  };

#define TEXT_FMS_R_STATIC_SCALE(CLASS,X,Y,TEXT,SCALE) \
  TEXT_FMS_R_SCALE(CLASS,X,Y,SCALE) \
    source = "static"; \
    text = TEXT; \
  };

#define TEXT_FMS_C_STATIC_SCALE(CLASS,X,Y,TEXT,SCALE) \
  TEXT_FMS_C_SCALE(CLASS,X,Y,SCALE) \
    source = "static"; \
    text = TEXT; \
  };

#define TEXT_FMS_RS(CLASS,X,Y) \
  class CLASS { \
    type = "text"; \
    align = "left"; \
    scale = 0.7; \
    pos[] = {{X-0.002, Y-0.004}, 1}; \
    right[] = {{X + 0.1, Y-0.004}, 1}; \
    down[] = {{X-0.002, Y + 0.079}, 1};

#define FMS_HALF_LINE 0.0275
#define FMS_MARGIN_L 0.05
#define FMS_MARGIN_R 1-0.1
#define FMS_YHEAD 0.1
#define FMS_Y1 0.24
#define FMS_Y12 0.305
#define FMS_Y2 0.385
#define FMS_Y22 0.45
#define FMS_Y3 0.53
#define FMS_Y32 0.60
#define FMS_Y4 0.67
#define FMS_Y42 0.74
#define FMS_Y5 0.81
#define FMS_Y52 0.86
#define FMS_Y_HALF 0.0325
#define FMS_MARGIN_ARR 0.07

#define COND_ISNUMBER(INDEX,VALUE) (user##INDEX>(VALUE-1))*(user##INDEX<(VALUE+1))
#define FMS_PAGE_MENU 0
#define FMS_LISTS_MENU 1
#define FMS_LISTS_STARTUP_1 2
#define FMS_LISTS_STARTUP_2 3
#define FMS_PAGE_NAV_MENU 4
#define FMS_PAGE_NAV_WAYPOINT 5
#define FMS_PAGE_PERFORMANCE 6
#define FMS_LISTS_SHUTDOWN_1 7
#define FMS_LISTS_SHUTDOWN_2 8
#define FMS_PAGE_NAV_IMPORT 9
#define FMS_PAGE_CMWS 10
#define FMS_PAGE_NAV_LOCATIONS_LIST 11
#define FMS_PAGE_NAV_LOCATIONS_SEL 12
#define FMS_PAGE_WPN 13
#define FMS_PAGE_MSN 14
#define FMS_PAGE_FLIR 15
#define FMS_PAGE_SKR 16
#define FMS_PAGE_RDR 17
#define FMS_PAGE_HMD 18
#define FMS_PAGE_HUD 19
#define FMS_PAGE_PERFPLAN 20
#define FMS_PAGE_COMM 21
#define FMS_PAGE_COMM_ACRE 22
#define FMS_PAGE_COMM_INFO_ACRE 23
#define FMS_PAGE_COMM_PRESETS_ACRE 24

#define FMS_L_PAGE_INDEX 31
#define FMS_R_PAGE_INDEX 32

#define TRIANGLE(CLASS,X,Y,SCALE,DIRECTION) \
  class CLASS \
  { \
    type    = "polygon"; \
    points[] = \
    { \
      { \
        {{X + 0.0, Y + (0.05*SCALE*DIRECTION)},1}, \
        {{X + (0.05*SCALE), Y},1}, \
        {{X - (0.05*SCALE), Y},1} \
      } \
    }; \
  };