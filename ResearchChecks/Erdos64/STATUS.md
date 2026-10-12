# Erdős #64 — verification checkpoint (2026-10-12)

Scope: an induced path P13, four distinct outside vertices with arbitrary adjacency among the outside vertices. To prove a necessary minimum of five outside neighbors, remove outside-outside edges (which cannot alter the degree contributions to P13 or create a cycle). The resulting outside set is independent.

A length-13 bit mask gives each outside vertex's neighbors on the path. Distance-2 or distance-6 repeated attachment positions generate C4 or C8, hence are excluded. Two external vertices with at least two shared path neighbors generate C4. Exact screening checks all C4 and C8 within each pair. Four multisets of masks (not necessarily distinct) are enumerated in sorted order, and all path vertices must receive sufficient additional outside neighbors (two at each endpoint, one at each internal vertex).

Latest C++ reproduction, run locally in the assistant container on 2026-10-12:
- 400 individual masks
- 506,998 pair-compatible triples (corrected)
- 8,099,222 pair-compatible quadruples
- zero quadruples supplying the complete P13 degree requirements

**Correction:** Earlier M192 narration reported 501,798 triples, but the archived enumerator rerun returned **506,998**; the final quadruple count and exclusion did not change. The CI workflow tests these exact outputs.

Status: **exhaustively computed, not yet independently reimplemented, not Lean-certified.** The exact finite universe and necessary-condition reduction must be audited prior to calling this a fully verified theorem. The result does not solve Erdős–Gyárfás.

Research process: do not prioritize Lean translation of brute-force code until a meaningful checker/finite certificate or a proof of the completeness of its enumeration is ready. Run the C++ regression on changes, and use Lean for mathematically stable, high-value lemmas.
