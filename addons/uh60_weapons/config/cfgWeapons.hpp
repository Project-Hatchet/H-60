class cfgWeapons {
    class ace_hellfire_launcher;
    class vtx_hellfire_launcher: ace_hellfire_launcher {
      displayName = "AGM-114K Hellfire II";
      magazines[] = {"VTX_4Rnd_ACE_Hellfire_AGM114K"};
    };
    class autocannon_Base_F;
    class autocannon_30mm_RCWS: autocannon_Base_F {
      class player;
    };
    class vtx_chaingun: autocannon_30mm_RCWS {
      displayName = "M230 Chaingun";
      displayNameShort = "M230";
      magazines[] = {"VTX_M230_Chaingun_L", "VTX_M230_Chaingun_R"};
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
};
