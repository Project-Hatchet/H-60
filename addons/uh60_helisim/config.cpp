#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        //HeliSim Core, and the H-60 - this pack modifies vtx_H60_base, so it must load after
        //uh60_config, where that class lives.
        requiredAddons[] = {"vtx_UH60", "vtx_UH60_config", "bmkhs_helisim"};
        //THE AIRFRAME THIS PACK DRIVES. XEH_preInit reads this to know what to schedule.
        bmkhsBaseClass = "vtx_H60_base";
        author = "BradMick";
        authors[] = {""};
        VERSION_CONFIG;
    };// ADDON
};// cfgPatches

#include "config\CfgEventHandlers.hpp"
#include "config\cfgVehicles.hpp"
