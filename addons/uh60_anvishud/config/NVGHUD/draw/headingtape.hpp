class HeadingScale
{
  type = "scale";
  NeverEatSeaWeed = 1;
  horizontal = 1;
  source = "heading";
  sourceScale = 1;
  width = 5;
  top = 0.1;     // left
  center = 0.5; // center
  bottom = 0.9; // right
  lineXleft = 0.68; // top of lines
  lineYright = 0.72; // bottom of lines
  lineXleftMajor = 0.68; // top of lines
  lineYrightMajor = 0.72; // bottom of lines
  majorLineEach = 3;
  numberEach = 3;
  step = "10";
  stepSize = "0.06";
  align = "center";
  scale = 1;
  pos[] = {0.096, 0.0546+0.58};
  right[] = {0.143, 0.0546+0.58};
  down[] = {0.096, 0.093+0.58};
};

class HeadingCaret {
  type="line";
  width = 4;
  points[] ={
    // forward
    {{0.5, 0.735}, 1}, {{0.5, 0.78}, 1},{},
  }; // points
}; // FOVCenter
class headingCaretNormal {
  condition = "(user0 - heading) > -180";
  class HeadingCaret {
    type="line";
    width = 4;
    points[] ={
      // //caret
      {{0.5, 0.75}, 1, "WaypointDirectionBase",1, "WaypointDirectionCorrection", 1, "WaypointDirectionLimits", 1,{-0.010, 0.015},1},
      {{0.5, 0.75}, 1, "WaypointDirectionBase",1, "WaypointDirectionCorrection", 1, "WaypointDirectionLimits", 1,{ 0.000, 0.000},1},
      {{0.5, 0.75}, 1, "WaypointDirectionBase",1, "WaypointDirectionCorrection", 1, "WaypointDirectionLimits", 1,{ 0.010, 0.015},1}
    }; // points
  }; // HeadingCaret
};
class headingCaretInv {
  condition = "(user0 - heading) < -180";
  class HeadingCaret {
    type="line";
    width = 4;
    points[] ={
      // //caret
      {{0.5, 0.75}, 1, "WaypointDirectionBaseInv",1, "WaypointDirectionCorrectionInv", 1, "WaypointDirectionLimits", 1,{-0.010, 0.015},1},
      {{0.5, 0.75}, 1, "WaypointDirectionBaseInv",1, "WaypointDirectionCorrectionInv", 1, "WaypointDirectionLimits", 1,{ 0.000, 0.000},1},
      {{0.5, 0.75}, 1, "WaypointDirectionBaseInv",1, "WaypointDirectionCorrectionInv", 1, "WaypointDirectionLimits", 1,{ 0.010, 0.015},1}
    }; // points
  }; // HeadingCaret
};