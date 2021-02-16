borderBottom = 0;
borderLeft = 0;
borderRight = 0;
borderTop = 0;
color[] = {0.082,0.608,0.039,1};
enableParallax = 0;
helmetDown[] = {0,-0.065,0};
helmetMountedDisplay = 1;
helmetPosition[] = {-0.0325,0.0325,0.1};
helmetRight[] = {0.065,0,0};
topLeft = ""; // not used because HMD, but still needed
topRight = ""; // not used because HMD, but still needed
bottomLeft = ""; // not used because HMD, but still needed
turret[] = {-1};
font="RobotoCondensedLight";
class material {
	ambient[] = {1, 1, 1, 1};
	diffuse[] = {0.5, 0.5, 0.5, 1};
	emissive[] = {100, 100, 100, 50};
};
class Bones {
	#define POS10X 0.765
	#define POS10Y 0.76
	class TurretToView
	{
		type = "vector";
		source = "TurretToView";
		pos0[] = {0.5, 0.5};
		pos10[] = {POS10X, POS10Y};
	}; // WPPoint
	class HUDCenter
	{
		type = "fixed";
		pos[] = {0.5, 0.5};
	}; // HUDCenter
	class ForwardVector
	{
		type = "vector";
		source = "forward";
		pos0[] = {0, 0};
		pos10[] = {POS10X, POS10Y};
	}; // ForwardVector
	class ImpactPoint
	{
		type = "vector";
		source = "impactpointtoview";
		pos0[] = {0.5, 0.5};
		pos10[] = {POS10X, POS10Y};
	}; // ImpactPoint
	class PilotCameraToView
	{
		type = "vector";
		source = "pilotcameratoview";
		pos0[] = {0.5, 0.5};
		pos10[] = {POS10X, POS10Y};
	}; // WPPoint
}; // Bones
class Draw {
	condition="(user15>-1)*on";
	class noCoPilot {
		condition="user39<1";
	    class TurretDirection {
	        type="line";
	        width = 3;
	        points[] ={
	            {"PilotCameraToView", { 0.02, -0.015}, 1},
	            {"PilotCameraToView", { 0,     0.015}, 1},
	            {"PilotCameraToView", {-0.02, -0.015}, 1},
	            {"PilotCameraToView", { 0.02, -0.015}, 1}
	        }; // points
	    }; // TurretDirection
	    class laserOn {
	        condition="laseron";
	        class TurretDirection {
	            type="line";
	            width = 3;
	            points[] ={
	                {"PilotCameraToView", {-0.04, -0.04}, 1},
	                {"PilotCameraToView", {-0.02, -0.02}, 1},{},
	                {"PilotCameraToView", {0.04, 0.04}, 1},
	                {"PilotCameraToView", {0.02, 0.02}, 1},{},
	                {"PilotCameraToView", {-0.04,0.04}, 1},
	                {"PilotCameraToView", {-0.02,0.02}, 1},{},
	                {"PilotCameraToView", {0.04,-0.04}, 1},
	                {"PilotCameraToView", {0.02,-0.02}, 1}
	            }; // points
	        }; // TurretDirection
	    }; // laserOn
	}; // noCoPilot
	#include "weaponInfo.hpp"
	#include "CCIP.hpp"
}; // Draw
