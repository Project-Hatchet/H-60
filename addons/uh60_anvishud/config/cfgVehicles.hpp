#define HMD_COLOR color[]={QUOTE(USERNNN(USERMFDV_HMD_R)), QUOTE(USERNNN(USERMFDV_HMD_G)), QUOTE(USERNNN(USERMFDV_HMD_B)), QUOTE(USERNNN(USERMFDV_HMD_A))}

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
        class MFD;
    }; // Heli_Transport_01_base_F
    class vtx_H60_base: Heli_Transport_01_base_F {
        mfdMaxUserValues = 109;   //0-99, then HeliSim's 100-108 (main/script_macros.hpp)
        class hct_driver: hct_driver {
            class modules: modules {
                class anvishud {
                    startOnEnter = 1;
                }; // anvishud
            }; // modules
        }; // hct_driver
        class hct_copilot: hct_copilot {
            class modules: modules {
                class anvishud {
                    startOnEnter = 1;
                }; // anvishud
            }; // modules
        }; // hct_driver
    }; // vtx_H60_base
}; // CfgVehicles
