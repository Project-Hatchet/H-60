params ["_vehicle"];

_vehicle animateSource ["LandingLight_Show", ([0,1] select vtx_uh60_misc_landingLightOn)];
_vehicle animateSource ["SearchLight_Show", ([0,1] select vtx_uh60_misc_searchLightOn)];
_vehicle animateSource ["CockpitLight_Show", ([0,1] select (_vehicle animationPhase "Switch_lights_cockpit" > 0.5))];
_vehicle animateSource ["CabinLight_Show", ([0,1] select (_vehicle animationPhase "Switch_lights_cockpit" > 0.5))];
_vehicle animateSource ["PositionLight_Show", ([0,1] select (_vehicle animationPhase "Switch_lights_position" > 0.5))];

private _isLightOn = vtx_uh60_misc_landingLightOn
  || {vtx_uh60_misc_searchLightOn}
  || {_vehicle animationPhase "Switch_lights_position" > 0.5}
  || {_vehicle animationPhase "Switch_lights_cockpit" > 0.5};

if (_isLightOn isNotEqualTo isLightOn _vehicle) then {
    _vehicle setPilotLight _isLightOn;
};
