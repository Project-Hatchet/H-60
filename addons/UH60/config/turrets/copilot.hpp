class CopilotTurret: CopilotTurret {
  CanEject=0;
  gunnerAction = "UH60_Pilot";
  gunnerInAction = "UH60_Pilot";
  canHideGunner = 0;
  viewGunnerInExternal = 1;
  gunnerUsesPilotView = 1;
  // 1100 = View - Pilot LOD; without these the turret defaults to the door-gunner
  // View - Gunner LOD and the copilot cockpit loses its upper console (#556)
  LODTurnedIn = 1100;
  LODTurnedOut = 1100;
  memoryPointGunnerOptics = "";
  memoryPointGunnerOutOptics = "";
  gunnerRightHandAnimName="Cyclic_left";
  gunnerLeftHandAnimName="Collective_left";
  gunnerLeftLegAnimName="Pedal_Left_CP";
  gunnerRightLegAnimName="Pedal_Right_CP";
  memoryPointsGetInGunner="pos codriver";
  memoryPointsGetInGunnerDir="pos codriver dir";

  gunnerGetInAction="copilot_Heli_Light_02_Enter";
  gunnerGetOutAction="copilot_Heli_Light_02_Exit";
  selectionFireAnim="";

  preciseGetInOut=1;
  GunnerDoor="Door_LF";
  proxyIndex=3;
  commanding=-1;
  class ViewGunner: ViewPilot {
    #include "ViewPilot.hpp"
  };
  class OpticsIn {};
  class Hitpoints {};
  class Components {
    class SensorsManagerComponent {
      class Components {
        class LaserSensorComponent: SensorTemplateLaser {};
        class PassiveRadarSensorComponent: SensorTemplatePassiveRadar {
          angleRangeHorizontal 	= 360;
          angleRangeVertical 		= 360;
        };
        class DatalinkSensorComponent: SensorTemplateDataLink {
          angleRangeHorizontal 	= 360;
          angleRangeVertical 		= 360;
        };
      };
    };
    class VehicleSystemsDisplayManagerComponentLeft {};
    class VehicleSystemsDisplayManagerComponentRight {};
  };
};
