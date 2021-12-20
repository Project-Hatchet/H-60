class LeftWindow: CargoTurret { //Left Doorgun
  animationSourceHatch = "gunner_ffv_l";
  canHideGunner = 1;
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
  minElev=MACRO_MINELEV; maxElev=MACRO_MAXELEV; initElev=0;
  minTurn=-MACRO_TURN; maxTurn=MACRO_TURN; initTurn=90;
  proxyIndex=24;
  class TurnIn {
    limitsArrayTop[] = {{40, 80}, {40, -80}};
    limitsArrayBottom[] = {{-40, 30}, {-40, -30}};
  };
	class TurnOut: TurnIn {
    limitsArrayTop[] = {{40, 95}, {40, -95}};
    limitsArrayBottom[] = {{-80, 95}, {-80, -95}};
  };
};
class RightWindow: LeftWindow {
  animationSourceHatch = "gunner_ffv_r";
  gunnerName="Right Window";
  memoryPointsGetInGunner = "pos gunner R";
  memoryPointsGetInGunnerDir = "pos gunner R dir";
  proxyIndex=25;
  class TurnIn: TurnIn {};
	class TurnOut: TurnOut {};
};
