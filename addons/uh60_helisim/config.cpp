#include "script_component.hpp"

class CfgPatches
{
    class vtx_uh60_helisim
    {
        units[] = {};
        author = "BradMick";
        weapons[] = {};
        requiredVersion = 2.10;
        //HeliSim Core, and the H-60 - this pack modifies vtx_H60_base, which lives in uh60_config.
        requiredAddons[] = {"bmkhs_helisim", "vtx_UH60", "vtx_UH60_config", "vtx_hh60", "vtx_mh60m"};
        //The airframe this pack drives. Its preInit reads this to know what to schedule,
        //so a pack for another aircraft changes one line and touches no SQF.
        bmkhsBaseClass   = "vtx_H60_base";
        VERSION_CONFIG;
    };
};

#include "CfgFunctions.hpp"
#include "config\CfgEventHandlers.hpp"
#include "config\CfgUserActions.hpp"
#include "config\cfgVehicles.hpp"
