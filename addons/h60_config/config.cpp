#pragma hemtt suppress pw3_padded_arg config
#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        // Common base: hct_H60_base + crew. Variants are in their own PBOs;
        // this CfgPatches name stays so missions that list it keep loading.
        units[] = {
          "hct_h60_doorgunner",
          "hct_h60_pilot"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // Phase 1: uh60_config owns every vehicle declaration and loads
        // EARLY. The old screen-addon edges (mfd/fms/anvishud/doorguns) are
        // gone: the MFD template mounts below resolve by name when the config
        // is read, so the screen addons may load after us (load-order
        // experiment, 2026-09-05). Every addon that re-opens our classes now
        // declares an edge on hct_h60_config instead. hct_UH60 remains the
        // asset PBO (models, textures, sounds, anims, fonts).
        requiredAddons[] = {"hct_UH60"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgMoves.hpp"

class CfgEditorSubcategories {
    class hct_h60 {
        displayName = "$STR_hct_h60_config_HatchetH60Pack";
    };
};

class CfgFontFamilies {
    class hct_h60_Font {
        fonts[] = {"\z\vtx\addons\UH60\config\Font\font46"};
    };
};

#define mag_xx(a,b) class _xx_##a {magazine = QUOTE(a); count = b;}
#define weap_xx(a,b) class _xx_##a {weapon = a; count = b;}

#include "config\cfgVehicles.hpp"
