// The FLIR / sling-camera video as the MFDs show it: a ui() display rendered to the
// MFD overlay face (hct_h60_mfd_fnc_flirVideo "texture"). The camera renders at the
// monitor's aspect, so the picture is laid out per client from that aspect and the
// group clips what overflows the 4:3 screen - the raw render target on the face was
// squeezed into it, worst on ultrawide monitors.
class RscText;
class RscPicture;
class RscControlsGroupNoScrollbars;

class hct_h60_mfd_flirVideo {
    idd = -1;
    onLoad = "['onLoad', _this] call (missionNamespace getVariable 'hct_h60_mfd_fnc_flirVideo');";
    class ControlsBackground {
        class background: RscText {
            idc = -1;
            x = 0;
            y = 0;
            w = 1;
            h = 1;
            text = "";
            colorBackground[] = {0, 0, 0, 1};
        };
    };
    class Controls {
        class video: RscControlsGroupNoScrollbars {
            idc = 100;
            x = 0;
            y = 0;
            w = 1;
            h = 1;
            class Controls {
                class picture: RscPicture {
                    idc = 101;
                    x = 0;
                    y = 0;
                    w = 1;
                    h = 1;
                    text = "";
                    colorText[] = {1, 1, 1, 1};
                };
            };
        };
    };
};
