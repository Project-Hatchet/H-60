class Bones {};

class Draw
{
  color[] = common_black;
  COLORED_POLYGON(BG,-0.3*0.1,-0.9*0.1,0.6*0.1,1.8*0.1,common_black)
  class white {
    color[] = common_white;
    COLORED_POLYGON(BG,(-0.05*0.1),(-0.7*0.1),(0.1*0.1),(0.1*0.1),common_white)
    COLORED_POLYGON(BG2,(-0.1*0.1),(-0.25*0.1),(0.2*0.1),(0.15*0.1),common_white)
    class Rails {
      type="line";
      width = 5;
      points[] ={
        {{0, -0.7 * 0.1},1},
        {{0, -0.25 * 0.1},1}
      };
    };
    TEXT_MID_SCALED(LSRTEXT,(0*0.1),0.00,"30",0.05)
    TEXT_MID_SCALED_SOURCE(AMMO,(0*0.1),0.04,0.05,"PylonAmmo",0,1,0)
  };
};