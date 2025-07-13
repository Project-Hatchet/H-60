class CfgVehicles {
	class Helicopter_Base_F;
	class Helicopter_Base_H: Helicopter_Base_F {
		class hct_driver;
		class hct_copilot;
	}; // Helicopter_Base_H
	class Heli_Transport_01_base_F: Helicopter_Base_H {
		class hct_driver: hct_driver {
			class interaction;
			class modules;
		}; // hct_driver
		class hct_copilot: hct_copilot {
			class interaction;
			class modules;
		}; // hct_copilot
		class MFD;
	}; // Heli_Transport_01_base_F

	class vtx_H60_base: Heli_Transport_01_base_F {
    class hct_driver: hct_driver {
			class modules: modules {
				class helisim {
					startOnEnter = 1;
				}; // fms
			}; // modules
		}; // hct_driver
		class hct_copilot: hct_copilot {
			class modules: modules {
				class helisim {
					startOnEnter = 1;
        }; // fms
			}; // modules
		}; // hct_copilot

    liftForceCoef          = 0.00;//1.1;
    bodyFrictionCoef       = 0.7;//0.00;
    cyclicAsideForceCoef   = 0.00;//0.5;
    cyclicForwardForceCoef = 0.00;//0.6;
    backRotorForceCoef     = 0.00;//0.8;

    #include "bmkhs_uh60_config.hpp"
    //#include "\bmkhs_helisim\audio\sounds.hpp"
	};// vtx_H60_base
};
