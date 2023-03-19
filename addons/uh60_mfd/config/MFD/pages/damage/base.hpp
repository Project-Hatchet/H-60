class damage {
  class backgroundWrapper {
  color[] = common_black;
    class polygon {
      type        = "polygon";
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
  class variant1 {
    class warning {
      color[] = common_black;
      class errorPoly {
        type        = "polygon";
        points[] ={
          {
            {{0.5 - 0.10, 0.5 - 0.00},1},
            {{0.5 + 0.10, 0.5 - 0.00},1},
            {{0.5 + 0.10, 0.5 + 0.04},1},
            {{0.5 - 0.10, 0.5 + 0.04},1}
          }
        };
      };
      class white {
        color[] = common_white;
        class outline {
          type="line";
          width = 2;
          points[] ={
            {{0.5 - 0.10, 0.5 - 0.00},1},
            {{0.5 + 0.10, 0.5 - 0.00},1},
            {{0.5 + 0.10, 0.5 + 0.04},1},
            {{0.5 - 0.10, 0.5 + 0.04},1},
            {{0.5 - 0.10, 0.5 - 0.00},1}
          };
        };
        TEXT_MID_SCALED(FLIR_FAIL,0.5,0.5,"MFD FAIL",0.04)
      };
    };
  };
};