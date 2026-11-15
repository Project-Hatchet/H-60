class cfgWeapons {
    class HMG_01;
    class HMG_M2: HMG_01 {
        class manual;
    };
    class HCT_HMG_M3M: HMG_M2 {
        displayName = "$STR_hct_mh60s_GAU21";
        magazines[] = {"HCT_600Rnd_127x99_mag_Tracer_Red"};
        class manual: manual {
            reloadTime = 0.0545;
        };
        class GunParticles {
        	class effect1 {
        		positionName = "GAU21L_End";
        		directionName = "GAU21L_Beg";
        		effectName = "MachineGunCloud";
        	};
        	class effect2 {
        		positionName = "GAU21L_eject_pos";
        		directionName = "GAU21L_eject_dir";
        		effectName = "MachineGunEject";
        	};
        	class effect3 {
        		positionName = "GAU21L_eject_pos";
        		directionName = "GAU21L_eject_dir";
        		effectName = "MachineGunCartridge2";
        	};
        };

    };
};
