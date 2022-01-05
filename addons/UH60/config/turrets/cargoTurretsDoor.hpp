class CargoTurret_01: CargoTurret {
    gunnerAction = "passenger_bench_1";
    memoryPointsGetInGunner = "pos Cargo R";
    memoryPointsGetInGunnerDir = "pos Cargo R dir";
    gunnerName = "Door Right 1 (hoist controls)";
    gunnerCompartments = Compartment2;
    proxyIndex = 12;
    isPersonTurret = 1;        /// this turret is able to fire both when turned in and out
    selectionFireAnim = "";
    disableSoundAttenuation = 0;
    LODTurnedIn = 1200;
    LODTurnedOut = 1200;
    LODOpticsIn = 1200;
    LODOpticsOut = 1200;
    class TurnIn /// limits for gunner turned in
    {
        limitsArrayBottom[] = {[-45,-94.9656],[-45,80.9904],[-31.9033,82.8465],[-31.7935,95]};
        limitsArrayTop[] = {[14.705,-95],[14.1224,-62.859],[12.3049,32.9414],[9.0862,94.948]};
    };
    class TurnOut: TurnIn {}; /// turn out uses the same limits as turn in this time
};
class CargoTurret_02: CargoTurret_01 {
    gunnerName = "Door Right 2";
    memoryPointsGetInGunner = "pos Cargo R5";
    memoryPointsGetInGunnerDir = "pos Cargo R5 dir";
    proxyIndex = 13;
};
class CargoTurret_03: CargoTurret_01 {
    gunnerName = "Door Left 1";
    proxyIndex = 14;
    memoryPointsGetInGunner = "pos Cargo L";
    memoryPointsGetInGunnerDir = "pos Cargo L dir";
    class TurnIn {
        limitsArrayBottom[] = {[-32.2276,-94.9017],[-32.7616,-79.1958],[-45,-75.6488],[-44.9653,95]};
        limitsArrayTop[] = {[9.4395,-94.8557],[12.5849,-34.3841],[14.0365,60.8758],[14.1021,95]};
    };
};
class CargoTurret_04: CargoTurret_03 {
    gunnerName = "Door Left 2";
    memoryPointsGetInGunner = "pos Cargo L5";
    memoryPointsGetInGunnerDir = "pos Cargo L5 dir";
    proxyIndex = 15;
};
