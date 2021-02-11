class Level0
{
    type = "line";
    width = 8;
    lineType = 2;
    points[] = {
        {"Level0", {-0.4, 0}, 1}, {"Level0", {0.4, 0}, 1}
    };
};

class LevelP10
{
    type = "line";
    width = 8;
    lineType = 1;
    points[] = {{"LevelP10", {-0.2, 0}, 1}, {"LevelP10", {0.2, 0}, 1}};
};

class LevelM10: LevelP10 {
    points[] = {{"LevelM10", {-0.2, 0}, 1}, {"LevelM10", {0.2, 0}, 1}};
};

class LevelP20: LevelP10 {
    points[] = {{"LevelP20", {-0.2, 0}, 1}, {"LevelP20", {0.2, 0}, 1}};
};

class LevelM20: LevelP10 {
    points[] = {{"LevelM20", {-0.2, 0}, 1}, {"LevelM20", {0.2, 0}, 1}};
};

class LevelP30: LevelP10 {
    points[] = {{"LevelP30", {-0.2, 0}, 1}, {"LevelP30", {0.2, 0}, 1}};
};

class LevelM30: LevelP10 {
    points[] = {{"LevelM30", {-0.2, 0}, 1}, {"LevelM30", {0.2, 0}, 1}};
};
