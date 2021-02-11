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
turret[] = {0};
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
}; // Bones
class Draw {
	condition="user15>-1";
	class hasCopilot {
		condition="user39>1";
	    class TurretDirection {
	        type="line";
	        width = 6;
	        points[] ={
	            {"TurretToView", {0, -0.05}, 1},
	            {"TurretToView", {0, -0.01}, 1},{},
	            {"TurretToView", {0, 0.05}, 1},
	            {"TurretToView", {0, 0.01}, 1},{},
	            {"TurretToView", {-0.05,0}, 1},
	            {"TurretToView", {-0.01,0}, 1},{},
	            {"TurretToView", {0.05,0}, 1},
	            {"TurretToView", {0.01,0}, 1}
	        }; // points
	    }; // TurretDirection
	    class laserOn {
	        condition="laseron";
	        class TurretDirection {
	            type="line";
	            width = 6;
	            points[] ={
	                {"TurretToView", {-0.04, -0.04}, 1},
	                {"TurretToView", {-0.02, -0.02}, 1},{},
	                {"TurretToView", {0.04, 0.04}, 1},
	                {"TurretToView", {0.02, 0.02}, 1},{},
	                {"TurretToView", {-0.04,0.04}, 1},
	                {"TurretToView", {-0.02,0.02}, 1},{},
	                {"TurretToView", {0.04,-0.04}, 1},
	                {"TurretToView", {0.02,-0.02}, 1}
	            }; // points
	        }; // TurretDirection
	    }; // laserOn
	}; // hasCopilot
}; // Draw
