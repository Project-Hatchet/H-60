#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60", "vtx_UH60_config", "vtx_MH60M", "vtx_MH60S"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "cfgVehicles.hpp"
