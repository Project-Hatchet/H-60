class CLOCK
{
	topLeft="CLOCK_LH";
	topRight="CLOCK_RH";
	bottomLeft="CLOCK_LD";
	borderLeft=0;
	borderRight=0;
	borderTop=0;
	borderBottom=0;
	color[]=common_white;
	enableParallax=0;
	class material
	{
	 ambient[] = {1, 1, 1, 1};
	 diffuse[] = {1, 1, 1, 1};
	 emissive[] = {100, 100, 100, 1};
	};
	class Bones
	{
		class secondIndicator {
			type="rotational";
			source="ClockSecond";
			sourceScale = 1;
			center[] = {0.5,0.5};
			min = "0";
			max = "1";
			minAngle = 0;
			maxAngle = 360;
			aspectRatio = 1;
		};
	}; // Bones
	class Draw
	{
	    #define TEXT_MID_MID_SRC_CLOCK(CLASS,X,Y) \
	        class CLASS { \
	            type = "text"; \
	            align = "center"; \
	            scale = 1; \
	            pos[] = {{X, Y}, 1}; \
	            right[] = {{X + 0.3, Y}, 1}; \
	            down[] = {{X, Y + 0.15}, 1};

		TEXT_MID_MID_SRC_CLOCK(CLOCK_HHMM,0.5,0.3)
			source = "time";
			text = "%H%M";
		};
		TEXT_MID_MID_SRC_CLOCK(CLOCK_S,0.5,0.42)
			source = "time";
			text = "%S";
		};
		TEXT_MID_MID_SRC_CLOCK(CLOCK_MODE,0.5,0.54)
			source = "static";
			text = "C";
		};
		#define TEXT_MID_SMALL_CLOCK(CLASS,X,Y,TEXT) \
		    class CLASS { \
		        type = "text"; \
		        source = "static"; \
				text = TEXT; \
		        align = "center"; \
		        scale = 1; \
		        sourceScale = 1; \
	            pos[] = {{X, Y}, 1}; \
	            right[] = {{X + 0.2, Y}, 1}; \
	            down[] = {{X, Y + 0.1}, 1}; \
			};
		#define TEXT_MID_SMALL_CLOCK_NUM(NUM,X,Y) \
			TEXT_MID_SMALL_CLOCK(DOUBLES(CLOCK,NUM),X,Y,NUM)

		TEXT_MID_SMALL_CLOCK_NUM(60,0.5,0.05)
		TEXT_MID_SMALL_CLOCK_NUM(5,0.7,0.1)
		TEXT_MID_SMALL_CLOCK_NUM(10,0.85,0.25)
		TEXT_MID_SMALL_CLOCK_NUM(15,0.9,0.45)
		TEXT_MID_SMALL_CLOCK_NUM(20,0.85,0.65)
		TEXT_MID_SMALL_CLOCK_NUM(25,0.7,0.8)
		TEXT_MID_SMALL_CLOCK_NUM(30,0.5,0.85)
		TEXT_MID_SMALL_CLOCK_NUM(35,0.3,0.8)
		TEXT_MID_SMALL_CLOCK_NUM(40,0.15,0.65)
		TEXT_MID_SMALL_CLOCK_NUM(45,0.1,0.45)
		TEXT_MID_SMALL_CLOCK_NUM(50,0.15,0.25)
		TEXT_MID_SMALL_CLOCK_NUM(55,0.3,0.1)

		class clockSecondArm {
			type="line";
			width = 25;
			points[] ={
				{"secondIndicator",{0, 0.17},1},
				{"secondIndicator",{0, 0.35},1}
			};
		}; // clockSecondArm
	}; // Draw

};
