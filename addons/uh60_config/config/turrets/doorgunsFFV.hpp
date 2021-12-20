class LeftWindow: CargoTurret { //Left Doorgun
  animationSourceHatch = "gunner_ffv_l";
  canHideGunner = 1;
  forceHideGunner = 0;
  enabledByAnimationSource = "";
  gunnerAction=vehicle_turnout_2;
  gunnerCompartments = Compartment1;
  gunnerInAction=passenger_inside_1;
  gunnerName="Left Window";
  gunnerType = "vtx_uh60_doorgunner";
  hideWeaponsGunner = 0;
  isPersonTurret = 1;
  memoryPointsGetInGunner = "pos gunner L";
  memoryPointsGetInGunnerDir = "pos gunner L dir";
  minElev=-80; maxElev=40; initElev=0;
  minTurn=-80; maxTurn=80; initTurn=0;
  minOutElev = -80; maxOutElev = 40; initOutElev = 0;
  minOutTurn = -160; maxOutTurn = 160; initOutTurn = 0;
  proxyIndex=24;
  class TurnIn {
    limitsArrayTop[] = {{40, 55}, {45, 0}, {40, -95}};
    limitsArrayBottom[] = {{-20, 35}, {-25, 0}, {-20, -20}, {0, -30}};
  };
	class TurnOut: TurnIn {
    limitsArrayTop[] = {{60, 90}, {60, -95}};
    limitsArrayBottom[] = {{-30, 90}, {-80, 20}, {-80, -30}, {0, -95}};
  };
};
class RightWindow: LeftWindow {
  animationSourceHatch = "gunner_ffv_r";
  gunnerName="Right Window";
  memoryPointsGetInGunner = "pos gunner R";
  memoryPointsGetInGunnerDir = "pos gunner R dir";
  proxyIndex=25;
  minElev=-80; maxElev=40; initElev=0;
  minTurn=-80; maxTurn=80; initTurn=0;
  minOutElev = -80; maxOutElev = 40; initOutElev = 0;
  minOutTurn = -90; maxOutTurn = 90; initOutTurn = 0;
  class TurnIn {
    limitsArrayTop[] = {{40, 95}, {45, 0}, {40, -95}};
    limitsArrayBottom[] = {{0, 35}, {-20, 25}, {-25, 0}, {-20, -20}, {0, -30}};
  };
	class TurnOut: TurnIn {
    limitsArrayTop[] = {{20, 125}, {80, 90}, {45, 0}, {40, -95}};
    limitsArrayBottom[] = {{-1, 125}, {-35, 90}, {-55, 70}, {-80, 20}, {-80, -40}, {-40, -65}, {0, -75}};
  };
};
