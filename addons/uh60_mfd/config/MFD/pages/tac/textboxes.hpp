class hook {
  condition = COND_ISNUMPYLON(7,2);
  color[] = common_black;
  COLORED_POLYGON(background,(0.5-0.15),0.99-0.16,0.3,0.16,common_black)
  class white {
    color[] = common_white;
    TEXT_MID_SCALED_USERTEXT(L0,0.5,0.99-0.16,45,TAC_LINE_HEIGHT)
    TEXT_MID_SCALED_USERTEXT(L1,0.5,0.99-0.12,46,TAC_LINE_HEIGHT)
    TEXT_MID_SCALED_USERTEXT(L2,0.5,0.99-0.08,47,TAC_LINE_HEIGHT)
    TEXT_MID_SCALED_USERTEXT(L3,0.5,0.99-0.04,48,TAC_LINE_HEIGHT)
    class border {
            type="line";
            width = 2;
            points[] ={
                {{0.5-0.15,0.99-0.16},1},
                {{0.5+0.15,0.99-0.16},1},
                {{0.5+0.15,0.99-0.00},1},
                {{0.5-0.15,0.99-0.00},1},
                {{0.5-0.15,0.99-0.16},1}
            };
    };
  };
};