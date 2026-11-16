// RELEASE GUARD: refuse to build a release while the dev-only .sqfc exclude is active.
//
// .hemtt/project.toml carries a commented-out `"**/*.sqfc"` entry under [files] exclude.
// Un-commenting it makes -filePatching work during development (Arma prefers a .sqfc over
// its matching .sqf, so a PBO carrying bytecode silently ignores loose source edits). The
// exclude is global though, so a release built with it would ship PBOs without their
// compiled SQF. This fails the release loudly instead. (Ported from the AH-64D.)

let toml = HEMTT_RFS.join(".hemtt").join("project.toml");

if !toml.is_file() {
    return;
}

let contents = toml.open_file().read();

// an un-commented line mentioning sqfc: no '#' before the first 'sqfc'
let offending = false;
for line in contents.split("\n") {
    let at = line.index_of("sqfc");
    if at < 0 {
        continue;
    }
    let hash = line.index_of("#");
    if hash < 0 || hash > at {
        offending = true;
    }
}

if offending {
    fatal("RELEASE BLOCKED: the dev-only `**/*.sqfc` exclude is active in .hemtt/project.toml.\n" +
          "  Releasing with it would ship PBOs without precompiled SQF bytecode.\n" +
          "  Comment that exclude entry out again, then re-run the release.");
}

print("release guard: .sqfc exclude is not active, bytecode will be packed normally");
