class SensorsManagerComponent {
    class Components {
        class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
			angleRangeHorizontal 	= 60;
			angleRangeVertical 		= 60;
        };
        class LaserSensorComponent: SensorTemplateLaser {};
        class PassiveRadarSensorComponent: SensorTemplatePassiveRadar {
			angleRangeHorizontal 	= 360;
			angleRangeVertical 		= 360;
        };
        class DatalinkSensorComponent: SensorTemplateDataLink {
			angleRangeHorizontal 	= 360;
			angleRangeVertical 		= 360;
        };
    }; // Components
}; // SensorsManagerComponent
