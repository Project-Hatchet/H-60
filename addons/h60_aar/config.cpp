#include "script_component.hpp"

class CfgPatches
{
	class hct_h60_aar
	{
		requiredAddons[]=	{"hct_h60_config"};
		requiredVersion= 1.62;
		version=1;
		units[]={};
		weapons[]={};
    skipWhenMissingDependencies = 1;
	};
};

#include "CfgEventHandlers.hpp"

#include "config\cfgVehicles.hpp"
