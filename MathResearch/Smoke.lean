namespace MathResearch

theorem and_comm_nat (p q : Prop) : (p ∧ q) → (q ∧ p) := by
  intro h
  exact ⟨h.2, h.1⟩

#print axioms MathResearch.and_comm_nat

end MathResearch
