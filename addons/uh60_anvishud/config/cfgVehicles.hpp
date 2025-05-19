#define HMD_COLOR color[]={USERNNN(USERMFDV_HMD_R), USERNNN(USERMFDV_HMD_G), USERNNN(USERMFDV_HMD_B), USERNNN(USERMFDV_HMD_A)}

class ANVISHUD {
    #include "MFD\HMD.hpp"
    HMD_COLOR;
};
class NVGHUD {
    #include "NVGHUD\defines.hpp"
    #include "NVGHUD\MFD.hpp"
    HMD_COLOR;
};

class ANVISHUD_COPILOT {
    #include "MFD\HMD.hpp"
    HMD_COLOR;
};
class NVGHUD_COPILOT {
    #include "NVGHUD\defines.hpp"
    #include "NVGHUD\MFD.hpp"
    HMD_COLOR;
};

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
        mfdMaxUserValues = 100;
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
