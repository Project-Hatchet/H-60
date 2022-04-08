class Bones
{
	class Center
	{
		type = "fixed";
		pos[] = {-0.04,0.0};
	};
	class Center2
	{
		type = "fixed";
		pos[] = {-0.04,0.08};
	};
	class Center3
	{
		type = "fixed";
		pos[] = {0.04,0.00};
	};
	class Center4
	{
		type = "fixed";
		pos[] = {0.04,0.08};
	};
};
class Draw
{
	class Rails {
		type="line";
		width = 3;
		points[] ={
			// vertical bar center
			{{0, -0.05},1},
			{{0, 0.05},1},{},
			// top row
			{{-0.04,-0.03}, 1},
			{{ 0.04,-0.03}, 1},{},
			// hangers
			{{-0.04,-0.03},1},{{-0.04,-0.01},1},{},
			{{ 0.04,-0.03},1},{{ 0.04,-0.01},1},{},
			// bot row
			{{-0.04,0.05}, 1},
			{{0.04, 0.05}, 1},{},
			// hangers
			{{-0.04,0.05},1},{{-0.04,0.06},1},{},
			{{ 0.04,0.05},1},{{ 0.04,0.06},1},{}
		};
	};
	class Default
	{
		condition = "PylonAmmoRelative>0";
		color[] = {1,1,1};
		alpha = 0.6;
		class Missile1
		{
			condition = "PylonAmmo>=4";
			class Shape
			{
				type = "line";
				width = 4.0;
				points[] = {{"Center",{0,-0.0147436},1},{"Center",{0.0075,-0.0127679},1},{"Center",{0.01299,-0.00737179},1},{"Center",{0.015,0},1},{"Center",{0.01299,0.00737179},1},{"Center",{0.0075,0.0127679},1},{"Center",{0,0.0147436},1},{"Center",{-0.0075,0.0127679},1},{"Center",{-0.01299,0.00737179},1},{"Center",{-0.015,0},1},{"Center",{-0.01299,-0.00737179},1},{"Center",{-0.0075,-0.0127679},1},{"Center",{0,-0.0147436},1},{},{"Center",{0.0106066,-0.0104253},1},{"Center",{0.0212132,-0.0208506},1},{},{"Center",{0.0106066,0.0104253},1},{"Center",{0.0212132,0.0208506},1},{},{"Center",{-0.0106066,0.0104253},1},{"Center",{-0.0212132,0.0208506},1},{},{"Center",{-0.0106066,-0.0104253},1},{"Center",{-0.0212132,-0.0208506},1},{}};
			};
		};
		class Missile2
		{
			condition = "PylonAmmo>=3";
			class Shape
			{
				type = "line";
				width = 4.0;
				points[] = {{"Center2",{0,-0.0147436},1},{"Center2",{0.0075,-0.0127679},1},{"Center2",{0.01299,-0.00737179},1},{"Center2",{0.015,0},1},{"Center2",{0.01299,0.00737179},1},{"Center2",{0.0075,0.0127679},1},{"Center2",{0,0.0147436},1},{"Center2",{-0.0075,0.0127679},1},{"Center2",{-0.01299,0.00737179},1},{"Center2",{-0.015,0},1},{"Center2",{-0.01299,-0.00737179},1},{"Center2",{-0.0075,-0.0127679},1},{"Center2",{0,-0.0147436},1},{},{"Center2",{0.0106066,-0.0104253},1},{"Center2",{0.0212132,-0.0208506},1},{},{"Center2",{0.0106066,0.0104253},1},{"Center2",{0.0212132,0.0208506},1},{},{"Center2",{-0.0106066,0.0104253},1},{"Center2",{-0.0212132,0.0208506},1},{},{"Center2",{-0.0106066,-0.0104253},1},{"Center2",{-0.0212132,-0.0208506},1},{}};
			};
		};
		class Missile3
		{
			condition = "PylonAmmo>=2";
			class Shape
			{
				type = "line";
				width = 4.0;
				points[] = {{"Center3",{0,-0.0147436},1},{"Center3",{0.0075,-0.0127679},1},{"Center3",{0.01299,-0.00737179},1},{"Center3",{0.015,0},1},{"Center3",{0.01299,0.00737179},1},{"Center3",{0.0075,0.0127679},1},{"Center3",{0,0.0147436},1},{"Center3",{-0.0075,0.0127679},1},{"Center3",{-0.01299,0.00737179},1},{"Center3",{-0.015,0},1},{"Center3",{-0.01299,-0.00737179},1},{"Center3",{-0.0075,-0.0127679},1},{"Center3",{0,-0.0147436},1},{},{"Center3",{0.0106066,-0.0104253},1},{"Center3",{0.0212132,-0.0208506},1},{},{"Center3",{0.0106066,0.0104253},1},{"Center3",{0.0212132,0.0208506},1},{},{"Center3",{-0.0106066,0.0104253},1},{"Center3",{-0.0212132,0.0208506},1},{},{"Center3",{-0.0106066,-0.0104253},1},{"Center3",{-0.0212132,-0.0208506},1},{}};
			};
		};
		class Missile4
		{
			condition = "PylonAmmo>=1";
			class Shape
			{
				type = "line";
				width = 4.0;
				points[] = {{"Center4",{0,-0.0147436},1},{"Center4",{0.0075,-0.0127679},1},{"Center4",{0.01299,-0.00737179},1},{"Center4",{0.015,0},1},{"Center4",{0.01299,0.00737179},1},{"Center4",{0.0075,0.0127679},1},{"Center4",{0,0.0147436},1},{"Center4",{-0.0075,0.0127679},1},{"Center4",{-0.01299,0.00737179},1},{"Center4",{-0.015,0},1},{"Center4",{-0.01299,-0.00737179},1},{"Center4",{-0.0075,-0.0127679},1},{"Center4",{0,-0.0147436},1},{},{"Center4",{0.0106066,-0.0104253},1},{"Center4",{0.0212132,-0.0208506},1},{},{"Center4",{0.0106066,0.0104253},1},{"Center4",{0.0212132,0.0208506},1},{},{"Center4",{-0.0106066,0.0104253},1},{"Center4",{-0.0212132,0.0208506},1},{},{"Center4",{-0.0106066,-0.0104253},1},{"Center4",{-0.0212132,-0.0208506},1},{}};
			};
		};
	};
	class Selected: Default
	{
		condition = "(PylonSelected +  PylonAmmo/2)/2";
		alpha = 1;
		class Missile1: Missile1
		{
			class Shape: Shape{};
			class Background
			{
				type = "polygon";
				points[] = {{{"Center",1,{0,0},1},{"Center",{0.0106066,-0.0104253},1},{"Center",{0.015,6.44463e-10},1},{"Center",{0.0106066,0.0104253},1}},{{"Center",1,{0,0},1},{"Center",{0.0106066,0.0104253},1},{"Center",{-1.31134e-09,0.0147436},1},{"Center",{-0.0106066,0.0104253},1}},{{"Center",1,{0,0},1},{"Center",{-0.0106066,0.0104253},1},{"Center",{-0.015,-1.75816e-10},1},{"Center",{-0.0106066,-0.0104253},1}},{{"Center",1,{0,0},1},{"Center",{-0.0106066,-0.0104253},1},{"Center",{2.62268e-09,-0.0147436},1},{"Center",{0.0106066,-0.0104253},1}}};
			};
		};
		class Missile2: Missile2
		{
			class Shape: Shape{};
			class Background
			{
				type = "polygon";
				points[] = {{{"Center2",1,{0,0},1},{"Center2",{0.0106066,-0.0104253},1},{"Center2",{0.015,6.44463e-10},1},{"Center2",{0.0106066,0.0104253},1}},{{"Center2",1,{0,0},1},{"Center2",{0.0106066,0.0104253},1},{"Center2",{-1.31134e-09,0.0147436},1},{"Center2",{-0.0106066,0.0104253},1}},{{"Center2",1,{0,0},1},{"Center2",{-0.0106066,0.0104253},1},{"Center2",{-0.015,-1.75816e-10},1},{"Center2",{-0.0106066,-0.0104253},1}},{{"Center2",1,{0,0},1},{"Center2",{-0.0106066,-0.0104253},1},{"Center2",{2.62268e-09,-0.0147436},1},{"Center2",{0.0106066,-0.0104253},1}}};
			};
		};
		class Missile3: Missile3
		{
			class Shape: Shape{};
			class Background
			{
				type = "polygon";
				points[] = {{{"Center3",1,{0,0},1},{"Center3",{0.0106066,-0.0104253},1},{"Center3",{0.015,6.44463e-10},1},{"Center3",{0.0106066,0.0104253},1}},{{"Center3",1,{0,0},1},{"Center3",{0.0106066,0.0104253},1},{"Center3",{-1.31134e-09,0.0147436},1},{"Center3",{-0.0106066,0.0104253},1}},{{"Center3",1,{0,0},1},{"Center3",{-0.0106066,0.0104253},1},{"Center3",{-0.015,-1.75816e-10},1},{"Center3",{-0.0106066,-0.0104253},1}},{{"Center3",1,{0,0},1},{"Center3",{-0.0106066,-0.0104253},1},{"Center3",{2.62268e-09,-0.0147436},1},{"Center3",{0.0106066,-0.0104253},1}}};
			};
		};
		class Missile4: Missile4
		{
			class Shape: Shape{};
			class Background
			{
				type = "polygon";
				points[] = {{{"Center4",1,{0,0},1},{"Center4",{0.0106066,-0.0104253},1},{"Center4",{0.015,6.44463e-10},1},{"Center4",{0.0106066,0.0104253},1}},{{"Center4",1,{0,0},1},{"Center4",{0.0106066,0.0104253},1},{"Center4",{-1.31134e-09,0.0147436},1},{"Center4",{-0.0106066,0.0104253},1}},{{"Center4",1,{0,0},1},{"Center4",{-0.0106066,0.0104253},1},{"Center4",{-0.015,-1.75816e-10},1},{"Center4",{-0.0106066,-0.0104253},1}},{{"Center4",1,{0,0},1},{"Center4",{-0.0106066,-0.0104253},1},{"Center4",{2.62268e-09,-0.0147436},1},{"Center4",{0.0106066,-0.0104253},1}}};
			};
		};
	};
	class HalfEmpty: Selected
	{
		alpha = 0.15;
		condition = "PylonAmmoRelative <= 1";
		color[] = {1,1,1,1.0};
		class Missile1: Missile1
		{
			condition = "PylonAmmo<=4";
			class Shape: Shape{};
			class Background: Background{};
		};
		class Missile2: Missile2
		{
			condition = "PylonAmmo<=3";
			class Shape: Shape{};
			class Background: Background{};
		};
		class Missile3: Missile3
		{
			condition = "PylonAmmo<=2";
			class Shape: Shape{};
			class Background: Background{};
		};
		class Missile4: Missile4
		{
			condition = "PylonAmmo<=1";
			class Shape: Shape{};
			class Background: Background{};
		};
	};
	class Empty: HalfEmpty
	{
		condition = "PylonAmmoRelative <= 0";
	};
};