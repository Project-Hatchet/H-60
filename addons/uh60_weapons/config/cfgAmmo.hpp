class CfgAmmo {
  class M_Scalpel_AT;
  class B_30mm_MP_Tracer_Green;
  class ACE_Hellfire_AGM114K: M_Scalpel_AT {class ace_missileguidance;};
  class ACE_Hellfire_AGM114N: M_Scalpel_AT {class ace_missileguidance;};
  class VTX_Hellfire_AGM114K: ACE_Hellfire_AGM114K {
    displayName = "AGM-114K Hellfire";
    model = "z\vtx\addons\uh60_weapons\fza_agm114l.p3d";
    proxyShape = "z\vtx\addons\uh60_weapons\fza_agm114l.p3d";
    class ace_missileguidance: ace_missileguidance {
      attackProfiles[] = {"hellfire","hellfire_hi","hellfire_lo"};
      canVanillaLock = 0;
      defaultAttackProfile = "hellfire";
      defaultSeekerLockMode = "LOAL";
      defaultSeekerType = "SALH";
      enabled = 0;
      incDeflection = 0.0005;
      maxDeflection = 0.009;
      minDeflection = 0.0005;
      seekerAccuracy = 0.99;
      seekerAngle = 75;
      seekerLockModes[] = {"LOAL","LOBL"};
      seekerMaxRange = 8000;
      seekerMinRange = 1;
      seekerTypes[] = {"SALH"};
      seekLastTargetPos = 0;
    };
    initTime = 0.2;
    thrust = 100;
    thrusttime = 5;
    effectsMissileInit = "RocketBackEffectsRPG";
    effectsMissile = "vtx_agm114_trail";
    ExplosionEffects = "vtx_agm114_explosion";
    submunitionAmmo = "ammo_Penetrator_AGM_02";
  };
  hit = 400;
  class VTX_Hellfire_AGM114N: ACE_Hellfire_AGM114N {
    displayName = "AGM-114N Hellfire";
    model = "z\vtx\addons\uh60_weapons\fza_agm114l.p3d";
    proxyShape = "z\vtx\addons\uh60_weapons\fza_agm114l.p3d";
    class ace_missileguidance: ace_missileguidance {
      attackProfiles[] = {"hellfire","hellfire_hi","hellfire_lo"};
      canVanillaLock = 0;
      defaultAttackProfile = "hellfire";
      defaultSeekerLockMode = "LOAL";
      defaultSeekerType = "SALH";
      enabled = 0;
      incDeflection = 0.0005;
      maxDeflection = 0.009;
      minDeflection = 0.0005;
      seekerAccuracy = 0.99;
      seekerAngle = 75;
      seekerLockModes[] = {"LOAL","LOBL"};
      seekerMaxRange = 8000;
      seekerMinRange = 1;
      seekerTypes[] = {"SALH"};
      seekLastTargetPos = 0;
    };
    hit = 400;
    initTime = 0.2;
    thrust = 100;
    thrusttime = 5;
    irLock = 0;
    laserLock = 0;
    manualControl = 0;
  timeToLive = 40;
    effectsMissileInit = "RocketBackEffectsRPG";
    effectsMissile = "vtx_agm114_trail";
  };

  class M_PG_AT;
  class VTX_APKWS: M_PG_AT
  {
    displayName = "AGR-20 APKWS";
    displayNameShort = "APKWS";
    description = "AGR-20 Advanced Precision Kill Weapon System Laser Guided Rocket";
    descriptionShort = "AGR-20 APKWS Guided Rocket";
    irLock = 0;
    laserLock = 0;
    manualControl = 0;
    maxSpeed = 300;
    ace_rearm_caliber = 70;
    class ace_missileguidance
    {
      enabled = 1;
      minDeflection = 0.0005;
      maxDeflection = 0.0025;
      incDeflection = 0.0005;
      canVanillaLock = 0;
      defaultSeekerType = "SALH";
      seekerTypes[] = {"SALH"};
      defaultSeekerLockMode = "LOAL";
      seekerLockModes[] = {"LOAL"};
      seekerAngle = 40; //
      seekerAccuracy = 1;
      seekerMinRange = 1;
      seekerMaxRange = 5000; //
      defaultAttackProfile = "LIN";
      attackProfiles[] = {"LIN"};
    };
  };

  class vtx_30mm_shells_ap : B_30mm_MP_Tracer_Green {
    caliber=4.4;
    explosive = 0.1;
    hit = 170;
    indirectHit = 60;
    indirectHitRange = 2;
    explosionEffects = "ExploAmmoExplosion";
    deflecting = 10;
    tracerColor[] = {0.7,0.1,0.1,0.04};
    tracerColorR[] = {0.7,0.1,0.1,0.04};
  };
  class vtx_30mm_shells_hedp : vtx_30mm_shells_ap {
    explosive = 1;
    hit = 20;
    indirectHit = 40;
    indirectHitRange = 2;
    explosionEffects = "ExploAmmoExplosion";
    deflecting = -1;

    ace_frag_enabled = 0; 
    ace_frag_metal = 210;  
    ace_frag_charge = 185;  
    ace_frag_gurney_c = 2843;  
    ace_frag_gurney_k = 3/5;  
    ace_frag_classes[] = {"ACE_frag_large"};  
    ace_frag_skip = 0;  
    ace_frag_force = 1; 
    tracerColor[] = {0.7,0.1,0.1,0.04};
    tracerColorR[] = {0.7,0.1,0.1,0.04};
    // https://ace3mod.com/wiki/framework/frag-framework.html
    
  };
  
};
