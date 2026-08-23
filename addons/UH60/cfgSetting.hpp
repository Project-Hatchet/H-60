class CfgSettings {
    class CBA {
        class Versioning {
            class UH60 {
                main_addon = "vtx_uh60"; // must name the CfgPatches class - "UH60" matched nothing, so the CBA version check never ran
                class Dependencies {
                    CBA[] = {"cba_main", {3,18,0}, "(true)"};
                    ACE[] = {"ace_main", {3,18,0}, "(true)"};
                };
            };
        };
    };
};
