class CfgVehicles
{
    #include "crew.hpp"
    class Helicopter_Base_H;
    class Heli_Transport_01_base_F: Helicopter_Base_H
    {
    	#include "cfgUVAnimations.hpp"
        class Turrets
        {
            class MainTurret;
            class CopilotTurret;
        };
        class Eventhandlers;
        class Viewoptics;
        class ViewPilot;
        class RotorLibHelicopterProperties;
        class CargoTurret;
        class Components;
        class Sounds;
        class HitPoints;
    };

    class vtx_H60_base: Heli_Transport_01_base_F
    {
        class Wheels
        {
            class Wheel_1
            {
                sprungMass					= 6000;
            };
            class Wheel_2: Wheel_1
            {
                sprungMass					= 8500;
            };
        };
    };
};
