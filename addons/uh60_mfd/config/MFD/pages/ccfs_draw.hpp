
#define CCFS_POLYGON(X,Y) \
    {X, 1, Y, 1,{0.75*-0.015, -0.015},1}, \
    {X, 1, Y, 1,{0.75*0.015, -0.015},1}, \
    {X, 1, Y, 1,{0.75*0.015, 0.015},1}, \
    {X, 1, Y, 1,{0.75*-0.015, 0.015},1}



class ball {
	type        = "polygon";
	points[] ={
		{
			CCFS_POLYGON(BALL_X,BALL_Y)
		}
	};
};

class LEFT {
	type        = "polygon";
	points[] ={
		{
			{"LEFT_POS", {-0.01,-0.08},1},
			{"LEFT_POS", { 0.01,-0.08},1},
			{"LEFT_POS", { 0.01, 0.08},1},
			{"LEFT_POS", {-0.01, 0.08},1}
		}
	};
}; // textBackground


class RIGHT {
	type        = "polygon";
	points[] ={
		{
			{"RIGHT_POS", {-0.01,-0.08},1},
			{"RIGHT_POS", { 0.01,-0.08},1},
			{"RIGHT_POS", { 0.01, 0.08},1},
			{"RIGHT_POS", {-0.01, 0.08},1}
		}
	};
}; // textBackground

class MID_LINE {
  type="line";
  width = 3;
  lineType = 2;
  points[] ={
    {{0.5, 0.1},1},
    {{0.5, 0.9},1}
  };
}; // HEADER_BARS_BOTTOM