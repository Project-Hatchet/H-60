class backgroundWrapper {
	class polygon {
		type        = "polygon";
		texture = "z\vtx\addons\uh60_mfd\data\JVMF.paa";
		points[] ={
			{
				{{0, 0},1},
				{{1, 0},1},
				{{1, 1},1},
				{{0, 1},1}
			}
		};
	};
}; // backgroundWrapper

#define JVMF_LINE_HEIGHT 0.06
#define JVMF_LEFT_ALIGN 0.1
#define JVMF_TOP_MARGIN 0.16

TEXT_LEFT_SCALED(JVMF_MESSAGE_NEW,0.01,0.17,"NEW",0.04)
TEXT_LEFT_SCALED(JVMF_MESSAGE_NEW2,0.01,0.17+0.04,"MSG",0.04)
TEXT_LEFT_SCALED(JVMF_MESSAGE_CYCLE,0.01,0.36,"CYCLE",0.04)
TEXT_LEFT_SCALED(JVMF_MESSAGE_INBOX,0.01,0.36+0.04,"PAGE",0.04)

TEXT_MID_SCALED(JVMF_REPLY_ACK,0.35,JVMF_LINE_HEIGHT * 0.3,"ACK",0.04)
class wilco_wrap {
    color[] = common_yellow;
    TEXT_MID_SCALED(JVMF_REPLY_WILCO,0.64,JVMF_LINE_HEIGHT * 0.3,"WILCO",0.04)
};
class haveco_wrap {
    color[] = common_green;
    TEXT_MID_SCALED(JVMF_REPLY_HAVECO,0.74,JVMF_LINE_HEIGHT * 0.3,"HAVECO",0.04)
};
class cantco_wrap {
    color[] = common_red;
    TEXT_MID_SCALED(JVMF_REPLY_CANTCO,0.86,JVMF_LINE_HEIGHT * 0.3,"CANTCO",0.04)
};
// class reply_options_blue {
//     color[] = common_blue;
//     TEXT_MID_SCALED(JVMF_REPLY_OPTIONS,0.5,JVMF_LINE_HEIGHT * 0.5,"",0.04)
// };

#define JVMF_BORDER_MARGIN 0.02
#define JVMF_BOTTOM_MARGIN 0.14
#define JVMF_LINE(CLASS,X1,Y1,X2,Y2) \
    class CLASS { \
        type="line"; \
        width = 3; \
        points[] = { \
            {{X1, Y1}, 1}, \
            {{X2, Y2}, 1} \
        }; \
    };

class jvmf_type_0 {
	condition=COND_ISNUMBER(JVMF_TYPE,0);
	#include "jvmf\jvmf_freetext.hpp"
};

class jvmf_type_1 {
	condition=COND_ISNUMBER(JVMF_TYPE,1);
	#include "jvmf\jvmf_1.hpp"
};

class jvmf_type_2 {
	// condition=COND_ISNUMBER(JVMF_TYPE,2);
	condition="0";
	#include "jvmf\jvmf_position.hpp"
};

class jvmf_position {
	condition=COND_ISNUMBER(JVMF_TYPE,2);
	#include "jvmf\jvmf_position.hpp"
};

// class jvmf_text {
// 	// condition=COND_ISNUMBER(JVMF_TYPE,0);
// 	condition="0";
// 	#include "jvmf\jvmf_shared.hpp"
// };

#define BOTTOM_TEXT_Y 0.96
TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"FLIR")
TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")
