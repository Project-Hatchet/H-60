[
    "vtx_uh60_misc_setting_FoldInteractionComplexity", "LIST",
    [LSTRING(FoldInteractionComplexity), LSTRING(FoldInteractionComplexity_Tooltip)],
    ["UH-60M", "MISC"],
    [[0, 1], [
        LSTRING(FoldInteractionSingle),
        LSTRING(FoldInteractionSeparate)
    ], 0],
    true // isGlobal
] call CBA_fnc_addSetting;
