#pragma hemtt suppress pw3_padded_arg config
#include "script_component.hpp"

// The civilian/export S-70i.
// Variant PBO: owns its vehicle declarations and variant-only assets. It derives
// from the common base hct_H60_base (uh60_config) and flies the shared UH60 p3d.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"hct_S70i"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_UH60", "hct_h60_config", "hct_h60_helisim"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "config\cfgVehicles.hpp"
