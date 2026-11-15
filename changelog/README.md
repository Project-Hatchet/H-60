# Changelog fragments

One small file per pull request, instead of everyone editing the top of
`CHANGELOG-DEV.md` (which conflicted whenever two PRs were open).

**Add a file** `changelog/<pr-number>-<short-slug>.md` containing one `- ` bullet per
change, written for players, in the same voice as `CHANGELOG-DEV.md`:

```
- Fix the hoist hook staying stuck at the cabin for other players
- Add a "Stabilize Hook" keybind
```

Rules: bullets only (no headers, no version numbers - those are written at
release time), `.md` extension, the PR number first so the lines keep their
order. CI fails a PR that changes anything under `addons/` without a fragment,
unless the PR carries the `Release Notes: Ignore` label.

**What happens to it:** Dev builds list the pending fragments in their Workshop
note (`push_dev.py --note-from-fragments`) and in `DEVBUILD.md`. The release PR
runs `python tools/changelog.py assemble --version X.Y.Z --delete`, which writes
the bullets under `**X.Y.Z**` in `CHANGELOG-DEV.md` and removes the files.
Nothing else edits `CHANGELOG-DEV.md` on Main.

`python tools/changelog.py --help` for the lint / check / render / assemble commands.
