class CargoTurret_01: CargoTurret
{
    gunnerAction = "passenger_bench_1";
    memoryPointsGetInGunner = "pos cargo R";
    memoryPointsGetInGunnerDir = "pos cargo R dir";
    gunnerName = "Door Right 1 (hoist controls)";
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
    memoryPointsGetInGunner = "pos cargo R5";
    memoryPointsGetInGunnerDir = "pos cargo R5 dir";
    proxyIndex = 13;
};

#ifdef KNEELING_SEAT
    #undef KNEELING_SEAT
#endif
#define KNEELING_SEAT(CLASS,LABEL,MEMPT,INDEX) \
    class CLASS: CargoTurret_01 { \
        gunnerAction = "passenger_inside_4"; \
        gunnerName = LABEL; \
        memoryPointsGetInGunner = pos Cargo MEMPT; \
        memoryPointsGetInGunnerDir = pos Cargo MEMPT dir; \
        proxyIndex = INDEX; \
    };
KNEELING_SEAT(CargoTurret_07,"Cabin (right back)",R2,18)
//KNEELING_SEAT(CargoTurret_11,"Cabin (right, front)",21)
KNEELING_SEAT(CargoTurret_14,"Cabin (right center 1)",R3,22)
KNEELING_SEAT(CargoTurret_15,"Cabin (right center 2)",R4,23)
