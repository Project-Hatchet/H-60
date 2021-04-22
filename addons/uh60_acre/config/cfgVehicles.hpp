class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F{
        class hatchet_driver;
        class hatchet_copilot;
    };
    class Heli_Transport_01_base_F: Helicopter_Base_H
    {
        class hatchet_driver: hatchet_driver {
            class interaction;
            class modules;
        };
        class hatchet_copilot: hatchet_copilot {
            class interaction;
            class modules;
        };
    };
    class vtx_H60_base: Heli_Transport_01_base_F
    {
        #include "acreRacks.hpp"
        #include "vxf.hpp"
    };
};
