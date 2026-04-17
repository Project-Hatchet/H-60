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

  // Disable SoundAttenuation (Internal Filter)
  /* disableSoundAttenuation = 0;
  viewGunnerInExternal = 0;
  isPersonTurret = 0; */
  soundAttenuationTurret = "HeliAttenuationGunner";

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
};
