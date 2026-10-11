# Building and releasing the H-60

The pack is built with [HEMTT](https://hemtt.dev). One command builds it, one script pushes a Dev build, one script prepares a Stable package. Nothing here signs or uploads to Stable; those two steps stay by hand on purpose.

## Everyday builds

```
python tools/validate_tree.py   # include case, empty files, BOMs, PREP parity, HEMTT portability rules; the CI validate job
hemtt check            # lints and parses every config, script and stringtable; the CI gate
hemtt build            # .hemttout/build - the mod folder, 25 PBOs
hemtt launch           # .hemtt/launch.toml profiles (when they exist)
```

`hemtt build --no-bin` is what the Linux CI job runs. Since every model and animation in the tree is committed binarized, `--no-bin` changes nothing and the CI artifact is byte-identical to a local build. The Windows SCons job and `SConstruct` remain only until the HEMTT output has shipped one Stable (plan WP4e); do not use them for new work.

Install HEMTT with `winget install BrettMayson.HEMTT`. The scripts below find it on PATH or in the winget package folder.

## Versioning

One source: `addons/main/script_version.hpp` (`MAJOR`, `MINOR`, `PATCHLVL`, `BUILD`). HEMTT reads it directly and stamps every PBO header with it. Stable releases are `X.Y.Z.0`; Dev builds carry the *next* Stable's number with `BUILD` counting up, stamped by the devbuild bot on the generated `devbuild` branch (`tools/build.json` names the next Stable when it is a minor/major bump).

## Dev builds (Workshop Development branch)

The `devbuild` branch is machine-generated: Main plus every open PR labeled **Ready for Testing**, rebuilt by the bot on every label change and on every push to Main. `DEVBUILD.md` at its root lists what it contains. CI builds it; the Workshop push is a person running:

```
python tools/push_dev.py --branch devbuild --note-from-prs --dry-run   # build + verify, no upload
python tools/push_dev.py --branch devbuild --note-from-prs --yes       # upload
```

`push_dev.py` refuses a dirty working tree and a local `devbuild` that differs from origin (the bot force-pushes it), builds with `hemtt build`, replaces `release/@H-60` with the output plus a Development-branch `mod.cpp`, verifies one fresh PBO per addon, and uploads through `PublisherCmd` with the Steam client logged in on the machine. The Workshop note lists the PRs under test with links. Post the player-facing changelog to Discord after the push.

Branch pushes outside the devbuild flow (`--branch release/x.y.z --note-from-changelog --bump`) still work as before: they stamp the version into the branch and use the top `CHANGELOG-DEV.md` block as the note.

## Stable releases

Everything that a Stable needs in git lands in **one release PR** to Main from a `release/<version>` branch: `script_version.hpp` set to `X.Y.Z` with `BUILD 0`, the `**X.Y.Z**` block prepended to `CHANGELOG.md`, the matching `CHANGELOG-DEV.md` block, the README version badge, plan-record and documentation bookkeeping for the cycle, and removal of `devNextVersion` from `tools/build.json` if it names this release. Merge it first; a package built before that carries the old version.

Then:

```
python tools/build_stable.py --branch Main
```

runs `hemtt release` (unsigned, archived), verifies 25 PBOs whose headers all carry the release version, confirms the repo-root Stable `mod.cpp` is the one shipped and that no signatures slipped in, and copies the mod folder and the versioned zip to `OneDrive\Documents\Hatchet\H-60\Releases\Stable Branch\<version>\`. `--dest` overrides the folder, `--force` replaces an existing one.

By hand, in this order:

1. **Sign.** DSSignFile with a new key pair for the release (`hatchet_h60_<version>`); `.bisign` beside every PBO, the `.bikey` in `@H-60\keys\`. Dev builds are never signed.
2. **Upload** the signed `@H-60` to the Stable Workshop item.
3. **GitHub release** from the Release Drafter draft (retitle and tag `v<version>`; label merged PRs so the notes are complete; add any direct commits by hand).
4. **Announce** with the Stable changelog.

## Proving a build-system change

Two tools exist for the question "did the build change what ships?":

- `tools/pbo_compare.py compare <addons A> <addons B>` — manifest and header comparison of two output folders, with the known packer differences classified; anything unexpected fails.
- `tools/config_dump/` — the in-game config dump plus `compare_dumps.py`, which compares captured values and tolerates the documented serialisation differences. It is the only check that sees a value change inside `config.bin`.

Run both for any change to how configs are produced. The Phase 3 proof (`docs/phase-3/proof/equivalence-85944de.md`) is the worked example.
