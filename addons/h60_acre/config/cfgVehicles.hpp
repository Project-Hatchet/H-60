class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F{
        class hct_driver;
        class hct_copilot;
    };
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class hct_driver: hct_driver {
            class interaction;
            class modules;
        };
        class hct_copilot: hct_copilot {
            class interaction;
            class modules;
        };
    };
    class hct_H60_base: Heli_Transport_01_base_F {
        #include "acreRacks_base.hpp"
        #include "hct.hpp"
    };
    class hct_MH60M: hct_H60_base {
        #include "acreRacks_mh60m.hpp"
    };
    class hct_UH60M : hct_H60_base {
        #include "acreRacks_uh60m.hpp"
    };
};
