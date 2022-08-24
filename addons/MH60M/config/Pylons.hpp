#define EXTRAPYLONMAGS "vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy","vtx_1000rnd_dummy"
class TransportPylonsComponent {
    uiPicture = "z\vtx\addons\MH60M\Data\UI\vtx_mh60m_dap_3den_ca.paa";
    class Pylons {
        class pylons1 {
            attachment = "VTX_M230_Chaingun_L";
            priority = 5;
            hardpoints[] = {
              "VTX_ST_L"
            };
            UIposition[] = {0.59, 0.41};
        };
        class pylons2: pylons1 {
            attachment = "VTX_PylonRack_M261_M229"; // 19rnd 70mm rockets
            mirroredMissilePos = 1;
            hardpoints[] = {
              "VTX_ST_R"
            };
            UIposition[] = {0.08, 0.41};
        };
        #define DUMMY_PYLON(CLASS) \
            class CLASS { \
                attachment = "vtx_1000rnd_dummy"; \
                priority = 5; \
                hardpoints[] = {}; \
                UIposition[] = {10, 10}; \
            };
        DUMMY_PYLON(dummy3) // CAS OVERLAY
        DUMMY_PYLON(dummy4) // TAC CENTER
        DUMMY_PYLON(dummy5) // TAC ALIGN
        DUMMY_PYLON(dummy6) // TAC ZOOM
        DUMMY_PYLON(dummy7) // TAC MOVEMENT
        DUMMY_PYLON(dummy8)   //Left HMD Color R
        DUMMY_PYLON(dummy9)   //Left HMD Color G
        DUMMY_PYLON(dummy10)  //Left HMD Color B
        DUMMY_PYLON(dummy11)  //Left HMD Brighhtness
        DUMMY_PYLON(dummy12)  //Right HMD Color R
        DUMMY_PYLON(dummy13)  //Right HMD Color G
        DUMMY_PYLON(dummy14)  //Right HMD Color B
        DUMMY_PYLON(dummy15)  //Right HMD Brightness
        DUMMY_PYLON(dummy16)  // L00
        DUMMY_PYLON(dummy17)  // L01
        DUMMY_PYLON(dummy18)  // L02
        DUMMY_PYLON(dummy19)  // L10
        DUMMY_PYLON(dummy20)  // L11
        DUMMY_PYLON(dummy21)  // L12
        DUMMY_PYLON(dummy22)  // L13
        DUMMY_PYLON(dummy23)  // L14
        DUMMY_PYLON(dummy24)  // L15
        DUMMY_PYLON(dummy25)  // R00
        DUMMY_PYLON(dummy26)  // R01
        DUMMY_PYLON(dummy27)  // R02
        DUMMY_PYLON(dummy28)  // R10
        DUMMY_PYLON(dummy29)  // R11
        DUMMY_PYLON(dummy30)  // R12
        DUMMY_PYLON(dummy31)  // R13
        DUMMY_PYLON(dummy32)  // R14
        DUMMY_PYLON(dummy33)  // R15
        DUMMY_PYLON(dummy34)  // R20
        DUMMY_PYLON(dummy35)  // R21
        DUMMY_PYLON(dummy36)  // R22
        DUMMY_PYLON(dummy37)  // R23
        DUMMY_PYLON(dummy38)  // R24
        DUMMY_PYLON(dummy39)  // R25
        DUMMY_PYLON(dummy40)  // HF engagement box
        DUMMY_PYLON(dummy41)  // HF Trajectory
        DUMMY_PYLON(dummy42)  // PRI CHAN
        DUMMY_PYLON(dummy43)  // ALT CHAN
        DUMMY_PYLON(dummy44)  // LST
        DUMMY_PYLON(dummy45)  // LRFD
        DUMMY_PYLON(dummy46)  // ADVISORIES
        DUMMY_PYLON(dummy47)  // LST MODE
    };
    class Presets {
        class Empty {
            displayName = "Empty";
            attachment[] = {};
        };
        class Default {
            displayName = "Default";
            attachment[] = {"VTX_M230_Chaingun_L", "VTX_PylonRack_M261_M229", EXTRAPYLONMAGS};
        };
        class Interdiction {
            displayName = "30mm + DAGR";
            attachment[] = {"VTX_M230_Chaingun_L", "VTX_PylonRack_M261_DAGR", EXTRAPYLONMAGS};
        };
        class Rocket {
            displayName = "Rocket";
            attachment[] = {"VTX_PylonRack_M261_M229", "VTX_PylonRack_M261_M229", EXTRAPYLONMAGS};
        };
        class APKWS {
            displayName = "APKWS";
            attachment[] = {"VTX_PylonRack_M261_APKWS", "VTX_PylonRack_M261_APKWS", EXTRAPYLONMAGS};
        };
        class Hellfire {
            displayName = "Hellfire";
            attachment[] = {"VTX_4Rnd_ACE_Hellfire_AGM114K", "VTX_4Rnd_ACE_Hellfire_AGM114K", EXTRAPYLONMAGS};
        };
        class MixedGuided {
            displayName = "DAGR + Hellfire";
            attachment[] = {"VTX_PylonRack_M261_APKWS", "VTX_4Rnd_ACE_Hellfire_AGM114K", EXTRAPYLONMAGS};
        };
    };
}; // TransportPylonsComponent
