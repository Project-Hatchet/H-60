#define LOBL_BOX_SIZE 0.05

class LOBL_Good {
	condition = COND_ISNUMPYLON(40,0);
	class Box {
		type="line";
		width = 2;
		points[] ={
			{"FLIR_HELLFIRE_REF", {-LOBL_BOX_SIZE*(3/4), 0-LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", {-LOBL_BOX_SIZE*(3/4), 0+LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", { LOBL_BOX_SIZE*(3/4), 0+LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", { LOBL_BOX_SIZE*(3/4), 0-LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", {-LOBL_BOX_SIZE*(3/4), 0-LOBL_BOX_SIZE},1}
		};
	}; // Box
}; // LOAL

class LOBL_Bad {
	condition = COND_ISNUMPYLON(40,1);
	class Box {
		type="line";
		width = 2;
		lineType = 1;
		points[] ={
			{"FLIR_HELLFIRE_REF", {-LOBL_BOX_SIZE*(3/4), 0-LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", {-LOBL_BOX_SIZE*(3/4), 0+LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", { LOBL_BOX_SIZE*(3/4), 0+LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", { LOBL_BOX_SIZE*(3/4), 0-LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", {-LOBL_BOX_SIZE*(3/4), 0-LOBL_BOX_SIZE},1}
		};
	}; // Box
}; // LOAL

class LOBL_Limits {
	condition = COND_ISNUMPYLON(40,2);
	class Box {
		type="line";
		width = 2;
		lineType = 1;
		points[] ={
			{"FLIR_HELLFIRE_REF", {-LOBL_BOX_SIZE*(3/4), 0-LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", {-LOBL_BOX_SIZE*(3/4), 0+LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", { LOBL_BOX_SIZE*(3/4), 0+LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", { LOBL_BOX_SIZE*(3/4), 0-LOBL_BOX_SIZE},1},
			{"FLIR_HELLFIRE_REF", {-LOBL_BOX_SIZE*(3/4), 0-LOBL_BOX_SIZE},1}
		};
	}; // Box
	BOXEDTEXT(LSR,0.7,0.7,0.1,0.04,"LIMITS")
}; // LOAL

class LOAL_Good {
	condition = COND_ISNUMPYLON(40,3);
	class Box {
		type="line";
		width = 2;
		lineType = 0;
		points[] ={
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1},
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0+0.025},1},
			{"FLIR_HELLFIRE_REF", {00.025*(3/4), 0+0.025},1},
			{"FLIR_HELLFIRE_REF", {00.025*(3/4), 0-0.025},1},
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1}
		};
	}; // Box
}; // LOAL

class LOAL_Bad {
	condition = COND_ISNUMPYLON(40,4);
	class Box {
		type="line";
		width = 2;
		lineType = 1;
		points[] ={
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1},
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0+0.025},1},
			{"FLIR_HELLFIRE_REF", {00.025*(3/4), 0+0.025},1},
			{"FLIR_HELLFIRE_REF", {00.025*(3/4), 0-0.025},1},
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1}
		};
	}; // Box
}; // LOAL

class LOAL_Limits {
	condition = COND_ISNUMPYLON(40,5);
	class Box {
		type="line";
		width = 2;
		lineType = 1;
		points[] ={
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1},
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0+0.025},1},
			{"FLIR_HELLFIRE_REF", {00.025*(3/4), 0+0.025},1},
			{"FLIR_HELLFIRE_REF", {00.025*(3/4), 0-0.025},1},
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1}
		};
	}; // Box
	BOXEDTEXT(LSR,0.7,0.7,0.1,0.04,"LIMITS")
}; // LOAL


class NOT_RDY {
	condition = COND_ISNUMPYLON(40,6);
	class Box {
		type="line";
		width = 2;
		lineType = 1;
		points[] ={
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1},
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0+0.025},1},
			{"FLIR_HELLFIRE_REF", {00.025*(3/4), 0+0.025},1},
			{"FLIR_HELLFIRE_REF", {00.025*(3/4), 0-0.025},1},
			{"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1}
		};
	}; // Box
	BOXEDTEXT(LSR,0.7,0.7,0.2,0.04,"MSL NOT RDY")
}; // LOAL