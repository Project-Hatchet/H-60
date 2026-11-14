#include "script_component.hpp"

// The civilian/export S-70i.
// Variant PBO: owns its vehicle declarations and variant-only assets. It derives
// from the common base vtx_H60_base (uh60_config) and flies the shared UH60 p3d.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"vtx_S70i"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60", "vtx_UH60_config", "vtx_uh60_helisim"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "config\cfgVehicles.hpp"
