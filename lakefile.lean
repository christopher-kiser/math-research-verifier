import Lake
open Lake DSL

package mathResearch where

lean_lib MathResearch where
  roots := #[`MathResearch.Smoke, `MathResearch.Erdos64.PairPacking, `MathResearch.Erdos64.NoRepeatedPair]
