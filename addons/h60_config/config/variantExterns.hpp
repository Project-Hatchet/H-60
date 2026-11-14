// Rapify scaffold for variant addons, not config content.
// Every variant PBO (uh60m, s70i, hh60, mh60m, mh60s) includes this at file scope
// before its CfgVehicles, so the screen templates, sensor templates and pedestal
// screens its variant declarations derive from are forward-declared inside its
// own translation unit. All of them are owned elsewhere and resolve by name when
// the config is read (load-order experiment, 2026-09-05). Adds nothing at runtime.

// screen templates (owned by uh60_mfd / uh60_fms / uh60_anvishud)
class VTX_MFD_1;
class VTX_MFD_1_NOFLIR;
class VTX_MFD_1_CMWS;
class VTX_MFD_1_Monospace;
class VTX_MFD_1_Bold;
class VTX_MFD_2;
class VTX_MFD_2_NOFLIR;
class VTX_MFD_2_CMWS;
class VTX_MFD_2_Monospace;
class VTX_MFD_2_Bold;
class VTX_MFD_3;
class VTX_MFD_3_NOFLIR;
class VTX_MFD_3_CMWS;
class VTX_MFD_3_Monospace;
class VTX_MFD_3_Bold;
class VTX_MFD_4;
class VTX_MFD_4_NOFLIR;
class VTX_MFD_4_CMWS;
class VTX_MFD_4_Monospace;
class VTX_MFD_4_Bold;
class NVGHUD;
class NVGHUD_COPILOT;
class VTX_FMS_L;
class VTX_FMS_R;
class VTX_ESIS_BOOT;

// pedestal screens (owned by uh60_config/config/MFD/MFDConfig.hpp)
class VTX_CLOCK;
class VTX_ESIS_Horizon;
class VTX_ESIS_Misc;
class VTX_FDRight;
class VTX_FDLeft;

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
