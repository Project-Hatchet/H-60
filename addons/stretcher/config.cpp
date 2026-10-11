#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
          QGVAR(1),
          QGVAR(2),
          QGVAR(3)
        };
        weapons[] = {
          "vtx_stretcher_item"
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
