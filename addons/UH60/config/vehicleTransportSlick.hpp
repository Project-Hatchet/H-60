class VehicleTransport {
    class Carrier {
        cargoBayDimensions[]		= {"VTV_slick_1", "VTV_slick_2"};	// Memory points in model defining cargo space
        disableHeightLimit			= 1;								// If set to 1 disable height limit of transported vehicles
        maxLoadMass					= 4100;							// Maximum cargo weight (in Kg) which the vehicle can transport
        cargoAlignment[]			= {"back", "right"};				// Array of 2 elements defining alignment of vehicles in cargo space. Possible values are left, right, center, front, back. Order is important.
        cargoSpacing[]				= {0.1, 0.1, 0.1};						// Offset from X,Y,Z axes (in metres)
        exits[]						= {"VTV_exit_1", "VTV_exit_2"};		// Memory points in model defining loading ramps, could have multiple
        unloadingInterval			= 2;								// Time between unloading vehicles (in seconds)
        loadingDistance				= 5;								// Maximal distance for loading in exit point (in meters).
        loadingAngle				= 60;								// Maximal sector where cargo vehicle must be to for loading (in degrees).
        parachuteClassDefault       = B_Parachute_02_F;					// Type of parachute used when dropped in air. Can be overridden by parachuteClass in Cargo.
        parachuteHeightLimitDefault = 50;								// Minimal height above terrain when parachute is used. Can be overriden by parachuteHeightLimit in Cargo.
    };
};
