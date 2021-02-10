class cabindoor_R {
    displayName = "Right Cabin Door";
    condition = "true";
    statement = "";
    selection = "cabindoor_R_handle";
    exceptions[] = {"isNotInside", "isNotSwimming"};
    distance = 10;
    class cabindoor_R_open {
        displayName = "Open";
        condition = "true";
        statement = "_target animateSource [""cabindoor_R"", 0];";
    }; // cabindoor_R_close
    class cabindoor_R_close {
        displayName = "Close";
        condition = "true";
        statement = "_target animateSource [""cabindoor_R"", 1];";
    }; // cabindoor_R_open
}; // cabindoor_R

class cabindoor_L: cabindoor_R {
    displayName = "Left Cabin Door";
    class cabindoor_L_open {
        displayName = "Open";
        condition = "true";
        statement = "_target animateSource [""cabindoor_L"", 0];";
    }; // cabindoor_R_close
    class cabindoor_L_close {
        displayName = "Close";
        condition = "true";
        statement = "_target animateSource [""cabindoor_L"", 1];";
    }; // cabindoor_R_open
}; // cabindoor_R
