class CfgWeapons {
    class MGunCore;
    class M134_minigun: MGunCore {
        class LowROF;
        class manual;
        class HighROF;
    };
    class hct_MH60M_M134_minigun: M134_minigun {
        displayName = "$STR_hct_mh60m_N2xM134";
        displayNameShort = "$STR_hct_mh60m_N2xM134";
        class LowROF: LowROF {
            displayName = "$STR_hct_mh60m_M134LO";
            displayNameShort = "$STR_hct_mh60m_M134LO";
            sounds[]=
            {
                "StandardSound"
            };
            class StandardSound
            {
                begin1[]=
                {
                    "z\vtx\addons\UH60\Sounds\vtx_minigun",
                    20,
                    0.9,
                    1500,
                    {25704,27159}
                };
                soundBegin[]=
                {
                    "begin1",
                    10
                };
            };
        };
        class GunParticles {
            class effect1 {
                directionName = "cartridge_dir";
                effectName = "MachineGunCartridge";
                positionName = "chamber_2";
            };
            class effect2 {
                directionName = "cartridge_dir";
                effectName = "MachineGunCartridge";
                positionName = "chamber_1";
            };
            class FirstEffect    {
                directionName = "muzzle_2";
                effectName = "MachineGun1";
                positionName = "muzzle_2";
            };
            class SecondEffect     {
                directionName = "muzzle_1";
                effectName = "MachineGun1";
                positionName = "muzzle_1";
            };
        };
        class manual : manual {
            sounds[]=
            {
                "StandardSound"
            };
            class StandardSound
            {
                begin1[]=
                {
                    "z\vtx\addons\UH60\Sounds\vtx_minigun",
                    20,
                    0.9,
                    1500,
                    {25704,27159}
                };
                soundBegin[]=
                {
                    "begin1",
                    10
                };
            };
        };
        class HighROF : HighROF {
            displayName = "$STR_hct_mh60m_N2xM134";
            displayNameShort = "$STR_hct_mh60m_N2xM134";

            sounds[]=
            {
                "StandardSound"
            };
            class StandardSound
            {
                begin1[]=
                {
                    "z\vtx\addons\UH60\Sounds\vtx_minigun",
                    20,
                    0.9,
                    1500,
                    {25704,27159}
                };
                soundBegin[]=
                {
                    "begin1",
                    10
                };
            };
        };
    };
};
