class blue_labels {
    color[] = common_blue;
    #define JVMF_LABELS_LEFT 0.3
    TEXT_MID_MID(JVMF_MESSAGE_TYPE,0.5,JVMF_TOP_MARGIN - (JVMF_LINE_HEIGHT * 1),"5-LINE CLOSE AIR SUPPORT BRIEF")
    TEXT_RIGHT_MID(JVMF_TITLE_LABEL,JVMF_LABELS_LEFT,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 0),"MSG TITLE")
    TEXT_RIGHT_MID(JVMF_LINE1,JVMF_LABELS_LEFT,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 1),"GAME PLAN")
    TEXT_RIGHT_MID(JVMF_LINE2,JVMF_LABELS_LEFT,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 2),"FRIENDLY MARK")
    TEXT_RIGHT_MID(JVMF_LINE3,JVMF_LABELS_LEFT,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 3),"TARGET POS")
    TEXT_RIGHT_MID(JVMF_LINE4,JVMF_LABELS_LEFT,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 4),"TARGET DESCR")
    TEXT_RIGHT_MID(JVMF_LINE6,JVMF_LABELS_LEFT,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 6),"REMARKS")
};
#define JVMF_LEFT_PADDING 0.25
TEXT_LEFT_MID_USERTEXT(JVMF_TITLE,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 0),30)
TEXT_LEFT_MID_USERTEXT(JVMF_LINE1,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 1),31)
TEXT_LEFT_MID_USERTEXT(JVMF_LINE2,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 2),32)
TEXT_LEFT_MID_USERTEXT(JVMF_LINE3,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 3),33)
TEXT_LEFT_MID_USERTEXT(JVMF_LINE4,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 4),34)
TEXT_LEFT_MID_USERTEXT(JVMF_LINE5,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 5),35)
TEXT_LEFT_MID_USERTEXT(JVMF_LINE6,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 6),36)
TEXT_LEFT_MID_USERTEXT(JVMF_LINE7,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 7),37)
TEXT_LEFT_MID_USERTEXT(JVMF_LINE8,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 8),38)
TEXT_LEFT_MID_USERTEXT(JVMF_LINE9,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 9),39)
TEXT_LEFT_MID_USERTEXT(JVMF_LINE10,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 10),40)
class reply_wrapper {
    color[] = common_blue;
    TEXT_RIGHT_MID(JVMF_REPLY_LABEL,JVMF_LABELS_LEFT,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 11),"STATUS")
};
TEXT_LEFT_MID_USERTEXT(JVMF_REPLY,JVMF_LEFT_ALIGN + JVMF_LEFT_PADDING,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 11),41)

TEXT_LEFT_MID_USERTEXT(JVMF_MESSAGE_INBOX,0.35,JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 12.5),42)

class jvmf_border {
    color[] = common_blue;
    class title_box {
        type="line";
        width = 3;
        points[] = {
            {{JVMF_LEFT_ALIGN - JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN - JVMF_LINE_HEIGHT}, 1},
            {{1 - JVMF_LEFT_ALIGN + JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN - JVMF_LINE_HEIGHT}, 1},
            {{1 - JVMF_LEFT_ALIGN + JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN + JVMF_LINE_HEIGHT}, 1},
            {{JVMF_LEFT_ALIGN - JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN + JVMF_LINE_HEIGHT}, 1},
            {{JVMF_LEFT_ALIGN - JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN - JVMF_LINE_HEIGHT}, 1}
        };
    }; // title_box
    #define BOX_LEFT (JVMF_LEFT_ALIGN - JVMF_BORDER_MARGIN)
    #define BOX_RIGHT (1 - JVMF_LEFT_ALIGN + JVMF_BORDER_MARGIN)
    #define LINE_Y(LINE) (JVMF_TOP_MARGIN+(JVMF_LINE_HEIGHT*LINE))
    JVMF_LINE(HORIZ_0,BOX_LEFT,LINE_Y(0),BOX_RIGHT,LINE_Y(0))
    JVMF_LINE(HORIZ_2,BOX_LEFT,LINE_Y(2),BOX_RIGHT,LINE_Y(2))
    JVMF_LINE(HORIZ_3,BOX_LEFT,LINE_Y(3),BOX_RIGHT,LINE_Y(3))
    JVMF_LINE(HORIZ_4,BOX_LEFT,LINE_Y(4),BOX_RIGHT,LINE_Y(4))
    JVMF_LINE(HORIZ_6,BOX_LEFT,LINE_Y(6),BOX_RIGHT,LINE_Y(6))
    JVMF_LINE(VERTICAL,(JVMF_LEFT_ALIGN+JVMF_LEFT_PADDING-JVMF_BORDER_MARGIN),LINE_Y(0),(JVMF_LEFT_ALIGN+JVMF_LEFT_PADDING-JVMF_BORDER_MARGIN),LINE_Y(12))
    class content_box {
        type="line";
        width = 3;
        points[] = {
            {{1 - JVMF_LEFT_ALIGN + JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN + JVMF_LINE_HEIGHT}, 1},
            {{1 - JVMF_LEFT_ALIGN + JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 11)}, 1},
            {{JVMF_LEFT_ALIGN - JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 11)}, 1},
            {{JVMF_LEFT_ALIGN - JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN + JVMF_LINE_HEIGHT}, 1}
        };
    }; // content_box
    class reply_box {
        type="line";
        width = 3;
        points[] = {
            {{1 - JVMF_LEFT_ALIGN + JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 11)}, 1},
            {{1 - JVMF_LEFT_ALIGN + JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 12)}, 1},
            {{JVMF_LEFT_ALIGN - JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 12)}, 1},
            {{JVMF_LEFT_ALIGN - JVMF_BORDER_MARGIN, JVMF_TOP_MARGIN + (JVMF_LINE_HEIGHT * 11)}, 1}
        };
    }; // content_box
}; // jvmf_border
