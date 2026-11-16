# Workflows

| Workflow | Runs on | What it does |
|---|---|---|
| `build.yml` - Validate & Build | every push to `Main` and `devbuild`, every PR, manual | **validate**: `tools/validate_tree.py` (include case, empty files, BOMs, PREP/file parity, addon layout, HEMTT portability rules) and, on PRs, the changelog-fragment check (`tools/changelog.py check`). **hemtt**: `hemtt check --pedantic`, then `hemtt build --no-bin`, uploaded as the `hatchet-<sha>-hemtt` artifact (14 days). Needs no Arma 3 Tools or secrets, so fork PRs build too. |
| `devbuild.yml` - Devbuild | PR label changes / pushes / closes, pushes to `Main` | Regenerates the `devbuild` branch from `Main` plus every open PR labeled "Ready for Testing", and stamps the next dev version (`tools/devbuild.json` can name the next Stable). The header of the file lists its one-time setup. |
| `release-drafter.yml` - Release Drafter | pushes to `Main` | Keeps the draft GitHub release up to date from merged PRs' "Release notes: ..." labels (`.github/release-drafter.yml`). |

Releases and Workshop pushes are local scripts, not workflows: `tools/push_dev.py`
(Dev) and `tools/build_stable.py` (Stable) - see `docs/RELEASE.md`.
