
#define FREETEXT_LINE_SCALING 0.04
class jvmf_border {
    color[] = common_blue;
    TEXT_MID_SCALED(receive_text,0.28,0.1,"RECEIVE QUEUE",0.04)
    class receive_queue {
        type="line";
        width = 2;
        points[] = {
            {{0.12,0.10}, 1},
            {{0.41,0.10}, 1},
            {{0.41,0.90}, 1},
            {{0.12,0.90}, 1},
            {{0.12,0.10}, 1}
        };
    }; // title_box
    TEXT_MID_SCALED(freetext,1-0.3,0.1,"FREETEXT",0.04)
	TEXT_LEFT_SCALED(from,0.45,0.2-(FREETEXT_LINE_SCALING*1),"FROM/TO",0.04)
	TEXT_LEFT_SCALED(reply,0.45,0.2+(FREETEXT_LINE_SCALING*16),"STATUS",0.04)
    class message_box {
        type="line";
        width = 2;
        points[] = {
            {{1-0.05,0.100}, 1},
            {{1-0.56,0.100}, 1},
            {{1-0.56,0.900}, 1},
            {{1-0.05,0.900}, 1},
            {{1-0.05,0.100}, 1},{},
            {{1-0.05,0.205}, 1},
            {{1-0.56,0.205}, 1}
        };
    }; // message_box
};
TEXT_LEFT_SCALED_USERTEXT(fromText,0.58,0.2-(FREETEXT_LINE_SCALING*1),30,0.04)
TEXT_LEFT_SCALED_USERTEXT(replyLabel,0.58,0.2+(FREETEXT_LINE_SCALING*16),41,0.04)
// class selected_background {
// 	color[] = {0.02,0.05,0.02,0.1};
// 	class polygon {
// 		type="polygon";
// 		points[] ={
// 			{
// 				{{0.12,0.20}, 1},
// 				{{0.41,0.20}, 1},
// 				{{0.41,0.20+FREETEXT_LINE_SCALING}, 1},
// 				{{0.12,0.20+FREETEXT_LINE_SCALING}, 1}
// 			}
// 		}; // points
// 	}; // polygon
// }; // selected_background
class top_border {
	color[] = common_green;
    class receive_queue {
        type="line";
        width = 2;
        points[] = {
            {{0.05,0.02}, 1},
            {{0.41,0.02}, 1},
            {{0.41,0.07}, 1},
            {{0.05,0.07}, 1},
            {{0.05,0.02}, 1}
        };
    }; // title_box
    class message_box {
        type="line";
        width = 2;
        points[] = {
            {{1-0.05,0.02}, 1},
            {{1-0.56,0.02}, 1},
            {{1-0.56,0.07}, 1},
            {{1-0.05,0.07}, 1},
            {{1-0.05,0.02}, 1}
        };
    }; // message_box
};