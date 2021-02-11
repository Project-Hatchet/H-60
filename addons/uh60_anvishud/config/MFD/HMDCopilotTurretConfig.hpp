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
}; // Bones
class Draw {
}; // Draw
