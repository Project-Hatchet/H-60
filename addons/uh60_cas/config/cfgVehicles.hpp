class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F{
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
    }; // Heli_Transport_01_base_F
    class vtx_H60_base: Heli_Transport_01_base_F {
        class hct_driver: hct_driver {
            class modules: modules {
                //class cas {
                //    startOnEnter = 1;
                //}; // fms
            }; // modules
            class interaction: interaction {
                class cas {
                    #include "pilotInteraction.hpp"
                }; // FMS
            }; // interaction
        }; // hct_driver
        class hct_copilot: hct_copilot {
            class modules: modules {
                //class cas {
                //    startOnEnter = 1;
                //}; // fms
            }; // modules
            class interaction: interaction {
                class cas {
                    #include "coPilotInteraction.hpp"
                }; // FMS
            }; // interaction
        }; // hct_copilot
    }; // vtx_H60_base
}; // CfgVehicles
