class MainTurret: MainTurret { //Left Doorgun
    animationSourceBody="MinigunL_Dir";
    animationSourceGun="MinigunL_Elev";
    animationSourceHatch = "gunner_ffv_l";
    body="MinigunL_Dir";
    gun="MinigunL_Elev";
    gunBeg="muzzle_1";
    gunEnd="chamber_1";
    gunnerAction = "vehicle_turnout_1";
    gunnerInAction = "passenger_inside_1";
    gunnerName="Left Door Gunner";
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
    // M134 mount limits, real-world figures from Stanman (advisor), 2026-10-06:
    //   elevation 1.5 up / 55 down; traverse 81 aft of abeam on both guns,
    //   90 forward of abeam on the LEFT gun, 78 forward on the RIGHT gun.
    // Turret azimuth is measured from the nose, positive to the LEFT, so the
    // left gun sits abeam at +90 and the right gun at -90:
    //   left : forward stop 90 - 90 =   0, aft stop   90 + 81  =  171
    //   right: forward stop -(90 - 78) = -12, aft stop -(90 + 81) = -171
    // These four numbers ARE the arc. There is deliberately no limits-array
    // polygon (class TurnIn is emptied below): a pintle mount's traverse and
    // elevation stops are independent, which is exactly a box, and a second
    // layer of limits is how the old values drifted apart (the polygon said
    // 90 down while the box stopped at 70). Add a polygon back only to cut a
    // specific corner that is proven to clip the airframe in game.
    // (The MH-60S pylon variants override these in MH60S doorguns_pylons.hpp
    // to keep the guns off the wings.)
    minElev=-55; maxElev=1.5; initElev=-50;
    minTurn=0; maxTurn=171; initTurn=90;
    personTurretAction = "vehicle_turnout_1";
    proxyIndex = 6;
    selectionFireAnim="zasleh";
    // shared properties
    canHideGunner = 1;
    forceHideGunner = 0;
    // #510 + turn-out sound objective (2026-09-07, flight-proven): filtered
    // cabin audio while turned in, raw slipstream when turned out. =0 gives
    // that switching natively; =2 kills attenuation in BOTH states (tested -
    // it is not a turn-out-only switch, despite what the wiki implies)
    soundAttenuationTurret = "VTX_H60_CabinAttenuation";
    disableSoundAttenuation = 0;
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
    playerPosition = 2;
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
    class TurnIn {};            // no polygon - the min/max box above is the whole arc
    class TurnOut : TurnIn {};
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
    gunnerName="Right Door Gunner";
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
    // right gun: same elevation, 78 forward / 81 aft of abeam (see the left gun)
    minElev=-55; maxElev=1.5; initElev=-50;
    minTurn=-171; maxTurn=-12; initTurn=-90;
    personTurretAction = "vehicle_turnout_1";
    proxyIndex = 7;
    selectionFireAnim="zasleh_1";
    weapons[]=
    {
        "vtx_wpn_m134_2nd"
    };
};


