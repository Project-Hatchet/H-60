class window_r {
  condition = "(hct_vehicle animationPhase 'Minigun_Mount_l_hide' == 1) && {!('turnout' in animationstate hct_player)}";
  class window_r {
      clickSound = "hct_CabinDoor_Sound";
      position="window_r_2";
      positionType="anim";
      label="Right Window";
      animation="window_r_2";
      animStates[] = {1, 0};
      animLabels[] = {"Open", "Closed"};
      animStart = "hct_vehicle animateSource ['window_r', parseNumber (hct_vehicle animationSourcePhase 'window_r' < 0.5)]";
      radius=0.1;
      animSpeed=1;
  }; // window_r
}
