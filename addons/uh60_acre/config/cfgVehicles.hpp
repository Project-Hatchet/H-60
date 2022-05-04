class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F{
        class htf_driver;
        class htf_copilot;
    };
    class Heli_Transport_01_base_F: Helicopter_Base_H
    {
        class htf_driver: htf_driver {
            class interaction;
            class modules;
        };
        class htf_copilot: htf_copilot {
            class interaction;
            class modules;
        };
    };
    class vtx_H60_base: Heli_Transport_01_base_F
    {
        #include "acreRacks.hpp"
        #include "htf.hpp"
    };
};
