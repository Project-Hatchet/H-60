class CfgDistanceFilters {
  class vtx_weapons_lowpass_filter 
  {
    type = "lowpassfilter";
    mincutofffrequency = 1000;
    qfactor = 1;
    innerrange = 40;
    range = 1000;
    powerfactor = 55;
  };
};

class CfgSoundCurves {
  class vtx_weapons_basic_volumecurve 
  {
    points[] = {{0, 1}, {0.100000, 0.750000}, {0.200000, 0.500000}, {0.300000, 0.200000}, {0.400000, 0.100000}, {0.500000, 0.050000}, {0.600000, 0.010000}, {0.700000, 0.007500}, {0.800000, 0.002500}, {0.900000, 0.001000}, {1, 0}};
  };
  class vtx_weapons_processorcurve 
  {
    points[] = {{0, 1}, {0.005000, 0.750000}, {0.010000, 0.025000}, {1, 0.010000}};
  };
};

class CfgSound3DProcessors {
  class vtx_weapons_3dprocessor 
  {
    type = "panner";
    innerrange = 1;
    range = 500;
    rangecurve = "vtx_weapons_processorcurve";
  };
};

class CfgSoundSets {
  class vtx_m230_soundset 
  {
    volumeFactor = 1;
    volumecurve = "vtx_weapons_basic_volumecurve";
    sound3dprocessingtype = "vtx_weapons_3dprocessor";
    distancefilter = "vtx_weapons_lowpass_filter";
    occlusionFactor = 0.250000;
    obstructionFactor = 0.300000;
    spatial = 1;
    doppler = 0;
    loop = 0;
    frequencyrandomizer = 0.500000;
    soundShaders[] = {"vtx_m230_close_soundshader","vtx_m230_close_distance_soundshader","vtx_m230_medium_distance_soundshader","vtx_m230_close_distance_pool_soundshader","vtx_m230_far_distance_pool_soundshader","vtx_m230_very_far_distance_pool_soundshader"};
  };
};