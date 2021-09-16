class cfgWeapons {
    class LMG_Minigun;
    class gatling_20mm;
    class LMG_Minigun_Transport : LMG_Minigun {
        class manual;
    };
    class vtx_wpn_m134 : LMG_Minigun_Transport {
        magazines[] = {"vtx_2000Rnd_65x39_Belt_Tracer_Red"};
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
        burst=20;
        soundContinuous=1;
        autoFire=1;
    };
    class far : manual {};
    class medium : manual {};
    class close : manual {};
    class short : manual {};

    };
    class vtx_wpn_m134_2nd : vtx_wpn_m134 {
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
};
