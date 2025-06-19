class window_l {
  condition = "(hct_vehicle animationPhase 'Minigun_Mount_l_hide' == 1) && {!('turnout' in animationstate hct_player)}";
  class window_r_1 {
    interactionCondition = "!isTurnedOut hct_player";
    clickSound = "hct_CabinDoor_Sound";
    position = "window_l_1";
    positionType = "static";
    label = "Inner Window";
    animation = "window_l_1";
    radius = 0.1;
    scrollIncrement = 0.05;
    dragRange = 0.2;
    looping = 0;
    animLimits[] = {0, 1.5708};
    dragStart="";
    dragging="";
    dragStop="";
  }; // window_l_1
  class window_l_2: window_r_1 {
    position = "window_l_2";
    label = "Outer Window";
    animation = "window_l_2";
  }; // window_l_2
};
