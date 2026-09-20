// DAP emergency passenger seats (Riverman ruling 2026-09-18): the door-sill
// pair NOT used by the crew-chief turn-out (turn-out rides 15/12, the
// "Door Left 2"/"Door Right 1" spots) stays available FULL TIME - two seats
// so a DAP can pick up a downed aircrew without carrying the base M's absurd
// 10-pax cabin. Exact copies of the base M's "Door Right 2"/"Door Left 1"
// seats (cargoTurrets.hpp), same names, same class names, written standalone
// because the DAP doesn't include CargoTurret_01. Never locked by the
// turn-out lock hook (it matches gunnerName "(Turned Out)" only); the
// door-state lock from fnc_interactedCabinDoor (#612) applies to them like
// on every variant, since they match the "Door " name prefix.
class CargoTurret_02: CargoTurret {
    gunnerAction = "passenger_bench_1";
    gunnerInAction = "passenger_bench_1";
    memoryPointsGetInGunner = "pos Cargo R5";
    memoryPointsGetInGunnerDir = "pos Cargo R5 dir";
    gunnerName = "Door Right 2";
    gunnerCompartments = Compartment2;
    proxyIndex = 13;
    isPersonTurret = 2;        /// enables a person to get into the turret from outside
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
class CargoTurret_03: CargoTurret_02 {
    gunnerName = "Door Left 1";
    proxyIndex = 14;
    // NOT the M's "pos Cargo L" (tester report 2026-09-20): on the DAP that
    // point already serves the L Crew Chief seat, and the engine resolves one
    // get-in per memory point - the crew chief won and this seat was
    // unreachable from outside/scroll. L5 is free on the DAP (the M's Door
    // Left 2 point; that seat doesn't exist here).
    memoryPointsGetInGunner = "pos Cargo L5";
    memoryPointsGetInGunnerDir = "pos Cargo L5 dir";
    class TurnIn {
        limitsArrayBottom[] = {[-32.2276,-94.9017],[-32.7616,-79.1958],[-45,-75.6488],[-44.9653,95]};
        limitsArrayTop[] = {[9.4395,-94.8557],[12.5849,-34.3841],[14.0365,60.8758],[14.1021,95]};
    };
};
