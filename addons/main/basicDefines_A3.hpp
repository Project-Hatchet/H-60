#define true 1
#define false 0

#define VSoft 0
#define VArmor 1
#define VAir 2

// type scope
#define private 0
#define protected 1
#define public 2

#define CanSeeRadar 1
#define CanSeeEye 2
#define CanSeeOptics 4
#define CanSeeEar 8
#define CanSeeCompass 16
#define CanSeeRadarC CanSeeRadar+CanSeeCompass
#define CanSeeAll 31
#define CanSeePeripheral 32

//lock acquiring
#define manualLA            0
#define automaticLA     1

//lockable target type
#define lockGroundTT            0
#define lockAirGroundTT     1
#define lockAirTT                 2
#define lockGround            0
#define lockAirGround     1
#define lockAir                 2

//missile lock type
#define fireAndForgetLT     0
#define keepLockedLT            1
#define manualLT                    2

#define SPEED_STATIC 1e10

#define LockNo		0
#define LockCadet	1
#define LockYes		2

enum {StabilizedInAxesNone,StabilizedInAxisX,StabilizedInAxisY,StabilizedInAxesBoth,StabilizedInAxesXYZ};

#define StabilizedInAxesNone 0
#define StabilizedInAxisX 1
#define StabilizedInAxisY 2
#define StabilizedInAxesBoth 3
#define StabilizedInAxesXYZ 4

#define CM_none                0
#define CM_Lock_Visual 1
#define CM_Lock_IR         2
#define CM_Lock_Laser    4
#define CM_Lock_Radar    8
#define CM_Missile         16


#define CMImmunity_GOOD 0.9
#define CMImmunity_MIDDLE 0.65
#define CMImmunity_BAD        0.5

#define mag_xx(a,b) class _xx_##a {magazine = a; count = b;}
#define weap_xx(a,b) class _xx_##a {weapon = a; count = b;}
#define item_xx(a,b) class _xx_##a {name = a; count = b;}
#define bag_xx(a,b) class _xx_##a {backpack = a; count = b;}

#define DEFAULT_SLOT 0
#define MUZZLE_SLOT 101
#define OPTICS_SLOT 201
#define FLASHLIGHT_SLOT 301
#define NVG_SLOT 602
#define GOGGLE_SLOT 603
#define HEADGEAR_SLOT 605
#define UNIFORM_SLOT 801

#define HMD_SLOT             616
#define BINOCULAR_SLOT 617
#define MEDIKIT_SLOT     619
#define RADIO_SLOT        611

#define VEST_SLOT            701
#define BACKPACK_SLOT    901

#define LOAD(weight,capacity) maximumLoad = ##capacity##; \
							    mass = ##weight##;
							    
#define HeadArmourCoef 2.5
#define BodyArmourCoef 10
#define HandArmourCoef 5
#define LegArmourCoef 5