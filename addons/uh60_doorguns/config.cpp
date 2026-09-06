#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60", "vtx_UH60_config"}; // vtx_wpn_m134_safe derives from vtx_wpn_m134, owned by uh60_config since Phase 1 PR C
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "config\cfgWeapons.hpp"
#include "config\cfgMagazines.hpp"
