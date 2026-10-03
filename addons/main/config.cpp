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

#ifdef DEBUG_MODE_FULL
class ctrlControlsGroupNoScrollbars;
class ctrlTree;
class Display3DEN {
    class Controls {
        class PanelRight: ctrlControlsGroupNoScrollbars {
            class Controls {
                class PanelRightCreate: ctrlControlsGroupNoScrollbars {
                    class Controls {
                        class Create: ctrlControlsGroupNoScrollbars {
                            class Controls {
                                // Units
                                class CreateObjectWEST: ctrlTree {
                                    defaultItem[] = {"BLU_F", "vtx_h60"};
                                };
                                class CreateObjectEAST: CreateObjectWEST {
                                    defaultItem[] = {};
                                };
                                class CreateObjectGUER: CreateObjectWEST {
                                    defaultItem[] = {};
                                };
                                class CreateObjectCIV: CreateObjectWEST {
                                    defaultItem[] = {};
                                };
                                // Groups
                                class CreateObjectEMPTY: CreateObjectWEST {};
                                class CreateGroupWEST: CreateObjectEMPTY {
                                    defaultItem[] = {};
                                };
                                class CreateGroupEAST: CreateObjectEMPTY {
                                    defaultItem[] = {};
                                };
                                class CreateGroupGUER: CreateObjectEMPTY {
                                    defaultItem[] = {};
                                };
                                class CreateGroupCiv: CreateObjectEMPTY {
                                    defaultItem[] = {};
                                };
                            };
                        };
                    };
                };
            };
        };
    };
};
#endif
