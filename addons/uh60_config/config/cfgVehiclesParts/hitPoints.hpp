//HeliSim-role hitpoints live in uh60_helisim (helisim_hitpoints.hpp).
#define MULTIPLIER (1/15)
class HitPoints
{
	class FlightComp1
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.35;
		name = "FlightComp1";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class hitRWRFront {
		armor = MULTIPLIER * 1.08;
		radius = 0.59;
		name = "noseRWR";
		explosionShielding =0.360;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class hitRWRRear {
		armor = MULTIPLIER * 1.08;
		radius = 0.59;
		name = "tailRWR";
		explosionShielding =0.360;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class hitRWR
	{
		armor = MULTIPLIER * 1.08;
		radius = 0.59;
		name = "hitRWR";
		depends = "(hitRWRFront + hitRWRRear)";
		explosionShielding =0.360;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class SlingHit
	{
		armor = MULTIPLIER * 0.3;
		material = 51;
		name = "SlingHit";
		visual = "";
		passThrough = 0;
		radius = 0.2;
		class DestructionEffects
		{
			ammoExplosionEffect = "";
			class Explo
			{
				simulation = "particles";
				type = "WinchDestructionExplo";
				position = "slingLoad0";
				intensity = 1;
				interval = 1;
				lifeTime = 0.06;
			};
			class Sparks
			{
				simulation = "particles";
				type = "WinchDestructionSparks";
				position = "slingLoad0";
				intensity = 1;
				interval = 1;
				lifeTime = 0.1;
			};
		};
	};
	class HoistHit
	{
		armor = MULTIPLIER * 0.38;
		radius = 0.26;
		name = "HoistHit";
		explosionShielding =0.211;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class HoistHookHit
	{
		armor = MULTIPLIER * 0.38;
		radius = 0.13;
		name = "HoistHookHit";
		explosionShielding =0.211;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class MainRotorHub
	{
		armor = MULTIPLIER * 0.96;
		radius = 1.01;
		name = "MainRotorHub";
		explosionShielding =0.533;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class WingStoreL
	{
		armor = MULTIPLIER * 0.54;
		radius = 0.4;
		name = "WingStoreL";
		explosionShielding =0.300;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class WingStoreR
	{
		armor = MULTIPLIER * 0.54;
		radius = 0.4;
		name = "WingStoreR";
		explosionShielding =0.300;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class AirDataComp
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.12;
		name = "AirDataComp";
		explosionShielding =0.150;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class FlirHit
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.35;
		name = "FlirHit";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class ProbTip
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.21;
		name = "FuelProbTip";
		explosionShielding =0.599;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class EgiComp
	{
		armor = MULTIPLIER * 0.47;
		radius = 0.28;
		name = "EgiComp";
		explosionShielding =0.261;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class FlightControlComp2
	{
		armor = MULTIPLIER * 0.48;
		radius = 0.35;
		name = "FlightControlComp2";
		explosionShielding =0.266;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class MFD1
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.21;
		name = "MFD1";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class MFD2
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.21;
		name = "MFD2";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class MFD3
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.21;
		name = "MFD3";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class MFD4
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.21;
		name = "MFD4";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class Flare1
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.3;
		name = "Flare1";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class Flare2
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.3;
		name = "Flare2";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class Flare3
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.3;
		name = "Flare3";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class HHFlare1
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.3;
		name = "HHFlare1";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class HHFlare2
	{
		armor = MULTIPLIER * 0.36;
		radius = 0.3;
		name = "HHFlare2";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
};
