#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_UH60", "hct_h60_config", "hct_h60_ui", "hct_h60_mfd", "hct_h60_weapons", "ace_laser"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "config\mouseBlocker.hpp"
#include "Armakeybinds.hpp"
