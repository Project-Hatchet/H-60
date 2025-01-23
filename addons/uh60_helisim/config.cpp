#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60","bmkhs_core"};
        author = "BradMick";
        authors[] = {""};
        VERSION_CONFIG;
    };// ADDON
};// cfgPatches

#include "config\bmkhs_uh60_config.hpp"
#include "config\CfgEventHandlers.hpp"
#include "config\cfgVehicles.hpp"