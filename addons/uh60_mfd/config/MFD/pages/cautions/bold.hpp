#define EICAS_LINE_USERTEXT(CNAME,X,Y,INDEX,SHOWNUM) \
	class CNAME { \
		class inverted { \
			condition = QUOTE(pylonAmmo3 > SHOWNUM); \
			class yellow { \
				color[] = common_yellow; \
				EICAS_LINE_TAPE(TAPE,X,Y) \
			}; \
			class black { \
				color[] = common_black; \
				TEXT_LEFT_SCALED_USERTEXT(Left_0_0,X,Y,INDEX,EICAS_LINE_HEIGHT) \
			}; \
		}; \
	};

class cautions_overlay {
	color[] = common_yellow;
	condition = "pylonAmmo3 > 0";
	EICAS_LINE_USERTEXT(Right_2_0,0.69,0.70+(EICAS_LINE_SPACING*0),14,1)
	EICAS_LINE_USERTEXT(Right_2_1,0.69,0.70+(EICAS_LINE_SPACING*1),15,2)
	EICAS_LINE_USERTEXT(Right_2_2,0.69,0.70+(EICAS_LINE_SPACING*2),16,3)
	EICAS_LINE_USERTEXT(Right_2_3,0.69,0.70+(EICAS_LINE_SPACING*3),17,4)
	EICAS_LINE_USERTEXT(Right_2_4,0.69,0.70+(EICAS_LINE_SPACING*4),18,5)
	EICAS_LINE_USERTEXT(Right_2_5,0.69,0.70+(EICAS_LINE_SPACING*5),19,6)
	
	class upArrow {
		type        = "polygon";
		points[] ={
			{
				{{0.68+0.285-(0.03*0),0.70},1},
				{{0.68+0.285-(0.03*1),0.68},1},
				{{0.68+0.285-(0.03*2),0.70},1}
			}
		};
	};
	class downArrow {
		type        = "polygon";
		points[] ={
			{
				{{0.68+0.285-(0.03*0),0.92},1},
				{{0.68+0.285-(0.03*1),0.94},1},
				{{0.68+0.285-(0.03*2),0.92},1}
			}
		};
	};
	class red {
		color[] = {1,0,0,1};
		class polygon {
			type        = "polygon";
			points[] ={
				{
					{{0.68     ,0.922},1},
					{{0.68+0.05,0.922},1},
					{{0.68+0.05,0.95},1},
					{{0.68     ,0.95},1}
				}
			};
		};
		class black {
			color[] = common_black;
			TEXT_LEFT_SCALED(Text,0.682,0.915,"CAS",0.04)
		};
	};
};