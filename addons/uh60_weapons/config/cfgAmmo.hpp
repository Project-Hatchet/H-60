class CfgAmmo {
  class M_Scalpel_AT;
  class B_30mm_MP_Tracer_Green;
  class ACE_Hellfire_AGM114K: M_Scalpel_AT {class ace_missileguidance;};
  class ACE_Hellfire_AGM114L: M_Scalpel_AT {class ace_missileguidance;};
  class ACE_Hellfire_AGM114N: M_Scalpel_AT {class ace_missileguidance;};
  class VTX_Hellfire_AGM114K: ACE_Hellfire_AGM114K {
    displayName = "AGM-114K Hellfire";
    model = "z\vtx\addons\uh60_weapons\fza_agm114k.p3d";
    proxyShape = "z\vtx\addons\uh60_weapons\fza_agm114k.p3d";
    class ace_missileguidance: ace_missileguidance {
      enabled = 1; // Missile Guidance must be explicitly enabled
    };
  };
  class VTX_Hellfire_AGM114L: ACE_Hellfire_AGM114L {
    displayName = "AGM-114L Hellfire";
    model = "z\vtx\addons\uh60_weapons\fza_agm114l.p3d";
    proxyShape = "z\vtx\addons\uh60_weapons\fza_agm114l.p3d";
    class ace_missileguidance: ace_missileguidance {
      enabled = 1; // Missile Guidance must be explicitly enabled
    };
  };
  class VTX_Hellfire_AGM114N: ACE_Hellfire_AGM114N {
    displayName = "AGM-114N Hellfire";
    model = "z\vtx\addons\uh60_weapons\fza_agm114n.p3d";
    proxyShape = "z\vtx\addons\uh60_weapons\fza_agm114n.p3d";
    class ace_missileguidance: ace_missileguidance {
      enabled = 1; // Missile Guidance must be explicitly enabled
    };
  };
  class vtx_300Rnd_30mm_shells_ap : B_30mm_MP_Tracer_Green {
    caliber=4.4;
    explosive = 0.1;
    hit = 170;
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

  class vtx_300Rnd_30mm_shells_hedp : vtx_300Rnd_30mm_shells_ap {
    explosive = 1;
    hit = 20;
    indirectHit = 40;
    indirectHitRange = 2;
    explosionEffects = "ExploAmmoExplosion";
    deflecting = -1;

    //TODO: add ace fragmentation to round 
    ace_frag_enabled = 1; 
    ace_frag_metal = 210;  
    ace_frag_charge = 185;  
    ace_frag_gurney_c = 2843;  
    ace_frag_gurney_k = 3/5;  
    ace_frag_classes[] = {"ACE_frag_large"};  
    ace_frag_skip = 0;  
    ace_frag_force = 1; 
    // https://ace3mod.com/wiki/framework/frag-framework.html
    
  };
  
  class vtx_300Rnd_20mm_shells_ap : vtx_300Rnd_20mm_shells_hei {
  };
    
    deflecting = 10;
    explosionEffects = "ExploAmmoExplosion";
    indirectHitRange = 2;
    hit = 160;
    explosive = 0.1;
    indirectHit = 60;
    caliber=4.4;
};
