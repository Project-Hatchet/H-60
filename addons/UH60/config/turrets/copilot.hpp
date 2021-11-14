class CopilotTurret: CopilotTurret {
	CanEject=0;
	gunnerAction=UH60_Pilot;
	gunnerInAction=UH60_Pilot;
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
	GunnerDoor="DoorL";
	proxyIndex=3;
	commanding=-1;
	class ViewGunner: ViewPilot {
		#include "ViewPilot.hpp"
	};
	class MFD {
        class VTX_H60_HDTS_Copilot: VTX_H60_HDTS_Copilot {};
	};
	class Hitpoints {};
    class Components: Components {
		class SensorsManagerComponent {
			class Components {
				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar {};
				class DatalinkSensorComponent: SensorTemplateDataLink {};
			};
		};
	};
};
