/*
class warning_enabled {
  condition = COND_ISNUMBER(WARN_INDEX,1);
    class background {
        color[] = {1,0,0,1};
        class background_polygon {
        type        = "polygon";
        points[] ={
          {
                    {{0.25, 0.29},1},
            {{0.75, 0.29},1},
            {{0.75, 0.4},1},
            {{0.25, 0.4},1}
          }
        }; // points
        }; // background_polygon
    }; // background
    class text {
        color[] = {0,0,0,1};
        class warning_text {
            type = "text";
            source = "static";
            align = "center";
            scale = 1;
            sourceScale = 1;
            pos[] = {{0.5, 0.3}, 1};
            right[] = {{0.5 + 0.1, 0.3}, 1};
            down[] = {{0.5, 0.3 + 0.1}, 1};
            text = "AUTO RECOVER";
        };
    };
};
*/
