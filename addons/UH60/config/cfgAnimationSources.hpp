class AnimationSources
{
    //#define ANIMSRC(name,src,per,init)
    ANIMSRC(Skis_Show,user,1,0);
    ANIMSRC(cockpitlight_show,user,1,0);
    ANIMSRC(hoist_hook_hide,user,1,0);
    class recoil_source
    {
            source="reload";
            weapon="vtx_chaingun";
    };
    class muzzle_rot
    {
            source="ammorandom";
            weapon="vtx_chaingun";
    };
    class Switch_minigun_safe_cover_l
    {
            source="user";
            animPeriod=0.2;
            initPhase=0;
    };
    class Switch_minigun_safe_cover_r: Switch_minigun_safe_cover_l {};
    class Switch_minigun_safe_l: Switch_minigun_safe_cover_l {};
    class Switch_minigun_safe_r: Switch_minigun_safe_cover_l {};
    class FLIR_BACK {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class GAU21_L_Hide {
        source="user";
        animPeriod=1;
        initPhase=1;
    };
    class GAU21_R_Hide {
        source="user";
        animPeriod=1;
        initPhase=1;
    };
    class LandingLight_Show : GAU21_R_Hide {};
    class CabinLight_Show : GAU21_R_Hide {};
    class RADAR_HIDE {
        source="user";
        animPeriod=1;
        initPhase=1;
    };
    class FLIR_HIDE {
        source="user";
        animPeriod=1;
        initPhase=1;
    };
    class FLIR_DIRECTION {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class FLIR_ELEVATION {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class Fuelprobe_Show {
        displayName = "Show Fuel Probe";
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class Cockpitdoors_Hide {
        displayName = "Hide Cockpit doors";
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class ERFS_Show {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class MAWS_Tubes_Show {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class Fuelprobe_Extend {
        source="user";
        animPeriod=5;
        initPhase=0;
    };
    class LASS_Show {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class ESSS_Show {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    //exterior parts
    class GunnerSeats_Hide {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class CabinSeats_Hide {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class Minigun_Mount_L_hide {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class Minigun_Mount_R_hide {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class Minigun_L_hide {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class Minigun_R_hide {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class Hoist_hook {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class cabindoor_L {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class cabindoor_R {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    class Stabilator_rotate_user {
        source="user";
        animPeriod=1;
        initPhase=0;
    };
    //interriorparts
    class MAP_X
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class MAP_Y
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class MAP_Rotation
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class MAP1_Scale
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class COMM1_ROT
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class COMM2_ROT:COMM1_ROT{};
    class COMM3_ROT:COMM1_ROT{};
    class COMM4_ROT:COMM1_ROT{};
    class MVOL_ROT
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class TX_ROT
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class FD_1_ROT
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class FD_2_ROT:FD_1_ROT{};
    class FD_3_ROT:FD_1_ROT{};
    class FD_4_ROT:FD_1_ROT{};
    class FD_5_ROT:FD_1_ROT{};

    class ACCLow
    {
            source="user";
            animPeriod=0.00001;
            initPhase=0;
    };
    class APUFail:ACCLow{};
    class APUOn:ACCLow{};
    class BattGood:ACCLow{};
    class BattLow:ACCLow{};
    class EmerRlse:ACCLow{};
    class OilHot:ACCLow{};
    class TestLte:ACCLow{};
    class CautionEng1Out:ACCLow{};
    class CautionEng2Out:ACCLow{};
    class CautionFire:ACCLow{};
    class CautionMasterCaution:ACCLow{
        initPhase = 0;
    };
    class Gauge_temp
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Lever_RotorBrake
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Knob_LightInstPanel
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Knob_LightLowerConsole
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Knob_LightUpperConsole
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Knob_Lights_Formation
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Switch_lights_position
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Switch_lights_collision
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Switch_lights_cockpit
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class MFD1_hide
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class MFD2_hide
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class MFD3_hide
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class MFD4_hide
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class ESIS_hide
    {
        source="user";
        animPeriod=1;
        initPhase=1;
    };
    class PowerOnOff
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class GeneratorsOnOff
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Switch_fuelboostpump1
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Switch_fuelboostpump2
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Switch_batt1
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Switch_batt2
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Switch_stbyinst
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Switch_airsce
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Lever_fuelsys1
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Lever_fuelsys2
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Lever_engpower1
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Lever_engpower2
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Switch_ignition
    {
            source="user";
            animPeriod=1;
            initPhase=0;
    };
    class Switch_gen1
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Handle_wheelbrake
    {
            source="user";
            animPeriod=1;
            initPhase=1;
    };
    class Switch_gen2
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Switch_apugen
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Switch_apucont
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class Switch_fuelpump
    {
            source="user";
            animPeriod=1;
            initPhase=0.5;
    };
    class wheel_dumper_l
    {
        source="damper";
        wheel="Wheel_1";
    };
    class wheel_dumper_r
    {
        source="damper";
        wheel="Wheel_2";
    };
    class wheel_dumper_rear
    {
        source="damper";
        wheel="Wheel_3";
    };
    class Wheel_l_source
    {
        source="wheel";
        wheel="Wheel_1";
    };
    class Wheel_r_source
    {
        source="wheel";
        wheel="Wheel_2";
    };
    class Wheel_rear_source
    {
        source="wheel";
        wheel="Wheel_3";
    };
    class Gatling_1
    {
        source="revolving";
        weapon="vtx_wpn_m134";
    };
    class Gatling_2
    {
        source="revolving";
        weapon="vtx_wpn_m134_2nd";
    };
    class Muzzle_flash
    {
        source="ammorandom";
        weapon="vtx_wpn_m134";
    };
    class Muzzle_flash2
    {
        source="ammorandom";
        weapon="vtx_wpn_m134_2nd";
    };
};
