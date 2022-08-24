class backgroundWrapper {
color[] = common_black;
	class polygon {
		type        = "polygon";
		points[] ={
			{
				{{0, 0},1},
				{{1, 0},1},
				{{1, 1},1},
				{{0, 1},1}
			}
		};
	};
	class text {
		BOXEDTEXT(DEPL1,BEZEL_XT1,0.07-0.02,0.1,0.04,"DEPLOY","1")
		BOXEDTEXT(DEPL2,BEZEL_XT1,0.07+0.02,0.1,0.04,"FLIR","1")
		BOXEDTEXT(TEXT_TAPE,0.5,0.5,0.5,0.04,"FLIR STOWED","1")
	};
}; // backgroundWrapper