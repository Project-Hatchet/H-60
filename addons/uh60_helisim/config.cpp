#include "script_component.hpp"

class CfgPatches {
    class vtx_uh60_helisim {
      units[] = {};
      author = "BradMick";
      weapons[] = {};
      requiredVersion = 1.0;
      requiredAddons[] = {"vtx_UH60", "bmkhs_helisim"};
    };// uh60_helisim
};// cfgPatches

#include "config\cfgVehicles.hpp"
#include "config\extendedEventHandlers.hpp"