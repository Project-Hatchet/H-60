# H-60 documentation

| Path | What it is |
|---|---|
| `IMPROVEMENT_PLAN.md` | The master plan: what the AH-64D and MH-47G reference projects teach, phases 0–6 (correctness fixes → base-class consolidation → deletions → HEMTT/CI → conventions → systems architecture → process), the cross-check against the public issue tracker, and sequencing/risk. Start here. |
| `H60_Improvement_Plan_Plain_English.pdf` | The master plan in plain English. |
| `phase-0/` | Correctness fixes. Phase 0 ships as one `fix/<slug>` branch and PR per bug, so the technical detail and verification live in the PR descriptions; the folder holds the plain-English summary PDF. |
| `phase-1/` | Base-class consolidation (**complete**, Stable 0.7.10): `PHASE_1_PLAN.md` (work packages, branch & PR strategy, do-NOT list, open items) and its rendered PDF reader copy. |
| `phase-2/` | Delete first (**in progress** on the HeliSim branch): `PHASE_2_PLAN.md`, the as-built record — re-audit numbers, the four PRs and their proofs, deferred items, the byte-identical verification method — and `H60_Phase_2_Plain_English.pdf`, the non-technical summary. |
| `phase-3/` | Build system (**planned**, not started): `PHASE_3_PLAN.md` — the HEMTT migration as staged, reversible work packages (equivalence harness → scouting pass → `.hemtt/` + tree fixes → build-for-build proof → four-step cut-over of CI, devbuild, Stable release and validators), the PBO-naming table, open rulings. A plain-English PDF follows when the phase ships. |
| `HATCHET.md` *(arrives with HeliSim, PR #632)* | HeliSim controls through Hatchet: the one path a cockpit switch takes from a click or keybind to HeliSim and back (Brad's integration note). |
| `HELISIM_TODO.md` *(arrives with HeliSim, PR #632)* | Open HeliSim items — Core features the H-60 waits on, framework follow-ups, H-60 tuning (flight director, control mixing, ground handling, MH-60S seats). |
| `phase-N/` | One folder per phase as each gets its detailed plan: `PHASE_N_PLAN.md` plus a rendered PDF, and `proof/` with verification reports once the phase is running. |

## Conventions

- File names in `SCREAMING_SNAKE_CASE.md` are the in-repo references; the matching `*.pdf` is the rendered plain-English or reader copy. When one changes, re-render the other.
- Each phase plan follows the same structure: Objective · Target end-state · Work packages (WP0 is always the verification harness) · Branch & PR strategy · Verification & acceptance · Do-NOT list · Risks & mitigations · Open items for Riverman.
- Design authority for systems work (Phase 5) is TM 1-1520-280-10 (UH-60M operator's manual). The TM and its digest are maintained outside the repo — ask Riverman for access.
- Generated API documentation (the `scons docs` NaturalDocs target) goes to `apidocs/`, which is gitignored — this folder is for written references only.
