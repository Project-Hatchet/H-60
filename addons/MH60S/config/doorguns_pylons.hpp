class MainTurret: MainTurret { //Left Doorgun
    animationSourceBody="MinigunL_Dir";
    animationSourceGun="MinigunL_Elev";
    body="MinigunL_Dir";
    commanding=-2;
    gun="MinigunL_Elev";
    gunBeg="muzzle_1";
    gunEnd="chamber_1";
    gunnerLeftHandAnimName="minigun_base_elev_l";
    gunnerLeftLegAnimName="M134Gunner_L_Legs";
    gunnerName="Left door gunner";
    gunnerRightHandAnimName= "minigun_base_elev_l";
    gunnerRightLegAnimName= "M134Gunner_L_Legs";
    memoryPointGunnerOptics="gunnerview_1";
    memoryPointsGetInGunner = "pos gunner L";
    memoryPointsGetInGunnerDir = "pos gunner L dir";
    minElev=-70; maxElev=20; initElev=-50;
    minTurn=-10; maxTurn=95; initTurn=90;
    class TurnIn {
        limitsArrayTop[] = {{10, 95}, {10, -10}};
        limitsArrayBottom[] = {{-70, 95}, {-70, -10}};
    };
    primaryGunner=0;
    proxyIndex=1;
    selectionFireAnim="zasleh";
    //class ViewGunner {#include "ViewGunnerLeft.hpp"}; // Headlimits don't seem to apply
    class ViewOptics {
        initAngleX=90; minAngleX=20; maxAngleX=160;
        initAngleY=-50; minAngleY=-70; maxAngleY=20;
        initFov=0.7; minFov=0.25; maxFov=1.1;
    };
    // shared properties
    weapons[]=
    {
        "vtx_wpn_m134_safe"
    };
    magazines[]=
    {
        "vtx_2000Rnd_65x39_Belt_Tracer_Red"
    };
    animationSourceHatch="";
    gunnerAction=M134Gunner;
    gunnerCompartments = Compartment2;
    gunnerInAction=M134Gunner;
    gunnerOpticsModel="\A3\Weapons_F\empty.p3d";
    gunnerOpticsShowCursor=0;
    gunnerOutOpticsShowCursor=1;
    gunnerType = "vtx_uh60_doorgunner";
    LODOpticsIn = 1200;
    soundServo[]={,db-40,1.0};
    stabilizedInAxes = 0;
};
class RightDoorGun: MainTurret {
    animationSourceBody="MinigunR_Dir";
    animationSourceGun="MinigunR_Elev";
    body="MinigunR_Dir";
    commanding=-3;
    gun="MinigunR_Elev";
    gunBeg="muzzle_2"; //gunBeg=endpoint of the gun
    gunEnd="chamber_2"; //gunEnd=chamber of the gun
    gunnerLeftHandAnimName="minigun_base_elev_r";
    gunnerLeftLegAnimName="M134Gunner_r_Legs";
    gunnerName="Right door gunner";
    gunnerRightHandAnimName= "minigun_base_elev_r";
    gunnerRightLegAnimName= "M134Gunner_r_Legs";
    memoryPointGunnerOptics="gunnerview_2";
    memoryPointsGetInGunner = "pos gunner R";
    memoryPointsGetInGunnerDir = "pos gunner R dir";
    minElev=-70; maxElev=20; initElev=-50;
    minTurn=-95; maxTurn=10; initTurn=-90;
    class TurnIn {
        limitsArrayTop[] = {{10, 10}, {10, -95}};
        limitsArrayBottom[] = {{-70, 10}, {-70, -95}};
    };
    primaryGunner=0;
    proxyIndex=2;
    selectionFireAnim="zasleh_1";
    class ViewOptics {
        initAngleX=0; minAngleX=-30; maxAngleX=+30;
        initAngleY=0; minAngleY=-100; maxAngleY=+100;
        initFov=0.7; minFov=0.25; maxFov=1.1;
    };
};
