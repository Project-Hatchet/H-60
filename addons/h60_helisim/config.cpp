#pragma hemtt suppress pw3_padded_arg config
//The mod's macros, for version.hpp and the keybind rows (CfgUserActions.hpp)
#include "script_component.hpp"

class CfgPatches
{
    class hct_h60_helisim
    {
        units[] = {};
        author = "BradMick";
        weapons[] = {};
        requiredVersion = 2.10;
        //HeliSim Core, and the H-60 - this pack modifies hct_H60_base, which lives in uh60_config,
        //and re-opens each variant for its seats (config\cfgVehicles.hpp), so it loads after them.
        requiredAddons[] = {"bmkhs_helisim", "hct_UH60", "hct_h60_config", "hct_h60_sounds", "hct_h60_mfd", "hct_uh60m", "hct_s70i", "hct_hh60", "hct_mh60m"};
        //The airframe this pack drives. Its preInit reads this to know what to schedule,
        //so a pack for another aircraft changes one line and touches no SQF.
        bmkhsBaseClass   = "hct_H60_base";
        #include "version.hpp"
    };
};

#include "CfgFunctions.hpp"
#include "config\CfgEventHandlers.hpp"
#include "config\CfgUserActions.hpp"
#include "config\cfgVehicles.hpp"
