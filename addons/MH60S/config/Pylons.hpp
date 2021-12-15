#define EXTRAPYLONMAGS "vtx_1000rnd_dummy", "vtx_1000rnd_dummy", "vtx_1000rnd_dummy", "vtx_1000rnd_dummy", "vtx_1000rnd_dummy", "vtx_1000rnd_dummy", "vtx_1000rnd_dummy", "vtx_1000rnd_dummy"
class TransportPylonsComponent {
    uiPicture = "z\vtx\addons\MH60M\Data\UI\vtx_mh60m_dap_3den_ca.paa";
    class Pylons {
        class pylons1 {
            attachment = "VTX_4Rnd_ACE_Hellfire_AGM114K";
            priority = 5;
            hardpoints[] = {"O_SKYFIRE", "DAR", "DAGR", "B_SHIEKER", "RHS_HP_LONGBOW_RACK", "RHS_HP_FFAR_ARMY", "RHS_HP_MELB", "RHS_HP_MELB_L", "CUP_NATO_HELO_UH60", "VTX_ST_L"};
            UIposition[] = {0.59, 0.41};
        };
        class pylons2: pylons1 {
            attachment = "VTX_PylonRack_M261_DAGR";
            mirroredMissilePos = 1;
            hardpoints[] = {"O_SKYFIRE", "DAR", "DAGR", "B_SHIEKER", "RHS_HP_LONGBOW_RACK", "RHS_HP_FFAR_ARMY", "RHS_HP_MELB", "RHS_HP_MELB_R", "CUP_NATO_HELO_UH60", "VTX_ST_R"};
            UIposition[] = {0.08, 0.41};
        };
        #define DUMMY_PYLON(CLASS) \
            class CLASS { \
                attachment = "vtx_1000rnd_dummy"; \
                priority = 5; \
                hardpoints[] = {}; \
                UIposition[] = {10, 10}; \
            };
        DUMMY_PYLON(dummy3)
        DUMMY_PYLON(dummy4)
        DUMMY_PYLON(dummy5)
        DUMMY_PYLON(dummy6)
        DUMMY_PYLON(dummy7)
        DUMMY_PYLON(dummy8)
        DUMMY_PYLON(dummy9)
        DUMMY_PYLON(dummy10)
  			DUMMY_PYLON(dummy11)
  			DUMMY_PYLON(dummy12)
  			DUMMY_PYLON(dummy13)
    };
    class Presets {
        class Empty {
            displayName = "Empty";
            attachment[] = {};
        };
        class Default {
            displayName = "Default";
            attachment[] = {"VTX_PylonRack_M261_DAGR", "VTX_4Rnd_ACE_Hellfire_AGM114K", EXTRAPYLONMAGS};
        };
        class Interdiction {
            displayName = "30mm + DAGR";
            attachment[] = {"PylonWeapon_300Rnd_20mm_shells", "VTX_PylonRack_M261_DAGR", EXTRAPYLONMAGS};
        };
        class Rocket {
            displayName = "Rocket";
            attachment[] = {"VTX_PylonRack_M261_M229", "VTX_PylonRack_M261_M229", EXTRAPYLONMAGS};
        };
        class DAGR {
            displayName = "DAGR";
            attachment[] = {"VTX_PylonRack_M261_DAGR", "VTX_PylonRack_M261_DAGR", EXTRAPYLONMAGS};
        };
        class Hellfire {
            displayName = "Hellfire";
            attachment[] = {"VTX_4Rnd_ACE_Hellfire_AGM114K", "VTX_4Rnd_ACE_Hellfire_AGM114K", EXTRAPYLONMAGS};
        };
        class Unguided {
            displayName = "30mm + Rocket";
            attachment[] = {"PylonWeapon_300Rnd_20mm_shells", "VTX_PylonRack_M261_M229", EXTRAPYLONMAGS};
        };
    };
}; // TransportPylonsComponent
