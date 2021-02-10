borderLeft=0;
borderRight=0;
borderTop=0;
borderBottom=0;
color[]=common_green;
enableParallax=0;
font="RobotoCondensedLight";
class material {
	ambient[] = {1, 1, 1, 1};
	diffuse[] = {0.5, 0.5, 0.5, 1};
	emissive[] = {100, 100, 100, 1};
};
class Bones {

}; // Bones
class Draw {
	#include "fms\header_draw.hpp"
	class menu {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_MENU);
		#include "fms\menu_draw.hpp"
	}; // menu
	class checklists {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_LISTS_MENU);
		#include "fms\checklists_draw.hpp"
	}; // checklists
	class checklists_start_1 {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_LISTS_STARTUP_1);
		#include "fms\checklists_start_1_draw.hpp"
	}; // checklists_startup_1
	class checklists_start_2 {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_LISTS_STARTUP_2);
		#include "fms\checklists_start_2_draw.hpp"
	}; // checklists_startup_2
	class checklists_STOP_1 {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_1);
		#include "fms\checklists_STOP_1_draw.hpp"
	}; // checklists_startup_1
	class checklists_STOP_2 {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_LISTS_SHUTDOWN_2);
		#include "fms\checklists_STOP_2_draw.hpp"
	}; // checklists_startup_2
	class nav_menu {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_NAV_MENU);
		#include "fms\nav_menu_draw.hpp"
	}; // checklists_startup_2
	class nav_waypoint {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_NAV_WAYPOINT);
		#include "fms\nav_waypoint_draw.hpp"
	}; // nav_waypoint
	class nav_import {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_NAV_IMPORT);
		#include "fms\nav_import_draw.hpp"
	}; // nav_import
	class performance {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_PERFORMANCE);
		#include "fms\performance_draw.hpp"
	}; // checklists_startup_2
	class wpn {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_WPN);
		#include "fms\wpn_draw.hpp"
	}; // checklists_startup_2
	class nav_locations_list {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_LIST);
		#include "fms\nav_locations_list.hpp"
	}; // nav_locations_list
	class nav_locations_sel {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_NAV_LOCATIONS_SEL);
		#include "fms\nav_locations_sel.hpp"
	}; // nav_locations_sel
	class nav_wpn {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_WPN);
		#include "fms\wpn_draw.hpp"
	}; // nav_wpn
	class MSN {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_MSN);
		#include "fms\mission_draw.hpp"
	}; // nav_wpn
	class RDR {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_RDR);
		#include "fms\radar_draw.hpp"
	}; // nav_wpn
	class FLIR {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_FLIR);
		#include "fms\flir_draw.hpp"
	}; // nav_wpn
	class HMD {
		condition = COND_ISNUMBER(FMS_PAGE_INDEX,FMS_PAGE_HMD);
		#include "fms\hmd_draw.hpp"
	}; // nav_wpn
}; // Draw
