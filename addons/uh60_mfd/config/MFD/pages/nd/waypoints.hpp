#define LINE_AND_WAYPT_ND(CNAME,CONDITION,DIST1,DIR1,DIST2,DIR2,COL) \
class CNAME { \
    condition =CONDITION; \
    color[]=common_black; \
    class background_line { \
    	type="line"; \
    	width = 8; \
    	points[] ={ \
            {"ND_WPRotateOffset", 1, DIST1, 1, DIR1, 1}, \
    		{"ND_WPRotateOffset", 1, DIST2, 1, DIR2, 1},{}, \
            SHAPE_STAR3("ND_WPRotateOffset",DIST2,DIR2) \
    	}; \
    }; \
    class main_color { \
        color[]=COL; \
        class main_line { \
        	type="line"; \
        	width = 4; \
        	points[] ={ \
                {"ND_WPRotateOffset", 1, DIST1, 1, DIR1, 1}, \
        		{"ND_WPRotateOffset", 1, DIST2, 1, DIR2, 1},{}, \
                SHAPE_STAR3("ND_WPRotateOffset",DIST2,DIR2) \
        	}; \
        }; \
    }; \
};

class waypoints {
	LINE_AND_WAYPT_ND(WP12,"((user2 > -1) * (user4  > -1))","TAC_WP1_DIST","TAC_WP1_DIR","TAC_WP2_DIST","TAC_WP2_DIR",common_purple)
	LINE_AND_WAYPT_ND(WP23,"((user4 > -1) * (user6  > -1))","TAC_WP2_DIST","TAC_WP2_DIR","TAC_WP3_DIST","TAC_WP3_DIR",common_white)
	LINE_AND_WAYPT_ND(WP34,"((user6 > -1) * (user8  > -1))","TAC_WP3_DIST","TAC_WP3_DIR","TAC_WP4_DIST","TAC_WP4_DIR",common_white)
	LINE_AND_WAYPT_ND(WP45,"((user8 > -1) * (user33 > -1))","TAC_WP4_DIST","TAC_WP4_DIR","TAC_WP5_DIST","TAC_WP5_DIR",common_white)
	LINE_AND_WAYPT_ND(WP56,"((user33 >-1) * (user35 > -1))","TAC_WP5_DIST","TAC_WP5_DIR","TAC_WP6_DIST","TAC_WP6_DIR",common_white)
};