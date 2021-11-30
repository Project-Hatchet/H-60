/*
"z\vtx\addons\uh60_misc\data\textures\S-70A-9_Australia\main_co.paa",
"z\vtx\addons\uh60_misc\data\textures\S-70A-9_Australia\misc_co.paa",
"z\vtx\addons\uh60_misc\data\textures\S-70A-9_Australia\tail_co.paa",
*/
#define TEXTURE(name,part) QPATHTOEF(uh60_misc,data\textures\name\part##_co.paa)
#define TEXTURES(name) TEXTURE(name,main),TEXTURE(name,misc),TEXTURE(name,tail),
#define TEXTURES_M_T(name) TEXTURE(name,main),"",TEXTURE(name,tail),

class CfgVehicles {
  class Helicopter_Base_H;
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class AnimationSources;
  };

  class vtx_H60_base: Heli_Transport_01_base_F {
    class AnimationSources: AnimationSources {

    }; // AnimationSources

    class textureSources {
      class hh60g {
        displayName = "HH-60G Pavehawk";
        author = "JLorion";
        textures[] = {
          "","","","","","","","","","","","","","","","",
          "z\vtx\addons\UH60\Data\JLorion_HH60\Hull Main_co.paa",
          "z\vtx\addons\UH60\Data\JLorion_HH60\Misc_co.paa",
          "z\vtx\addons\UH60\Data\JLorion_HH60\Hull Tail_co.paa",
          "","","","","", // Markings, door numbers L1, L2, R1, R2
          "z\vtx\addons\UH60\Data\JLorion_HH60\Fuel_probe_co.paa"
        };
      };
      class mh60m {
        displayName = "MH-60M Blackhawk";
        author = "Riverman";
        textures[] = {
          "","","","","","","","","","","","","","","","",
          "z\vtx\addons\MH60M\data\main_co.paa",
          "z\vtx\addons\MH60M\Data\Misc_co.paa",
          "z\vtx\addons\MH60M\data\tail_co.paa"
          "","","","","", // Markings, door numbers L1, L2, R1, R2
          "z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa"
        };
      };
      class mh60s {
        displayName = "MH-60S Seahawk";
        author = "Riverman";
        textures[] = {
          "","","","","","","","","","","","","","","","",
          "z\vtx\addons\MH60S\data\mh60s_main_co.paa",
          "z\vtx\addons\MH60S\data\mh60s_misc_co.paa",
          "z\vtx\addons\MH60S\data\mh60s_tail_co.paa",
          "","","","","", // Markings, door numbers L1, L2, R1, R2
          "z\vtx\addons\UH60\Data\FuelProbe\Fuel_probe_co.paa"
        };
      };
      class uh60m {
        displayName = "UH-60M";
        author = "Riverman";
        textures[] = {
            "","","","","","","","","","","","","","","","",
            "z\vtx\addons\UH60\Data\Exterior\Hull Main_co.paa",
            "z\vtx\addons\UH60\Data\Exterior\Misc_co.paa",
            "z\vtx\addons\UH60\Data\Exterior\Hull Tail_co.paa",
            "","","","","", // Markings, door numbers L1, L2, R1, R2
            "z\vtx\addons\UH60\Data\FuelProbe\Fuel_probe_co.paa"
        };
      };
      class s70a9_aus {
        displayName = "S-70A-9 (Australia)";
        author = "seven10";
        textures[] = {
          "","","","","","","","","","","","","","","","",
          TEXTURES(S-70A-9_Australia),
          "","","","","", // Markings, door numbers L1, L2, R1, R2
          "" // Probe
        };
      };
      class s70a9_aus_med {
        displayName = "S-70A-9 MEDEVAC (Australia)";
        author = "seven10";
        textures[] = {
          "","","","","","","","","","","","","","","","",
          TEXTURES(S-70A-9_Australia_Medevac),
          "","","","","", // Markings, door numbers L1, L2, R1, R2
          "" // Probe
        };
      };
      class uh60_swe {
        displayName = "UH-60 (Sweden)";
        author = "seven10";
        textures[] = {
          "","","","","","","","","","","","","","","","",
          TEXTURES_M_T(UH-60_Sweden),
          "","","","","", // Markings, door numbers L1, L2, R1, R2
          "" // Probe
        };
      };
      class uh60_swe_med {
        displayName = "UH-60 MEDEVAC (Sweden)";
        author = "seven10";
        textures[] = {
          "","","","","","","","","","","","","","","","",
          TEXTURES_M_T(UH-60_Sweden_Medevac),
          "","","","","", // Markings, door numbers L1, L2, R1, R2
          "" // Probe
        };
      };
      class uh60m_usa {
        displayName = "UH-60M (US Army)";
        author = "seven10";
        textures[] = {
          "","","","","","","","","","","","","","","","",
          TEXTURES_M_T(UH-60M_US_Army),
          "","","","","", // Markings, door numbers L1, L2, R1, R2
          "" // Probe
        };
      };
      class uh60m_usa_med {
        displayName = "UH-60M MEDEVAC (US Army)";
        author = "seven10";
        textures[] = {
          "","","","","","","","","","","","","","","","",
          TEXTURES_M_T(UH-60M_US_Army_Medevac),
          "","","","","", // Markings, door numbers L1, L2, R1, R2
          "" // Probe
        };
      };

    };
  };
};
