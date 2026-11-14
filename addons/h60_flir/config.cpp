#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60", "vtx_UH60_config", "vtx_uh60_ui", "vtx_uh60_mfd", "vtx_uh60_weapons", "ace_laser"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "config\mouseBlocker.hpp"
#include "Armakeybinds.hpp"
