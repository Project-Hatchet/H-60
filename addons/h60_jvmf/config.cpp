#include "script_component.hpp"

class CfgPatches
{
    class ADDON
    {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60", "vtx_UH60_config", "vtx_uh60_cas", "vtx_uh60_fms", "vtx_uh60_mfd"};
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
