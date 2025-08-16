# 72. Edit Distance

## 📝 Énoncé

On veut le nombre minimal d’opérations (insertion, suppression, remplacement) pour transformer `word1` en `word2`.  
Ex.: `horse` → `ros` = 3.

## 💡 Stratégie

**Programmation dynamique (distance de Levenshtein).**  
On crée une table `dp` de taille `(n+1) x (m+1)` où `dp[i][j]` = coût min pour convertir `word1[0..i-1]` en `word2[0..j-1]`.

- **Bases :**
  - `dp[i][0] = i` (supprimer i caractères)
  - `dp[0][j] = j` (insérer j caractères)
- **Transition :**
  - Si `word1[i-1] == word2[j-1]` → `dp[i][j] = dp[i-1][j-1]`
  - Sinon → `dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])`
    - `dp[i-1][j]` = suppression
    - `dp[i][j-1]` = insertion
    - `dp[i-1][j-1]` = remplacement

Optionnel : optimisation mémoire à **O(min(n, m))** via deux lignes.

## 🧠 Complexité

- **Temps :** `O(n * m)`
- **Espace :** `O(n * m)` (ou `O(min(n,m))` optimisé)

## ⚠️ Pièges à éviter

- Indices : bien utiliser `i-1` / `j-1` pour l’accès aux caractères.
- Oublier d’initialiser la première ligne et la première colonne.
- Confondre les opérations (insertion vs suppression) : penser en termes de **source → cible**.

## 💬 Ce que j’ai appris

- La distance d’édition classique est un cas d’école de DP 2D.
- Les trois opérations se traduisent proprement par trois voisins dans la table.
- L’optimisation mémoire est simple une fois la relation de récurrence stabilisée.

## ✅ Statut

Implémenté, documenté, prêt à soumettre.
