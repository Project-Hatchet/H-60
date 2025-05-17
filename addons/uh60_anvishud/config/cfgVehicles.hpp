class ANVISHUD {
    #include "MFD\HMD.hpp"
    color[]={USERNNN(USERMFDV_RHMD_R), USERNNN(USERMFDV_RHMD_G), USERNNN(USERMFDV_RHMD_B), USERNNN(USERMFDV_RHMD_A)};
};
class NVGHUD {
    #include "NVGHUD\defines.hpp"
    #include "NVGHUD\MFD.hpp"
    color[]={USERNNN(USERMFDV_RHMD_R), USERNNN(USERMFDV_RHMD_G), USERNNN(USERMFDV_RHMD_B), USERNNN(USERMFDV_RHMD_A)};
};

class ANVISHUD_COPILOT {
    #include "MFD\HMD.hpp"
    color[]={USERNNN(USERMFDV_LHMD_R), USERNNN(USERMFDV_LHMD_G), USERNNN(USERMFDV_LHMD_B), USERNNN(USERMFDV_LHMD_A)};
};
class NVGHUD_COPILOT {
    #include "NVGHUD\defines.hpp"
    #include "NVGHUD\MFD.hpp"
    color[]={USERNNN(USERMFDV_LHMD_R), USERNNN(USERMFDV_LHMD_G), USERNNN(USERMFDV_LHMD_B), USERNNN(USERMFDV_LHMD_A)};
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
        // class VTX_H60_HDTS_Copilot {
        // 		#include "MFD\HMD.hpp"
        //         turret[] = {0};
        //         color[]={pylonAmmoRelative8, pylonAmmoRelative9, pylonAmmoRelative10, pylonAmmoRelative11};
        // }; // VTX_H60_HDTS_Pilot
        // class VTX_H60_HDTS_Pilot {
        // 		#include "MFD\HMD.hpp"
        //         color[]={pylonAmmoRelative12, pylonAmmoRelative13, pylonAmmoRelative14, pylonAmmoRelative15};
        // }; // VTX_H60_HDTS_Pilot
        // class VTX_H60_NVGHUD {
        //     #include "NVGHUD\defines.hpp"
        //     #include "NVGHUD\MFD.hpp"
        //     color[]={pylonAmmoRelative12, pylonAmmoRelative13, pylonAmmoRelative14, pylonAmmoRelative15};
        // };
        // class MFD: MFD {
        //     class HMD3: VTX_H60_HDTS_Pilot {};
        //     class NVGHUD: VTX_H60_NVGHUD {};
        // };
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
