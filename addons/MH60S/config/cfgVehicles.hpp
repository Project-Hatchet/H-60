class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F {
        class Turrets;
    };
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class Turrets: Turrets {
            class CopilotTurret;
        };
    }; // Helicopter_Base_H
    class vtx_H60_base: Heli_Transport_01_base_F {
        class Components;
        class AnimationSources;
        class Turrets: Turrets
        {
            class MainTurret;
            class CopilotTurret: CopilotTurret {
                class Components;
            };
        };
        class ViewPilot;
    }; // Heli_Transport_01_base_F
    class vtx_MH60S_Pylons_GAU21L: vtx_H60_base {
        class VTX_H60_HDTS_Common;
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_CoPilot_Turret;
        scope = 1;
        displayName = "MH-60S Knighthawk - Pylons, GAU-21(L)";
        transportSoldier=0;
        class CargoTurret;
        class Turrets: Turrets
        {
            #include "\z\vtx\addons\UH60\config\turrets\copilot.hpp"
            #include "\z\vtx\addons\UH60\config\turrets\doorguns_pylons.hpp"
            #include "GAU21L.hpp"
            #include "cargoTurretsGAU21L.hpp"
        };
        class Components: Components {
            #include "Pylons.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
            class ESSS_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            }; // ESSS_Show
            class CabinSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class GunnerSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class GAU21_L_Hide {
                source="user";
                animPeriod=1;
                initPhase=0;
            };
            class MAWS_Tubes_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S_Pylons_GAU21L
    class vtx_MH60S_GAU21L: vtx_H60_base {
        class VTX_H60_HDTS_Common;
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_CoPilot_Turret;
        scope = 2;
        displayName = "MH-60S Knighthawk - GAU-21(L)";
        transportSoldier=0;
        class CargoTurret;
        class Turrets: Turrets
        {
            #include "\z\vtx\addons\UH60\config\turrets\doorguns.hpp"
            #include "\z\vtx\addons\UH60\config\turrets\copilot.hpp"
            #include "gau21L_free.hpp"
            #include "cargoTurretsGAU21L.hpp"
        };
        class AnimationSources: AnimationSources {
            class ESSS_Show {
                source="user";
                animPeriod=1;
                initPhase=0;
            }; // ESSS_Show
            class GunnerSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class CabinSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class GAU21_L_Hide {
                source="user";
                animPeriod=1;
                initPhase=0;
            };
            class MAWS_Tubes_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S_GAU21L
    class vtx_MH60S_Pylons: vtx_H60_base {
        class VTX_H60_HDTS_Common;
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_CoPilot_Turret;
        scope = 2;
        displayName = "MH-60S Knighthawk - Pylons";
        editorPreview = "z\vtx\addons\MH60S\Data\Preview\vtx_MH60S_Pylons.jpg";
        transportSoldier = 0;
        cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
        cargoAction[] = {};
        class CargoTurret;
        class Turrets: Turrets
        {
            #include "\z\vtx\addons\UH60\config\turrets\copilot.hpp"
            #include "\z\vtx\addons\UH60\config\turrets\doorguns_pylons.hpp"
            #include "\z\vtx\addons\UH60\config\turrets\cargoTurrets.hpp"
        };
        class Components: Components {
            #include "Pylons.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
            class Gatling_1 {
                source="revolving";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Gatling_2 {
                source="revolving";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Muzzle_flash1 {
                source="ammorandom";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Muzzle_flash2 {
                source="ammorandom";
                weapon="vtx_MH60M_M134_minigun";
            };
            class ESSS_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            }; // ESSS_Show
            class CabinSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class GunnerSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class GAU21_L_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class MAWS_Tubes_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
        weapons[] = {"CMFlareLauncher","vtx_MH60M_M134_minigun"};
        magazines[] = {"60Rnd_CMFlareMagazine","5000Rnd_762x51_Belt"};
        memoryPointGun[] = {"muzzle_1","muzzle_2"};
        gunBeg[] = {"muzzle_1","muzzle_2"};
        gunEnd[] = {"chamber_1","chamber_2"};
        selectionFireAnim = "zasleh_12";
    }; // vtx_MH60S_Pylons_GAU21L
    class vtx_MH60S: vtx_H60_base {
        class VTX_H60_HDTS_Common;
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_CoPilot_Turret;
        scope = 2;
        displayName = "MH-60S Knighthawk";
        editorPreview = "z\vtx\addons\MH60S\Data\Preview\vtx_MH60S.jpg";
        class Turrets: Turrets
        {
            #include "\z\vtx\addons\UH60\config\turrets\copilot.hpp"
            #include "\z\vtx\addons\UH60\config\turrets\doorguns.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S
}; // CfgVehicles
