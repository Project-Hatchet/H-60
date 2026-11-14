#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // Runtime-only calls into uh60_mfd, uh60_misc and HeliSim (bmkhs_*) need no edge:
        // every function is compiled at preInit. An edge here would load cas after mfd
        // and reorder the Hatchet interaction list (first match wins on overlap).
        requiredAddons[] = {"vtx_UH60", "vtx_UH60_config"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "config\cfgVehicles.hpp"
