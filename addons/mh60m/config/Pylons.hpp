class TransportPylonsComponent {
    uiPicture = "z\vtx\addons\MH60M\Data\UI\vtx_mh60m_dap_3den_ca.paa";
    class Pylons {
        class pylons1 {
            attachment = "HCT_M230_Chaingun_L";
            priority = 5;
            hardpoints[] = {
              "HCT_ST_L"
            };
            UIposition[] = {0.59, 0.41};
        };
        class pylons2: pylons1 {
            attachment = "HCT_PylonRack_M261_M229"; // 19rnd 70mm rockets
            mirroredMissilePos = 1;
            hardpoints[] = {
              "HCT_ST_R"
            };
            UIposition[] = {0.08, 0.41};
        };
    };
    class Presets {
        class Empty {
            displayName = "$STR_hct_mh60m_Empty";
            attachment[] = {};
        };
        class Default {
            displayName = "$STR_hct_mh60m_Default";
            attachment[] = {"HCT_M230_Chaingun_L", "HCT_PylonRack_M261_M229", ""};
        };
        class Interdiction {
            displayName = "$STR_hct_mh60m_N30mmAPKWS";
            attachment[] = {"HCT_M230_Chaingun_L", "HCT_PylonRack_M261_APKWS", ""};
        };
        class Rocket {
            displayName = "$STR_hct_mh60m_Rocket";
            attachment[] = {"HCT_PylonRack_M261_M229", "HCT_PylonRack_M261_M229", ""};
        };
        class APKWS {
            displayName = "$STR_hct_mh60m_APKWS";
            attachment[] = {"HCT_PylonRack_M261_APKWS", "HCT_PylonRack_M261_APKWS", ""};
        };
        class Hellfire {
            displayName = "$STR_hct_mh60m_Hellfire";
            attachment[] = {"HCT_4Rnd_ACE_Hellfire_AGM114K", "HCT_4Rnd_ACE_Hellfire_AGM114K", ""};
        };
        class MixedGuided {
            displayName = "$STR_hct_mh60m_APKWSHellfire";
            attachment[] = {"HCT_PylonRack_M261_APKWS", "HCT_4Rnd_ACE_Hellfire_AGM114K", ""};
        };
    };
}; // TransportPylonsComponent
