class cursor_background {
	condition = COND_ISNUMPYLON(7,1);
	color[] = common_black;
	class cursor
	{
		type = "line";
		width = 8;
		points[]={
				{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,-0.03)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,-0.005)},1},{},
				{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,0.03)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,0.005)},1},{},
				{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(-0.03,0)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(-0.005,0)},1},{},
				{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0.03,0)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0.005,0)},1},{}
		};
	}; // cursor
	class cursor_purple {
		color[] = common_purple;
		class cursor
		{
			type = "line";
			width = 4;
			points[]={
				{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,-0.03)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,-0.005)},1},{},
				{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,0.03)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,0.005)},1},{},
				{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(-0.03,0)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(-0.005,0)},1},{},
				{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0.03,0)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0.005,0)},1},{}
			};
		}; // cursor
	}; // purple
}; // black

#define HOOKED_SCALE 0.03
#define HOOKED_PT(X,Y) {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(X*HOOKED_SCALE,Y*HOOKED_SCALE)},1}

class cursor_background_selected {
	condition = COND_ISNUMPYLON(7,2);
	color[] = common_black;
	class cursor
	{
		type = "line";
		width = 8;
		points[]={
			HOOKED_PT(-1,-0.5),HOOKED_PT(-1,-1),HOOKED_PT(-0.5,-1),{},
			HOOKED_PT(1,-0.5),HOOKED_PT(1,-1),HOOKED_PT(0.5,-1),{},
			HOOKED_PT(1,0.5),HOOKED_PT(1,1),HOOKED_PT(0.5,1),{},
			HOOKED_PT(-1,0.5),HOOKED_PT(-1,1),HOOKED_PT(-0.5,1),{}
				// {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,-0.03)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,-0.005)},1},{},
				// {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,0.03)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0,0.005)},1},{},
				// {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(-0.03,0)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(-0.005,0)},1},{},
				// {"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0.03,0)},1},{"TAC_CURSOR_X", 1, "TAC_CURSOR_Y", 1, {PT34(0.005,0)},1},{}
		};
	}; // cursor
	class cursor_purple {
		color[] = common_green;
		class cursor
		{
			type = "line";
			width = 4;
			points[]={
				HOOKED_PT(-1,-0.5),HOOKED_PT(-1,-1),HOOKED_PT(-0.5,-1),{},
				HOOKED_PT(1,-0.5),HOOKED_PT(1,-1),HOOKED_PT(0.5,-1),{},
				HOOKED_PT(1,0.5),HOOKED_PT(1,1),HOOKED_PT(0.5,1),{},
				HOOKED_PT(-1,0.5),HOOKED_PT(-1,1),HOOKED_PT(-0.5,1),{}
			};
		}; // cursor
	}; // purple
}; // black

class context_menu {
	condition = "(user39>-1)";
	color[] = common_black;
	class backgroundPoly {
		type        = "polygon";
		points[] ={
			{
				{{0+0.4, 0+0.25},1},
				{{1-0.4, 0+0.25},1},
				{{1-0.4, 1-0.51},1},
				{{0+0.4, 1-0.51},1}
			}
		};
	};
	class white {
		color[] = common_white;
		class BackgroundBorder {
			type  = "line";
			width = 2;
			points[] ={
				{{0+0.4, 0+0.25},1},
				{{1-0.4, 0+0.25},1},
				{{1-0.4, 1-0.51},1},
				{{0+0.4, 1-0.51},1},
				{{0+0.4, 0+0.25},1}
			};
		}; // BackgroundBorder
		class text {
			condition = "(user39>-1)";
			#define INTERACT_LINE_HEIGHT 0.04
			TEXT_LEFT_SCALED(SEL1,0.41,0.25+(INTERACT_LINE_HEIGHT*0),"CREATE WAYPT",INTERACT_LINE_HEIGHT)
			TEXT_LEFT_SCALED(SEL2,0.41,0.25+(INTERACT_LINE_HEIGHT*1),"SLEW FLIR",INTERACT_LINE_HEIGHT)
			TEXT_LEFT_SCALED(SEL3,0.41,0.25+(INTERACT_LINE_HEIGHT*2),"ZOOM IN",INTERACT_LINE_HEIGHT)
			TEXT_LEFT_SCALED(SEL4,0.41,0.25+(INTERACT_LINE_HEIGHT*3),"ZOOM OUT",INTERACT_LINE_HEIGHT)
			TEXT_LEFT_SCALED(SEL5,0.41,0.25+(INTERACT_LINE_HEIGHT*4),"CTR MODE",INTERACT_LINE_HEIGHT)
			TEXT_LEFT_SCALED(SEL6,0.41,0.25+(INTERACT_LINE_HEIGHT*5),"EXIT",INTERACT_LINE_HEIGHT)
		}; // text
	}; // white
};