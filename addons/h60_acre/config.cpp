#pragma hemtt suppress pw3_padded_arg config
#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_UH60", "hct_h60_config", "hct_uh60m", "hct_mh60m", "hct_h60_fms", "acre_main"};
        skipWhenMissingDependencies = 1;
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "\z\vtx\addons\uh60_fms\config\fmsDefines.hpp"

#include "config\cfgVehicles.hpp"
