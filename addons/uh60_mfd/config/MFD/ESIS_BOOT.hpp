topLeft="ESIS_LH";
topRight="ESIS_RH";
bottomLeft="ESIS_LD";
borderLeft=0.0;
borderRight=0.0;
borderTop=-0.0;
borderBottom=0.0;
color[]= common_black;
enableParallax=0;
class material
{
	ambient[] = {1, 1, 1, 1};
	diffuse[] = {0.5, 0.5, 0.5, 1};
	emissive[] = {100, 100, 100, 1};
};
class Bones
{
	class Middle{
		type="fixed";
		pos[]={0.5,"0.5"};
	};
};//bones
class Draw {
	color[] = common_black;
	class gray {
		condition = "user49 > 65";
		class backgroundPolygon {
			color[] = {0.5,0.5,0.5,1};
			class polygon { // polygon
				type  = "polygon";
				points[] ={
					{
						{{0, 0},1},
						{{1, 0},1},
						{{1, 1},1},
						{{0, 1},1}
					}
				}; // POINTS
			}; // polygon
		}; // backgroundPolygon
	}; // gray
	class acinfo {
		condition = "(user49 > 50) * (user49 < 65)";
		class backgroundPolygon {
			color[] = common_white;
			class polygon { // polygon
				type  = "polygon";
				points[] ={
					{
						{{0, 0},1},
						{{1, 0},1},
						{{1, 1},1},
						{{0, 1},1}
					}
				}; // POINTS
			}; // polygon
		}; // backgroundPolygon
		class black {
			color[] = common_black;
			TEXT_MID_SCALED(BFGR,0.45,0.05,"PRHatchet",0.13)
			TEXT_MID_SCALED(Avionics,0.45,0.15,"Avionics Systems Inc.",0.13)
			
			TEXT_LEFT_SCALED(Aircraft,0.1,0.3,"Aircraft:",0.09)
			TEXT_LEFT_SCALED(SerialNum,0.15,0.38,"UH60M 1921 031",0.09)
			
			TEXT_LEFT_SCALED(ElapsedTime,0.1,0.5,"Elapsed Time 1337.0 hrs",0.09)
			
