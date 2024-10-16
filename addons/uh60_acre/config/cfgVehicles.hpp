class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F{
        class vxf_driver;
        class vxf_copilot;
    };
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class vxf_driver: vxf_driver {
            class interaction;
            class modules;
        };
        class vxf_copilot: vxf_copilot {
            class interaction;
            class modules;
        };
    };
    class vtx_H60_base: Heli_Transport_01_base_F {
        #include "acreRacks_base.hpp"
        #include "vxf.hpp"
    };
    class vtx_MH60M: vtx_H60_base {
        #include "acreRacks_mh60m.hpp"
    };
    class vtx_UH60M : vtx_H60_base {
        #include "acreRacks_uh60m.hpp"
    };
};
