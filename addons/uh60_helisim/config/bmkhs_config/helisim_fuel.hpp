/////////////////////////////////////////////////////////////////////////////////////////////
// Fuel //////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  variableName - the aircraft names its own tank variables. Core prefixes bmkhs_ and appends
//              the field: "no1Tank" publishes bmkhs_no1TankMass, bmkhs_no1TankMax,
//              bmkhs_no1TankLow. Names must be unique. Do not include the bmkhs_ prefix.
//  arm[]     - {lateral, longitudinal, vertical} in m, right-positive / nose-positive
//  capacity  - kg of usable fuel
//  lowFuelKg - low-level caution threshold in kg; 0 for no caution on this tank
//  removable - 1 if the tank can be taken out; 0 is always fitted
//  role      - "main" (an engine can draw from it) or "xfer" (feeds the mains only)
//
//UH-60: two main cells, 547 kg each (the pre-1.1 config's fuelTankMass). The arms are ESTIMATES -
//the cells sit side by side under the cabin floor aft of the main rotor, roughly FS 410, which is
//1.75 m aft of the mast (y 1.81). Survey them on the model before trusting the CG.

    //CROSSFEED positions - which tank each engine feeds from in each valve position, by
    //tank variableName. The first entry is the default, and with no systems modelled nothing
    //moves the valve, so the aircraft runs in NORM: each engine on its own cell.
    numCrossfeedModes = 3;
    class CrossfeedModes {
        class Norm { position = "NORM"; engSources[] = {"no1Tank", "no2Tank"}; };
        class No1  { position = "NO1";  engSources[] = {"no1Tank", "no1Tank"}; };
        class No2  { position = "NO2";  engSources[] = {"no2Tank", "no2Tank"}; };
    };

    //XFER pump destinations, in main order. Nothing selects a transfer yet, so the pump stays off.
    xferDestinations[] = {"NO1", "NO2"};

    numFuelTanks = 2;
    class FuelTanks {
        class FuelTank01 {
            variableName = "no1Tank";
            arm[]     = {-0.600, 0.060,-0.900};
            capacity  = 547.0;
            lowFuelKg = 78.0;      //172 lb per cell
            removable = 0;
            role      = "main";
        };
        class FuelTank02 {
            variableName = "no2Tank";
            arm[]     = { 0.600, 0.060,-0.900};
            capacity  = 547.0;
            lowFuelKg = 78.0;
            removable = 0;
            role      = "main";
        };
    };

    numAuxTanks = 0;
