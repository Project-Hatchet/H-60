#define DTS_BOT 0.85
#define DTS_WID 0.17
class dts {
    condition = DTS_LOAD_FAIL;
	COLORED_POLYGON(background,(0.5-(DTS_WID/2)),DTS_BOT-0.04,DTS_WID,0.04,common_yellow)
	class black {
		color[] = common_black;
		TEXT_LEFT_SCALED(L1,(0.5-(DTS_WID/2))+0.005,DTS_BOT-0.04,"DTS LOAD FAIL",TAC_LINE_HEIGHT)
		class border {
            type="line";
            width = 4;
            points[] ={
                {{0.5-(DTS_WID/2),DTS_BOT-0.04},1},
                {{0.5+(DTS_WID/2),DTS_BOT-0.04},1},
                {{0.5+(DTS_WID/2),DTS_BOT-0.00},1},
                {{0.5-(DTS_WID/2),DTS_BOT-0.00},1},
                {{0.5-(DTS_WID/2),DTS_BOT-0.04},1}
            };
		};
	};
};

#define RAL_BOT 0.8
#define RAL_WID 0.21
class ralt {
    condition = RAD_ALT_FAIL;
	COLORED_POLYGON(background,(0.5-(RAL_WID/2)),RAL_BOT-0.04,RAL_WID,0.04,common_yellow)
	class black {
		color[] = common_black;
		TEXT_LEFT_SCALED(L1,(0.5-(RAL_WID/2))+0.005,RAL_BOT-0.04,"RAD ALT AGL FAIL",TAC_LINE_HEIGHT)
		class border {
            type="line";
            width = 4;
            points[] ={
                {{0.5-(RAL_WID/2),RAL_BOT-0.04},1},
                {{0.5+(RAL_WID/2),RAL_BOT-0.04},1},
                {{0.5+(RAL_WID/2),RAL_BOT-0.00},1},
                {{0.5-(RAL_WID/2),RAL_BOT-0.00},1},
                {{0.5-(RAL_WID/2),RAL_BOT-0.04},1}
            };
		};
	};
};


class context_menu {
	condition = "(user39>-1)";
    #define INTERACT_LINE_HEIGHT 0.04
    class sel_1 {
        condition = COND_ISNUMBER(39,0);
        INVERTED_VIDEO_LINE(SEL1,0.40,0.25+(INTERACT_LINE_HEIGHT*0),0.2,0.04,"CREATE WAYPT",common_white)
    };
    class sel_2 {
        condition = COND_ISNUMBER(39,1);
        INVERTED_VIDEO_LINE(SEL1,0.40,0.25+(INTERACT_LINE_HEIGHT*1),0.2,0.04,"SLEW FLIR",common_white)
    };
    class sel_3 {
        condition = COND_ISNUMBER(39,2);
        INVERTED_VIDEO_LINE(SEL1,0.40,0.25+(INTERACT_LINE_HEIGHT*2),0.2,0.04,"ZOOM IN",common_white)
    };
    class sel_4 {
        condition = COND_ISNUMBER(39,3);
        INVERTED_VIDEO_LINE(SEL1,0.40,0.25+(INTERACT_LINE_HEIGHT*3),0.2,0.04,"ZOOM OUT",common_white)
    };
    class sel_5 {
        condition = COND_ISNUMBER(39,4);
        INVERTED_VIDEO_LINE(SEL1,0.40,0.25+(INTERACT_LINE_HEIGHT*4),0.2,0.04,"CTR MODE",common_white)
    };
    class sel_6 {
        condition = COND_ISNUMBER(39,5);
        INVERTED_VIDEO_LINE(SEL1,0.40,0.25+(INTERACT_LINE_HEIGHT*5),0.2,0.04,"EXIT",common_white)
    };
};