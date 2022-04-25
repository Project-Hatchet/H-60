#define DTS_BOT 0.85
#define DTS_WID 0.17
class dts {
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