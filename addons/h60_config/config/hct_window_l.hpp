class window_l {
  condition = "(hct_vehicle animationPhase 'Minigun_Mount_l_hide' == 1) && {!('turnout' in animationstate hct_player)}";
  class window_l {
      clickSound = "hct_CabinDoor_Sound";
      position="window_l_2";
      positionType="anim";
      label="Left Window";
      animation="window_l_2";
      animStates[] = {1, 0};
      animLabels[] = {"Open", "Closed"};
      animStart = "[hct_vehicle, 'l', -1] call vtx_uh60_config_fnc_setWindow";
      radius=0.1;
      animSpeed=1;
  }; // window_l
};
