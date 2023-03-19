class backgroundWrapper {
  color[] = {0,0,0,0.05};
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

class HEADER_BARS {
  type="line";
  width = 10;
  points[] ={
    {{0, 0.18},1},
    {{1, 0.18},1},{},
    {{0, 0.18 + 0.015},1},
    {{1, 0.18 + 0.015},1},
  };
}; // HEADER_BARS

TEXT_FMS_C(HEADER_TIME,0.5,0.03)
  source = "time";
  text = "%H:%M:%S";
};

