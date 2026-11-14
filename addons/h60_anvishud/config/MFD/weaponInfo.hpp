#define MARGIN_L 0.02
TEXT_HMD_L(WEAPON_NAME,0.015,0.81+(SMALL_LINEHEIGHT*2))
    source = "weapon";
    sourceScale = 1;
    text = "";
};

TEXT_HMD_L(WEAPON_MODE,0.015,0.81+(SMALL_LINEHEIGHT*3))
    source="ammo";
    sourceScale=1;
};// MARGIN_L

class TurretDirection {
    type="line";
    width = 3;
    points[] ={
        {"PilotCameraToView", { 0.02, -0.015}, 1},
        {"PilotCameraToView", { 0,     0.015}, 1},
        {"PilotCameraToView", {-0.02, -0.015}, 1},
        {"PilotCameraToView", { 0.02, -0.015}, 1}
    }; // points
}; // TurretDirection
class laserOn {
    condition="laseron";
    class TurretDirection {
        type="line";
        width = 3;
        points[] ={
            {"PilotCameraToView", {-0.04, -0.04}, 1},
            {"PilotCameraToView", {-0.02, -0.02}, 1},{},
            {"PilotCameraToView", {0.04, 0.04}, 1},
            {"PilotCameraToView", {0.02, 0.02}, 1},{},
            {"PilotCameraToView", {-0.04,0.04}, 1},
            {"PilotCameraToView", {-0.02,0.02}, 1},{},
            {"PilotCameraToView", {0.04,-0.04}, 1},
            {"PilotCameraToView", {0.02,-0.02}, 1}
        }; // points
    }; // TurretDirection
}; // laserOn
