class hook {
	color[] = common_black;
	COLORED_POLYGON(background,(0.5-0.15),0.99-0.12,0.3,0.12,common_black)
	class white {
		color[] = common_white;
		TEXT_MID_SCALED(L1,0.5,0.99-0.12,"4Q FJ 12345678",TAC_LINE_HEIGHT)
		TEXT_MID_SCALED(L2,0.5,0.99-0.08,"01 KM / 180°",TAC_LINE_HEIGHT)
		TEXT_MID_SCALED(L3,0.5,0.99-0.04,"1000 ft / 300 m",TAC_LINE_HEIGHT)
		class border {
            type="line";
            width = 2;
            points[] ={
                {{0.5-0.15,0.99-0.12},1},
                {{0.5+0.15,0.99-0.12},1},
                {{0.5+0.15,0.99-0.00},1},
                {{0.5-0.15,0.99-0.00},1},
                {{0.5-0.15,0.99-0.12},1}
            };
		};
	};
};