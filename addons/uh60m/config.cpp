#include "script_component.hpp"

// The Army UH-60M family: baseline, Slick and MEDEVAC.
// Variant PBO: owns its vehicle declarations and variant-only assets. It derives
// from the common base hct_H60_base (uh60_config) and flies the shared UH60 p3d.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"hct_UH60M", "hct_UH60M_SLICK", "hct_UH60M_MEDEVAC"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_UH60", "hct_h60_config", "hct_h60_helisim"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "config\cfgVehicles.hpp"
