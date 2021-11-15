
#define FREETEXT_LINE_SCALING 0.04
class jvmf_border {
    color[] = common_blue;
    TEXT_MID_SCALED(receive_text,0.28,0.1,"RECEIVE QUEUE",0.04)
    class receive_queue {
        type="line";
        width = 2;
        points[] = {
            {{0.12,0.10}, 1},
            {{0.48,0.10}, 1},
            {{0.48,0.90}, 1},
            {{0.12,0.90}, 1},
            {{0.12,0.10}, 1}
        };
    }; // title_box
    TEXT_MID_SCALED(freetext,1-0.3,0.1,"FREETEXT",0.04)
	TEXT_LEFT_SCALED(from,0.54,0.2-(FREETEXT_LINE_SCALING*1),"FROM",0.04)
    class message_box {
        type="line";
        width = 2;
        points[] = {
            {{1-0.12,0.100}, 1},
            {{1-0.48,0.100}, 1},
            {{1-0.48,0.900}, 1},
            {{1-0.12,0.900}, 1},
            {{1-0.12,0.100}, 1},{},
            {{1-0.12,0.205}, 1},
            {{1-0.48,0.205}, 1}
        };
    }; // message_box
};
class selected_background {
	color[] = {0.02,0.05,0.02,0.1};
	class polygon {
		type="polygon";
		points[] ={
			{
				{{0.12,0.20}, 1},
				{{0.48,0.20}, 1},
				{{0.48,0.20+FREETEXT_LINE_SCALING}, 1},
				{{0.12,0.20+FREETEXT_LINE_SCALING}, 1}
			}
		}; // points
	}; // polygon
}; // selected_background
class top_border {
	color[] = common_green;
    class receive_queue {
        type="line";
        width = 2;
        points[] = {
            {{0.05,0.02}, 1},
            {{0.48,0.02}, 1},
            {{0.48,0.07}, 1},
            {{0.05,0.07}, 1},
            {{0.05,0.02}, 1}
        };
    }; // title_box
    class message_box {
        type="line";
        width = 2;
        points[] = {
            {{1-0.05,0.02}, 1},
            {{1-0.48,0.02}, 1},
            {{1-0.48,0.07}, 1},
            {{1-0.05,0.07}, 1},
            {{1-0.05,0.02}, 1}
        };
    }; // message_box
};

TEXT_LEFT_SCALED(freetext00,0.65,0.2-+(FREETEXT_LINE_SCALING*1),"SENDR01",0.042)
TEXT_LEFT_SCALED(freetext01,0.13,0.2," > ? FRTXT SENDR01 2300              This is an example message",0.042)
TEXT_LEFT_SCALED(freetext02,0.13,0.2+(FREETEXT_LINE_SCALING*1),"XXXXXXXXX-XXXXXXXXX-XX         XX-XXXXXXXXX-XXXXXXXXX",0.042)
TEXT_LEFT_SCALED(freetext03,0.13,0.2+(FREETEXT_LINE_SCALING*2),"XXXXXXXXX-XXXXXXXXX-XX         XX-XXXXXXXXX-XXXXXXXXX",0.042)
TEXT_LEFT_SCALED(freetext04,0.13,0.2+(FREETEXT_LINE_SCALING*3),"XXXXXXXXX-XXXXXXXXX-XX         XX-XXXXXXXXX-XXXXXXXXX",0.042)
TEXT_LEFT_SCALED(freetext05,0.13,0.2+(FREETEXT_LINE_SCALING*4),"XXXXXXXXX-XXXXXXXXX-XX         XX-XXXXXXXXX-XXXXXXXXX",0.042)
TEXT_LEFT_SCALED(freetext06,0.13,0.2+(FREETEXT_LINE_SCALING*5),"XXXXXXXXX-XXXXXXXXX-XX         XX-XXXXXXXXX-XXXXXXXXX",0.042)
TEXT_LEFT_SCALED(freetext07,0.13,0.2+(FREETEXT_LINE_SCALING*6),"XXXXXXXXX-XXXXXXXXX-XX         XX-XXXXXXXXX-XXXXXXXXX",0.042)
TEXT_LEFT_SCALED(freetext08,0.13,0.2+(FREETEXT_LINE_SCALING*7),"XXXXXXXXX-XXXXXXXXX-XX         XX-XXXXXXXXX-XXXXXXXXX",0.042)
TEXT_LEFT_SCALED(freetext09,0.13,0.2+(FREETEXT_LINE_SCALING*8),"XXXXXXXXX-XXXXXXXXX-XX         XX-XXXXXXXXX-XXXXXXXXX",0.042)
TEXT_LEFT_SCALED(freetext10,0.13,0.2+(FREETEXT_LINE_SCALING*9),"XXXXXXXXX-XXXXXXXXX-XX         XX-XXXXXXXXX-XXXXXXXXX",0.042)

