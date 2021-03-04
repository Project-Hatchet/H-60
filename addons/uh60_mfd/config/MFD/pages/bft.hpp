class BFT
{
    type = sensor;
    //pos[] = {"BFT_POS", {0.5,0.5},1};
    //down[] = {"BFT_DOWN", {0.5,0.5},1};
	#ifdef SENSOR_SIZE
		#undef SENSOR_SIZE
	#endif
    #define SENSOR_SIZE(numb)\
        pos[]	= {"BFT_POS", 1, BFT_CENTER,{(0+numb), 0+numb}, 1};\
        down[]	= {"BFT_DOWN", 1, BFT_CENTER,{(0-numb), 0-numb}, 1};
    SENSOR_SIZE(-0.01)

    showTargetTypes = 1+2+4+8+16+32+64+128+256+512+1024;    // RWR only
    width = 1; // default width of lines can by different in case of class XXXX used instead of arrays
    range=4000;
    sensorLineType = 3; // same as "lineType"
    sensorLineWidth = 0;
    class MissileThreat
	{
		color[] = {1, 0, 0};
		class TargetLines
		{
			type = "line";
			width = 2;
			points[] = {{{0, -0.0198157}, 1}, {{0.003472, -0.0195145}, 1}, {{0.00684, -0.0186208}, 1}, {{0.01, -0.0171604}, 1}, {{0.012856, -0.0151788}, 1}, {{0.01532, -0.0127375}, 1}, {{0.01732, -0.00990783}, 1}, {{0.018794, -0.00677696}, 1}, {{0.019696, -0.00344}, 1}, {{0.02, 0}, 1}, {{0.019696, 0.00344}, 1}, {{0.018794, 0.00677696}, 1}, {{0.01732, 0.00990783}, 1}, {{0.01532, 0.0127375}, 1}, {{0.012856, 0.0151788}, 1}, {{0.01, 0.0171604}, 1}, {{0.00684, 0.0186208}, 1}, {{0.003472, 0.0195145}, 1}, {{0, 0.0198157}, 1}, {{-0.003472, 0.0195145}, 1}, {{-0.00684, 0.0186208}, 1}, {{-0.01, 0.0171604}, 1}, {{-0.012856, 0.0151788}, 1}, {{-0.01532, 0.0127375}, 1}, {{-0.01732, 0.00990783}, 1}, {{-0.018794, 0.00677696}, 1}, {{-0.019696, 0.00344}, 1}, {{-0.02, 0}, 1}, {{-0.019696, -0.00344}, 1}, {{-0.018794, -0.00677696}, 1}, {{-0.01732, -0.00990783}, 1}, {{-0.01532, -0.0127375}, 1}, {{-0.012856, -0.0151788}, 1}, {{-0.01, -0.0171604}, 1}, {{-0.00684, -0.0186208}, 1}, {{-0.003472, -0.0195145}, 1}, {{0, -0.0198157}, 1}};
		};
		class TextM
		{
			type = "text";
			source = "static";
			text = "M";
			align = "center";
			scale = 1;
			pos[] = {{0, -0.01}, 1};
			right[] = {{0.02, -0.01}, 1};
			down[] = {{0, 0.01}, 1};
		};
	};
	class lockingThreat
	{
		color[] = {1, 0.3, 0};
		class TargetLines
		{
			type = "line";
			points[] = {{{0.02, 0}, 1}, {{0, 0.0198157}, 1}, {{-0.02, 0}, 1}, {{0, -0.0198157}, 1}, {{0.02, 0}, 1}};
		};
	};
	class markingThreat: lockingThreat
	{
		class TargetLines: TargetLines
		{
		};
	};
	class rwr
	{
		class TargetLines { };
	};
	class rwrFriendly: rwr
	{
		color[] = {0, 0, 1};
		class TargetLines: TargetLines { };
	};
	class rwrEnemy: rwr
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines { };
	};
	class rwrGroup: rwr
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines { };
	};
	class rwrDestroyed
	{
	};
	class markedTarget
	{
		color[] = {1, 0.3, 0};
		class TargetLines
		{
			type = "line";
			width = 3;
			points[] = {{{-0.017, -0.0168433}, 1}, {{-0.01, -0.0168433}, 1}, {}, {{0.017, -0.0168433}, 1}, {{0.01, -0.0168433}, 1}, {}, {{-0.017, -0.0168433}, 1}, {{-0.017, -0.00990783}, 1}, {}, {{0.017, -0.0168433}, 1}, {{0.017, -0.00990783}, 1}, {}, {{-0.017, 0.0168433}, 1}, {{-0.01, 0.0168433}, 1}, {}, {{0.017, 0.0168433}, 1}, {{0.01, 0.0168433}, 1}, {}, {{-0.017, 0.0168433}, 1}, {{-0.017, 0.00990783}, 1}, {}, {{0.017, 0.0168433}, 1}, {{0.017, 0.00990783}, 1}, {}};
		};
	};
	class assignedTarget: markedTarget
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class target
	{
		color[] = {1, 0.3, 0};
		class TargetLines
		{
			type = "polygon";
			points[] = {{{{-0.01, -0.01}, 1}, {{0, -0.01}, 1}, {{0, 0}, 1}, {{-0.01, 0}, 1}}};
		};
	};
	class targetFriendly: target
	{
		color[] = {0, 0, 1};
		class TargetLines: TargetLines
		{
		};
	};
	class targetEnemy: target
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetGroup: target
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetDestroyed
	{
	};
	class targetGround: target
	{
		class TargetLines: TargetLines
		{
			type = "polygon";
			points[] = {{{{-0.01, -0.01}, 1}, {{0.015, -0.01}, 1}, {{0.015, 0}, 1}, {{-0.01, 0}, 1}}, {{{-0.007, -0.018}, 1}, {{-0.002, -0.018}, 1}, {{-0.002, 0.007}, 1}, {{-0.007, 0.007}, 1}}, {{{0.007, -0.018}, 1}, {{0.012, -0.018}, 1}, {{0.012, 0.007}, 1}, {{0.007, 0.007}, 1}}};
		};
	};
	class targetGroundFriendly: targetGround
	{
		color[] = {0, 0, 1};
		class TargetLines: TargetLines
		{
		};
	};
	class targetGroundEnemy: targetGround
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetGroundGroup: targetGround
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetGroundDestroyed
	{
	};
	class targetGroundRemote: target
	{
		class TargetLines: TargetLines
		{
		};
	};
	class targetGroundRemoteFriendly: targetGroundRemote
	{
		color[] = {0, 0, 1};
		class TargetLines: TargetLines
		{
		};
	};
	class targetGroundRemoteEnemy: targetGroundRemote
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetGroundRemoteGroup: targetGroundRemote
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetGroundRemoteDestroyed
	{
	};
	class targetLaser: target
	{
		class TargetLines: TargetLines
		{
			type = "line";
			width = 4;
			points[] = {{{0, -0.0198157}, 1}, {{-1.74846e-009, 0.0198157}, 1}, {}, {{0.02, 8.6617e-010}, 1}, {{-0.02, -2.36299e-010}, 1}, {}, {{0.0106066, -0.0105088}, 1}, {{-0.0106066, 0.0105088}, 1}, {}, {{0.0106066, 0.0105088}, 1}, {{-0.0106066, -0.0105088}, 1}, {}};
		};
	};
	class targetLaserFriendly: targetLaser
	{
		color[] = {0, 0, 1};
		class TargetLines: TargetLines
		{
		};
	};
	class targetLaserEnemy: targetLaser
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetLaserGroup: targetLaser
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetNVG: targetLaser
	{
		class TargetLines: TargetLines
		{
		};
	};
	class targetNVGFriendly: targetNVG
	{
		color[] = {0, 0, 1};
		class TargetLines: TargetLines
		{
		};
	};
	class targetNVGEnemy: targetNVG
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetNVGGroup: targetNVG
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetMan: target
	{
		class TargetLines: TargetLines
		{
		};
	};
	class targetManFriendly: targetMan
	{
		color[] = {0, 0, 1};
		class TargetLines: TargetLines
		{
		};
	};
	class targetManEnemy: targetMan
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetManGroup: targetMan
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetManRemote: target
	{
		class TargetLines: TargetLines
		{
		};
	};
	class targetManRemoteFriendly: targetManRemote
	{
		color[] = {0, 0, 1};
		class TargetLines: TargetLines
		{
		};
	};
	class targetManRemoteEnemy: targetManRemote
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetManRemoteGroup: targetManRemote
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetAir
	{
		color[] = {1, 1, 1};
		class TargetLines
		{
			type = "polygon";
			points[] = {{{{0, 0}, 1}, {{0.01, 0.015}, 1}, {{-0.01, 0.015}, 1}}, {{{0, 0}, 1}, {{0.01, -0.015}, 1}, {{-0.01, -0.015}, 1}}};
		};
	};
	class targetAirFriendly: targetAir
	{
		color[] = {0, 0, 1};
		class TargetLines: TargetLines
		{
		};
	};
	class targetAirEnemy: targetAir
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetAirGroup: targetAir
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetAirDestroyed
	{
	};
	class targetAirRemote: targetAir
	{
		color[] = {1, 1, 1};
		class TargetLines: TargetLines
		{
		};
	};
	class targetAirRemoteFriendly: targetAirRemote
	{
		color[] = {0, 0, 1};
		class TargetLines: TargetLines
		{
		};
	};
	class targetAirRemoteEnemy: targetAirRemote
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetAirRemoteGroup: targetAirRemote
	{
		color[] = {1, 0, 0};
		class TargetLines: TargetLines
		{
		};
	};
	class targetAirRemoteDestroyed
	{
	};
};
