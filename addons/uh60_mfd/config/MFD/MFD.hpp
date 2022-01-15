borderLeft=0;
borderRight=0;
borderTop=0;
borderBottom=0;
color[]=common_white;
enableParallax=0;
font="RobotoCondensedLight";
class material {
	ambient[] = {1, 1, 1, 1};
	diffuse[] = {0.5, 0.5, 0.5, 1};
	emissive[] = {100, 100, 100, 1};
};
class Bones {
	#include "pages\eicas_bones.hpp"
	#include "pages\pfd_bones.hpp"
	#include "pages\tac_bones.hpp"
	#include "pages\flir_bones.hpp"
	#include "pages\nd_bones.hpp"
	#include "pages\ccfs_bones.hpp"
}; // Bones
class Draw {
	class eicas {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_EICAS);
		#include "pages\eicas_draw.hpp"
	}; // eicas
	class pfd {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_PFD);
		#include "pages\pfd_draw.hpp"
	}; // pfd
	class tac {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_TAC);
		#include "pages\tac_draw.hpp"
	}; // tac
	class jvmf {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_JVMF);
		#include "pages\jvmf_draw.hpp"
	}; // jvmf
	class flir {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_FLIR);
		#include "pages\flir_draw.hpp"
	}; // flir
	class ccfs {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_CCFS);
		#include "pages\ccfs_draw.hpp"
	}; // ccfs
	class nd {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_ND);
		#include "pages\nd_draw.hpp"
	}; // nd
	class ccfs_menu {
		condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_CCFS_MENU);
		#include "pages\ccfs_menu_draw.hpp"
	}; // nd
	#include "pages\warning_overlay.hpp"
}; // Draw