			TEXT_MID_SCALED(Copyright,0.42,0.7-0.05,"Software Copyright © 2021",0.09)
			TEXT_MID_SCALED(last1,0.4,0.78-0.05,"123-245-764 234-678-234",0.09)
			TEXT_MID_SCALED(last2,0.4,0.86-0.05,"534-687-390 234-456-789",0.09)
		};
	}; // acinfo
	class align {
		condition = "(user49 > 0) * (user49 < 50)";
		class backgroundPolygon {
			color[] = RGBA256(0,6,50,1);
			class polygon { // polygon
				type        = "polygon";
				points[] ={
					{
						{{0, 0},1},
						{{1, 0},1},
						{{1, 1},1},
						{{0, 1},1}
					}
				}; // POINTS
			}; // polygon
		}; // backgroundPolygon
		class white {
			color[] = common_white;
			TEXT_MID_SCALED(ALIGN_PROG,0.45,0.6,"ALIGNMENT IN PROGRESS",0.1);
			TEXT_MID_SCALED_SRC(ALIGN_PROG_NUM,0.5,0.7,0.1)
				source = "user";
				sourceIndex = 49;
				sourceScale = 1;
				text = "";
			};
			class P1 {
				type        = "polygon";
				points[] ={{{{0.22, 0.480},1},{{0.30, 0.480},1},{{0.30, 0.52},1},{{0.22, 0.52},1}}};
			};//P1
			class P2 {
				type        = "polygon";
				points[] ={{{{0.31, 0.480},1},{{0.415, 0.480},1},{{0.415, 0.52},1},{{0.31, 0.52},1}}};
			};//P2
			class P3 {
				type        = "polygon";
				points[] ={{{{0.375, 0.480},1},{{0.415, 0.480},1},{{0.415, 0.56},1},{{0.375, 0.56},1}}};
			};//P3
			class P4 {
				type        = "polygon";
				points[] ={{{{0.78, 0.480},1},{{0.7, 0.480},1},{{0.7, 0.52},1},{{0.78, 0.52},1}}};
			};//P4
			class P5 {
				type        = "polygon";
				points[] ={{{{0.69, 0.480},1},{{0.585, 0.480},1},{{0.585, 0.52},1},{{0.69, 0.52},1}}};
			};//P5
			class P6 {
				type        = "polygon";
				points[] ={{{{0.625, 0.480},1},{{0.585, 0.480},1},{{0.585, 0.56},1},{{0.625, 0.56},1}}};
			};//P6
			class Bank_Marks{
				type="line";
				width=8;
				points[]={
					{"Middle", {0.306418, -0.257115},1},//40
					{"Middle", {0.260455, -0.218548},1},{},
					{"Middle", {0.257115, -0.306418},1},//50
					{"Middle", {0.218548, -0.260455},1},{},
					{"Middle", {0.200000, -0.346410},1},//60
					{"Middle", {0.170000, -0.294449},1},{},
					{"Middle", {0.136808, -0.375877},1},//70
					{"Middle", {0.116287, -0.319495},1},{},
					{"Middle", {0.069459, -0.393923},1},//80
					{"Middle", {0.059040, -0.334835},1},{},
					{"Middle", {0.000000, -0.400000},1},//90
					{"Middle", {0.000000, -0.340000},1},{},
					{"Middle", {-0.069459, -0.393923},1},//100
					{"Middle", {-0.059040, -0.334835},1},{},
					{"Middle", {-0.136808, -0.375877},1},//110
					{"Middle", {-0.116287, -0.319495},1},{},
					{"Middle", {-0.200000, -0.346410},1},//120
					{"Middle", {-0.170000, -0.294449},1},{},
					{"Middle", {-0.257115, -0.306418},1},//130
					{"Middle", {-0.218548, -0.260455},1},{},
					{"Middle", {-0.306418, -0.257115},1},//140
					{"Middle", {-0.260455, -0.218548},1},{},
				}; // points
			}; // Bank_Marks
		}; // white
		class black {
			color[] = common_black;
			class P1 {
				type        = "polygon";
				points[] ={{{{0.23, 0.49},1},{{0.29, 0.49},1},{{0.29, 0.51},1},{{0.23, 0.51},1}}};
			};//P1
			class P2 {
				type        = "polygon";
				points[] ={{{{0.32, 0.49},1},{{0.405, 0.490},1},{{0.405, 0.51},1},{{0.32, 0.51},1}}};
			};//P2
			class P3 {
				type        = "polygon";
				points[] ={{{{0.385, 0.490},1},{{0.405, 0.490},1},{{0.405, 0.55},1},{{0.385, 0.55},1}}};
			};//P3
			class P4 {
				type        = "polygon";
				points[] ={{{{0.77, 0.49},1},{{0.71, 0.49},1},{{0.71, 0.51},1},{{0.77, 0.51},1}}};
			};//P4
			class P5 {
				type        = "polygon";
				points[] ={{{{0.68, 0.49},1},{{0.595, 0.490},1},{{0.595, 0.51},1},{{0.68, 0.51},1}}};
			};//P5
			class P6 {
				type        = "polygon";
				points[] ={{{{0.615, 0.490},1},{{0.595, 0.490},1},{{0.595, 0.55},1},{{0.615, 0.55},1}}};
			};//P6
		}; // black
		class red {
			color[] = {1,0,0,1};
			TEXT_MID_SCALED(ATT,0.5,0.2,"ATT",0.15);
			TEXT_MID_SCALED(FAIL,0.5,0.3,"FAIL",0.15);
		}; // red
	}; // align
}; // Draw
