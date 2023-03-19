class cautions_overlay {
  color[] = common_black;
  condition = "pylonAmmo3 > 0";
  class polygon {
    type        = "polygon";
    points[] ={
      {
                {{0.68      ,0.7},1},
                {{0.68+0.285,0.7},1},
                {{0.68+0.285,0.92},1},
                {{0.68      ,0.92},1}
      }
    };
  };
  class yellow {
    color[] = common_yellow;
        class border {
            type="line";
            width = 2;
            points[] ={
                {{0.68      ,0.7},1},
                {{0.68+0.285,0.7},1},
                {{0.68+0.285,0.92},1},
                {{0.68      ,0.92},1},
                {{0.68      ,0.7},1}
            };
        };
  };
};