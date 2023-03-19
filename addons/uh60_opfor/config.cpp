#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
        "vtx_UH60M_O",
        "vtx_HH60_O",
            "vtx_MH60M_O",
            "vtx_MH60M_DAP_O",
            "vtx_MH60S_Pylons_GAU21L_O",
            "vtx_MH60S_GAU21L_O",
            "vtx_MH60S_Pylons_O",
            "vtx_MH60S_O"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60", "vtx_MH60M", "vtx_MH60S"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "cfgVehicles.hpp"
