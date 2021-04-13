params ["_vehicle"];
_vehicle setPilotLight ([false,true] select (_vehicle animationPhase "Switch_lights_position" > 0.5));
_vehicle animateSource ["LandingLight_Show", ([0,1] select vtx_uh60_misc_landingLightOn)];
_vehicle animateSource ["CockpitLight_Show", ([0,1] select (_vehicle animationPhase "Switch_lights_cockpit" > 0.5))];
_vehicle animateSource ["PositionLight_Show", ([0,1] select (_vehicle animationPhase "Switch_lights_position" > 0.5))];
