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
        requiredAddons[] = {"hct_UH60", "hct_h60_config"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "config\pedestal\pedestal.hpp"
#include "config\mfdDefines.hpp"
#include "config\cfgVehicles.hpp"
#include "config\flirVideo.hpp"
#include "Armakeybinds.hpp"
