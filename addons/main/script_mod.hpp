// COMPONENT should be defined in the script_component.hpp and included BEFORE this hpp

#define MAINPREFIX z
#define PREFIX vtx

#include "script_version.hpp"

#define VERSION MAJOR.MINOR.PATCHLVL.BUILD
#define VERSION_AR MAJOR,MINOR,PATCHLVL,BUILD
// CBA's VERSION_CONFIG writes version = VERSION unquoted, which only parses for a MAJOR.MINOR float.
// The H-60 version is four-part, and every shipped config.bin carries it as the string "0.7.10.0" - keep that.
#define VERSION_CONFIG version = QUOTE(VERSION); versionStr = QUOTE(VERSION); versionAr[] = {VERSION_AR}

#define VTX_TAG VTX

// MINIMAL required version for the Mod. Components can specify others..
#define REQUIRED_VERSION 2.12

#ifdef COMPONENT_BEAUTIFIED
    #define COMPONENT_NAME QUOTE(vtx - COMPONENT_BEAUTIFIED)
#else
    #define COMPONENT_NAME QUOTE(vtx - COMPONENT)
#endif
