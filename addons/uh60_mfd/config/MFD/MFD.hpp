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
	#include "pages\flir\bones.hpp"
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
	class flir {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_FLIR);
		#include "pages\flir\base.hpp"
	}; // flir
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
	class grid {
		#include "pages\grid_draw.hpp"
	};
	#include "pages\warning_overlay.hpp"
}; // Draw
