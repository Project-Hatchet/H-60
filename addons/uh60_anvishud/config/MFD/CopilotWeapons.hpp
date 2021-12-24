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
        width = 8;
        points[] = {{"ImpactPoint", {0.01, -0.0294872}, 1}, {"ImpactPoint", {-0.01, -0.0294872}, 1}, {}, {"ImpactPoint", {0.01, 0.0294872}, 1}, {"ImpactPoint", {-0.01, 0.0294872}, 1}, {}, {"ImpactPoint", {0, -0.0294872}, 1}, {"ImpactPoint", {0, 0.0294872}, 1}, {}};
    };
};
class ATMissile
{
    condition = "ATmissile";
    class Circle
    {
        type = "line";
        width = 8;
        points[] = {{"ForwardVector", 1, "HUDCenter", {-0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.15, -0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {-0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.15, 0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.15, -0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.15, 0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {-0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.13, -0.147436}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {-0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.13, 0.147436}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.13, -0.147436}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.13, 0.147436}, 1}};
    };
};

// class weapons_selected {
//     condition = "mgun+rocket+bomb+missile";
//     class STA1_SEL {
//         condition="pylonselected1";
//         TEXT_HMD_L(AMMO_NAME,MARGIN_L,0.92)
//             source = "pylonMagazineName";
//             sourceIndex = 1;
//             sourceScale = 1;
//             text = "";
//         }; // AMMO_NAME
//     }; // STA1_SEL
//     class STA2_SEL {
//         condition="pylonselected2";
//         TEXT_HMD_L(AMMO_NAME,MARGIN_L,0.92)
//             source = "pylonMagazineNameShort";
//             sourceIndex = 2;
//             sourceScale = 1;
//             text = "";
//         }; // AMMO_NAME
//     }; // STA2_SEL
// };
