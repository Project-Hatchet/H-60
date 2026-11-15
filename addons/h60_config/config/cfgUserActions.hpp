class UserActions: UserActions
{
  class HMDs_Kimi_UserAction_0_ON
  {
    displayName = "$STR_hct_h60_config_HMDON";
    condition = "false"; // Set
    statement = "this SetUserMFDvalue [0,1]";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -1;
  };
  class HMDs_Kimi_UserAction_0_OFF
  {
    displayName = "$STR_hct_h60_config_HMDOFF";
    condition = "false";
    statement = "this SetUserMFDvalue [0,0]";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -2;
  };
  class HMDs_Kimi_UserAction_1_IMPERIAL
  {
    displayName = "$STR_hct_h60_config_HMDIMPERIAL";
    condition = "false";
    statement = "this SetUserMFDvalue [1,1]";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -3;
  };
  class HMDs_Kimi_UserAction_1_METRIC
  {
    displayName = "$STR_hct_h60_config_HMDMETRIC";
    condition = "false";
    statement = "this SetUserMFDvalue [1,0]";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -4;
  };
  class HMDs_Kimi_UserAction_2_FULL
  {
    displayName = "$STR_hct_h60_config_HMDFULL";
    condition = "false";
    statement = "this SetUserMFDvalue [2,0]";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -5;
  };
  class HMDs_Kimi_UserAction_2_DECLUTTER
  {
    displayName = "$STR_hct_h60_config_HMDDECLUTTER";
    condition = "false";
    statement = "this SetUserMFDvalue [2,1]";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -6;
  };
  class HMDs_Kimi_UserAction_345_COLOR_GREEN
  {
    displayName = "$STR_hct_h60_config_HMDGREEN";
    condition = "false";
    statement = "this SetUserMFDvalue [3,0];this SetUserMFDvalue [4,1];this SetUserMFDvalue [5,0];";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -7;
  };
  class HMDs_Kimi_UserAction_345_COLOR_YELLOW
  {
    displayName = "$STR_hct_h60_config_HMDYELLOW";
    condition = "false";
    statement = "this SetUserMFDvalue [3,1];this SetUserMFDvalue [4,0.65];this SetUserMFDvalue [5,0];";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -8;
  };
  class HMDs_Kimi_UserAction_6_ALPHA_HIGH
  {
    displayName = "$STR_hct_h60_config_HMDBRTHIGH";
    condition = "false";
    statement = "this SetUserMFDvalue [6,0.5]";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -9;
  };
  class HMDs_Kimi_UserAction_6_ALPHA_MED
  {
    displayName = "$STR_hct_h60_config_HMDBRTMED";
    condition = "false";
    statement = "this SetUserMFDvalue [6,0.2]";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -10;
  };
  class HMDs_Kimi_UserAction_6_ALPHA_LOW
  {
    displayName = "$STR_hct_h60_config_HMDBRTLOW";
    condition = "false";
    statement = "this SetUserMFDvalue [6,0.05]";
    position = "pilotcontrol";
    radius = 20;
    onlyforplayer = 1;
    showWindow = 1;
    hideOnUse = 1;
    priority = -11;
  };
};
