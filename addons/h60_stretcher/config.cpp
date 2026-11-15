#pragma hemtt suppress pw3_padded_arg config
#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
          QGVAR(1),
          QGVAR(2),
          QGVAR(3),
          QGVAR(item)
        };
        weapons[] = {
          "hct_h60_stretcher_item"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_common"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "cfgVehicles.hpp"
#include "CfgWeapons.hpp"
