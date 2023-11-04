class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F{
        class hatchet_driver;
        class hatchet_copilot;
    }; // Helicopter_Base_H
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class hatchet_driver: hatchet_driver {
            class interaction;
            class modules;
        }; // hatchet_driver
        class hatchet_copilot: hatchet_copilot {
            class interaction;
            class modules;
        }; // hatchet_copilot
    }; // Heli_Transport_01_base_F
    class vtx_H60_base: Heli_Transport_01_base_F {
        class hatchet_driver: hatchet_driver {
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
        }; // hatchet_driver
        class hatchet_copilot: hatchet_copilot {
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
        }; // hatchet_copilot
    }; // vtx_H60_base
}; // CfgVehicles
