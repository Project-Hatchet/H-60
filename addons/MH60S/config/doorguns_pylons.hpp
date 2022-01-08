class MainTurret: MainTurret { //Left Doorgun
    minElev=-70; maxElev=20; initElev=-50;
    minTurn=-10; maxTurn=95; initTurn=90;
    class TurnIn {
        limitsArrayTop[] = {{10, 105}, {10, -10}};
        limitsArrayBottom[] = {{-70, 105}, {-70, -10}};
    };
    class TurnOut {
        limitsArrayTop[] = {{10, 105}, {10, -10}};
        limitsArrayBottom[] = {{-70, 105}, {-70, -10}};
    };
};
class RightDoorGun: RightDoorGun {
    minElev=-70; maxElev=20; initElev=-50;
    minTurn=-95; maxTurn=10; initTurn=-90;
    class TurnIn {
        limitsArrayTop[] = {{10, 10}, {10, -105}};
        limitsArrayBottom[] = {{-70, 10}, {-70, -105}};
    };
    class TurnOut {
        limitsArrayTop[] = {{10, 10}, {10, -105}};
        limitsArrayBottom[] = {{-70, 10}, {-70, -105}};
    };
};
