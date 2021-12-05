class cfgWeapons {
    class ace_hellfire_launcher;
    class ace_hellfire_launcher_L;
    class ace_hellfire_launcher_N;
    class vtx_hellfire_launcher: ace_hellfire_launcher {
      magazines[] = {"VTX_4Rnd_ACE_Hellfire_AGM114K"};
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
  class Rocket_04_HE_Plane_CAS_01_F ;
  class vtx_m229_he: Rocket_04_HE_Plane_CAS_01_F  {
    magazines[] = {"VTX_PylonRack_M261_M229"};
  };
	class vtx_rocket_apkws: Rocket_04_HE_Plane_CAS_01_F  {
    magazines[] = {"VTX_PylonRack_M261_DAGR"};
  };
	class vtx_rocket_wp: Rocket_04_HE_Plane_CAS_01_F  {
    magazines[] = {"VTX_PylonRack_M261_M156"};
  };
	class vtx_rocket_illum: Rocket_04_HE_Plane_CAS_01_F  {
    magazines[] = {"VTX_PylonRack_M261_M257"};
    class EventHandlers {
      class vtx_fired {
        fired = "";
      };
    };
  };
};
