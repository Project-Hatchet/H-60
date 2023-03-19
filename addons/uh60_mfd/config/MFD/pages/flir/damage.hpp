  class flirDamage {
    condition = FLIR_DISABLED;
    class PolygonJet {
      type        = "polygon";
      texture = "z\vtx\addons\uh60_mfd\data\FLIR_Cracked.paa";
      points[] ={
        {
          {{-1, -1},1},
          {{ 2, -1},1},
          {{ 2,  2},1},
          {{-1,  2},1}
        }
      };
    };
    class blackBackground {
      color[] = common_black;
      class bottomPoly {
        type        = "polygon";
        points[] ={
          {
            {{0, 0.95},1},
            {{1, 0.95},1},
            {{1, 1},1},
            {{0, 1},1}
          }
        };
      };
      class errorPoly {
        type        = "polygon";
        points[] ={
          {
            {{0.5 - 0.10, 0.4 - 0.00},1},
            {{0.5 + 0.10, 0.4 - 0.00},1},
            {{0.5 + 0.10, 0.4 + 0.04},1},
            {{0.5 - 0.10, 0.4 + 0.04},1}
          }
        };
      };
      class whiteOverlay {
        color[] = common_white;
        class outline {
          type="line";
          width = 2;
          points[] ={
            {{0.5 - 0.10, 0.4 - 0.00},1},
            {{0.5 + 0.10, 0.4 - 0.00},1},
            {{0.5 + 0.10, 0.4 + 0.04},1},
            {{0.5 - 0.10, 0.4 + 0.04},1},
            {{0.5 - 0.10, 0.4 - 0.00},1}
          };
        };
        TEXT_MID_SCALED(FLIR_FAIL,0.5,0.4,"FLIR FAIL",0.04)
      };
    };
  }; // overlayWrapper