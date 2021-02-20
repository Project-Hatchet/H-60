class CfgVehicles {
    class Helicopter_Base_H;
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class Turrets;
    }; // Helicopter_Base_H
    class vtx_H60_base: Heli_Transport_01_base_F {
        class vtx_templateFLIR;
        class Components;
        class AnimationSources;
        class Turrets: Turrets
        {
            class MainTurret;
            class CopilotTurret;
        };
    }; // Heli_Transport_01_base_F
    class vtx_MH60S_Pylons_GAU21L: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_Pilot;
        scope = 2;
        displayName = "MH-60S Knighthawk - Pylons, GAU-21(L)";
        transportSoldier=0;
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {};
            #include "doorguns.hpp"
            #include "GAU21L.hpp"
            #include "cargoTurrets.hpp"
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
            class FLIR_HIDE: MAWS_Tubes_Show {
                initPhase=0;
            };
            class FLIR_BACK: FLIR_HIDE {
                initPhase=1;
            };
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S_Pylons_GAU21L
    class vtx_MH60S_GAU21L: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_Pilot;
        scope = 2;
        displayName = "MH-60S Knighthawk - GAU-21(L)";
        transportSoldier=0;
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {};
            #include "doorguns_free.hpp"
            #include "gau21L_free.hpp"
            #include "cargoTurrets.hpp"
        };
        class AnimationSources: AnimationSources {
            class ESSS_Show {
                source="user";
                animPeriod=1;
                initPhase=0;
            }; // ESSS_Show
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
            class FLIR_HIDE: MAWS_Tubes_Show {
                initPhase=0;
            };
            class FLIR_BACK: FLIR_HIDE {
                initPhase=1;
            };
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S_GAU21L
    class vtx_MH60S_Pylons: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_Pilot;
        scope = 2;
        displayName = "MH-60S Knighthawk - Pylons";
        editorPreview = "z\vtx\addons\MH60S\Data\Preview\vtx_MH60S_Pylons.jpg";
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {};
            #include "doorguns.hpp"
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
                initPhase=0;
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
            class FLIR_HIDE: MAWS_Tubes_Show {
                initPhase=0;
            };
            class FLIR_BACK: FLIR_HIDE {
                initPhase=1;
            };
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S_Pylons_GAU21L
    class vtx_MH60S: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_Pilot;
        scope = 2;
        displayName = "MH-60S Knighthawk";
        editorPreview = "z\vtx\addons\MH60S\Data\Preview\vtx_MH60S.jpg";
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {};
            #include "doorguns_free.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S
}; // CfgVehicles
