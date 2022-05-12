class altScale {
	#define AGL_TICK_50 (0.52/4)
	#define AGL_TICK_10 (0.52/4/5)
	class altTicks {
		type="line";
		width = 4;
		points[] ={
			//50ft marks
			{{0.92, 0.20}, 1},{{0.98, 0.20}, 1},{},
			{{0.92, 0.20+(AGL_TICK_50*1)}, 1},{{0.98, 0.20+(AGL_TICK_50*1)}, 1},{},
			{{0.92, 0.20+(AGL_TICK_50*2)}, 1},{{0.98, 0.20+(AGL_TICK_50*2)}, 1},{},
			{{0.92, 0.20+(AGL_TICK_50*3)}, 1},{{0.98, 0.20+(AGL_TICK_50*3)}, 1},{},

			//10ft marks
			{{0.92, 0.20+(AGL_TICK_50*3)+(AGL_TICK_10*1)}, 1},{{0.98, 0.20+(AGL_TICK_50*3)+(AGL_TICK_10*1)}, 1},{},
			{{0.92, 0.20+(AGL_TICK_50*3)+(AGL_TICK_10*2)}, 1},{{0.98, 0.20+(AGL_TICK_50*3)+(AGL_TICK_10*2)}, 1},{},
			{{0.92, 0.20+(AGL_TICK_50*3)+(AGL_TICK_10*3)}, 1},{{0.98, 0.20+(AGL_TICK_50*3)+(AGL_TICK_10*3)}, 1},{},
			{{0.92, 0.20+(AGL_TICK_50*3)+(AGL_TICK_10*4)}, 1},{{0.98, 0.20+(AGL_TICK_50*3)+(AGL_TICK_10*4)}, 1},{},

			{"VSIScale", {-0.02, -0.01}, 1},
			{"VSIScale", {-0.00, 0}, 1},
			{"VSIScale", {-0.02, 00.01}, 1}
		}; // points
	}; // trimLine
	class altTickBase {
		type="line";
		width = 7;
		points[] ={
			{{0.91, 0.20+(AGL_TICK_50*4)}, 1},{{0.99, 0.20+(AGL_TICK_50*4)}, 1}
		}; // points
	}; // trimLine
	class altPolygon {
		type = "polygon";
		points[] ={
			{
				{{0.94, 0.72},1},
				{{0.96, 0.72},1},
				{"AGLScaleBar", { 0.01, 0},1},
				{"AGLScaleBar", {-0.01, 0},1}
			}
		};
	};
};