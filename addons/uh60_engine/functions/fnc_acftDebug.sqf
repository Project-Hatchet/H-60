params ["_vehicle"];

//--Master ignition key
_mikSwitchState      = _vehicle getVariable "vtx_uh60_acft_mikSwitchState";
//--Stby instrument switch
_stbyInstSwitchState = _vehicle getVariable "vtx_uh60_acft_stbyInstSwitchState";
//--Battery
_batt1SwitchState   = _vehicle getVariable "vtx_uh60_acft_batt1SwitchState";
_batt2SwitchState   = _vehicle getVariable "vtx_uh60_acft_batt2SwitchState";
//--APU
_apuPwrSwitchState  = _vehicle getVariable "vtx_uh60_acft_apuPwrSwitchState";
_apuFuelSwitchState = _vehicle getVariable "vtx_uh60_acft_apuFuelSwitchState";
_apuState           = _vehicle getVariable "vtx_uh60_acft_apuState";
//--Generators
_apuGenSwitchState  = _vehicle getVariable "vtx_uh60_acft_apuGenSwitchState";
_apuGenState        = _vehicle getVariable "vtx_uh60_acft_apuGenState";
_eng1GenSwitchState = _vehicle getVariable "vtx_uh60_acft_eng1GenSwitchState";
_eng1GenState       = _vehicle getVariable "vtx_uh60_acft_eng1GenState";
_eng2GenSwitchState = _vehicle getVariable "vtx_uh60_acft_eng2GenSwitchState";
_eng2GenState       = _vehicle getVariable "vtx_uh60_acft_eng2GenState";
//--Air source
_airsrceSwitchState = _vehicle getVariable "vtx_uh60_acft_airsrceSwitchState";
//--Electical buses
_battBusState      = _vehicle getVariable "vtx_uh60_acft_battBusState";
_acBusState        = _vehicle getVariable "vtx_uh60_acft_ACBusState";
_dcBusState        = _vehicle getVariable "vtx_uh60_acft_DCBusState";
//--Engine levers
_eng1FuelSysLeverState = _vehicle getVariable "vtx_uh60_acft_eng1FuelSysLeverState";
_eng2FuelSysLeverState = _vehicle getVariable "vtx_uh60_acft_eng2FuelSysLeverState";
_eng1PwrCtrlLeverState = _vehicle getVariable "vtx_uh60_acft_eng1PwrCtrlLeverState";
_eng2PwrCtrlLeverState = _vehicle getVariable "vtx_uh60_acft_eng2PwrCtrlLeverState";
//--RTD
_forcesRTD             = rotorsForcesRTD _vehicle;
enginesRpmRTD _vehicle params ["_RPMEngine1", "_RPMEngine2"];

HintSilent format ["Aircraft Module Debug Output
                    \nMIK Switch State = %16
                    \nStby Inst Switch State = %21
                    \n---------------------------
                    \nBatt 1 Switch State = %1
                    \nBatt 2 Switch State = %2
                    \nApu Pwr Switch State = %3
                    \nApu Fuel Switch State = %4
                    \nApu Gen Switch State = %5
                    \nEng 1 Gen Switch State = %6
                    \nEng 2 Gen Switch State = %7
                    \nAir Source Switch State = %8
                    \n---------------------------
                    \nApu Gen State = %9
                    \nEng 1 Gen State = %10
                    \nEng 2 Gen State = %11
                    \n---------------------------
                    \nBatt Bus has power? = %12
                    \nAC Bus has power? =%13
                    \nDC Bus has power? = %14
                    \n---------------------------
                    \nAPU State = %15
                    \n---------------------------
                    \nEng 1 Fuel Lever State = %17
                    \nEng 1 Pwr Lever State = %18
                    \n---------------------------
                    \nEng 2 Fuel Lever State = %19
                    \nEng 2 Pwr Lever State = %20
                    \n---------------------------
                    \nForces RTD = %22
                    \nEngine Power = %23
                    \nEngine Torque = %24
                    \nEngine RPM [%25, %26]",
                    _batt1SwitchState,      //1
                    _batt2SwitchState,      //2
                    _apuPwrSwitchState,     //3
                    _apuFuelSwitchState,    //4
                    _apuGenSwitchState,     //5
                    _eng1GenSwitchState,    //6
                    _eng2GenSwitchState,    //7
                    _airsrceSwitchState,    //8
                    _apuGenState,           //9
                    _eng1GenState,          //10
                    _eng2GenState,          //11
                    _battBusState,          //12
                    _acBusState,            //13
                    _dcBusState,            //14
                    _apuState,              //15
                    _mikSwitchState,        //16
                    _eng1FuelSysLeverState, //17
                    _eng1PwrCtrlLeverState, //18
                    _eng2FuelSysLeverState, //19
                    _eng2PwrCtrlLeverState, //20
                    _stbyInstSwitchState,   //21
                    (_forcesRTD select 0) select 1,        //22
                    enginesPowerRTD _vehicle,   //23
                    enginesTorqueRTD _vehicle,  //24
                    _RPMEngine1,                //25
                    _RPMEngine2];               //26