#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"RF_Data_Loadorder", "vtx_MH60M"};
        skipWhenMissingDependencies = 1;
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

class CfgSettings_RF {
  class mission_AC {
    Units_List[] += {
      {"vtx_MH60M",300,"AIR","MP"},
      {"vtx_MH60M_DAP",450,"AIR","MP"},
      {"vtx_MH60M_DAP_MLASS",600,"AIR","MP"}
    };
  };
};
