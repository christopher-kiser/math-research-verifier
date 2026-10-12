/-!
Project Erdős #64 — formal kernel-checkable eight-cycle assembly lemma.
Scope: symmetric adjacency supplied as a relation; this lemma asserts that
two internally disjoint four-edge paths with common endpoints form a simple C8.
The disjointness and all eight edges are explicit hypotheses, not inferred.
-/

namespace MathResearch.Erdos64

variable {V : Type} (adj : V → V → Prop)

def IsEightCycle (a x₁ x₂ x₃ b y₃ y₂ y₁ : V) : Prop :=
  ([a, x₁, x₂, x₃, b, y₃, y₂, y₁] : List V).Nodup ∧
  adj a x₁ ∧ adj x₁ x₂ ∧ adj x₂ x₃ ∧ adj x₃ b ∧
  adj b y₃ ∧ adj y₃ y₂ ∧ adj y₂ y₁ ∧ adj y₁ a

theorem eight_cycle_from_disjoint_four_paths
    {a x₁ x₂ x₃ b y₃ y₂ y₁ : V}
    (hd : ([a, x₁, x₂, x₃, b, y₃, y₂, y₁] : List V).Nodup)
    (h₁ : adj a x₁) (h₂ : adj x₁ x₂)
    (h₃ : adj x₂ x₃) (h₄ : adj x₃ b)
    (h₅ : adj b y₃) (h₆ : adj y₃ y₂)
    (h₇ : adj y₂ y₁) (h₈ : adj y₁ a) :
    IsEightCycle adj a x₁ x₂ x₃ b y₃ y₂ y₁ := by
  exact ⟨hd, h₁, h₂, h₃, h₄, h₅, h₆, h₇, h₈⟩

#print axioms eight_cycle_from_disjoint_four_paths

end MathResearch.Erdos64
