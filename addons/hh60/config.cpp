#include "script_component.hpp"

// The Air Force bird: sole owner of hct_HH60 (Phase 1 PR B). Config-only —
// it flies UH60's shared p3d and textures until the HH-60W model conversion.
// CfgPatches class is hct_HH60_addon, deliberately distinct from the vehicle
// class name (plan ruling, 2026-08-29).
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"hct_HH60"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_UH60", "hct_h60_config", "hct_h60_helisim"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "config\cfgVehicles.hpp"
