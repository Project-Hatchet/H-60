#include "script_component.hpp"

class CfgPatches
{
	class USAF_Hatchet_AAR
	{
		requiredAddons[]=	{"USAF_Main"};
		requiredVersion= 1.62;
		version=1;
		units[]={};
		weapons[]={};
    skipWhenMissingDependencies = 1;
	};
};

#include "CfgEventHandlers.hpp"

#include "config\cfgVehicles.hpp"
