class trimLine {
  type="line";
  width = 4;
  points[] ={
    {{0.3, 0.85}, 1},
    {{0.7, 0.85}, 1},{},
    {{0.5-0.02,0.85},1},{{0.5-0.02,0.85-0.04},1},{},
    {{0.5+0.02,0.85},1},{{0.5+0.02,0.85-0.04},1},{}
  }; // points
}; // trimLine

class trimBall {
  type="line";
  width = 6;
  points[] ={
    CIRCLE36("TrimBallX",0.0150),
    CIRCLE36("TrimBallX",0.0125),
    CIRCLE36("TrimBallX",0.0100),
    CIRCLE36("TrimBallX",0.0075),
    CIRCLE36("TrimBallX",0.0050),
    CIRCLE36("TrimBallX",0.0025)
  }; // points
}; // trimBall