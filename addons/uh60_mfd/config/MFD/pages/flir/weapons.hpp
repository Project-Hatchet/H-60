class pylonsBackground {
	color[] = common_black;
	COLORED_POLYGON(GUNS,0.44,0.75,0.12,0.11,common_black)
	COLORED_POLYGON(FLIR,0.47,0.69,0.06,0.06,common_black)
	COLORED_POLYGON(CM,0.45,0.86,0.1,0.1,common_black)
	COLORED_POLYGON(STA1,0.30-10,0.76,0.1,0.2,common_black)
	COLORED_POLYGON(STA2,0.60-10,0.76,0.1,0.2,common_black)
	class white {
		color[] = common_white;
		class lines {
			type="line";
			width = 4;
			points[] ={
				//wings
				{{0.35, 0.86}, 1},
				{{0.65, 0.86}, 1},{},
				{{0.4,0.86-0.01}, 1},{{0.4,0.86+0.01}, 1},{},
				{{0.6,0.86-0.01}, 1},{{0.6,0.86+0.01}, 1},{},
				//guns
				{{0.44, 0.86}, 1},
				{{0.44, 0.75}, 1},
				{{0.56, 0.75}, 1},
				{{0.56, 0.86}, 1},{},
				//flir
				{{0.47, 0.75}, 1},
				{{0.47, 0.69}, 1},
				{{0.53, 0.69}, 1},
				{{0.53, 0.75}, 1},{},
				//cm
				{{0.45, 0.86}, 1},
				{{0.45, 0.96}, 1},
				{{0.55, 0.96}, 1},
				{{0.55, 0.86}, 1}
			};
		}; // lines
		class Pylon1
		{
			type = "pylonicon";
			pos[] = {{0.4,0.87},1};
			pylon = 1;
			name = "VTX_H60";
		}; // Pylon1
		class Pylon2
		{
			type = "pylonicon";
			pos[] = {{0.6,0.87},1};
			pylon = 2;
			name = "VTX_H60";
		}; // Pylon2
		TEXT_MID_SCALED(LSR,0.5,0.62+0.07,"LSR",0.05)

		TEXT_MID_SCALED(GUNS,0.5,0.69+0.07,"GUNS",0.05)
		TEXT_MID_SCALED_SOURCE(GUNSAMMO,0.5,0.73+0.07,0.05,"ammo",2,1,0)
		
		TEXT_MID_SCALED(CM,0.5,0.79+0.07,"CM",0.05)
		TEXT_MID_SCALED_SOURCE(CMAMMO,0.5,0.83+0.07,0.05,"ammo",0,1,0)
	};
	class red {
		color[] = common_red;
		class gun {
			condition = "(1 -(pylonSelected1 - pylonSelected2)) * mgun";
			class poly {
				type = "polygon";
				points[] = {
					{
						{{0.5 + -0.015, 0.74 + 0.00},1},
						{{0.5 +  0.000, 0.74 + 0.02},1},
						{{0.5 +  0.015, 0.74 + 0.00},1}
					}
				};
			};
		};
		class laser {
			condition = "1 - pylonSelected1 - pylonSelected2 - mgun";
			class poly {
				type = "polygon";
				points[] = {
					{
						{{0.5 + -0.015, 0.68 + 0.00},1},
						{{0.5 +  0.000, 0.68 + 0.02},1},
						{{0.5 +  0.015, 0.68 + 0.00},1}
					}
				};
			};
		};
		class sta1 {
			condition = "pylonSelected1";
			class poly {
				type = "polygon";
				points[] = {
					{
						{{0.40 + -0.015, 0.74 + 0.00},1},
						{{0.40 +  0.000, 0.74 + 0.02},1},
						{{0.40 +  0.015, 0.74 + 0.00},1}
					}
				};
			};
		};
		class sta2 {
			condition = "pylonSelected2";
			class poly {
				type = "polygon";
				points[] = {
					{
						{{0.60 + -0.015, 0.74 + 0.00},1},
						{{0.60 +  0.000, 0.74 + 0.02},1},
						{{0.60 +  0.015, 0.74 + 0.00},1}
					}
				};
			};
		};
	};
};


class LaserOn {
    condition = "laseron";
    blinkingPattern[] = {0.5, 0.5};
	color[] = common_black;
	COLORED_POLYGON(PB1,0.4,0.2,0.2,0.04,common_black)
	class white {
		color[] = common_white;
		TEXT_MID_SCALED(LRD_LASE_TXT,0.5,0.2,"LRD LASE DES",0.04)
		class Border {
			type="line";
			width = 2;
			points[] ={
				{{0.5 - 0.10, 0.2 - 0.00},1},
				{{0.5 + 0.10, 0.2 - 0.00},1},
				{{0.5 + 0.10, 0.2 + 0.04},1},
				{{0.5 - 0.10, 0.2 + 0.04},1},
				{{0.5 - 0.10, 0.2 - 0.00},1}
			};
		}; // Border
	}; // whtie
}; // LaserOn


class hellfire {
	color[] = common_black;
	condition = "missile";
	BOXEDTEXT(LASERL,0.93,(BEZEL_Y1-0.02),0.11,0.04,"PRI CHAN","1")
	BOXEDTEXT(LASERV,0.93,(BEZEL_Y1+0.02),0.04,0.04,"A",COND_ISNUMPYLON(42,0))
	BOXEDTEXT(LASERB,0.93,(BEZEL_Y1+0.02),0.04,0.04,"B",COND_ISNUMPYLON(42,1))
	BOXEDTEXT(LASERC,0.93,(BEZEL_Y1+0.02),0.04,0.04,"C",COND_ISNUMPYLON(42,2))
	BOXEDTEXT(LASERD,0.93,(BEZEL_Y1+0.02),0.04,0.04,"D",COND_ISNUMPYLON(42,3))
	BOXEDTEXT(LASERE,0.93,(BEZEL_Y1+0.02),0.04,0.04,"E",COND_ISNUMPYLON(42,4))
	BOXEDTEXT(LASERF,0.93,(BEZEL_Y1+0.02),0.04,0.04,"F",COND_ISNUMPYLON(42,5))

	BOXEDTEXT(TRAJL,0.93,(BEZEL_Y2-0.02),0.09,0.04,"TRAJ","1")
	BOXEDTEXT(TRAJ_LO,0.93,(BEZEL_Y2+0.02),0.07,0.04,"LO",COND_ISNUMPYLON(41,0))
	BOXEDTEXT(TRAJV,0.93,(BEZEL_Y2+0.02),0.07,0.04,"DIR",COND_ISNUMPYLON(41,1))
	BOXEDTEXT(TRAJ_HI,0.93,(BEZEL_Y2+0.02),0.07,0.04,"HI",COND_ISNUMPYLON(41,2))

	BOXEDTEXT(MODEL,0.93,(BEZEL_Y3-0.02),0.08,0.04,"MODE","1")
	BOXEDTEXT(MODEV,0.93,(BEZEL_Y3+0.02),0.08,0.04,"NORM","1")

	BOXEDTEXT(ACQL,0.93,(BEZEL_Y4-0.02),0.07,0.04,"ACQ","1")
	BOXEDTEXT(ACQV,0.93,(BEZEL_Y4+0.02),0.07,0.04,"FLIR","1")
	class white {
		color[] = common_white;
		#include "hellfireBoxes.hpp"
	}; // white
};