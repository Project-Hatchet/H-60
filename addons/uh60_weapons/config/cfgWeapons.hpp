class cfgWeapons {
    class ace_hellfire_launcher;
    class ace_hellfire_launcher_L;
    class ace_hellfire_launcher_N;
    class vtx_hellfire_launcher: ace_hellfire_launcher {
      magazines[] = {"VTX_4Rnd_ACE_Hellfire_AGM114K"};
    };
    class vtx_hellfire_launcher_L: ace_hellfire_launcher_L {
      magazines[] = {"VTX_4Rnd_ACE_Hellfire_AGM114L"};
    };
    class vtx_hellfire_launcher_N: ace_hellfire_launcher_N {
      magazines[] = {"VTX_4Rnd_ACE_Hellfire_AGM114N"};
    };
    class autocannon_Base_F;
    class autocannon_30mm_RCWS: autocannon_Base_F {
      class player;
    };
    class vtx_chaingun_hedp: autocannon_30mm_RCWS {
      displayName = "M230 Chaingun";
      displayNameShort = "M230 HEDP";
      magazines[] = {"VTX_M230_Chaingun_L", "VTX_M230_Chaingun_R"};
      reloadTime = 0.096; // 625 rpm
      class player: player {
        displayName = "M230 HEDP";
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
};
