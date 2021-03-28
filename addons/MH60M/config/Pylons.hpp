class TransportPylonsComponent {
    uiPicture = "z\vtx\addons\MH60M\Data\UI\vtx_mh60m_dap_3den_ca.paa";
    class Pylons {
        class pylons1 {
            attachment = "VTX_M230_Chaingun_L";
            priority = 5;
            hardpoints[] = {"O_SKYFIRE", "DAR", "DAGR", "B_SHIEKER", "RHS_HP_LONGBOW_RACK", "RHS_HP_FFAR_ARMY", "RHS_HP_MELB", "RHS_HP_MELB_L", "CUP_NATO_HELO_UH60", "VTX_ST_L"};
            UIposition[] = {0.59, 0.41};
        };
        class pylons2: pylons1 {
            attachment = "VTX_PylonRack_M261_M229";
            mirroredMissilePos = 1;
            hardpoints[] = {"O_SKYFIRE", "DAR", "DAGR", "B_SHIEKER", "RHS_HP_LONGBOW_RACK", "RHS_HP_FFAR_ARMY", "RHS_HP_MELB", "RHS_HP_MELB_R", "CUP_NATO_HELO_UH60", "VTX_ST_R"};
            UIposition[] = {0.08, 0.41};
        };
    };
    class Presets {
        class Empty {
            displayName = "Empty";
            attachment[] = {};
        };
        class Default {
            displayName = "Default";
            attachment[] = {"PylonWeapon_300Rnd_20mm_shells", "VTX_PylonRack_M261_M229"};
        };
        class Interdiction {
            displayName = "30mm + DAGR";
            attachment[] = {"PylonWeapon_300Rnd_20mm_shells", "VTX_PylonRack_M261_DAGR"};
        };
        class Rocket {
            displayName = "Rocket";
            attachment[] = {"VTX_PylonRack_M261_M229", "VTX_PylonRack_M261_M229"};
        };
        class DAGR {
            displayName = "DAGR";
            attachment[] = {"VTX_PylonRack_M261_DAGR", "VTX_PylonRack_M261_DAGR"};
        };
        class Hellfire {
            displayName = "Hellfire";
            attachment[] = {"VTX_4Rnd_ACE_Hellfire_AGM114K", "VTX_4Rnd_ACE_Hellfire_AGM114K"};
        };
        class MixedGuided {
            displayName = "DAGR + Hellfire";
            attachment[] = {"VTX_PylonRack_M261_DAGR", "VTX_4Rnd_ACE_Hellfire_AGM114K"};
        };
    };
}; // TransportPylonsComponent
