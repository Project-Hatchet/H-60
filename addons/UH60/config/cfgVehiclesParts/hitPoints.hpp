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
/*
Sizes of new hitpoints in lod by lost
Air data comp 0.12
apu 0.46
auto stab hit 0.14
battery hit #1 0.21
battery hit #2 0.21
nav systems 0.28
engine 0.4
flare bucket 0.3
flight comp #1 0.35
flight comp #2 0.35
flir 0.35
fuel tank 0.98
fuel prop 0.21
Glass 0.16 (i dont think we want glass)
glass #2 0.12
hoist 0.26
Hoist Hook 0.13
light hit 0.15
rotor hit point 0.47
main rotor gear 0.7
main rotor hub 1.01
Mfd #1-4 0.21
search light 0.15
Sling hook 0.2
soar radar 0.34
Tail intermediate gear box 0.22
tail rotor Gear box 0.57
Tail rotor 0.24
wing Lass ammo 0.4
*/
