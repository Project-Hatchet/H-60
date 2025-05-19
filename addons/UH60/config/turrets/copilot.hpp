class CopilotTurret: CopilotTurret {
	CanEject=0;
	gunnerAction=UH60_Pilot;
	gunnerInAction=UH60_Pilot;
  canHideGunner = 0;
  viewGunnerInExternal = 1;
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
  class Reflectors
  {
    class Right
    {
      color[] = {7000, 7500, 10000};
      ambient[] = {70, 75, 100};
      intensity = 50;
      size = 1;
      innerAngle = 5;
      outerAngle = 65;
      coneFadeCoef = 10;
      position = "searchlight_pos";
      direction = "searchlight_dir";
      hitpoint = "searchlight";
      selection = "searchlight";
      useFlare = 1;
      dayLight = 0;
      FlareSize = 4;
      class Attenuation
      {
        start = 0;
        constant = 0;
        linear = 0;
        quadratic = 0.05;
        hardLimitStart = 400;
        hardLimitEnd = 450;
      };
    };
  };

};
