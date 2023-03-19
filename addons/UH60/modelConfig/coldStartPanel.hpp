class ACCLow
{
  type = "hide";
  source = "user";
  selection = "Emmisive_top_acclow";
  minValue = 0;
  maxValue = 1;
  hideValue = 0;
  unHideValue = 0.5;
};
class APUFail: ACCLow
{
  selection = "Emmisive_top_apufail";
};
class APUOn: ACCLow
{
  selection = "Emmisive_top_apuon";
};
// class BattGood: ACCLow
// {
//   selection = "Emmisive_top_battgood";
// };
class BattLow: ACCLow
{
  selection = "Emmisive_top_battlow";
};
class EmerRlse: ACCLow
{
  selection = "Emmisive_top_emerrlse";
};
class OilHot: ACCLow
{
  selection = "Emmisive_top_oilhot";
};
class TestLte: ACCLow
{
  selection = "Emmisive_top_testlte";
};