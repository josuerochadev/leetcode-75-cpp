# 1143. Longest Common Subsequence

## 📝 Énoncé

Étant donnés deux strings `text1` et `text2`, retourner la longueur de leur plus longue **sous-séquence commune (LCS)**.  
Une sous-séquence conserve l’ordre relatif des caractères mais peut en supprimer.

Exemples :

- `text1="abcde", text2="ace"` → LCS = `"ace"`, longueur = `3`.
- `text1="abc", text2="abc"` → LCS = `"abc"`, longueur = `3`.
- `text1="abc", text2="def"` → LCS inexistante, résultat = `0`.

Contraintes : `1 <= len(text1), len(text2) <= 1000`, lettres minuscules.

## 💡 Stratégie

**Programmation dynamique (DP) bottom-up** :

- Définir `dp[i][j]` = longueur de la LCS entre `text1[i:]` et `text2[j:]`.
- Transition :
  - Si `text1[i] == text2[j]` → `dp[i][j] = 1 + dp[i+1][j+1]`
  - Sinon → `dp[i][j] = max(dp[i+1][j], dp[i][j+1])`
- Initialisation : dernière ligne/colonne = `0`.
- Réponse : `dp[0][0]`.

Option **optimisée mémoire** : 1D (`O(min(n, m))`) en itérant à rebours sur la chaîne la plus courte.

## 🧠 Complexité

- Temps : `O(n * m)`
- Espace : `O(n * m)` (ou `O(min(n, m))` avec la variante 1D)

## ⚠️ Pièges à éviter

- ❌ Confondre **sous-séquence** et **sous-chaîne** (substring) : la sous-chaîne doit être contiguë, la sous-séquence non.
- ❌ Récursion sans mémoïsation → explosion exponentielle.
- ❌ Parcourir vers l’avant avec DP 1D → dépendances faussées. Toujours itérer **à rebours** pour 1D.
- ❌ Croire qu’on peut gloutonner (greedy) : contre-exemples classiques existent.

## 💬 Ce que j’ai appris

- La DP LCS est un cas d’école d’**alignement** de séquences.
- Le sens d’itération garantit la validité des dépendances (suffixes).
- L’optimisation mémoire 1D est simple une fois la transition comprise.

## ✅ Statut

Terminé ✅ – Solution tabulation 2D (avec variante 1D en commentaire).
