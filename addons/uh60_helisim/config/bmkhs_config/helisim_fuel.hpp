/////////////////////////////////////////////////////////////////////////////////////////////
// Fuel //////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

    //Each engine picks its tank with its own FUEL SYS lever - fuelSelector in helisim_engine.hpp

    xferDestinations[] = {"NO1", "NO2"};

    numFuelTanks = 3;
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
        class FuelTank03 {      //ERFS
            variableName = "erfsTank";
            arm[]     = {-0.047, 0.673,-0.272};
            capacity  = 608.0;  //200 US gal, estimate
            lowFuelKg = 0.0;
            removable = 1;
            role      = "xfer";
        };
    };

    numAuxTanks = 0;
