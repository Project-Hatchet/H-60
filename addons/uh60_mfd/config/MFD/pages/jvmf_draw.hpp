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

TEXT_LEFT_MID_USERTEXT(JVMF_MESSAGE_INBOX,0.01,0.38,42)

TEXT_MID_MID(JVMF_REPLY_ACK,0.14,JVMF_LINE_HEIGHT * 0.2,"ACK")
class wilco_wrap {
    color[] = common_yellow;
    TEXT_MID_MID(JVMF_REPLY_WILCO,0.24,JVMF_LINE_HEIGHT * 0.2,"WILCO")
};
class haveco_wrap {
    color[] = common_green;
    TEXT_MID_MID(JVMF_REPLY_HAVECO,0.74,JVMF_LINE_HEIGHT * 0.2,"HAVECO")
};
class cantco_wrap {
    color[] = common_red;
    TEXT_MID_MID(JVMF_REPLY_CANTCO,0.86,JVMF_LINE_HEIGHT * 0.2,"CANTCO")
};
class reply_options_blue {
    color[] = common_blue;
    TEXT_MID_MID(JVMF_REPLY_OPTIONS,0.5,JVMF_LINE_HEIGHT * 0.5,"REPLY OPTIONS")
};

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
	#include "jvmf\jvmf_0.hpp"
};

class jvmf_type_1 {
	condition=COND_ISNUMBER(JVMF_TYPE,1);
	#include "jvmf\jvmf_1.hpp"
};

class jvmf_type_2 {
	condition=COND_ISNUMBER(JVMF_TYPE,2);
	#include "jvmf\jvmf_2.hpp"
};

#define BOTTOM_TEXT_Y 0.96
TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"FLIR")
TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")
