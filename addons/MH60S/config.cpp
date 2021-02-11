#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"vtx_MH60S_Pylons_GAU21L", "vtx_MH60S_GAU21L", "vtx_MH60S_Pylons", "vtx_MH60S"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "config\cfgVehicles.hpp"
#include "config\cfgWeapons.hpp"
#include "config\cfgMagazines.hpp"
