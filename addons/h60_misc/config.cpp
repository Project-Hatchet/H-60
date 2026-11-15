#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"hct_fuelProbe", "hct_hoist", "hct_cockpitdoors", "hct_serviceplatform"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_UH60", "hct_h60_config"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "config\cfgVehicles.hpp"
