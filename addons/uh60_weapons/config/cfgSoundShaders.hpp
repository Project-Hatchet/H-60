class cfgSoundShaders {
	class vtx_m230_close_soundshader 
	{
		samples[] = {{"z\vtx\addons\UH60_weapons\Data\Audio\Close_1.ogg", 1}};
		volume = "3.9810717*(1-interior/1.4)";
		range = 20;
		rangeCurve[] = {{0, 1}, {20, 1}, {50, 0}};
		frequency = 1;
	};
	class vtx_m230_close_distance_soundshader 
	{
		samples[] = {{"z\vtx\addons\UH60_weapons\Data\Audio\Close_Distance.ogg", 1}};
		volume = "3.9810717*(1-interior/1.4)";
		range = 300;
		rangeCurve[] = {{0, 0}, {10, 0.25}, {20, 0.5}, {50, 1}, {100, 1}, {300, 0}};
		frequency = 1;
	};
	class vtx_m230_medium_distance_soundshader 
	{
		samples[] = {{"z\vtx\addons\UH60_weapons\Data\Audio\Medium_Distance.ogg", 1}};
		volume = 3.9810717;
		range = 600;
		rangeCurve[] = {{0, 0}, {100, 0}, {300, 1}, {600, 0}};
		frequency = 1;
	};
	class vtx_m230_close_distance_pool_soundshader 
	{
		samples[] = {{"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_1.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_2.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_3.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_4.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_5.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_6.ogg", 1}};
		volume = 3.9810717;
		range = 1500;
		rangeCurve[] = {{0, 0}, {300, 0}, {600, 1}, {1500, 0}};
		frequency = 1;
	};
	class vtx_m230_far_distance_pool_soundshader 
	{
		samples[] = {{"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_far_1.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_far_2.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_far_3.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_far_4.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_far_6.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_far_5.ogg", 1}};
		volume = 3.9810717;
		range = 2000;
		rangeCurve[] = {{0, 0}, {600, 0}, {1500, 1}, {2000, 0}};
		frequency = 1;
	};
	class vtx_m230_very_far_distance_pool_soundshader 
	{
		samples[] = {{"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_very_far_1.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_very_far_2.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_very_far_3.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_very_far_4.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_very_far_6.ogg", 1}, {"z\vtx\addons\UH60_weapons\Data\Audio\distance\shot_very_far_5.ogg", 1}};
		volume = 3.9810717;
		range = 4000;
		rangeCurve[] = {{0, 0}, {600, 0}, {1500, 0}, {3000, 1}, {4000, 0}};
		frequency = 1;
	};
};