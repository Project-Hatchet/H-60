class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F{
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
    }; // Heli_Transport_01_base_F
    class vtx_H60_base: Heli_Transport_01_base_F {
        class htf_driver: htf_driver {
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
        }; // htf_driver
        class htf_copilot: htf_copilot {
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
        }; // htf_copilot
    }; // vtx_H60_base
}; // CfgVehicles
