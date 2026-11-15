#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"RF_Data_Loadorder", "hct_MH60M"};
        skipWhenMissingDependencies = 1;
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

class CfgSettings_RF {
  class mission_AC {
    Units_List[] += {
      {"hct_MH60M",300,"AIR","MP"},
      {"hct_MH60M_DAP",450,"AIR","MP"}
    };
  };
};
