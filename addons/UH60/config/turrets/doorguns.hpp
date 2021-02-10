class MainTurret: MainTurret //Left Doorgun
{
    body="MinigunL_Dir";
    gun="MinigunL_Elev";
    animationSourceBody="MinigunL_Dir";
    animationSourceGun="MinigunL_Elev";
    memoryPointGunnerOptics="gunnerview_1";
    minElev=-70; maxElev=20; initElev=-50;
    minTurn=20; maxTurn=160; initTurn=90;
    soundServo[]={,db-40,1.0};
    animationSourceHatch="";
    stabilizedInAxes = 0;
    gunBeg="muzzle_1";
    gunEnd="chamber_1";
    gunnerLeftHandAnimName="minigun_base_elev_l";
    gunnerRightHandAnimName= "minigun_base_elev_l";
    gunnerLeftLegAnimName="M134Gunner_L_Legs";
    gunnerRightLegAnimName= "M134Gunner_L_Legs";
    LODOpticsIn = 1200;
    weapons[]=
    {
        "vtx_wpn_m134_safe"
    };
    magazines[]=
    {
        "vtx_2000Rnd_65x39_Belt_Tracer_Red"
    };
    gunnerType = "vtx_uh60_doorgunner";
    gunnerName="Left door gunner";
    gunnerOpticsModel="\A3\Weapons_F\empty.p3d";
    gunnerOutOpticsShowCursor=1;
    gunnerOpticsShowCursor=0;
    gunnerAction=M134Gunner;
    gunnerInAction=M134Gunner;
    memoryPointsGetInGunner= "pos gunner";
    memoryPointsGetInGunnerDir= "pos gunner dir";
    commanding=-2;
    primaryGunner=0;
    proxyIndex=1;
    selectionFireAnim="zasleh";
    class ViewOptics
    {
        initAngleX=90; minAngleX=20; maxAngleX=160;
        initAngleY=-50; minAngleY=-70; maxAngleY=20;
        initFov=0.7; minFov=0.25; maxFov=1.1;
    };
    gunnerCompartments = Compartment2;
};
class RightDoorGun: MainTurret
{
    body="MinigunR_Dir";
    gun="MinigunR_Elev";
    animationSourceBody="MinigunR_Dir";
    animationSourceGun="MinigunR_Elev";
    memoryPointsGetInGunner= "pos gunner2";
    memoryPointsGetInGunnerDir= "pos gunner2 dir";
    weapons[]=
    {
        "vtx_wpn_m134_safe"
    };
    magazines[]=
    {
        "vtx_2000Rnd_65x39_Belt_Tracer_Red"
    };
    stabilizedInAxes = 0;
    selectionFireAnim="zasleh_1";
    proxyIndex=2;
    gunnerName="Right door gunner";
    commanding=-3;
    minElev=-70; maxElev=20; initElev=-50;
    minTurn=205; maxTurn=345; initTurn=275;
    gunBeg="muzzle_2"; //gunBeg=endpoint of the gun
    gunEnd="chamber_2"; //gunEnd=chamber of the gun
    gunnerLeftHandAnimName="minigun_base_elev_r";
    gunnerRightHandAnimName= "minigun_base_elev_r";
    gunnerLeftLegAnimName="M134Gunner_r_Legs";
    gunnerRightLegAnimName= "M134Gunner_r_Legs";
    primaryGunner=0;
    memoryPointGunnerOptics="gunnerview_2";
    class ViewOptics
    {
        initAngleX=0; minAngleX=-30; maxAngleX=+30;
        initAngleY=0; minAngleY=-100; maxAngleY=+100;
        initFov=0.7; minFov=0.25; maxFov=1.1;
    };
};
