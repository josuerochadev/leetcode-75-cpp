# 198. House Robber

## 📝 Énoncé

Vous devez voler le maximum d’argent dans une série de maisons alignées, en respectant la contrainte :  
**Impossible de voler deux maisons adjacentes**, sinon l’alarme se déclenche.  
On vous donne `nums`, un tableau où `nums[i]` est la somme d’argent dans la maison `i`.

## 💡 Stratégie

Utiliser la programmation dynamique (DP) pour prendre la meilleure décision à chaque étape :

- **Choisir de voler la maison i** : gains = `nums[i] + dp[i-2]`
- **Ne pas voler la maison i** : gains = `dp[i-1]`
- Base :
  - `dp[0] = nums[0]`
  - `dp[1] = max(nums[0], nums[1])`
- Optimisation mémoire : on garde seulement les deux derniers résultats (`prev1`, `prev2`).

## 🧠 Complexité

- **Temps** : O(n) — on parcourt chaque maison une seule fois.
- **Espace** : O(1) — on n’utilise que deux variables pour stocker l’état.

## ⚠️ Pièges à éviter

- Oublier de gérer les cas `n = 0` ou `n = 1`.
- Penser à optimiser la mémoire (inutile d’utiliser un tableau `dp[]` complet).
- Ne pas confondre `prev1` et `prev2` dans la boucle.

## 💬 Ce que j’ai appris

- Modéliser un problème réel en termes de choix optimaux (voler ou non une maison).
- Utiliser la technique "DP avec espace constant".
- Importance des **cas de base** pour éviter les segfaults.

## ✅ Statut

✅ Résolu et testé.
