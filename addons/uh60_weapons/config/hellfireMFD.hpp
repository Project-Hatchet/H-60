class Bones
{
};

#define HELLFIREANGLE(X,Y,SCALE,DEG,RADIUS) \
  {{(X*SCALE) + ANGLEX(DEG,RADIUS * SCALE), (Y*SCALE) + ANGLEY(DEG,RADIUS * SCALE) }, 1}

#define HELLFIREPOINTS(X,Y,SCALE) \
  {{(X + -0.1) * SCALE, (Y + -0.30) * SCALE}, 1}, \
  {{(X +  0.1) * SCALE, (Y + -0.30) * SCALE}, 1}, \
  {{(X +  0.1) * SCALE, (Y +  0.30) * SCALE}, 1}, \
  {{(X + -0.1) * SCALE, (Y +  0.30) * SCALE}, 1}, \
  {{(X + -0.1) * SCALE, (Y + -0.30) * SCALE}, 1}, {}, \
  {{(X + -0.1) * SCALE, (Y + -0.38) * SCALE}, 1}, \
  {{(X +  0.1) * SCALE, (Y + -0.38) * SCALE}, 1}, \
  {{(X +  0.1) * SCALE, (Y + -0.30) * SCALE}, 1}, \
  {{(X + -0.1) * SCALE, (Y + -0.30) * SCALE}, 1}, \
  {{(X + -0.1) * SCALE, (Y + -0.38) * SCALE}, 1},{}, \
  HELLFIREANGLE(X,(Y+-0.38),SCALE,(90+(15*00)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*01)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*02)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*03)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*04)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*05)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*06)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*07)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*08)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*09)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*10)),0.1), \
  HELLFIREANGLE(X,(Y+-0.43),SCALE,(90+(15*11)),0.1), \
  HELLFIREANGLE(X,(Y+-0.38),SCALE,(90+(15*12)),0.1)

#define HELLFIRE_BG(X,Y,SCALE) \
  COLORED_POLYGON(BG,((X - 0.1) * SCALE),((Y - 0.53) * SCALE),0.02,(0.8*SCALE),common_black)

#define EMPTY_BG(X,Y,SCALE) \
  COLORED_POLYGON(BG,((X - (0.1/2)) * SCALE),((Y - (0.53/2)) * SCALE),0.01,(0.4*SCALE),common_white)

class Draw
{
  color[] = common_black;
  class MSL1 {
    condition = "PylonAmmo >0";
    HELLFIRE_BG(-0.2,-0.5,0.1)
    class white {
      color[] = common_white;
      class line {
        type="line";
        width=2;
        points[] = {HELLFIREPOINTS(-0.2,-0.5,0.1)};
      };
      TEXT_MID_SCALED(LSRTEXT,(-0.2*0.1),(-0.8*0.1),"L",0.05)
    };
  };
  class MSL2 {
    condition = "PylonAmmo >1";
    HELLFIRE_BG(0.2,-0.5,0.1)
    class white {
      color[] = common_white;
      class line {
        type="line";
        width=2;
        points[] = {HELLFIREPOINTS(0.2,-0.5,0.1)};
      };
      TEXT_MID_SCALED(LSRTEXT,(0.2*0.1),(-0.8*0.1),"L",0.05)
    };
  };
  class MSL3 {
    condition = "PylonAmmo >2";
    HELLFIRE_BG(0.2,0.5,0.1)
    class white {
      color[] = common_white;
      class line {
        type="line";
        width=2;
        points[] = {HELLFIREPOINTS(0.2,0.5,0.1)};
      };
      TEXT_MID_SCALED(LSRTEXT,(0.2*0.1),(0.2*0.1),"L",0.05)
    };
  };
  class MSL4 {
    condition = "PylonAmmo >3";
    HELLFIRE_BG(-0.2,0.5,0.1)
    class white {
      color[] = common_white;
      class line {
        type="line";
        width=2;
        points[] = {HELLFIREPOINTS(-0.2,0.5,0.1)};
      };
      TEXT_MID_SCALED(LSRTEXT,(-0.2*0.1),(0.2*0.1),"L",0.05)
    };
  };
  class emptyRacks {
    color[] = common_white;
    class MSL1 {
      condition = "PylonAmmo < 1";
      EMPTY_BG(-0.2,-0.5,0.1)
    };
    class MSL2 {
      condition = "PylonAmmo < 2";
      EMPTY_BG(0.2,-0.5,0.1)
    };
    class MSL3 {
      condition = "PylonAmmo < 3";
      EMPTY_BG(0.2,0.5,0.1)
    };
    class MSL4 {
      condition = "PylonAmmo < 4";
      EMPTY_BG(-0.2,0.5,0.1)
    };
  };
};