#include "script_component.hpp"

class CfgPatches
{
    class hct_h60_helisim
    {
        units[] = {};
        author = "BradMick";
        weapons[] = {};
        requiredVersion = 2.10;
        //HeliSim Core, and the H-60 - this pack modifies hct_H60_base, which lives in uh60_config.
        requiredAddons[] = {"bmkhs_helisim", "hct_UH60", "hct_h60_config", "hct_h60_sounds", "hct_h60_mfd"};
        //The airframe this pack drives. Its preInit reads this to know what to schedule,
        //so a pack for another aircraft changes one line and touches no SQF.
        bmkhsBaseClass   = "hct_H60_base";
        VERSION_CONFIG;
    };
};

#include "config\CfgEventHandlers.hpp"
#include "config\CfgUserActions.hpp"
#include "config\cfgVehicles.hpp"
