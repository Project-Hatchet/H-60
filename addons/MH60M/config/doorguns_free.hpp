class MainTurret: MainTurret //Left Doorgun
{
    body="MinigunL_Dir";
    gun="MinigunL_Elev";
    animationSourceBody="MinigunL_Dir";
    animationSourceGun="MinigunL_Elev";
    memoryPointGunnerOptics="gunnerview_1";
    minElev=-70; maxElev=20; initElev=-50;
    minTurn=-10; maxTurn=190; initTurn=90;
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
    memoryPointsGetInGunner= "pos gunner L";
    memoryPointsGetInGunnerDir= "pos gunner L dir";
    commanding=-2;
    primaryGunner=1;
    proxyIndex=1;
    selectionFireAnim="zasleh";
    gunnerCompartments = Compartment2;
    class TurnIn {
        limitsArrayTop[] = {[10,-10],[10,185]};
        limitsArrayBottom[] = {[-85,-10],[-85,185]};
    };
};
class RightDoorGun: MainTurret
{
    body="MinigunR_Dir";
    gun="MinigunR_Elev";
    animationSourceBody="MinigunR_Dir";
    animationSourceGun="MinigunR_Elev";
    memoryPointsGetInGunner= "pos gunner R";
    memoryPointsGetInGunnerDir= "pos gunner R dir";
    selectionFireAnim="zasleh_1";
    proxyIndex=2;
    gunnerName="Right door gunner";
    commanding=-3;
    minElev=-70; maxElev=20; initElev=-50;
    minTurn=-190; maxTurn=10; initTurn=-90;
    gunBeg="muzzle_2"; //gunBeg=endpoint of the gun
    gunEnd="chamber_2"; //gunEnd=chamber of the gun
    gunnerLeftHandAnimName="minigun_base_elev_r";
    gunnerRightHandAnimName= "minigun_base_elev_r";
    gunnerLeftLegAnimName="M134Gunner_r_Legs";
    gunnerRightLegAnimName= "M134Gunner_r_Legs";
    primaryGunner=0;
    memoryPointGunnerOptics="gunnerview_2";
    class TurnIn {
        limitsArrayTop[] = {{20,10},{20,170}};
        limitsArrayBottom[] = {{-85,10},{-85,170}};
    };
};
