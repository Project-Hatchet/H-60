class MFD_PFD_TEST
{
  topLeft="MFD3_LH";
  topRight="MFD3_RH";
  bottomLeft="MFD3_LD";
    borderLeft = 0;
    borderRight = 0;
    borderTop = 0;
    borderBottom = 0;
    enableParallax = 0;
  color[] = common_white;
  class material
  {
   ambient[] = {1, 1, 1, 1};
   diffuse[] = {0.5, 0.5, 0.5, 1};
   emissive[] = {0, 0, 0, 1};
  };
    class Pos10Vector
    {
        type = "vector";
        pos0[] = {0.5, 0.5};
        pos10[] = {1.225, 1.1};
    };
    class Bones
    {
        class PlaneOrientation
        {
            type = "fixed";
            pos[] = {0.5, 0.4};
        };
        class WeaponAim
        {
            type = "vector";
            source = "weapon";
            pos0[] = {0.5, 0.555};
            pos10[] = {1.5, 1.555};
        };
        class Velocity
        {
            type = "vector";
            source = "velocityToView";
            pos0[] = {0.5, 0.53};
            pos10[] = {1.5, 1.53};
        };
    PITCH_BONES(0.5,0.6,0.3,0.4)
    };
    class Draw
    {
        enableParallax = 0;
        class Horizon
        {
            clipTL[] = {0.35, 0.05};
            clipBR[] = {0.65, 0.5};
            class Dimmed
            {
        class polygon_top {
          color[] = pitch_att_blue;
          class background {
            type = "polygon";
            points[] ={
              {
                {"Levelp90",{-0.5, 0},1},
                {"Levelp90",{0.5, 0},1},
                {"Level0",{0.5, 0},1},
                {"Level0",{-0.5, 0},1}
              }
            };
          };
        }; // polygon_top
        class polygon_bottom {
          color[] = pitch_att_orange;
          class background {
            type = "polygon";
            points[] ={
              {
                {"Level0",{-0.5, 0},1},
                {"Level0",{0.5, 0},1},
                {"LevelM90",{0.5, 0},1},
                {"LevelM90",{-0.5, 0},1}
              }
            };
          };
        }; // polygon_bottom

        class clip_pitchLadder {
                clipTL[] = {0, 0.1};
                clipBR[] = {1, 15};
          class clip_levels {
            LEVEL_SET(5,10,0.02,0.05,0.08)
            LEVEL_SET(15,20,0.02,0.05,0.08)
            LEVEL_SET(25,30,0.02,0.05,0.08)
            LEVEL_SET(35,40,0.02,0.05,0.08)
            LEVEL_SET(45,50,0.02,0.05,0.08)
            LEVEL_SET(55,60,0.02,0.05,0.08)
            LEVEL_SET(65,70,0.02,0.05,0.08)
            LEVEL_SET(75,80,0.02,0.05,0.08)
            LEVEL_SET(85,90,0.02,0.05,0.08)
          }; // clip_levels
        }; // clip_pitchLadder
            }; // Dimmed
        }; // Horizon
    };
};
