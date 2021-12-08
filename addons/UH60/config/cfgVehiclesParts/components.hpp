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
			DUMMY_PYLON(dummy8)
			DUMMY_PYLON(dummy9)
			DUMMY_PYLON(dummy10)
			DUMMY_PYLON(dummy11)
			DUMMY_PYLON(dummy12)
			DUMMY_PYLON(dummy13)
		};
		class Presets {
		};
	}; // TransportPylonsComponent
	class SensorsManagerComponent {
		class Components {
			class PassiveRadarSensorComponent: SensorTemplatePassiveRadar {};
			class DatalinkSensorComponent: SensorTemplateDataLink {};
		};
	};
};
