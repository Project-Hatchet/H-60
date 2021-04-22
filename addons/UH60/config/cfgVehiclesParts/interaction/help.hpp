class help {
    condition = "vtx_uh60_ui_helpEnabled";
    class b_hidePlayer {
        positionType="coordinates";
        position[] = {0,5,-0.7};
        label="Toggle player body";
        radius=0.05;
        buttonUp="player hideObject !(isObjectHidden player);";
        clickSound="hatchet_Switch_Sound";
    }; // b_hidePlayer
};
