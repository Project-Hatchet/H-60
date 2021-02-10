class HEADER_BARS {
  type="line";
  width = 10;
  points[] ={
    {{0, 0.2},1},
    {{1, 0.2},1},{},
    {{0, 0.215},1},
    {{1, 0.215},1},
  };
}; // HEADER_BARS

TEXT_FMS_C(HEADER_TIME,0.5,0.03)
  source = "time";
  text = "%H:%M:%S";
};
