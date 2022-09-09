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
			width = 2;
			points[] ={
				//wings
				{{0.30, 0.86}, 1},
				{{0.70, 0.86}, 1},{},
				{{0.4,0.86-0.01}, 1},{{0.4,0.86+0.01}, 1},{},
				{{0.6,0.86-0.01}, 1},{{0.6,0.86+0.01}, 1},{},
				{{0.33,0.86-0.01}, 1},{{0.33,0.86+0.01}, 1},{},
				{{0.67,0.86-0.01}, 1},{{0.67,0.86+0.01}, 1},{},
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
		class Pylon48
		{
			type = "pylonicon";
			pos[] = {{0.33,0.87},1};
			pylon = 48;
			name = "VTX_H60";
		}; // Pylon1
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
		class Pylon49
		{
			type = "pylonicon";
			pos[] = {{0.67,0.87},1};
			pylon = 49;
			name = "VTX_H60";
		}; // Pylon1
		TEXT_MID_SCALED(LSR,0.5,0.62+0.07,"LSR",0.05)

		TEXT_MID_SCALED(GUNS,0.5,0.69+0.07,"GUNS",0.05)
		TEXT_MID_SCALED_SOURCE(GUNSAMMO,0.5,0.73+0.07,0.05,"ammo",2,1,0)
		
		TEXT_MID_SCALED(CM,0.5,0.79+0.07,"CM",0.05)
		TEXT_MID_SCALED_SOURCE(CMAMMO,0.5,0.83+0.07,0.05,"ammo",0,1,0)
	};
	class red {
		color[] = common_red;
		// class gun {
		// 	condition = "(1 -(pylonSelected1 - pylonSelected2 - pylonSelected48 - pylonSelected49)) * mgun";
		// 	class poly {
		// 		type = "polygon";
		// 		points[] = {
		// 			{
		// 				{{0.5 + -0.015, 0.74 + 0.00},1},
		// 				{{0.5 +  0.000, 0.74 + 0.02},1},
		// 				{{0.5 +  0.015, 0.74 + 0.00},1}
		// 			}
		// 		};
		// 	};
		// };
		// class laser {
		// 	condition = "1 - pylonSelected1 - pylonSelected2 - pylonSelected48 - pylonSelected49 - mgun";
		// 	class poly {
		// 		type = "polygon";
		// 		points[] = {
		// 			{
		// 				{{0.5 + -0.015, 0.68 + 0.00},1},
		// 				{{0.5 +  0.000, 0.68 + 0.02},1},
		// 				{{0.5 +  0.015, 0.68 + 0.00},1}
		// 			}
		// 		};
		// 	};
		// };
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
		}; // sta2
		class sta3L {
			condition = "pylonSelected48";
			class poly {
				type = "polygon";
				points[] = {
					{
						{{0.33 + -0.015, 0.74 + 0.00},1},
						{{0.33 +  0.000, 0.74 + 0.02},1},
						{{0.33 +  0.015, 0.74 + 0.00},1}
					}
				};
			};
		}; // sta3L
		class sta4R {
			condition = "pylonSelected49";
			class poly {
				type = "polygon";
				points[] = {
					{
						{{0.67 + -0.015, 0.74 + 0.00},1},
						{{0.67 +  0.000, 0.74 + 0.02},1},
						{{0.67 +  0.015, 0.74 + 0.00},1}
					}
				};
			};
		}; // sta3L
	};
};

class red {
	color[] = {1,0,0,1};
	class hang1 {
		condition = "pylonAmmo23 > 0";
		class cross {
			type="line";
			width = 7;
			points[] ={
				{{0.3 +0.05, 0.7},1},
				{{0.45+0.05, 0.9},1},{},
				{{0.3 +0.05, 0.9},1},
				{{0.45+0.05, 0.7},1}
			};
		}; // Cross
	}; // hang1
	class hang2 {
		condition = "pylonAmmo32 > 0";
		class cross {
			type="line";
			width = 7;
			points[] ={
				{{0.55-0.05, 0.7},1},
				{{0.7 -0.05, 0.9},1},{},
				{{0.55-0.05, 0.9},1},
				{{0.7 -0.05, 0.7},1}
			};
		}; // Cross
	};
};
