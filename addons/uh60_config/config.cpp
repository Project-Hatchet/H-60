#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"vtx_UH60M_MEDEVAC", "vtx_S70i"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60", "vtx_UH60_mfd", "vtx_UH60_fms", "vtx_UH60_anvishud", "vtx_UH60_doorguns"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "config\CfgVehicles.hpp"
