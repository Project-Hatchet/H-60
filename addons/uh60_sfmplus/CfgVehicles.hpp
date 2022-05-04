class CfgVehicles {
	class Helicopter_Base_F;
	class Helicopter_Base_H: Helicopter_Base_F {
		class htf_driver;
		class htf_copilot;
	}; // Helicopter_Base_H
	class Heli_Transport_01_base_F: Helicopter_Base_H {
		class htf_driver: htf_driver {
			class interaction;
			class modules;
		}; // htf_driver
		class htf_copilot: htf_copilot {
			class interaction;
			class modules;
		}; // htf_copilot
		class MFD;
	}; // Heli_Transport_01_base_F

	class vtx_H60_base: Heli_Transport_01_base_F {
		class htf_driver: htf_driver {
			class modules: modules {
				class sfmplus {
					startOnEnter = 1;
				}; // fms
			}; // modules
		}; // htf_driver
		class htf_copilot: htf_copilot {
			class modules: modules {
				class sfmplus {
					startOnEnter = 1;
				}; // fms
			}; // modules
		}; // htf_copilot
		#include "sfmplus.hpp"
	};
};