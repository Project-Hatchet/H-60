#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"hct_MH60S_Pylons_GAU21L", "hct_MH60S_GAU21L", "hct_MH60S_Pylons", "hct_MH60S"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_h60_weapons", "hct_h60_config"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "config\cfgVehicles.hpp"
#include "config\cfgWeapons.hpp"
#include "config\cfgMagazines.hpp"
