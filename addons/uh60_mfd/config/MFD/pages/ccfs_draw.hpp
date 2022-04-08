alpha = 1;
class backgroundWrapper {
	alpha = BACKGROUND_ALPHA;
	class polygon {
		type        = "polygon";
		texture = "z\vtx\addons\uh60_mfd\data\CCFS.paa";
		points[] ={
			{
				{{0, 0},1},
				{{1, 0},1},
				{{1, 1},1},
				{{0, 1},1}
			}
		};
	};
}; // backgroundWrapper



#define CCFS_POLYGON(X,Y) \
    {X, 1, Y, 1,{0.75*-0.015, -0.015},1}, \
    {X, 1, Y, 1,{0.75*0.015, -0.015},1}, \
    {X, 1, Y, 1,{0.75*0.015, 0.015},1}, \
    {X, 1, Y, 1,{0.75*-0.015, 0.015},1}


TEXT_MID_SCALED_USERTEXT(ANNOUNCETEXT,0.5,0.05,49,0.05)
TEXT_LEFT_SMALL(MENU,0.16,0.01,"EXIT")
TEXT_LEFT_SMALL(PAUSEPLAY,0.90,0.01,"PAUSE/PLAY")

class ballColor {
	color[] = common_red;
	class ball {
		type        = "polygon";
		points[] ={
			{
				CCFS_POLYGON(BALL_X,BALL_Y)
			}
		};
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

class BORDER_LINE {
  type="line";
  width = 4;
  lineType = 0;
  points[] ={
    {{0.05, 0.1},1}, // top
    {{0.95, 0.1},1},{},
    {{0.05, 0.9},1}, // bottom
    {{0.95, 0.9},1},{},
    {{0.25, 0.1},1}, // text box
    {{0.25, 0.05},1},
    {{0.75, 0.05},1},
    {{0.75, 0.1},1}

  };
}; // HEADER_BARS_BOTTOM

#define BOTTOM_TEXT_Y 0.96
TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"IVHMS")
TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")