#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {};
        author = "BradMick";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "config\cfgEventHandlers.hpp"
#include "config\cfgVehicles.hpp"
#include "config\extendedEventHandlers.hpp"