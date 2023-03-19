class Bones {};
#define OFFSET_Y -0.01


class Draw
{
  color[] = common_black;
  COLORED_POLYGON(BG,-0.25*0.1,(-0.9*0.1)-0.01,0.5*0.1,1.75*0.1,common_black)
  class white {
    color[] = common_white;
    class Rails {
      type="line";
      width = 2;
      points[] ={
        {{-0.25 * 0.1, -0.90 * 0.1 + OFFSET_Y},1},
        {{ 0.25 * 0.1, -0.90 * 0.1 + OFFSET_Y},1},
        {{ 0.25 * 0.1,  0.85 * 0.1 + OFFSET_Y},1},
        {{-0.25 * 0.1,  0.85 * 0.1 + OFFSET_Y},1},
        {{-0.25 * 0.1, -0.90 * 0.1 + OFFSET_Y},1}
      };
    };
    TEXT_MID_SCALED(LSRTEXT,(0*0.1),-0.05+OFFSET_Y,"6PD",0.05)
    TEXT_MID_SCALED_SOURCE(AMMO,(0*0.1),0+OFFSET_Y,0.05,"PylonAmmo",0,1,0)
  };
};