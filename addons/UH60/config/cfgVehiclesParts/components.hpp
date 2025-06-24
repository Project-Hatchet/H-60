class Components: Components {
	class TransportPylonsComponent {
    	uiPicture = "z\vtx\addons\MH60M\Data\UI\vtx_mh60m_dap_3den_ca.paa";
		class Pylons {
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
		};
		class Presets {
			class Empty {
				displayName = "Empty";
				attachment[] = {};
			};
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
