#pragma hemtt suppress pw3_padded_arg config
#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"hct_pylon"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
          "hct_UH60",
          "hct_h60_config",
          "ace_hellfire",
          "ace_missileguidance",
          "hct_h60_mfd",
          "ace_laser",
          "ace_pylons"
        };
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "config\mfdDefines.hpp"
#include "config\cfgEffects.hpp"
#include "config\cfgCloudlets.hpp"
#include "config\cfgAmmo.hpp"
#include "config\cfgWeapons.hpp"
#include "config\cfgMagazines.hpp"
#include "config\pylonPositionSlider.hpp"
#include "config\cfgVehicles.hpp"
#include "config\cfgSoundSets.hpp"
#include "config\cfgSoundShaders.hpp"
#include "config\armaKeybinds.hpp"
