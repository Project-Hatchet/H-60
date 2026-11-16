class Reflectors {
  class Search {
    color[] = {7000, 7500, 10000};
    ambient[] = {70, 75, 100};
    intensity = 50;
    size = 1;
    innerAngle = 5;
    outerAngle = 65;
    coneFadeCoef = 10;
    position = "light_search_pos";
    direction = "light_search_dir";
    hitpoint = "light_search";
    selection = "";
    useFlare = 1;
    dayLight = 0;
    FlareSize = 4;
    class Attenuation {
      start = 0;
      constant = 0;
      linear = 0;
      quadratic = 0.05;
      hardLimitStart = 400;
      hardLimitEnd = 600;
    };
  };
  class Landing: Search { //main landing light
    position = "L svetlo";
    direction = "konec L svetla";
    hitpoint = "L svetlo";
    selection = "light_landing_sel";
  };
  class Left {//main gear light
    ambient[] = {100,0,0};
    color[] = {70,0,0};
    size = 1;
    dayLight = 1;
    useFlare = 1;
    intensity = 3;
    coneFadeCoef = 2;
    innerAngle = 90;
    outerAngle = 180;
    position = "light_position_left";
    direction = "light_position_left_dir";
    hitpoint = "";
    selection = "";
    class Attenuation {
      start = 0;
      constant = 0;
      linear = 0;
      quadratic = 0;
      hardLimitStart = 9;
      hardLimitEnd = 10;
    };
  };
  class Right { //main gear light
    ambient[] = {0,100,0};
    color[] = {0,70,0};
    size = 1;
    dayLight = 1;
    useFlare = 1;
    intensity = 3;
    coneFadeCoef = 2;
    innerAngle = 90;
    outerAngle = 180;
    position = "light_position_right";
    direction = "light_position_right_dir";
    hitpoint = "";
    selection = "";
    class Attenuation {
      start = 0;
      constant = 0;
      linear = 0;
      quadratic = 0;
      hardLimitStart = 9;
      hardLimitEnd = 10;
    };
  };
  class Cockpit {
    position = "light_cockpit";
    direction = "light_cockpit_dir";
    hitpoint = "light_cockpit";
    selection = "light_cockpit";
    color[] = {0,233/2,255/2};
    ambient[] = {0,15,30};
    intensity = 2;
    size = 1;
    innerAngle = 15;
    outerAngle = 150;
    coneFadeCoef = 1;
    useFlare = 1;
    flareSize = 0.1;
    flareMaxDistance = 1;
    dayLight = 0;
    class Attenuation {
      start = 0;
      constant = 0;
      linear = 1;
      quadratic = 1;
      hardLimitStart = 1;
      hardLimitEnd = 2;
    };
  };
  class CabinLight {
    position = "light_cabin";
    direction = "light_cabin_dir";
    hitpoint = "light_cabin";
    selection = "light_cabin";
    color[] = {0,233/2,255/2};
    ambient[] = {0,45,90};
    intensity = 4;
    size = 2;
    innerAngle = 90;
    outerAngle = 180;
    coneFadeCoef = 0.5;
    useFlare = 1;
    flareSize = 0.3;
    flareMaxDistance = 2;
    dayLight = 0;
    class Attenuation {
      start = 0;
      constant = 0;
      linear = 0.5;
      quadratic = 0.5;
      hardLimitStart = 1;
      hardLimitEnd = 2;
    };
  };
};
aggregateReflectors[] = {};
