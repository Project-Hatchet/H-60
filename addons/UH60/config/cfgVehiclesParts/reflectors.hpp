class Reflectors
{
    class Landing //main landing light
	{
		position = "L svetlo";
		direction = "konec L svetla";
		hitpoint = "L svetlo";
		selection = "L svetlo";
		color[] = {7000,7500,10000}; //R,G,B
		ambient[] = {70,75,100}; //R,G,B
		intensity = 50;
		size = 1;
		innerAngle = 15;
		outerAngle = 65;
		coneFadeCoef = 10;
		useFlare = 1;
		flareSize = 10;
		flareMaxDistance = 250;
		dayLight = 0;
		class Attenuation
		{
	        start = 0;
			constant = 0;
			linear = 1;
			quadratic = 1;
			hardLimitStart = 100;
			hardLimitEnd = 200;
		};
    };
    class Left //main landing light
	{
		ambient[] = {100,0,0};
                color[] = {70,0,0};
                size = 1;
                dayLight = 1;
                useFlare = 1;
                intensity = 3;
                coneFadeCoef = 2;
                innerAngle = 90;
                outerAngle = 180;
                position = "light_position_left";
             	direction = "light_position_left_dir";
                hitpoint = "";
                selection = "";

                class Attenuation {
                        start = 0;
                        constant = 0;
                        linear = 0;
                        quadratic = 0;
                        hardLimitStart = 9;
                        hardLimitEnd = 10;
                };
	};
	class Right //main landing light
        {
                ambient[] = {0,100,0};
                color[] = {0,70,0};
                size = 1;
                dayLight = 1;
                useFlare = 1;
                intensity = 3;
                coneFadeCoef = 2;
                innerAngle = 90;
                outerAngle = 180;
                position = "light_position_right";
                direction = "light_position_right_dir";
                hitpoint = "";
                selection = "";

                class Attenuation {
                        start = 0;
                        constant = 0;
                        linear = 0;
                        quadratic = 0;
                        hardLimitStart = 9;
                        hardLimitEnd = 10;
                };
        };
        class Cockpit
        {
            position = "light_cockpit";
            direction = "light_cockpit_dir";
            hitpoint = "light_cockpit";
            selection = "light_cockpit";
            color[] = {0,233/2,255/2};
            ambient[] = {0,15,30};
            intensity = 2;
            size = 1;
            innerAngle = 15;
            outerAngle = 150;
            coneFadeCoef = 1;
            useFlare = 1;
            flareSize = 0.1;
            flareMaxDistance = 1;
            dayLight = 0;
            class Attenuation
            {
                start = 0;
                constant = 0;
                linear = 1;
                quadratic = 1;
                hardLimitStart = 1;
                hardLimitEnd = 2;
            };
        };
};
aggregateReflectors[] = {};
