//soundGetIn[]={"z\vtx\addons\UH60\sounds\open_close",db-10,1};
//soundGetOut[]={"z\vtx\addons\UH60\sounds\open_close",db-10,1, 40};
//soundEngineOnInt[] = {"z\vtx\addons\UH60\sounds\UH1H_start_int", db-7, 1.0};
//soundEngineOnExt[] = {"z\vtx\addons\UH60\sounds\UH1H_start_ext", db-7, 1.0, 700};
//soundEngineOffInt[] =    {"z\vtx\addons\UH60\sounds\UH1H_stop_int", db-7, 1.0};
//soundEngineOffExt[] =    {"z\vtx\addons\UH60\sounds\UH1H_stop_ext", db-7, 1.0, 700};

class Sounds: Sounds
{
    /*External UH60 */
    class Engine
    {
        sound[] = {"z\vtx\addons\UH60\sounds\apu_int_loop.wss", 2.5, 0.8, 800};
        frequency = "rotorSpeed";
		volume="camPos*((rotorSpeed-0.72)*4)";
    };
    class RotorLowOut
    {
        sound[] = {"z\vtx\addons\UH60\sounds\Rotor.ogg", 1, 1.1, 1400};
        frequency = "rotorSpeed-(rotorThrust*0.6)";
		volume="camPos*(0 max (rotorSpeed-0.1))";
        cone[] = {1.6,3.14, 2.0, 0.5};
    };
    class RotorHighOut
    {
        sound[] = {"z\vtx\addons\UH60\sounds\Rotor.ogg", 1, 1.1, 1600};
        frequency = "rotorSpeed-(rotorThrust*0.6)";
		volume="camPos*10*(0 max (rotorThrust-0.95))";
        cone[] = {1.6,3.14, 2.0, 0.5};
    };
    class RotorSoundFar
    {
        sound[] = {"z\vtx\addons\UH60\sounds\Rotor_Far.ogg", 1, 1.1, 2000};
        frequency = "rotorSpeed";
        volume = "camPos*(0 max (rotorSpeed-0.1))*5";
    };

    //volume = "camPos*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)";
    //

    /*Internal UH60 */
    class EngineIn
    {
        sound[] = {"z\vtx\addons\UH60\sounds\Internal.ogg", db0, 0.8};
        frequency = "rotorSpeed*1.2-(rotorThrust*0.1)";
		volume="(1-camPos)*((rotorSpeed-0.75)*4)";
    };
    class RotorLowIn
    {
        sound[] = {"z\vtx\addons\UH60\sounds\Rotor.ogg", db5, 1.1};
        frequency = "rotorSpeed-(rotorThrust*0.3)";
		volume="2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
    };
    class ApuSoundLoop
    {
        sound[] = {"z\vtx\addons\UH60\sounds\apu_int_loop.wss", db5, 1.1};
        frequency = "CustomSoundController1";
		volume="(1-camPos)*CustomSoundController2";
    };
    /*class RotorHighIn
    {
        sound[] = {"z\vtx\addons\UH60\sounds\UH1H_rotor_high_int_1", db10, 1.1};
        frequency = "rotorSpeed";
        volume = "(1-camPos)*3*(rotorThrust-0.9)" ;
    };
    */
};
