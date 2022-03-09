alpha = 0.65;
class backgroundWrapper {
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

TEXT_MID_SCALED(CCFS_TITLE1,0.45,0.10,"After years of asking for an updated model with UES exhausts",0.045)
TEXT_MID_SCALED(CCFS_TITLE2,0.45,0.15,"We, as a team, have decided to make a pong game",0.045)
TEXT_MID_SCALED(CCFS_TITLE3,0.45,0.20,"That can be played by aircrew on the MFDs of the H-60",0.045)
TEXT_MID_SCALED(CCFS_TITLE4,0.45,0.92,"WARNING: WHILE PLAYING, NO WPTS WILL BE RENDERED ON YOUR MAP",0.04)

TEXT_MID_SCALED(THANKS1,0.45,0.76,"Thank you for your continued support and enthusiasm",0.04)
TEXT_MID_SCALED(THANKS3,0.47,0.80,"The Hatchet team",0.04)

TEXT_MID_SCALED(HOST,0.06,0.32,"Host game",0.05)
//TEXT_MID_SCALED(JOIN,0.06,0.46,"Join game",0.05)


#define JOIN_BOX_OFFSET -0.135

TEXT_MID_SCALED(JOIN,0.06,0.86+JOIN_BOX_OFFSET,"Join game",0.05)

class upArrow {
	type        = "polygon";
	points[] ={
		{
			{{0.01, 0.62+0.02+JOIN_BOX_OFFSET},1},
			{{0.03, 0.62-0.02+JOIN_BOX_OFFSET},1},
			{{0.05, 0.62+0.02+JOIN_BOX_OFFSET},1}
		}
	};
};
class downArrow {
	type        = "polygon";
	points[] ={
		{
			{{0.01, 0.76-0.02+JOIN_BOX_OFFSET},1},
			{{0.03, 0.76+0.02+JOIN_BOX_OFFSET},1},
			{{0.05, 0.76-0.02+JOIN_BOX_OFFSET},1}
		}
	};
};

TEXT_LEFT_SCALED(ROOMLBL,0.01,0.66+JOIN_BOX_OFFSET,"Room",0.05)
TEXT_LEFT_SCALED(ROOMNUM,0.08,0.66+JOIN_BOX_OFFSET,"1",0.05)

class host_box {
  type="line";
  width = 3;
  lineType = 2;
  points[] ={
    {{0.0, 0.32-0.02},1},
    {{0.2, 0.32-0.02},1},
    {{0.2, 0.37+0.02},1},
    {{0.0, 0.37+0.02},1}
  };
}; // HEADER_BARS

class join_box {
  type="line";
  width = 3;
  lineType = 2;
  points[] ={
    {{0.0, 0.55+JOIN_BOX_OFFSET},1},
    {{0.2, 0.55+JOIN_BOX_OFFSET},1},
    {{0.2, 0.92+JOIN_BOX_OFFSET},1},
    {{0.0, 0.92+JOIN_BOX_OFFSET},1}
  };
}; // HEADER_BARS

class credits_box {
  type="line";
  width = 3;
  lineType = 2;
  points[] ={
    {{0.65+0.05+0.05, 0.30},1},
    {{0.95-0.05+0.05, 0.30},1},
    {{0.95-0.05+0.05, 0.75},1},
    {{0.65+0.05+0.05, 0.75},1},
    {{0.65+0.05+0.05, 0.30},1}
  };
}; // HEADER_BARS

#define CREDITS_LINE_HEIGHT 0.05
TEXT_MID_SCALED(CREDITS00,0.8+0.05,0.32+(CREDITS_LINE_HEIGHT*00),"Yax",0.05)
TEXT_MID_SCALED(CREDITS01,0.8+0.05,0.32+(CREDITS_LINE_HEIGHT*01),"RiverX",0.05)
TEXT_MID_SCALED(CREDITS02,0.8+0.05,0.32+(CREDITS_LINE_HEIGHT*02),"Ampersand",0.05)
TEXT_MID_SCALED(CREDITS03,0.8+0.05,0.32+(CREDITS_LINE_HEIGHT*03),"A26Mike",0.05)
TEXT_MID_SCALED(CREDITS04,0.8+0.05,0.32+(CREDITS_LINE_HEIGHT*04),"Riverman",0.05)
TEXT_MID_SCALED(CREDITS05,0.8+0.05,0.32+(CREDITS_LINE_HEIGHT*05),"Fat_Lurch",0.05)
TEXT_MID_SCALED(CREDITS06,0.8+0.05,0.32+(CREDITS_LINE_HEIGHT*06),"Lost",0.05)
TEXT_MID_SCALED(CREDITS07,0.8+0.05,0.32+(CREDITS_LINE_HEIGHT*07),"Seven10",0.05)

#define BOTTOM_TEXT_Y 0.96
TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

TEXT_LEFT_SMALL(B5,0.65,BOTTOM_TEXT_Y,"DCP")
TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"FLIR")
TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")