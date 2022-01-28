#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"vtx_MH60M", "vtx_MH60M_DAP"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
          "vtx_UH60_config",
          "vtx_UH60_weapons"
        };
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "config\cfgVehicles.hpp"
#include "config\cfgWeapons.hpp"
