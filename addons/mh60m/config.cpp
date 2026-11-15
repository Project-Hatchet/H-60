#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"hct_MH60M", "hct_MH60M_DAP"}; // hct_MH60M_DAP_MLASS is a hidden compat stub (cfgVehicles.hpp) - not listed
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_h60_config", "hct_h60_weapons", "hct_h60_mfd", "hct_h60_fms", "hct_h60_anvishud", "hct_h60_helisim"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "config\cfgVehicles.hpp"
#include "config\cfgWeapons.hpp"
