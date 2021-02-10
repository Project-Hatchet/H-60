#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
    		"vtx_UH60M",
    		"vtx_HH60"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_main"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgMoves.hpp"

class CfgEditorSubcategories {
    class vtx_h60 {
        displayName = "H-60 Pack";
    };
};

class CfgFontFamilies {
    class VTX_UH60M_Font {
    fonts[] = {"\z\vtx\addons\UH60\config\Font\font46"};
    };
};

#define mag_xx(a,b) class _xx_##a {magazine = a; count = b;}
#define weap_xx(a,b) class _xx_##a {weapon = a; count = b;}

#include "config\defines\viewAngleDefines.hpp"
#include "config\defines\mfdDefines.hpp"
#include "config\cfgWeapons.hpp"
#include "config\cfgMagazines.hpp"
#include "config\cfgVehicles.hpp"
#include "config\cfgSounds.hpp"

#include "config\UI\baseClasses.hpp"
