#include "basicdefines_A3.hpp"
#include "script_component.hpp"

class CfgPatches {
    class ADDON {
    name = COMPONENT_NAME;
    units[] = {};
    weapons[] = {};
    requiredVersion = REQUIRED_VERSION;
    requiredAddons[] = {"A3_Data_F_Decade_Loadorder", "ace_main", "hct_core"};
    author = "";
    authors[] = {"Yax", "Riverx"};
    authorUrl = "https://uh-60m.gitbook.io/workspace/guides/getting-started";
    VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"
