# 746. Min Cost Climbing Stairs

## 📝 Énoncé

On a un tableau `cost` où `cost[i]` est le coût du iᵉ échelon d’un escalier.  
On peut commencer à l’index 0 ou à l’index 1, et à chaque fois on peut monter de **1 ou 2 marches** après avoir payé le coût.  
Objectif : déterminer le coût minimum pour atteindre le sommet.

## 💡 Stratégie

- **Observation** : Le coût pour atteindre la marche `i` dépend uniquement des deux marches précédentes.
- Utilisation d’un **DP bottom-up** :
  - `dp[i] = cost[i] + min(dp[i-1], dp[i-2])`
  - On peut optimiser l’espace en utilisant seulement deux variables (`prev1`, `prev2`).

## 🧠 Complexité

- Temps : **O(n)**
- Espace : **O(1)** (optimisation mémoire)

## ⚠️ Pièges à éviter

- Ne pas oublier que le sommet est **au-delà du dernier index**, donc la boucle va jusqu’à `n`.
- Bien gérer le fait qu’on peut commencer à `0` ou `1`.

## 💬 Ce que j’ai appris

- Comment réduire la mémoire d’un DP classique à deux variables.
- La logique du DP sur les problèmes de “chemin minimal” dans des structures linéaires.

## ✅ Statut

Résolu ✅
