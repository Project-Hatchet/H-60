class TransportPylonsComponent {
    uiPicture = "z\vtx\addons\MH60M\Data\UI\vtx_mh60m_dap_3den_ca.paa";
    class Pylons {
        class pylons1 {
            attachment = "VTX_4Rnd_ACE_Hellfire_AGM114K";
            priority = 5;
            hardpoints[] = {
              "VTX_ST_L"
            };
            UIposition[] = {0.59, 0.41};
        };
        class pylons2: pylons1 {
            attachment = "VTX_PylonRack_M261_APKWS";
            mirroredMissilePos = 1;
            hardpoints[] = {
              "VTX_ST_R"
            };
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
            attachment[] = {"VTX_PylonRack_M261_APKWS", "VTX_4Rnd_ACE_Hellfire_AGM114K", ""};
        };
        class Interdiction {
            displayName = "20mm + DAGR";
            attachment[] = {"PylonWeapon_300Rnd_20mm_shells", "VTX_PylonRack_M261_APKWS", ""};
        };
        class Rocket {
            displayName = "Rocket";
            attachment[] = {"VTX_PylonRack_M261_M229", "VTX_PylonRack_M261_M229", ""};
        };
        class APKWS {
            displayName = "APKWS";
            attachment[] = {"VTX_PylonRack_M261_APKWS", "VTX_PylonRack_M261_APKWS", ""};
        };
        class Hellfire {
            displayName = "Hellfire";
            attachment[] = {"VTX_4Rnd_ACE_Hellfire_AGM114K", "VTX_4Rnd_ACE_Hellfire_AGM114K", ""};
        };
        class Unguided {
            displayName = "20mm + Rocket";
            attachment[] = {"PylonWeapon_300Rnd_20mm_shells", "VTX_PylonRack_M261_M229", ""};
        };
    };
}; // TransportPylonsComponent
