class cfgWeapons {
  	class MissileLauncher;
    class ace_hellfire_launcher;
    class ace_hellfire_launcher_L;
    class ace_hellfire_launcher_N;
    class weapon_HARMLauncher : MissileLauncher {
      class LoalDistance: MissileLauncher {};
    };
    class vtx_hellfire_launcher: ace_hellfire_launcher {
      ace_laser_showHud = 0;
      magazines[] = {"VTX_4Rnd_ACE_Hellfire_AGM114K"};
      class Eventhandlers {
        class vtx_hellfire {
          fired = "_this call vtx_uh60_weapons_fnc_fired";
        };
      };
    };
    class vtx_hellfire_launcher_N: ace_hellfire_launcher_N {
      ace_laser_showHud = 0;
      magazines[] = {"VTX_4Rnd_ACE_Hellfire_AGM114N"};
      class Eventhandlers {
        class vtx_hellfire {
          fired = "_this call vtx_uh60_weapons_fnc_fired";
        };
      };
    };
    class autocannon_Base_F;
    class autocannon_30mm_RCWS: autocannon_Base_F {
      class player;
      class manual;
    };
    class vtx_chaingun_hedp: autocannon_30mm_RCWS {
      displayName = "M230 Chaingun";
      displayNameShort = "M230 HEDP";
      magazines[] = {"VTX_M230_Chaingun_L", "VTX_M230_Chaingun_R"};
      class player: player {
        displayName = "M230 HEDP";
        reloadTime = 0.109;
			  dispersion = 0.006;
      class StandardSound 
      {
          soundSetShot[] = {"vtx_m230_soundset"};
      };	
      };
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
              positionName = "muzzle_effect_pos";
              directionName = "muzzleend";
              effectName = "MachineGun1";
          };
      };
      class Eventhandlers {
        class vtx_chaingun {
          fired = "_this call vtx_uh60_weapons_fnc_firedChaingun";
        };
      };
    };
    class vtx_chaingun_ap: vtx_chaingun_hedp {
      displayName = "M230 Chaingun";
      displayNameShort = "M230 AP";
      magazines[] = {"VTX_M230_Chaingun_L_AP", "VTX_M230_Chaingun_R_AP"};
      class player: player {
        displayName = "M230 AP";
      };
    };
  class RocketPods;
  class missiles_DAR: RocketPods {
    class Burst;
    class Far_AI;
    class Medium_AI;
  };
  class vtx_hydra: missiles_DAR{
    displayName = "M299";
    displayNameShort = "M299";
    magazines[] = {"VTX_PylonRack_M261_M229"};
    class Burst: Burst {
      displayName = "M299/Ripple";
    };
    class Single: Burst {
      displayName = "M299/Single";
      autoFire = 0;
    };
    modes[] = {"Far_AI","Medium_AI", "Single", "Burst"};
  };

  class ace_missileguidance_dagr;
  class vtx_dagr: ace_missileguidance_dagr {
    magazines[] = {"VTX_PylonRack_M261_DAGR"};
    class Burst;
    class Far_AI;
    class Medium_AI;
  };
	class vtx_apkws: vtx_dagr {
    displayName = "APKWS";
    displayNameShort = "APKWS";
    magazines[] = {"VTX_PylonRack_M261_APKWS"};
    class Burst: Burst {
      displayName = "APKWS";
    };
    class Far_AI: Far_AI {displayName = "APKWS";};
    class Medium_AI: Medium_AI {displayName = "APKWS";};
  };
  class weapon_HARMLauncher_HL : weapon_HARMLauncher {
    displayName = "AGM-88HL";
    displayNameShort = "AGM-88HL";
    magazines[] = {"PylonMissile_Missile_HARM_x1_HL"};
    lockAcquire = 1;
    weaponLockDelay = 0;
    class Eventhandlers {
      class vtx_harm {
        fired = "_this call vtx_uh60_weapons_fnc_fired";
      };
    };
    class LoalDistance : LoalDistance {
      displayName = "AGM-88HL";
    };
  };
};
