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
    class vtx_chaingun: autocannon_30mm_RCWS {
      displayName = "M230 Chaingun";
      displayNameShort = "M230";
      magazines[] = {"VTX_M230_Chaingun_L", "VTX_M230_Chaingun_R"};
      reloadTime = 0.096; // 625 rpm
      class player: player {
        displayName = "M230";
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
  class RocketPods;
  class missiles_DAR: RocketPods {
    magazines[] += {"VTX_PylonRack_M261_M229"};
  };
	class missiles_DAGR: RocketPods {
    magazines[] += {"VTX_PylonRack_M261_DAGR"};
  };
};
