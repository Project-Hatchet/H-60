class Components: Components {
	class SensorsManagerComponent {
		class Components {
			class PassiveRadarSensorComponent: SensorTemplatePassiveRadar {};
			class DatalinkSensorComponent: SensorTemplateDataLink {};
		};
	};

    class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftPilot
    {
    	class Components: Components
    	{
    		class MissileDisplay	// Camera feed from missile's warhead
    		{
    			componentType = "TransportFeedDisplayComponent";
    			source = "Missile";
    			// resource = "RscTransportCameraComponentMissile"; // hardcoded
    		};
    	};
    }; // vtx_VehicleSystemsDisplayManagerLeft

    class VehicleSystemsDisplayManagerComponentRight : VehicleSystemsTemplateRightPilot
    {
    	class Components: Components
    	{
    		class MissileDisplay	// Camera feed from missile's warhead
    		{
    			componentType = "TransportFeedDisplayComponent";
    			source = "Missile";
    			// resource = "RscTransportCameraComponentMissile"; // hardcoded
    		};
    	};
    }; //  vtx_VehicleSystemsDisplayManagerRight

};
