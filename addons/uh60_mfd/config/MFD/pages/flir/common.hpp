class GndStab {
	condition = "pilotcameralock";
	color[] = common_black;
	COLORED_POLYGON(PB1,0.2,0.2,0.2,0.04,common_black)
	BOXEDTEXT_USER(TEXT_TAPE,0.5,0.17,0.5,0.04,10,"1")
	class white {
		color[] = common_white;
		TEXT_MID_SCALED(LRD_LASE_TXT,0.3,0.2,"GND STAB",0.04)
		class Border {
			type="line";
			width = 2;
			points[] ={
				{{0.3 - 0.10, 0.2 - 0.00},1},
				{{0.3 + 0.10, 0.2 - 0.00},1},
				{{0.3 + 0.10, 0.2 + 0.04},1},
				{{0.3 - 0.10, 0.2 + 0.04},1},
				{{0.3 - 0.10, 0.2 - 0.00},1}
			};
		}; // Border
	}; // whtie
}; // GndStab
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
class PntTrk {
	condition = "pilotcameralock>1";
	color[] = common_black;
	COLORED_POLYGON(PB1,0.6,0.2,0.2,0.04,common_black)
	class white {
		color[] = common_white;
		TEXT_MID_SCALED(LRD_LASE_TXT,0.7,0.2,"PNT TRK",0.04)
		class Border {
			type="line";
			width = 2;
			points[] ={
				{{0.7 - 0.10, 0.2 - 0.00},1},
				{{0.7 + 0.10, 0.2 - 0.00},1},
				{{0.7 + 0.10, 0.2 + 0.04},1},
				{{0.7 - 0.10, 0.2 + 0.04},1},
				{{0.7 - 0.10, 0.2 - 0.00},1}
			};
		}; // Border
	}; // whtie
}; // GndStab

class crossBackground {
	color[] = common_black;
	class TargetCross {
		type="line";
		width = 5;
		points[] ={
			{{0.5-(0.10*0.75), 0.5},1},
			{{0.5-(0.02*0.75), 0.5},1},{},
			{{0.5+(0.10*0.75), 0.5},1},
			{{0.5+(0.02*0.75), 0.5},1},{},
			{{0.5, 0.5-0.10},1},
			{{0.5, 0.5-0.02},1},{},
			{{0.5, 0.5+0.10},1},
			{{0.5, 0.5+0.02},1},{}
		};
	};
	class white {
		color[] = common_white;
		class TargetCross {
			type="line";
			width = 2;
			points[] ={
				{{0.5-(0.10*0.75), 0.5},1},
				{{0.5-(0.02*0.75), 0.5},1},{},
				{{0.5+(0.10*0.75), 0.5},1},
				{{0.5+(0.02*0.75), 0.5},1},{},
				{{0.5, 0.5-0.10},1},
				{{0.5, 0.5-0.02},1},{},
				{{0.5, 0.5+0.10},1},
				{{0.5, 0.5+0.02},1},{}
			};
		};
	};
};