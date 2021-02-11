class CargoTurret_01: CargoTurret
{
        gunnerAction = "passenger_bench_1";
        memoryPointsGetInGunner = "pos cargo";
        memoryPointsGetInGunnerDir = "pos copilot dir";
        gunnerName = "Door Right 1";
        gunnerCompartments = Compartment2;
        proxyIndex = 12;
        isPersonTurret = 1;        /// this turret is able to fire both when turned in and out
        class TurnIn /// limits for gunner turned in
        {
                limitsArrayBottom[] = {[-45,-94.9656],[-45,80.9904],[-31.9033,82.8465],[-31.7935,95]};
                limitsArrayTop[] = {[14.705,-95],[14.1224,-62.859],[12.3049,32.9414],[9.0862,94.948]};
        };
        class TurnOut: TurnIn {}; /// turn out uses the same limits as turn in this time
};
class CargoTurret_02: CargoTurret_01 {
    gunnerName = "Door Right 2";
    proxyIndex = 13;
};
class CargoTurret_03: CargoTurret_01 {
    gunnerName = "Door Left 1";
    memoryPointsGetInGunnerDir = "pos cargo dir";
    proxyIndex = 14;
    class TurnIn {
        limitsArrayBottom[] = {[-32.2276,-94.9017],[-32.7616,-79.1958],[-45,-75.6488],[-44.9653,95]};
        limitsArrayTop[] = {[9.4395,-94.8557],[12.5849,-34.3841],[14.0365,60.8758],[14.1021,95]};
    };
};
class CargoTurret_04: CargoTurret_03 {
    gunnerName = "Door Left 2";
    proxyIndex = 15;
};
    //"passenger_inside_4",
#define KNEELING_SEAT(CLASS,LABEL,INDEX) \
    class CLASS: CargoTurret_03 { \
        gunnerAction = "passenger_inside_4"; \
        gunnerName =LABEL; \
        proxyIndex = INDEX; \
    };
KNEELING_SEAT(CargoTurret_05,"Cabin (left center 1)",16)
KNEELING_SEAT(CargoTurret_06,"Cabin (left center 2)",17)
//KNEELING_SEAT(CargoTurret_07,"Cabin (right back)",18)
//KNEELING_SEAT(CargoTurret_08,"Cabin (left back)",19)
KNEELING_SEAT(CargoTurret_10,"Cabin (center, front)",20)
KNEELING_SEAT(CargoTurret_11,"Cabin (right, front)",21)
KNEELING_SEAT(CargoTurret_14,"Cabin (right center 1)",24)
KNEELING_SEAT(CargoTurret_15,"Cabin (right center 2)",25)
