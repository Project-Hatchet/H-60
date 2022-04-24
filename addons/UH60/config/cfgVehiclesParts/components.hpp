class Components: Components {
	class TransportPylonsComponent {
    	uiPicture = "z\vtx\addons\MH60M\Data\UI\vtx_mh60m_dap_3den_ca.paa";
		class Pylons {
			#define DUMMY_PYLON(CLASS) \
				class CLASS { \
					attachment = "vtx_1000rnd_dummy"; \
					priority = 5; \
					hardpoints[] = {}; \
					UIposition[] = {10, 10}; \
				};
			class pylons1 {
				attachment = "";
				priority = 5;
				hardpoints[] = {};
				UIposition[] = {0.59, 0.41};
			};
			class pylons2: pylons1 {
				attachment = "";
				mirroredMissilePos = 1;
				hardpoints[] = {};
				UIposition[] = {0.08, 0.41};
			};
			DUMMY_PYLON(dummy3)
			DUMMY_PYLON(dummy4)
			DUMMY_PYLON(dummy5)
			DUMMY_PYLON(dummy6)
			DUMMY_PYLON(dummy7)
			DUMMY_PYLON(dummy8)   //Left HMD Color R
			DUMMY_PYLON(dummy9)   //Left HMD Color G
			DUMMY_PYLON(dummy10)  //Left HMD Color B
			DUMMY_PYLON(dummy11)  //Left HMD Brighhtness
			DUMMY_PYLON(dummy12)  //Right HMD Color R
			DUMMY_PYLON(dummy13)  //Right HMD Color G
			DUMMY_PYLON(dummy14)  //Right HMD Color B
			DUMMY_PYLON(dummy15)  //Right HMD Brightness
			DUMMY_PYLON(dummy16)  // L00
			DUMMY_PYLON(dummy17)  // L01
			DUMMY_PYLON(dummy18)  // L02
			DUMMY_PYLON(dummy19)  // L10
			DUMMY_PYLON(dummy20)  // L11
			DUMMY_PYLON(dummy21)  // L12
			DUMMY_PYLON(dummy22)  // L13
			DUMMY_PYLON(dummy23)  // L14
			DUMMY_PYLON(dummy24)  // L15
			DUMMY_PYLON(dummy25)  // R00
			DUMMY_PYLON(dummy26)  // R01
			DUMMY_PYLON(dummy27)  // R02
			DUMMY_PYLON(dummy28)  // R10
			DUMMY_PYLON(dummy29)  // R11
			DUMMY_PYLON(dummy30)  // R12
			DUMMY_PYLON(dummy31)  // R13
			DUMMY_PYLON(dummy32)  // R14
			DUMMY_PYLON(dummy33)  // R15
			DUMMY_PYLON(dummy34)  // R20
			DUMMY_PYLON(dummy35)  // R21
			DUMMY_PYLON(dummy36)  // R22
			DUMMY_PYLON(dummy37)  // R23
			DUMMY_PYLON(dummy38)  // R24
			DUMMY_PYLON(dummy39)  // R25
		};
		class Presets {
		};
	}; // TransportPylonsComponent
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
};
