class GAU21_Left: MainTurret
{
    body="GAU21L_Dir";
    gun="GAU21L_Elev";
    animationSourceBody="GAU21L_Dir";
    animationSourceGun="GAU21L_Elev";
    weapons[]=
    {
        "VTX_HMG_M3M"
    };
    magazines[]=
    {
        "VTX_600Rnd_127x99_mag_Tracer_Red"
    };
    stabilizedInAxes = 0;
    selectionFireAnim="zasleh_2";
    proxyIndex=4;
    turretAxis="axis_gau21_dir_L";
    gunAxis="axis_gau21_elev_L";
    gunnerName="Left GAU21 Gunner";
    commanding=-3;
    gunnerAction=GAU21Gunner;
    gunnerInAction=GAU21Gunner;
    minElev=-80; maxElev=25; initElev=-50 ;
    minTurn=25; maxTurn=150; initTurn=120;
    class TurnIn {
        limitsArrayTop[] = {{10, 142}, {10, -16}};
        limitsArrayBottom[] = {
          {-7.61484,13.8006},
          {-36.7361,12.9635},
          {-80.0102,34.6545},
          {-69.9961,155.202}
        };
    };
    gunBeg="GAU21L_End"; //gunBeg=endpoint of the gun
    gunEnd="GAU21L_Beg"; //gunEnd=chamber of the gun
    gunnerLeftHandAnimName="GAU21_ELEV_L";
    gunnerRightHandAnimName= "GAU21_ELEV_L";
    gunnerLeftLegAnimName="GAU21_GunnerL_Legs";
    gunnerRightLegAnimName= "GAU21_GunnerL_Legs";
    primaryGunner=0;
    memoryPointGun="GAU21L_End";
    memoryPointGunnerOptics="gunnerview_3";
};
