class CfgAmmo {
  class M_Scalpel_AT;
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
      pitchRate = 30; // degrees per second
      yawRate = 30;
      seekerAccuracy = 0.99;
      seekerAngle = 75;
      seekerLockModes[] = {"LOAL","LOBL"};
      defaultNavigationType = "Direct";
      navigationTypes[] = { "Direct", "ZeroEffortMiss" };
      seekerMaxRange = 8000;
      seekerMinRange = 1;
      seekerTypes[] = {"SALH"};
      seekLastTargetPos = 0;
      class navigationStates {
          class initial {
              transitionCondition = "ace_hellfire_fnc_midCourseTransition";
              navigationType = "Direct";
          };
          class terminal {
              transitionCondition = "";
              navigationType = "ZeroEffortMiss";
          };
          // transitions from initial -> termimal
          states[] = {"initial", "terminal"};
      };
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
      pitchRate = 30; // degrees per second
      yawRate = 30;
      seekerAccuracy = 0.99;
      seekerAngle = 75;
      seekerLockModes[] = {"LOAL","LOBL"};
      defaultNavigationType = "Direct";
      navigationTypes[] = { "Direct", "ZeroEffortMiss" };
      seekerMaxRange = 8000;
      seekerMinRange = 1;
      seekerTypes[] = {"SALH"};
      seekLastTargetPos = 0;
      class navigationStates {
          class initial {
              transitionCondition = "ace_hellfire_fnc_midCourseTransition";
              navigationType = "Direct";
          };
          class terminal {
              transitionCondition = "";
              navigationType = "ZeroEffortMiss";
          };
          // transitions from initial -> termimal
          states[] = {"initial", "terminal"};
      };
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
  class B_30mm_HE;
  class vtx_30mm_shells_hedp : B_30mm_HE
  {
   //Ace Cfg
        ACE_caliber = 30.00;
        ACE_bulletLength = 104;
        ACE_bulletMass = 234;
        ACE_muzzleVelocityVariationSD = 0.37;
        ACE_ammoTempMuzzleVelocityShifts[] = {-27.20, -26.44, -23.76, -21.00, -17.54, -13.10, -7.95, -1.62, 6.24, 15.48, 27.75};
        ACE_ballisticCoefficients[] = {0.151};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere = "ICAO";
        ACE_dragModel = 1;
        ACE_muzzleVelocities[] = {805};
        ACE_barrelLengths[] = {1676};
        ace_vehicle_damage_incendiary = 0.7;

        ace_frag_enabled            = 1;
        ace_frag_skip               = 0;

        hit                         = 60;
        indirectHit                 = 20;
        indirectHitRange            = 3.5;
        typicalSpeed                = 800;
        maxspeed                    = 825;
        explosive                   = 0.8;

        airFriction                 = -0.00036;
        airlock                     = 0;
        irlock                      = 0;
        weaponType                  = "cannon";
        warheadName                 = "AP";

        //dual purpose warhead
        submunitionAmmo             ="ammo_Penetrator_30mm";
        submunitionDirectionType    ="SubmunitionModelDirection";
        submunitionInitSpeed        =1000;
        submunitionParentSpeedCoef  =0;
        submunitionInitialOffset[]  ={0,0,-0.2};
        triggerOnImpact             =1;
        deleteParentWhenTriggered   =0;
    };
};
