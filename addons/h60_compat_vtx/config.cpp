#pragma hemtt suppress pw3_padded_arg config
#include "script_component.hpp"

// Keeps content made before the vtx -> hct rename loading:
//  - every old CfgPatches name exists (missions list them in addons[]),
//  - every old placeable vehicle/unit, weapon and magazine classname exists as a
//    hidden alias of its new class (placed objects, pylon loadouts, inventories),
//  - every old function name points at the new function (mission scripts).
// Generated from the last pre-rename build; do not add new content here.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"vtx_HH60", "vtx_hook", "vtx_hook_helper", "vtx_MH60M", "vtx_MH60M_DAP", "vtx_MH60M_DAP_MLASS", "vtx_MH60S", "vtx_MH60S_GAU21L", "vtx_MH60S_Pylons", "vtx_MH60S_Pylons_GAU21L", "vtx_pylon", "vtx_S70i", "vtx_stretcher_1", "vtx_stretcher_2", "vtx_stretcher_3", "vtx_stretcher_item", "vtx_uh60_doorgunner", "vtx_uh60_pilot", "vtx_UH60M", "vtx_UH60M_MEDEVAC", "vtx_UH60M_SLICK"};
        weapons[] = {"vtx_stretcher_item"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"hct_h60_config", "hct_uh60m", "hct_s70i", "hct_hh60", "hct_mh60m", "hct_mh60s", "hct_h60_doorguns", "hct_h60_weapons", "hct_h60_misc", "hct_h60_hoist", "hct_h60_stretcher", "hct_h60_helisim", "hct_h60_sounds", "hct_h60_mfd", "hct_h60_fms", "hct_h60_flir", "hct_h60_cas", "hct_h60_ui", "hct_h60_jvmf", "hct_h60_anvishud", "hct_h60_ground", "hct_h60_ace_viv"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
    class USAF_Hatchet_AAR { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_ace_viv { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_air_control { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_hh60 { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_main { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_mh60m { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_mh60s { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_s70i { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_stretcher { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60 { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_acre { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_anvishud { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_cas { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_config { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_doorguns { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_flir { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_fms { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_ground { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_helisim { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_hoist { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_jvmf { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_mfd { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_misc { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_SFX { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_ui { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60_weapons { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
    class vtx_uh60m { units[] = {}; weapons[] = {}; requiredVersion = REQUIRED_VERSION; requiredAddons[] = {}; };
};

class CfgVehicles {
    class hct_HH60;
    class hct_hook;
    class hct_hook_helper;
    class hct_MH60M;
    class hct_MH60M_DAP;
    class hct_MH60M_DAP_MLASS;
    class hct_MH60S;
    class hct_MH60S_GAU21L;
    class hct_MH60S_Pylons;
    class hct_MH60S_Pylons_GAU21L;
    class hct_pylon;
    class hct_S70i;
    class hct_h60_stretcher_1;
    class hct_h60_stretcher_2;
    class hct_h60_stretcher_3;
    class hct_h60_stretcher_item;
    class hct_h60_doorgunner;
    class hct_h60_pilot;
    class hct_UH60M;
    class hct_UH60M_MEDEVAC;
    class hct_UH60M_SLICK;
    class vtx_HH60: hct_HH60 { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_hook: hct_hook { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_hook_helper: hct_hook_helper { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_MH60M: hct_MH60M { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_MH60M_DAP: hct_MH60M_DAP { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_MH60M_DAP_MLASS: hct_MH60M_DAP_MLASS { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_MH60S: hct_MH60S { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_MH60S_GAU21L: hct_MH60S_GAU21L { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_MH60S_Pylons: hct_MH60S_Pylons { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_MH60S_Pylons_GAU21L: hct_MH60S_Pylons_GAU21L { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_pylon: hct_pylon { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_S70i: hct_S70i { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_stretcher_1: hct_h60_stretcher_1 { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_stretcher_2: hct_h60_stretcher_2 { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_stretcher_3: hct_h60_stretcher_3 { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_stretcher_item: hct_h60_stretcher_item { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_uh60_doorgunner: hct_h60_doorgunner { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_uh60_pilot: hct_h60_pilot { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_UH60M: hct_UH60M { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_UH60M_MEDEVAC: hct_UH60M_MEDEVAC { scope = 1; scopeCurator = 0; forceInGarage = 0; };
    class vtx_UH60M_SLICK: hct_UH60M_SLICK { scope = 1; scopeCurator = 0; forceInGarage = 0; };
};

class CfgWeapons {
    class hct_h60_stretcher_item;
    class vtx_stretcher_item: hct_h60_stretcher_item { scope = 1; scopeArsenal = 0; };
};

class CfgMagazines {
    class HCT_M230_Chaingun_L;
    class HCT_M230_Chaingun_R;
    class HCT_PylonRack_M261_DAGR;
    class hct_h60_safe;
    class VTX_M230_Chaingun_L: HCT_M230_Chaingun_L { scope = 1; scopeArsenal = 0; };
    class VTX_M230_Chaingun_R: HCT_M230_Chaingun_R { scope = 1; scopeArsenal = 0; };
    class VTX_PylonRack_M261_DAGR: HCT_PylonRack_M261_DAGR { scope = 1; scopeArsenal = 0; };
    class vtx_uh60_safe: hct_h60_safe { scope = 1; scopeArsenal = 0; };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};
