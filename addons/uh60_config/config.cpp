#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
          "vtx_UH60M",
          "vtx_UH60M_Slick",
          "vtx_UH60M_MEDEVAC",
          "vtx_S70M",
          "vtx_uh60_doorgunner",
          "vtx_uh60_pilot"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // Phase 1: uh60_config owns every vehicle declaration and loads
        // EARLY. The old screen-addon edges (mfd/fms/anvishud/doorguns) are
        // gone: the MFD template mounts below resolve by name when the config
        // is read, so the screen addons may load after us (load-order
        // experiment, 2026-09-05). Every addon that re-opens our classes now
        // declares an edge on vtx_UH60_config instead. vtx_UH60 remains the
        // asset PBO (models, textures, sounds, anims, fonts).
        requiredAddons[] = {"vtx_UH60"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgMoves.hpp"

class CfgEditorSubcategories {
    class vtx_h60 {
        displayName = "Hatchet H-60 Pack";
    };
};

class CfgFontFamilies {
    class VTX_UH60M_Font {
        fonts[] = {"\z\vtx\addons\UH60\config\Font\font46"};
    };
    class FalconDED {
        // sizes 6-37 exist in UH60\config\Font but were never enabled; only 46 ships
        fonts[] = {
            "\z\vtx\addons\UH60\config\Font\FalconDED46"
        };
    };
};

#define mag_xx(a,b) class _xx_##a {magazine = a; count = b;}
#define weap_xx(a,b) class _xx_##a {weapon = a; count = b;}

#include "config\defines\mfdDefines.hpp"
#include "config\cfgWeapons.hpp"
#include "config\cfgMagazines.hpp"
#include "config\CfgVehicles.hpp"
#include "config\cfgSounds.hpp"

#include "config\UI\baseClasses.hpp"
