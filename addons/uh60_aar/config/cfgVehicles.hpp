class cfgVehicles {
    class Land_Screwdriver_V1_F;
    class vtx_aar_basket : Land_Screwdriver_V1_F {
        author = "Project Hatchet Studio";
        displayName = "AAR Basket";
        model = "z\vtx\addons\uh60_aar\Data\Basket\Basket.p3d";
    };

    // TANKER
    class VTOL_01_vehicle_base_F;
    class B_T_VTOL_01_vehicle_F: VTOL_01_vehicle_base_F {
        class EventHandlers;
    };
    class VTX_KV44: B_T_VTOL_01_vehicle_F {
        displayName = "KV-44X Tanker";
        displayNameShort = "KV-44X Tanker";
        class EventHandlers: EventHandlers {
            class vtx_aar {
                init = "_this call vtx_uh60_aar_fnc_initTanker";
            };
        };
    };

    // HELICOPTER
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F{
        class vxf_driver;
        class vxf_copilot;
    }; // Helicopter_Base_H
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class vxf_driver: vxf_driver {
            class modules;
        }; // vxf_driver
        class vxf_copilot: vxf_copilot {
            class modules;
        }; // vxf_copilot
    }; // Heli_Transport_01_base_F
    class vtx_H60_base: Heli_Transport_01_base_F {
        class vxf_driver: vxf_driver {
            class modules: modules {
                class aar {
                    startOnEnter = 1;
                    probePos[] = {1.2,11.5,-1.1};
                    probeCondition = "(_this animationPhase ""fuelProbe_Extend"") > 0.95";
                    fillRate = 0.016;
                }; // fms
            }; // modules
        }; // vxf_driver
        class vxf_copilot: vxf_copilot {
            class modules: modules {
                class aar {
                    startOnEnter = 1;
                    probePos[] = {1.2,11.5,-1.1};
                    probeCondition = "(_this animationPhase ""fuelProbe_Extend"") > 0.95";
                    fillRate = 0.016;
                }; // fms
            }; // modules
        }; // vxf_copilot
    }; // vtx_H60_base
};
