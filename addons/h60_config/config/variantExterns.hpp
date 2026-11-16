// Rapify scaffold for variant addons, not config content.
// Every variant PBO (uh60m, s70i, hh60, mh60m, mh60s) includes this at file scope
// before its CfgVehicles, so the screen templates, sensor templates and pedestal
// screens its variant declarations derive from are forward-declared inside its
// own translation unit. All of them are owned elsewhere and resolve by name when
// the config is read (load-order experiment, 2026-09-05). Adds nothing at runtime.

// screen templates (owned by uh60_mfd / uh60_fms / uh60_anvishud)
class HCT_MFD_1;
class HCT_MFD_1_NOFLIR;
class HCT_MFD_1_CMWS;
class HCT_MFD_1_Monospace;
class HCT_MFD_1_Bold;
class HCT_MFD_2;
class HCT_MFD_2_NOFLIR;
class HCT_MFD_2_CMWS;
class HCT_MFD_2_Monospace;
class HCT_MFD_2_Bold;
class HCT_MFD_3;
class HCT_MFD_3_NOFLIR;
class HCT_MFD_3_CMWS;
class HCT_MFD_3_Monospace;
class HCT_MFD_3_Bold;
class HCT_MFD_4;
class HCT_MFD_4_NOFLIR;
class HCT_MFD_4_CMWS;
class HCT_MFD_4_Monospace;
class HCT_MFD_4_Bold;
class NVGHUD;
class NVGHUD_COPILOT;
class HCT_FMS_L;
class HCT_FMS_R;
class HCT_ESIS_BOOT;

// pedestal screens (owned by h60_mfd/config/pedestal/pedestal.hpp)
class HCT_CLOCK;
class HCT_ESIS_Horizon;
class HCT_ESIS_Misc;
class HCT_FDRight;
class HCT_FDLeft;

// vanilla externs referenced by the shared turret/component includes
class VehicleSystemsTemplateLeftPilot;
class VehicleSystemsTemplateRightPilot;
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
