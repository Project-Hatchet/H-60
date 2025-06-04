#include "script_component.hpp"

class CfgPatches
{
	class USAF_Hatchet_AAR
	{
		requiredAddons[]=	{"vtx_uh60_config"};
		requiredVersion= 1.62;
		version=1;
		units[]={};
		weapons[]={};
    skipWhenMissingDependencies = 1;
	};
};

#include "CfgEventHandlers.hpp"

#include "config\cfgVehicles.hpp"
