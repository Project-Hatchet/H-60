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
        class VTX_H60_HDTS_Copilot {
        		#include "MFD\HMD.hpp"
                turret[] = {0};
                color[]={pylonAmmoRelative8, pylonAmmoRelative9, pylonAmmoRelative10, pylonAmmoRelative11};
        }; // VTX_H60_HDTS_Pilot
        class VTX_H60_HDTS_Pilot {
        		#include "MFD\HMD.hpp"
                turret[] = {-1};
                color[]={pylonAmmoRelative12, pylonAmmoRelative13, pylonAmmoRelative14, pylonAmmoRelative15};
        }; // VTX_H60_HDTS_Pilot
        class MFD: MFD {
            class HMD3: VTX_H60_HDTS_Pilot {};
        };
        class htf_driver: htf_driver {
            class modules: modules {
                class anvishud {
                    startOnEnter = 1;
                }; // anvishud
            }; // modules
        }; // htf_driver
        class htf_copilot: htf_copilot {
            class modules: modules {
                class anvishud {
                    startOnEnter = 1;
                }; // anvishud
            }; // modules
        }; // htf_driver
    }; // vtx_H60_base
}; // CfgVehicles
