class CfgMovesBasic
{
  class DefaultDie;
  class ManActions
  {
    UH60_Pilot="UH60_Pilot";
    UH60_Gunner="UH60_Gunner";
    GAU21Gunner="GAU21Gunner";
    M134Gunner="M134Gunner";
  };
};
class CfgMovesMaleSdr: CfgMovesBasic
{
  class States
  {
    class Crew;
    class UH60_Pilot_dead: DefaultDie
    {
      actions="DeadActions";
      speed=0.5;
      looped="false";
      terminal=1;
      file="\z\vtx\addons\UH60\anim\KIA_UH60_Pilot.rtm";
      connectTo[]=
      {
        "DeadState",
        0.1
      };
    };
    class UH60_Gunner_dead: DefaultDie
    {
      actions="DeadActions";
      speed=0.5;
      looped="false";
      terminal=1;
      file="\z\vtx\addons\UH60\anim\KIA_UH60_Gunner.rtm";
      connectTo[]=
      {
        "DeadState",
        0.1
      };
    };
    class UH60_Pilot: Crew
    {
      file="\z\vtx\addons\UH60\anim\UH60_Pilot.rtm";
      interpolateTo[]=
      {
        "UH60_Pilot",
        1
      };
    };
    class UH60_Gunner: Crew
    {
      file="\z\vtx\addons\UH60\anim\UH60_Gunner.rtm";
      interpolateTo[]=
      {
        "UH60_Gunner",
        1
      };
    };
    class GAU21Gunner: Crew
                {
                        file="\z\vtx\addons\UH60\anim\GAU21Gunner.rtm";
                        interpolateTo[]=
                        {
                                "GAU21Gunner",
                                1
                        };
                };
                class M134Gunner: Crew
                {
                        file="\z\vtx\addons\UH60\anim\UH60_Gunner.rtm";
                        interpolateTo[]=
                        {
                                "M134Gunner",
                                1
                        };
                };
  };
};
