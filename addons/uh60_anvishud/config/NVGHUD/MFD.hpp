borderBottom = 0;
borderLeft = 0;
borderRight = 0;
borderTop = 0;
//color[] = {0.082,0.608,0.039,1};
enableParallax = 0;
#undef HMD_SIZE
#define HMD_SIZE 0.055
helmetDown[] = {0,-HMD_SIZE,0};
helmetMountedDisplay = 1;
helmetPosition[] = {-(HMD_SIZE/2),(HMD_SIZE/2),0.1};
helmetRight[] = {HMD_SIZE,0,0};
topLeft = ""; // not used because HMD, but still needed
topRight = ""; // not used because HMD, but still needed
bottomLeft = ""; // not used because HMD, but still needed
font="RobotoCondensedLight";
/*
class material {
  ambient[] = {1, 1, 1, 1};
  diffuse[] = {0.5, 0.5, 0.5, 1};
  emissive[] = {100, 100, 100, 50};
};
*/
class Bones {
  #include "bones\base.hpp"
}; // Bones
class Draw {
  condition="(user15>4)";
  #include "draw\base.hpp"
}; // Draw
