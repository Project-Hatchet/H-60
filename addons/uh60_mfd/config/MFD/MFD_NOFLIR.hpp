borderLeft=0;
borderRight=0;
borderTop=0;
borderBottom=0;
color[]=common_white;
enableParallax=0;
font="RobotoCondensedLight";
turret[] = {-2};
class material {
	ambient[] = {1, 1, 1, 1};
	diffuse[] = {0.5, 0.5, 0.5, 1};
	emissive[] = {100, 100, 100, 1};
};
class Bones {
	#include "pages\eicas_bones.hpp"
	#include "pages\pfd\bones.hpp"
	#include "pages\tac\bones.hpp"
	#include "pages\nd\bones.hpp"
	#include "pages\ccfs_bones.hpp"
}; // Bones
class Draw {
	class eicas {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_EICAS);
		#include "pages\eicas_draw.hpp"
	}; // eicas
	class pfd {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_PFD);
		#include "pages\pfd\base.hpp"
	}; // pfd
	class tac_t {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_TAC);
		#include "pages\tac\base.hpp"
	};
	class jvmf {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_JVMF);
		#include "pages\jvmf_draw.hpp"
	}; // jvmf
	class ccfs {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_CCFS);
		#include "pages\ccfs_draw.hpp"
	}; // ccfs
	class nd {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_ND);
		#include "pages\nd\base.hpp"
	}; // nd
	class ccfs_menu {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_CCFS_MENU);
		#include "pages\ccfs_menu_draw.hpp"
	}; // nd
	class damage {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_DAMAGED);
		#include "pages\damage\base.hpp"
	}; // nd
	// class grid {
	// 	#include "pages\grid_draw.hpp"
	// };
	class alwaysShow {
		TEXT_LEFT_SCALED(B1,(BEZEL_XB1-0.02+0.005),BOTTOM_TEXT_Y,"PFD",TAC_LINE_HEIGHT)
		TEXT_LEFT_SCALED(B2,(BEZEL_XB2-0.015+0.005),BOTTOM_TEXT_Y,"ND",TAC_LINE_HEIGHT)
		TEXT_LEFT_SCALED(B3,(BEZEL_XB3-0.03+0.005),BOTTOM_TEXT_Y,"EICAS",TAC_LINE_HEIGHT)
		// TEXT_LEFT_SCALED(B6,(BEZEL_XB4-0.025+0.005),BOTTOM_TEXT_Y,"FLIR",TAC_LINE_HEIGHT)
		TEXT_LEFT_SCALED(B7,(BEZEL_XB5-0.02+0.005),BOTTOM_TEXT_Y,"TAC",TAC_LINE_HEIGHT)
		TEXT_LEFT_SCALED(B8,(BEZEL_XB6-0.03+0.005),BOTTOM_TEXT_Y,"JVMF",TAC_LINE_HEIGHT)
	};
	#include "pages\warning_overlay.hpp"
}; // Draw
