class CfgVehicles {
	class Helicopter_Base_F;
	class Helicopter_Base_H: Helicopter_Base_F {
		class vxf_driver;
		class vxf_copilot;
	}; // Helicopter_Base_H
	class Heli_Transport_01_base_F: Helicopter_Base_H {
		class vxf_driver: vxf_driver {
			class interaction;
			class modules;
		}; // vxf_driver
		class vxf_copilot: vxf_copilot {
			class interaction;
			class modules;
		}; // vxf_copilot
		class MFD;
	}; // Heli_Transport_01_base_F

	class vtx_H60_base: Heli_Transport_01_base_F {
    class vxf_driver: vxf_driver {
			class modules: modules {
				class helisim {
					startOnEnter = 1;   
				}; // fms
			}; // modules
		}; // vxf_driver
		class vxf_copilot: vxf_copilot {
			class modules: modules {
				class helisim {
					startOnEnter = 1;		
        }; // fms
			}; // modules
		}; // vxf_copilot

    liftForceCoef          = 0.00;
    bodyFrictionCoef       = 0.00;
    cyclicAsideForceCoef   = 0.00;
    cyclicForwardForceCoef = 0.00;
    backRotorForceCoef     = 0.00;
   
    #include "bmkhs_uh60_config.hpp"
    //#include "\bmkhs_helisim\audio\sounds.hpp"
	};// vtx_H60_base
};