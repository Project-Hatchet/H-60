#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60", "vtx_MH60M", "vtx_MH60S", "vtx_uh60_opfor"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgMissions.hpp"
