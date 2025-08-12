# 17. Letter Combinations of a Phone Number

## 📝 Énoncé
Étant donné une chaîne `digits` composée de chiffres entre `2` et `9`, retourner **toutes** les combinaisons de lettres possibles que ce numéro peut représenter (comme sur les claviers téléphoniques). Retourner le résultat dans **n’importe quel ordre**.

**Exemples**
- `digits = "23"` → `["ad","ae","af","bd","be","bf","cd","ce","cf"]`
- `digits = ""` → `[]`
- `digits = "2"` → `["a","b","c"]`

**Contraintes**
- `0 <= digits.length <= 4`
- `digits[i] ∈ ['2','9']`

## 💡 Stratégie
- **Paradigme** : Backtracking (DFS).  
- **Idée** : Chaque chiffre correspond à un set de lettres. On construit les combinaisons **caractère par caractère** en parcourant les positions de `digits`.  
- **Étapes** :
  1. Si `digits` est vide, retourner `[]` immédiatement (contrat de l’énoncé).
  2. Utiliser une table de mapping fixe (`2→abc`, `3→def`, …, `9→wxyz`).
  3. Lancer une fonction récursive `dfs(i)` :
     - Si `i == digits.size()`, on a construit une combinaison complète → on l’ajoute au résultat.
     - Sinon, on récupère les lettres associées à `digits[i]` et on boucle : on **ajoute une lettre**, on **descend** d’un niveau (`i+1`), puis on **retire** la lettre (backtrack).
- **Pourquoi ça marche** : On énumère exactement le produit cartésien des lettres de chaque chiffre, sans doublon ni omission.

## 🧠 Complexité
- **Temps** : O(3^n à 4^n), où `n = len(digits)` (chaque chiffre offre 3 ou 4 choix).  
- **Espace** : O(n) pour la pile d’appels + O(#solutions) pour stocker les résultats.

## ⚠️ Pièges à éviter
- **Mapping incorrect** (`3→"bcd"` au lieu de `"def"`) : casse tous les résultats.
- **Ne pas gérer le cas vide** (`digits == ""`) : l’énoncé exige de retourner `[]`, pas `[""]`.
- **Mutations de chaîne sans backtrack** : oublier de retirer le dernier caractère après l’appel récursif produit des chaînes corrompues.
- **Réutiliser un buffer global sans `reserve`** : pas bloquant mais coûteux. `reserve(digits.size())` est propre et performant.

## 💬 Ce que j’ai appris
- Le backtracking est **le** pattern canonique pour l’énumération de combinaisons contraintes.
- L’importance d’un **mapping source de vérité** (défini une seule fois, immuable).
- Les cas bord (chaîne vide) doivent être traités explicitement pour coller aux specs.

## ✅ Statut
Terminé ✅ – Solution backtracking propre et conforme.