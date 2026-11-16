#pragma hemtt suppress pw3_padded_arg config
#include "script_component.hpp"

// Phase 1 PR C: hct_UH60 is the asset PBO — models, textures, sounds, crew
// anims, fonts, model.cfg. All vehicle/weapon/UI config (hct_H60_base, the
// shared turret and parts includes, CfgMoves, crew units, fonts declaration,
// editor subcategory) is owned by addons/uh60_config.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_h60_main"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};
#include "cfgSetting.hpp"
#include "CfgEventHandlers.hpp"
