class cfgMagazines {
  class VehicleMagazine;
  class PylonRack_4Rnd_ACE_Hellfire_AGM114K;
  class PylonRack_4Rnd_ACE_Hellfire_AGM114N;
  class VTX_4Rnd_ACE_Hellfire_AGM114K: PylonRack_4Rnd_ACE_Hellfire_AGM114K { // 4x Launcher Support Rack
    displayName = "4x AGM-114K [H60]";
    count = 4;
    mass = 340;
    hardpoints[] = {"UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_HELLFIRE_RACK", "RHS_HP_LONGBOW_RACK"};
    ammo = "VTX_Hellfire_AGM114K";
    pylonWeapon = "vtx_hellfire_launcher";
  };
  class VTX_4Rnd_ACE_Hellfire_AGM114N: PylonRack_4Rnd_ACE_Hellfire_AGM114N { // 4x Launcher Support Rack
    displayName = "4x AGM-114N [H60]";
    count = 4;
    mass = 340;
    hardpoints[] = {"UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_HELLFIRE_RACK", "RHS_HP_LONGBOW_RACK"};
    ammo = "VTX_Hellfire_AGM114N";
    pylonWeapon = "vtx_hellfire_launcher_N";
  };
  class VTX_M230_Chaingun_L: VehicleMagazine {
    scope = 2;
    ammo = "B_30mm_MP_Tracer_Green";
    displayname = "30x113 mm";
    displayNameShort = "30x113 mm";
    initspeed = 805;
    pylonWeapon = "vtx_chaingun";
    muzzlePos = "muzzlePos";
    muzzleEnd = "muzzleEnd";
    weight = 180;
    mass = 180;
    tracersEvery = 1;
    lastRoundsTracer = 1;
    count = 300;
    hardpoints[] =    {"VTX_ST_L"};
    model = \z\vtx\addons\uh60_weapons\Data\M230\M230_L.p3d;
  };
  class VTX_M230_Chaingun_R: VehicleMagazine {
    scope = 2;
    ammo = "B_30mm_MP_Tracer_Green";
    displayname = "30x113 mm";
    displayNameShort = "30x113 mm";
    initspeed = 805;
    pylonWeapon = "vtx_chaingun";
    muzzlePos = "muzzlePos";
    muzzleEnd = "muzzleEnd";
    weight = 180;
    mass = 180;
    tracersEvery = 1;
    lastRoundsTracer = 1;
    count = 300;
    hardpoints[] =    {"VTX_ST_R"};
    model = \z\vtx\addons\uh60_weapons\Data\M230\M230_R.p3d;
  };

  class PylonRack_7Rnd_Rocket_04_HE_F ;
	class VTX_PylonRack_M261_M229: PylonRack_7Rnd_Rocket_04_HE_F  {
		author = "Ampersand";
		count = 19;
    displayName = "19x M229 HE [H60]";
    displayNameShort = "M229 HE";
    weight = 300;
    pylonWeapon = "vtx_m229_he";
    model = QPATHTOF(fza_pod_m261.p3d);
	};
  class VTX_PylonRack_M261_DAGR: VTX_PylonRack_M261_M229  {
    ammo = "VTX_Rocket_APKWS";
    count = 19;
    displayName = "19x APKWS [H60]";
    displayNameShort = "APKWS";
    pylonWeapon = "vtx_rocket_apkws";
  };
  class VTX_PylonRack_M261_M156: VTX_PylonRack_M261_M229  {
    ammo = "VTX_M156_WP";
    count = 19;
    displayName = "19x M159 WP [H60]";
    displayNameShort = "M159 WP";
    pylonWeapon = "vtx_rocket_wp";
  };
  class VTX_PylonRack_M261_M257: VTX_PylonRack_M261_M229  {
    ammo = "VTX_M257_Illum";
    count = 19;
    displayName = "19x M257 Illum [H60]";
    displayNameShort = "M257 Illum";
    pylonWeapon = "vtx_rocket_illum";
  };
};
