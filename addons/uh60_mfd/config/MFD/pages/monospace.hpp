borderLeft=0;
borderRight=0;
borderTop=0;
borderBottom=0;
color[]=common_white;
enableParallax=0;
font="EtelkaMonospacePro";

class material {
	ambient[] = {1, 1, 1, 1};
	diffuse[] = {0.5, 0.5, 0.5, 1};
	emissive[] = {100, 100, 100, 1};
};

class Bones {
};

class Draw {
	class JVMF {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_JVMF);
		TEXT_LEFT_SCALED_USERTEXT(freetext01,0.13,0.21+(JVMF_LINE_SCALING*0),31,0.04)
		TEXT_LEFT_SCALED_USERTEXT(freetext02,0.13,0.21+(JVMF_LINE_SCALING*1),32,0.04)
		TEXT_LEFT_SCALED_USERTEXT(freetext03,0.13,0.21+(JVMF_LINE_SCALING*2),33,0.04)
		TEXT_LEFT_SCALED_USERTEXT(freetext04,0.13,0.21+(JVMF_LINE_SCALING*3),34,0.04)
		TEXT_LEFT_SCALED_USERTEXT(freetext05,0.13,0.21+(JVMF_LINE_SCALING*4),35,0.04)
		TEXT_LEFT_SCALED_USERTEXT(freetext06,0.13,0.21+(JVMF_LINE_SCALING*5),36,0.04)
		TEXT_LEFT_SCALED_USERTEXT(freetext07,0.13,0.21+(JVMF_LINE_SCALING*6),37,0.04)
		TEXT_LEFT_SCALED_USERTEXT(freetext08,0.13,0.21+(JVMF_LINE_SCALING*7),38,0.04)
		class jvmf_type_0 {
			condition=COND_ISNUMBER(JVMF_TYPE,0);
			//condition="1";
			// TEXT_LEFT_SCALED_USERTEXT(freetext00,0.65,0.2-(JVMF_LINE_SCALING*1),"SENDR01",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext01,0.13,0.2+(JVMF_LINE_SCALING*0)," > ? FRTXT SENDR01 2300      This is an example message",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext02,0.13,0.2+(JVMF_LINE_SCALING*1),"123456789-123456789-1234     123456789-123456789-12345678",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext03,0.13,0.2+(JVMF_LINE_SCALING*2),"> POSRPT SENDR     12:00    123456789-123456789-12345678",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext04,0.13,0.2+(JVMF_LINE_SCALING*3),"XXXXXXXXX-XXXXXXXXX-XXXX     123456789-123456789-12345678",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext05,0.13,0.2+(JVMF_LINE_SCALING*4),"XXXXXXXXX-XXXXXXXXX-XXXX     123456789-123456789-12345678",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext06,0.13,0.2+(JVMF_LINE_SCALING*5),"XXXXXXXXX-XXXXXXXXX-XXXX     123456789-123456789-12345678",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext07,0.13,0.2+(JVMF_LINE_SCALING*6),"XXXXXXXXX-XXXXXXXXX-XXXX     123456789-123456789-12345678",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext08,0.13,0.2+(JVMF_LINE_SCALING*7),"XXXXXXXXX-XXXXXXXXX-XXXX     123456789-123456789-12345678",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext09,0.13,0.2+(JVMF_LINE_SCALING*8),"XXXXXXXXX-XXXXXXXXX-XXXX     123456789-123456789-12345678",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext10,0.13,0.2+(JVMF_LINE_SCALING*9),"XXXXXXXXX-XXXXXXXXX-XXXX     123456789-123456789-12345678",0.03)
			// TEXT_LEFT_SCALED_USERTEXT(freetext00,0.65,0.2-(JVMF_LINE_SCALING*1),"SENDR01",0.03)
			TEXT_LEFT_SCALED_USERTEXT(freetext09,0.13,0.21+(JVMF_LINE_SCALING*8),39,0.04)
			TEXT_LEFT_SCALED_USERTEXT(freetext10,0.13,0.21+(JVMF_LINE_SCALING*9),40,0.04)
		};
		#define JVMF_LINE_SCALING 0.04
	};
	class ivhms {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_IVHMS);
		#include "ivhms_draw.hpp"
	}; // ivhms
	class ivhms_nums {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_IVHMS_NUMS);
		#include "ivhms_nums_draw.hpp"
	}; // ivhms
	#define EICAS_LINE_SPACING 0.035
	#define EICAS_LINE_HEIGHT 0.04

	#define LX 0.05
	#define RX 0.69

	#define Y0 0.02
	#define Y1 0.45
	#define Y2 0.70
	
	#define EICAS_LINE_SPACING 0.035
	#define EICAS_LINE_HEIGHT 0.04
	#define EICAS_LINE_TEXT(CNAME,X,Y,PYLON,TEXT) \
		class CNAME { \
			class regular { \
				condition = QUOTE(PYLON > 0); \
				color[] = common_yellow; \
				TEXT_LEFT_SCALED(Left_0_0,X,Y,TEXT,EICAS_LINE_HEIGHT) \
			}; \
		};

	#define EICAS_LINE_TEXT_USERTEXT(CNAME,X,Y,INDEX) \
		class CNAME { \
			class regular { \
				color[] = common_yellow; \
				TEXT_LEFT_SCALED_USERTEXT(Left_0_0,X,Y,INDEX,EICAS_LINE_HEIGHT) \
			}; \
		};

	class eicas {
		color[] = common_yellow;
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_EICAS);
		 EICAS_LINE_TEXT(Left_0_0,0.05,0.02+(EICAS_LINE_SPACING*0),pylonAmmo16,"GEN 1 FAIL")
		 EICAS_LINE_TEXT(Left_0_1,0.05,0.02+(EICAS_LINE_SPACING*1),pylonAmmo17,"HYD PUMP 1 FAIL")
		 EICAS_LINE_TEXT(Left_0_2,0.05,0.02+(EICAS_LINE_SPACING*2),pylonAmmo18,"")
		 EICAS_LINE_TEXT(Left_1_0,0.05,0.45+(EICAS_LINE_SPACING*0),pylonAmmo19,"CHIP ENG 1")
		 EICAS_LINE_TEXT(Left_1_1,0.05,0.45+(EICAS_LINE_SPACING*1),pylonAmmo20,"CHIP MAIN MDL SUMP")
		 EICAS_LINE_TEXT(Left_1_2,0.05,0.45+(EICAS_LINE_SPACING*2),pylonAmmo21,"MAIN XMSN PRES")
		 EICAS_LINE_TEXT(Left_1_3,0.05,0.45+(EICAS_LINE_SPACING*3),pylonAmmo22,"HULL INTEGRITY CRIT")
		 EICAS_LINE_TEXT(Left_1_4,0.05,0.45+(EICAS_LINE_SPACING*4),pylonAmmo23,"")
		 EICAS_LINE_TEXT(Left_1_5,0.05,0.45+(EICAS_LINE_SPACING*5),pylonAmmo24,"ENG 1 STARTER ON")
		EICAS_LINE_TEXT(Right_0_0,0.69,0.02+(EICAS_LINE_SPACING*0),pylonAmmo25,"GEN 2 FAIL")
		EICAS_LINE_TEXT(Right_0_1,0.69,0.02+(EICAS_LINE_SPACING*1),pylonAmmo26,"HYD PUMP 2")
		EICAS_LINE_TEXT(Right_0_2,0.69,0.02+(EICAS_LINE_SPACING*2),pylonAmmo27,"")
		EICAS_LINE_TEXT(Right_1_0,0.69,0.45+(EICAS_LINE_SPACING*0),pylonAmmo28,"CHIP ENG 2")
		EICAS_LINE_TEXT(Right_1_1,0.69,0.45+(EICAS_LINE_SPACING*1),pylonAmmo29,"T/R SERVO 1 FAIL")
		EICAS_LINE_TEXT(Right_1_2,0.69,0.45+(EICAS_LINE_SPACING*2),pylonAmmo30,"T/R QUAD FAIL")
		EICAS_LINE_TEXT(Right_1_3,0.69,0.45+(EICAS_LINE_SPACING*3),pylonAmmo31,"")
		EICAS_LINE_TEXT(Right_1_4,0.69,0.45+(EICAS_LINE_SPACING*4),pylonAmmo32,"")
		EICAS_LINE_TEXT(Right_1_5,0.69,0.45+(EICAS_LINE_SPACING*5),pylonAmmo33,"ENG 2 STARTER ON")
		EICAS_LINE_TEXT(Right_2_0,0.69,0.70+(EICAS_LINE_SPACING*0),pylonAmmo34,"STBY INST NOT ARMD")
		EICAS_LINE_TEXT(Right_2_1,0.69,0.70+(EICAS_LINE_SPACING*1),pylonAmmo35,"")
		EICAS_LINE_TEXT(Right_2_2,0.69,0.70+(EICAS_LINE_SPACING*2),pylonAmmo36,"CMWS FAIL")
		EICAS_LINE_TEXT(Right_2_3,0.69,0.70+(EICAS_LINE_SPACING*3),pylonAmmo37,"FLIR FAIL")
		EICAS_LINE_TEXT(Right_2_4,0.69,0.70+(EICAS_LINE_SPACING*4),pylonAmmo38,"MFD FAIL")
		EICAS_LINE_TEXT(Right_2_5,0.69,0.70+(EICAS_LINE_SPACING*5),pylonAmmo39,"")
	}; // eicas
	class tac {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_TAC);
		#include "cautions\monospace.hpp"
	};
	class nd {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_ND);
		#include "cautions\monospace.hpp"
	};
};