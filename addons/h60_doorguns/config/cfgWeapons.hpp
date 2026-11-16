class CfgWeapons {
    class LMG_Minigun;
    class LMG_Minigun_Transport : LMG_Minigun {
        class manual;
        class far;
        class medium;
        class close;
        class short;
    };
    class hct_wpn_m134 : LMG_Minigun_Transport {
        magazines[] = {"hct_2000Rnd_65x39_Belt_Tracer_Red"};
	class gunParticles
    {
        class effect1
        {
            positionName = "cartridge_pos";
            directionName = "cartridge_dir";
            effectName = "MachineGunCartridge1";
        };
        class effect2
        {
            positionName = "muzzle_1";
            directionName = "chamber_1";
            effectName = "MachineGun1";
        };
    };
    class manual : manual {
        reloadTime = 0.015;
        dispersion = 0.01;
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
        ffMagnitude=0.5;
        ffFrequency=11;
        ffCount=6;
        burst=1;
        soundContinuous=1;
        autoFire=1;
    };
    class far : far {
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
        ffMagnitude=0.5;
        ffFrequency=11;
        ffCount=6;
        burst=20;
        soundContinuous=1;
        autoFire=1;
    };
    class medium : medium {
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
        ffMagnitude=0.5;
        ffFrequency=11;
        ffCount=6;
        burst=20;
        soundContinuous=1;
        autoFire=1;
    };
    class close : close {
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
        ffMagnitude=0.5;
        ffFrequency=11;
        ffCount=6;
        burst=20;
        soundContinuous=1;
        autoFire=1;
    };
    class short : short {
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
        ffMagnitude=0.5;
        ffFrequency=11;
        ffCount=6;
        burst=20;
        soundContinuous=1;
        autoFire=1;
    };

    };
    class hct_wpn_m134_2nd : hct_wpn_m134 {
	    class gunParticles
        {
            class effect1
            {
                positionName = "cartridge_pos";
                directionName = "cartridge_dir";
                effectName = "MachineGunCartridge1";
            };
            class effect2
            {
                positionName = "muzzle_2";
                directionName = "chamber_2";
                effectName = "MachineGun1";
            };
        };
    };

    // SAFE: the door gun with the safety on (fnc_switchSafety)
    class hct_wpn_m134_safe: hct_wpn_m134 {
        magazines[] = {"hct_h60_safe"};
    };
};
