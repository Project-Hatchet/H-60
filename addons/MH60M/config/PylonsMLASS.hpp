class TransportPylonsComponent {
    uiPicture = "z\vtx\addons\MH60M\Data\UI\vtx_mh60m_dap_3den_ca.paa";
    class Pylons {
        class pylons1 {
            attachment = "VTX_M230_Chaingun_L";
            priority = 5;
            hardpoints[] = {
              "VTX_ST_L"
            };
            UIposition[] = {0.55, 0.41};
        };
        class pylons2: pylons1 {
            attachment = "VTX_PylonRack_M261_M229"; // 19rnd 70mm rockets
            mirroredMissilePos = 1;
            hardpoints[] = {
              "VTX_ST_R"
            };
            UIposition[] = {0.12, 0.41};
        };
        class pylons3: pylons1 {
            UIposition[] = {0.59, 0.47};
            hardpoints[] = {
              "VTX_ST_OUTBOARD"
            };
            attachment = "VTX_4Rnd_ACE_Hellfire_AGM114K";
        };
        class pylons4: pylons2 {
            UIposition[] = {0.08, 0.47};
            hardpoints[] = {
              "VTX_ST_OUTBOARD"
            };
            attachment = "VTX_4Rnd_ACE_Hellfire_AGM114K";
        };
    };
    class Presets {
        class Empty {
            displayName = "Empty";
            attachment[] = {};
        };
        class Default {
            displayName = "Default";
            attachment[] = {"VTX_M230_Chaingun_L", "VTX_PylonRack_M261_M229"};
        };
        class Interdiction {
            displayName = "30mm + APKWS";
            attachment[] = {"VTX_M230_Chaingun_L", "VTX_PylonRack_M261_APKWS"};
        };
        class Rocket {
            displayName = "Rocket";
            attachment[] = {"VTX_PylonRack_M261_M229", "VTX_PylonRack_M261_M229"};
        };
        class APKWS {
            displayName = "APKWS";
            attachment[] = {"VTX_PylonRack_M261_APKWS", "VTX_PylonRack_M261_APKWS"};
        };
        class Hellfire {
            displayName = "Hellfire";
            attachment[] = {"VTX_4Rnd_ACE_Hellfire_AGM114K", "VTX_4Rnd_ACE_Hellfire_AGM114K"};
        };
        class MixedGuided {
            displayName = "APKWS + Hellfire";
            attachment[] = {"VTX_PylonRack_M261_APKWS", "VTX_4Rnd_ACE_Hellfire_AGM114K"};
        };
    };
}; // TransportPylonsComponent
