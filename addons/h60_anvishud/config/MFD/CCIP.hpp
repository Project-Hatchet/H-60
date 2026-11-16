class MGun
{
    condition = "mgun";
    class Circle
    {
        type = "line";
        width = 8;
        points[] = {{"ImpactPoint", {0.025, 0}, 1}, {"ImpactPoint", {0.01, 0}, 1}, {}, {"ImpactPoint", {0, 0.0245726}, 1}, {"ImpactPoint", {0, 0.00982906}, 1}, {}, {"ImpactPoint", {-0.025, 0}, 1}, {"ImpactPoint", {-0.01, 0}, 1}, {}, {"ImpactPoint", {0, -0.0245726}, 1}, {"ImpactPoint", {0, -0.00982906}, 1}, {}, {"ImpactPoint", {0, -0.00982906}, 1}, {"ImpactPoint", {0.005, -0.00851197}, 1}, {"ImpactPoint", {0.00866, -0.00491453}, 1}, {"ImpactPoint", {0.01, 0}, 1}, {"ImpactPoint", {0.00866, 0.00491453}, 1}, {"ImpactPoint", {0.005, 0.00851197}, 1}, {"ImpactPoint", {0, 0.00982906}, 1}, {"ImpactPoint", {-0.005, 0.00851197}, 1}, {"ImpactPoint", {-0.00866, 0.00491453}, 1}, {"ImpactPoint", {-0.01, 0}, 1}, {"ImpactPoint", {-0.00866, -0.00491453}, 1}, {"ImpactPoint", {-0.005, -0.00851197}, 1}, {"ImpactPoint", {0, -0.00982906}, 1}};
    };
};
class Rockets
{
    condition = "rocket";
    class RocketDummy
    {
        type = "line";
        width = 4;
        //points[] = {{"ImpactPoint", {0.01, -0.0294872}, 1}, {"ImpactPoint", {-0.01, -0.0294872}, 1}, {}, {"ImpactPoint", {0.01, 0.0294872}, 1}, {"ImpactPoint", {-0.01, 0.0294872}, 1}, {}, {"ImpactPoint", {0, -0.0294872}, 1}, {"ImpactPoint", {0, 0.0294872}, 1}, {}};
        points[] = {
            {"ImpactPoint", {0.025, 0.0}, 1},
            {"ImpactPoint", {0.005, 0.0}, 1}, {},
            {"ImpactPoint", {-0.025, 0.0}, 1},
            {"ImpactPoint", {-0.005, 0.0}, 1}, {},
            {"ImpactPoint", {0.0, 0.025}, 1},
            {"ImpactPoint", {0.0, 0.005}, 1}, {},
            {"ImpactPoint", {0.0, -0.025}, 1},
            {"ImpactPoint", {0.0, -0.005}, 1}, {}
        };
    };
};
class ATMissile
{
    condition = "ATmissile";
    class Circle
    {
        type = "line";
        width = 8;
        points[] = {{"ForwardVector", {-0.15, -0.147436}, 1}, {"ForwardVector", {-0.15, -0.127778}, 1}, {}, {"ForwardVector", {-0.15, 0.147436}, 1}, {"ForwardVector", {-0.15, 0.127778}, 1}, {}, {"ForwardVector", {0.15, -0.147436}, 1}, {"ForwardVector", {0.15, -0.127778}, 1}, {}, {"ForwardVector", {0.15, 0.147436}, 1}, {"ForwardVector", {0.15, 0.127778}, 1}, {}, {"ForwardVector", {-0.15, -0.147436}, 1}, {"ForwardVector", {-0.13, -0.147436}, 1}, {}, {"ForwardVector", {-0.15, 0.147436}, 1}, {"ForwardVector", {-0.13, 0.147436}, 1}, {}, {"ForwardVector", {0.15, -0.147436}, 1}, {"ForwardVector", {0.13, -0.147436}, 1}, {}, {"ForwardVector", {0.15, 0.147436}, 1}, {"ForwardVector", {0.13, 0.147436}, 1}};
    };
};
