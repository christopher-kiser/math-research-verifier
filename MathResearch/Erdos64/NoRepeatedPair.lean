/-!
Project Erdős #64: paths in distinct components cannot realize the same
pair of outside endpoints in a graph with no eight-cycle.
All internal-vertex disjointness assumptions are explicit.
-/
import MathResearch.Erdos64.PairPacking

namespace MathResearch.Erdos64

variable {V : Type}

theorem no_repeated_pair_of_no_eight_cycle
    (adj : V → V → Prop)
    (hno : ∀ (a x₁ x₂ x₃ b y₃ y₂ y₁ : V),
      ¬ IsEightCycle adj a x₁ x₂ x₃ b y₃ y₂ y₁)
    {a x₁ x₂ x₃ b y₃ y₂ y₁ : V}
    (hd : ([a, x₁, x₂, x₃, b, y₃, y₂, y₁] : List V).Nodup)
    (hfirst :
      adj a x₁ ∧ adj x₁ x₂ ∧ adj x₂ x₃ ∧ adj x₃ b)
    (hsecond :
      adj b y₃ ∧ adj y₃ y₂ ∧ adj y₂ y₁ ∧ adj y₁ a) :
    False := by
  apply hno a x₁ x₂ x₃ b y₃ y₂ y₁
  exact ⟨hd, hfirst.1, hfirst.2.1, hfirst.2.2.1,
    hfirst.2.2.2, hsecond.1, hsecond.2.1,
    hsecond.2.2.1, hsecond.2.2.2⟩

#print axioms no_repeated_pair_of_no_eight_cycle

end MathResearch.Erdos64
