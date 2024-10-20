class plane_background {
	color[] =  common_black;
	class plane {
		type="line";
		width = 8;
		points[] ={
			{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, {-0.02, -0.00+0}, 1},
			{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, { 0.02, -0.00+0}, 1},{},
			{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, {0,     -0.00+-0.01}, 1},
			{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, {0,     -0.00+0.035}, 1},{},
			{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, {0.01,  -0.00+0.03}, 1},
			{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, {-0.01,  -0.00+0.03}, 1}
		};
	};
	class white {
		color[] =  common_white;
		class plane {
			type="line";
			width = 4;
			points[] ={
				{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, {-0.02, -0.00+0}, 1},
				{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, { 0.02, -0.00+0}, 1},{},
				{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, {0,     -0.00+-0.01}, 1},
				{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, {0,     -0.00+0.035}, 1},{},
				{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, {0.01,  -0.00+0.03}, 1},
				{"TAC_SELF_DIST", 1, "TAC_SELF_DIR", 1, {-0.01,  -0.00+0.03}, 1}
			};
		};
	};
};

class north_background {
	condition = TAC_SELF_ORIENT;
	color[] =  common_black;
	class white {
		color[] =  common_white;
		class arrow {
			type="line";
			width = 4;
			points[] ={
				{"TAC_North", {0,-0.05}, 1},
				{"TAC_North", {0, 0.05}, 1},{}
			};
		};
		class poly {
			type="polygon";
			points[] ={
				{
					{"TAC_North", {-0.001, 0.06},1},
					{"TAC_North", {00.01, 0.035},1},
					{"TAC_North", {-0.01, 0.035},1}
				}
			};
		};
		class black {
			color[] = common_black;
			class poly {
				type="polygon";
				points[] ={
					{
						{"TAC_North", {-0.015*3/4, 0.015},1},
						{"TAC_North", { 0.015*3/4, 0.015},1},
						{"TAC_North", { 0.015*3/4,-0.015},1},
						{"TAC_North", {-0.015*3/4,-0.015},1}
					}
				};
			};
			class white {
				color[] = common_white;
				TEXT_LEFT_SCALED(N_text,BEZEL_XB2-0.005,BEZEL_Y5-0.02+0.1,"N",TAC_LINE_HEIGHT)
			};
		};
	};
};