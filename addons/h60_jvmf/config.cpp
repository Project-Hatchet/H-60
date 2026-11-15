#pragma hemtt suppress pw3_padded_arg config
#include "script_component.hpp"

class CfgPatches
{
    class ADDON
    {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_UH60", "hct_h60_config", "hct_h60_cas", "hct_h60_fms", "hct_h60_mfd"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "uiConfig\baseClasses.hpp"
#include "uiConfig\writeDialog.hpp"
#include "uiConfig\positionDialog.hpp"
#include "uiConfig\inboxDialog.hpp"

#include "config\cfgVehicles.hpp"
#include "config\cfgWeapons.hpp"
