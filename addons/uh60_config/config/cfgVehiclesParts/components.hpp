class Components: Components {
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
