//UH-60 HeliSim configuration. Core reads this class.

class BMKHS_HeliSim {
    //No systems modelled yet: no electrical, APU, hydraulics or drivetrain components, no
    //HeliSim cockpit controls. The stock H-60 cockpit runs as before; its start sequence turns
    //the engine on, and Core spools both engines from that.
    useSystems = 0;

    //How many engines. No hitpoints are declared, so this is where the count comes from.
    numEngines = 2;

    #include "bmkhs_config\helisim_airfoils.hpp"
    #include "bmkhs_config\helisim_engine.hpp"
    #include "bmkhs_config\helisim_flightControls.hpp"
    #include "bmkhs_config\helisim_fuel.hpp"
    #include "bmkhs_config\helisim_fuselage.hpp"
    #include "bmkhs_config\helisim_mass.hpp"
    #include "bmkhs_config\helisim_misc.hpp"
    #include "bmkhs_config\helisim_rotor.hpp"
    #include "bmkhs_config\helisim_simpleRotor.hpp"
    #include "bmkhs_config\helisim_wings.hpp"
};
