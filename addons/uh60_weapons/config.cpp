#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
          "vtx_UH60",
          "ace_hellfire",
          "ace_missileguidance"
        };
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "config\mfdDefines.hpp"
#include "config\cfgAmmo.hpp"
#include "config\cfgWeapons.hpp"
#include "config\cfgMagazines.hpp"
#include "config\pylonPositionSlider.hpp"
