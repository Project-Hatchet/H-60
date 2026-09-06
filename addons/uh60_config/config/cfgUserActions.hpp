class UserActions: UserActions
{
  class HMDs_Kimi_UserAction_0_ON
  {
    displayName = "<t color='#26ff00'>HMD ON</t>";
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
    displayName = "<t color='#ffff00'>HMD OFF</t>";
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
    displayName = "<t color='#26ff00'>HMD IMPERIAL</t>";
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
    displayName = "<t color='#ffff00'>HMD METRIC</t>";
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
    displayName = "<t color='#26ff00'>HMD FULL</t>";
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
    displayName = "<t color='#ffff00'>HMD DECLUTTER</t>";
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
    displayName = "<t color='#00ff00'>HMD GREEN</t>";
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
    displayName = "<t color='#ffff00'>HMD YELLOW</t>";
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
    displayName = "HMD BRT HIGH";
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
    displayName = "HMD BRT MED";
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
    displayName = "HMD BRT LOW";
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
