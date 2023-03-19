#define LINE_AND_WAYPT(CNAME,CONDITION,DIST1,DIR1,DIST2,DIR2,COL) \
class CNAME { \
    condition =CONDITION; \
    color[]=common_black; \
    class background_line { \
      type="line"; \
      width = 8; \
      points[] ={ \
            {"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, DIST1, 1, DIR1, 1}, \
        {"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, DIST2, 1, DIR2, 1},{}, \
            SHAPE_STAR2("TAC_SELF_DIST","TAC_SELF_DIR",DIST2,DIR2) \
      }; \
    }; \
    class main_color { \
        color[]=COL; \
        class main_line { \
          type="line"; \
          width = 4; \
          points[] ={ \
                {"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, DIST1, 1, DIR1, 1}, \
            {"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, DIST2, 1, DIR2, 1},{}, \
                SHAPE_STAR2("TAC_SELF_DIST","TAC_SELF_DIR",DIST2,DIR2) \
          }; \
        }; \
    }; \
};

class waypoints {
  LINE_AND_WAYPT(WP12,"((user2 > -1) * (user4  > -1))","TAC_WP1_DIST","TAC_WP1_DIR","TAC_WP2_DIST","TAC_WP2_DIR",common_purple)
  LINE_AND_WAYPT(WP23,"((user4 > -1) * (user6  > -1))","TAC_WP2_DIST","TAC_WP2_DIR","TAC_WP3_DIST","TAC_WP3_DIR",common_white)
  LINE_AND_WAYPT(WP34,"((user6 > -1) * (user8  > -1))","TAC_WP3_DIST","TAC_WP3_DIR","TAC_WP4_DIST","TAC_WP4_DIR",common_white)
  LINE_AND_WAYPT(WP45,"((user8 > -1) * (user33 > -1))","TAC_WP4_DIST","TAC_WP4_DIR","TAC_WP5_DIST","TAC_WP5_DIR",common_white)
  LINE_AND_WAYPT(WP56,"((user33 >-1) * (user35 > -1))","TAC_WP5_DIST","TAC_WP5_DIR","TAC_WP6_DIST","TAC_WP6_DIR",common_white)
};

class test {
  condition = "0";
  color[] = common_white;
  class plane {
    type="line";
    width = 8;
    points[] ={
      {"TAC_WP1_DIST", 1, "TAC_WP1_DIR", 1, {0,0}, 1},
      {"TAC_WP2_DIST", 1, "TAC_WP2_DIR", 1, {0,0}, 1},
      {"TAC_WP3_DIST", 1, "TAC_WP3_DIR", 1, {0,0}, 1},
      {"TAC_WP4_DIST", 1, "TAC_WP4_DIR", 1, {0,0}, 1},
      {"TAC_WP5_DIST", 1, "TAC_WP5_DIR", 1, {0,0}, 1},
      {"TAC_WP6_DIST", 1, "TAC_WP6_DIR", 1, {0,0}, 1}
    };
  };
};