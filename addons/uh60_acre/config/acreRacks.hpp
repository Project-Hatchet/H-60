
class AcreRacks {
    class Comm_1 {
        displayName = "Comm 1 - AN/ARC-201";            // Name displayed in the interaction menu
        shortName = "COMM1";                                     // Short name displayed on the HUD. Maximum of 5 characters
        componentName = "ACRE_VRC103";                // Able to mount a PRC152
        allowedPositions[] = {"driver", {"turret", {0}}}; // Who can configure the radio and open the radio GUI. Same wildcards as the intercom. It also allows transmitting/receiving
        disabledPositions[] = {};
        defaultComponents[] = {};                         // Use this to attach simple components like Antennas. Not yet fully implemented
        mountedRadio = "ACRE_PRC117F";                                        // Predefined mounted radio
        isRadioRemovable = 0;                                 // Radio can be removed
        intercom[] = {"Intercom_1"};                                            // Radio not wired to any intercom. All units in intercom can receive/send transmittions (ACE3 interaction menu) but they cannot manipulate the radio (GUI interface)
    };
    class Comm_2: Comm_1 {
        displayName = "Comm 2 - AN/ARC-231";            // Name displayed in the interaction menu
        shortName = "COMM2";                                     // Short name displayed on the HUD. Maximum of 5 characters
    };
    class Comm_3: Comm_1 {
        displayName = "Comm 3 - AN/ARC-231";            // Name displayed in the interaction menu
        shortName = "COMM3";                                     // Short name displayed on the HUD. Maximum of 5 characters
    };
    class Comm_4: Comm_1 {
        displayName = "Comm 4 - AN/ARC-201";            // Name displayed in the interaction menu
        shortName = "COMM4";                                     // Short name displayed on the HUD. Maximum of 5 characters
    };
    class Rack_TC {
        displayName = "TC Coax";            // Name displayed in the interaction menu
        shortName = "TC";                                     // Short name displayed on the HUD. Maximum of 5 characters
        componentName = "ACRE_VRC111";                // Able to mount a PRC152
        allowedPositions[] = {{"cargo", 9}}; // Who can configure the radio and open the radio GUI. Same wildcards as the intercom. It also allows transmitting/receiving
        disabledPositions[] = {};
        defaultComponents[] = {};                         // Use this to attach simple components like Antennas. Not yet fully implemented
        mountedRadio = "";                                        // Predefined mounted radio
        isRadioRemovable = 1;                                 // Radio can be removed
        intercom[] = {};                                            // Radio not wired to any intercom. All units in intercom can receive/send transmittions (ACE3 interaction menu) but they cannot manipulate the radio (GUI interface)
    };
};
class AcreIntercoms {
    class Intercom_1 {                                                         // Each entry defines a network
        displayName = "Intercommunications system";                         // Name of the intercom network displayed to the players
        shortName = "ICS";
        // "all" is a wildcard that selects, in this case, all turrets (not including ffv)
        allowedPositions[] = {"crew", {"turret", {0}}};
        // Commander FFV turret and turret positions [1] and [2] do not have access to crew intercom
        disabledPositions[] = {};
        // Noone else can have access to this intercom network
        limitedPositions[] = {{"cargo", "all"}};
        // This is the number of simultaneous connections that units defined in the previous array can have (default: 0)
        numLimitedPositions = 2;
        // Seats with master stations have the possibility of broadcasting a message in that network (default: {})
        masterPositions[] = {"driver", {"turret", {0}}};
        connectedByDefault = 1;
    };
};
