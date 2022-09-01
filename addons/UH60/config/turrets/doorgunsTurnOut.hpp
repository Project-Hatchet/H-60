class MainTurret: MainTurret { //Left Doorgun
    animationSourceBody="MinigunL_Dir";
    animationSourceGun="MinigunL_Elev";
    animationSourceHatch = "gunner_ffv_l";
    body="MinigunL_Dir";
    gun="MinigunL_Elev";
    gunBeg="muzzle_1";
    gunEnd="chamber_1";
    gunnerAction = "passenger_inside_6_Idle";
    gunnerInAction = "passenger_inside_1";
    gunnerName="Left door gunner";
    /* need axis set up
    gunnerInAction = "Gunner_HeliTransport3_1";
    gunnerLeftHandAnimName = "gunner_1_hand_l";
    gunnerRightHandAnimName = "gunner_1_hand_r";
    gunnerLeftLegAnimName = "gunner_1_legs";
    gunnerRightLegAnimName = "gunner_1_legs";
    */
    // AimDownSights while turned out can see gunner body
    //memoryPointGunnerOutOptics = "gunnerview_1";
    //gunnerOutOpticsModel = "\A3\Weapons_F\empty.p3d";
    gunnerOpticsModel = "\A3\Weapons_F\empty.p3d";
    memoryPointGunnerOptics="gunnerview_1";
    memoryPointsGetInGunner = "pos gunner L";
    memoryPointsGetInGunnerDir = "pos gunner L dir";
    minElev=-70; maxElev=20; initElev=-50;
    minTurn=-10; maxTurn=185; initTurn=90;
    personTurretAction = "vehicle_turnout_1";
    proxyIndex = 6;
    selectionFireAnim="zasleh";
    // shared properties
    canHideGunner = 1;
    forceHideGunner = 0;
    gunnerType = "vtx_uh60_doorgunner";
    gunnerLeftHandAnimName = "";
    gunnerRightHandAnimName = "";
    gunnerLeftLegAnimName = "";
    gunnerRightLegAnimName = "";
    hideWeaponsGunner = 1;
    isPersonTurret = 0;
    outGunnerMayFire = 1;
    primaryGunner = 0;
    stabilizedInAxes = 0;
    viewGunnerInExternal = 1;
    hasGunner = 1;
    weapons[]=
    {
        "vtx_wpn_m134"
    };
    magazines[]=
    {
        "vtx_2000Rnd_65x39_Belt_Tracer_Red"
    };
    minOutElev=0; maxOutElev=0; initOutElev=0;
    minOutTurn=0; maxOutTurn=0; initOutTurn=0;
    class TurnIn {
        limitsArrayTop[] = {{10, 185}, {10, -10}};
        limitsArrayBottom[] = {{-70, 185}, {-70, -10}};
    };
  	class TurnOut {
        limitsArrayTop[] = {{10, 80}, {50,0}, {10, -90}};
        limitsArrayBottom[] = {{-9.5111, -85.0371}, {-38.3027, -63.4442}, {-70, 0}, {-30, 80}};
    };
    class ViewOptics {
        initAngleX=0; minAngleX=0; maxAngleX=0;
        initAngleY=0; minAngleY=0; maxAngleY=0;
        initFov=0.7; minFov=0.25; maxFov=1.1;
    };
};
class RightDoorGun: MainTurret {
    animationSourceBody="MinigunR_Dir";
    animationSourceGun="MinigunR_Elev";
    animationSourceHatch = "gunner_ffv_r";
    body="MinigunR_Dir";
    gun="MinigunR_Elev";
    gunBeg="muzzle_2"; //gunBeg=endpoint of the gun
    gunEnd="chamber_2"; //gunEnd=chamber of the gun
    gunnerAction = "vehicle_turnout_1";
    gunnerInAction = "passenger_inside_1";
    gunnerName="Right door gunner";
    gunnerLeftHandAnimName = "";
    gunnerRightHandAnimName = "";
    gunnerLeftLegAnimName = "";
    gunnerRightLegAnimName = "";
    /* need axis set up
    gunnerLeftHandAnimName = "gunner_2_hand_l";
    gunnerRightHandAnimName = "gunner_2_hand_r";
    gunnerLeftLegAnimName = "gunner_2_legs";
    gunnerRightLegAnimName = "gunner_2_legs";
    */
    // AimDownSights while turned out can see gunner body
    //memoryPointGunnerOutOptics = "gunnerview_2";
    //gunnerOutOpticsModel = "\A3\Weapons_F\empty.p3d";
    memoryPointGunnerOptics="gunnerview_2";
    memoryPointsGetInGunner = "pos gunner R";
    memoryPointsGetInGunnerDir = "pos gunner R dir";
    minElev=-70; maxElev=20; initElev=-50;
    minTurn=-185; maxTurn=10; initTurn=-90;
    personTurretAction = "vehicle_turnout_1";
    proxyIndex = 7;
    selectionFireAnim="zasleh_1";
    class TurnIn {
        limitsArrayTop[] = {{10, 10}, {10, -185}};
        limitsArrayBottom[] = {{-70, 10}, {-70, -185}};
    };
  	class TurnOut {
        limitsArrayTop[] = {{10, -80}, {50, 0}, {10, 90}};
        limitsArrayBottom[] = {{-9.5111, 85.0371}, {-38.3027, 63.4442}, {-70, 0}, {-30, -80}};
    };
    weapons[]=
    {
        "vtx_wpn_m134_2nd"
    };
};


