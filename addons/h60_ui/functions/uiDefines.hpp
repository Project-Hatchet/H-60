#define HUD (uiNamespace getVariable ["hct_h60_ui_hud", nil])
#define CTRL(IDC) (HUD displayCtrl IDC)
#define HELPCTRL(IDC) (CTRL(4001121) controlsGroupCtrl IDC)
#define HELP (HUD displayCtrl 4001121)
#define SETTEXT(IDC,TXT) CTRL(IDC) ctrlSetText TXT
#define SETTEXTGRP(CONTROL,IDC,TXT) (CONTROL controlsGroupCtrl IDC) ctrlSetText TXT
