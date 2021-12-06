class AceInteract {
    class cabindoor_R_Open {
        displayName = "Open Door";
        condition = "(_target animationPhase ""cabindoor_L"") > 0 ";
        statement = "_target animateSource [""cabindoor_R"", 0];";
        selection = "cabindoor_R_handle";
        exceptions[] = {"isNotInside", "isNotSwimming"};
        distance = 5;
    }; // cabindoor_R

    class cabindoor_R_Close: cabindoor_R_Open {
        displayName = "Close door";
        selection = "cabindoor_R_handle";
        condition = "(_target animationPhase ""cabindoor_R"") < 1 ";
        statement = "_target animateSource [""cabindoor_R"", 1];";
    };

    class cabindoor_L_Open: cabindoor_R_Open {
        selection = "cabindoor_L_handle";
        condition = "(_target animationPhase ""cabindoor_L"") > 0 ";
        statement = "_target animateSource [""cabindoor_L"", 0];";
    };

    class cabindoor_L_Close: cabindoor_L_Open {
        selection = "cabindoor_L_handle";
        condition = "(_target animationPhase ""cabindoor_L"") < 1 ";
        statement = "_target animateSource [""cabindoor_L"", 1];";
    };

    class set_skis : cabindoor_R_Open {
        displayName = "Install Skis";
        condition = "(_target animationPhase ""skis"") < 1";
        statement = "_target animate [""skis"", 1];";
    };

    class remove_skis : set_skis {
        displayName = "Uninstall Skis";
        condition = "(_target animationPhase ""skis"") > 0";
        statement = "_target animate [""skis"", 0];";
    };
};