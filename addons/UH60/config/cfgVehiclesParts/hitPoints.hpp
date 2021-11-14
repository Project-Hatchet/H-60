class HitPoints: HitPoints {
    class HitEngine1 {
        armor = 1;
        convexComponent = "engine_1_hit";
        explosionShielding = 4;
        material = 51;
        minimalHit = 0;
        name = "engine_1_hit";
        passThrough = 0;
        radius = 0.3;
        visual = "motor";

    };
    class HitEngine2: HitEngine1 {
        convexComponent = "engine_2_hit";
        name = "engine_2_hit";
    };
    class HitBattery1: HitEngine1 {
        convexComponent = "battery_1_hit";
        name = "battery_1_hit";
    };
    class HitBattery2: HitEngine1 {
        convexComponent = "battery_2_hit";
        name = "battery_2_hit";
    };
    class HitComGun	: HitEngine1 {
        convexComponent = "flir_hit";
        name = "flir_hit";
        radius = 0.2;
    };
    class HitComTurret: HitEngine1 {
        convexComponent = "radar_hit";
        name = "radar_hit";
        radius = 0.2;
    };
    class HitMAWS: HitEngine1 {
        convexComponent = "maws_hit";
        name = "maws_hit";
        radius = 0.1;
    };
    class HitVRotor {
        armor = 1.3;
        convexComponent = "tail_rotor_hit";
        explosionShielding = 6;
        material = 51;
        minimalHit = 0.05;
        name = "tail_rotor_hit";
        passThrough = 0.3;
        radius = 1;
        visual = "tail rotor static";
    };
};
