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
        class VTX_H60_HDTS_Copilot {
        		#include "MFD\HMD.hpp"
                turret[] = {0};
        }; // VTX_H60_HDTS_Pilot
        class VTX_H60_HDTS_Pilot {
        		#include "MFD\HMD.hpp"
                turret[] = {-1};
        }; // VTX_H60_HDTS_Pilot
        class MFD: MFD {
            class HMD3: VTX_H60_HDTS_Pilot {};
        };
        class vxf_driver: vxf_driver {
            class modules: modules {
                class anvishud {
                    startOnEnter = 1;
                }; // anvishud
            }; // modules
        }; // vxf_driver
        class vxf_copilot: vxf_copilot {
            class modules: modules {
                class anvishud {
                    startOnEnter = 1;
                }; // anvishud
            }; // modules
        }; // vxf_driver
    }; // vtx_H60_base
}; // CfgVehicles
