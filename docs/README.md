# H-60 documentation

| Path | What it is |
|---|---|
| `IMPROVEMENT_PLAN.md` | The master plan: what the AH-64D and MH-47G reference projects teach, phases 0–6 (correctness fixes → base-class consolidation → deletions → HEMTT/CI → conventions → systems architecture → process), the cross-check against the public issue tracker, and sequencing/risk. Start here. |
| `H60_Improvement_Plan_Plain_English.pdf` | The master plan in plain English. |
| `phase-0/` | Correctness fixes. Phase 0 ships as one `fix/<slug>` branch and PR per bug, so the technical detail and verification live in the PR descriptions; the folder holds the plain-English summary PDF. |
| `phase-1/` | Base-class consolidation: `PHASE_1_PLAN.md` (work packages, branch & PR strategy, do-NOT list, open items) and its rendered PDF reader copy. |
| `phase-N/` | One folder per phase as each gets its detailed plan: `PHASE_N_PLAN.md` plus a rendered PDF, and `proof/` with verification reports once the phase is running. |

## Conventions

- File names in `SCREAMING_SNAKE_CASE.md` are the in-repo references; the matching `*.pdf` is the rendered plain-English or reader copy. When one changes, re-render the other.
- Each phase plan follows the same structure: Objective · Target end-state · Work packages (WP0 is always the verification harness) · Branch & PR strategy · Verification & acceptance · Do-NOT list · Risks & mitigations · Open items for Riverman.
- Design authority for systems work (Phase 5) is TM 1-1520-280-10 (UH-60M operator's manual). The TM and its digest are maintained outside the repo — ask Riverman for access.
- Generated API documentation (the `scons docs` NaturalDocs target) goes to `apidocs/`, which is gitignored — this folder is for written references only.
