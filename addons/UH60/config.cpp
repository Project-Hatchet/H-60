#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
      		"vtx_UH60M",
      		"vtx_HH60",
          "vtx_UH60M_Slick",
          "vtx_uh60_doorgunner",
          "vtx_uh60_pilot"
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
    class FalconDED {
		fonts[] = {
			// "\z\vtx\addons\UH60\config\Font\FalconDED6",
			// "\z\vtx\addons\UH60\config\Font\FalconDED7",
			// "\z\vtx\addons\UH60\config\Font\FalconDED8",
			// "\z\vtx\addons\UH60\config\Font\FalconDED9",
			// "\z\vtx\addons\UH60\config\Font\FalconDED10",
			// "\z\vtx\addons\UH60\config\Font\FalconDED11",
			// "\z\vtx\addons\UH60\config\Font\FalconDED12",
			// "\z\vtx\addons\UH60\config\Font\FalconDED13",
			// "\z\vtx\addons\UH60\config\Font\FalconDED14",
			// "\z\vtx\addons\UH60\config\Font\FalconDED15",
			// "\z\vtx\addons\UH60\config\Font\FalconDED16",
			// "\z\vtx\addons\UH60\config\Font\FalconDED17",
			// "\z\vtx\addons\UH60\config\Font\FalconDED18",
			// "\z\vtx\addons\UH60\config\Font\FalconDED19",
			// "\z\vtx\addons\UH60\config\Font\FalconDED20",
			// "\z\vtx\addons\UH60\config\Font\FalconDED21",
			// "\z\vtx\addons\UH60\config\Font\FalconDED22",
			// "\z\vtx\addons\UH60\config\Font\FalconDED23",
			// "\z\vtx\addons\UH60\config\Font\FalconDED24",
			// "\z\vtx\addons\UH60\config\Font\FalconDED25",
			// "\z\vtx\addons\UH60\config\Font\FalconDED26",
			// "\z\vtx\addons\UH60\config\Font\FalconDED27",
			// "\z\vtx\addons\UH60\config\Font\FalconDED28",
			// "\z\vtx\addons\UH60\config\Font\FalconDED29",
			// "\z\vtx\addons\UH60\config\Font\FalconDED30",
			// "\z\vtx\addons\UH60\config\Font\FalconDED31",
			// "\z\vtx\addons\UH60\config\Font\FalconDED34",
			// "\z\vtx\addons\UH60\config\Font\FalconDED35",
			// "\z\vtx\addons\UH60\config\Font\FalconDED37",
			"\z\vtx\addons\UH60\config\Font\FalconDED46"
		};
	};
};

#define mag_xx(a,b) class _xx_##a {magazine = a; count = b;}
#define weap_xx(a,b) class _xx_##a {weapon = a; count = b;}

#include "config\defines\mfdDefines.hpp"
#include "config\cfgWeapons.hpp"
#include "config\cfgMagazines.hpp"
#include "config\cfgVehicles.hpp"
#include "config\cfgSounds.hpp"

#include "config\UI\baseClasses.hpp"
