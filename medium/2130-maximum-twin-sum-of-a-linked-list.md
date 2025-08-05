# 2130. Maximum Twin Sum of a Linked List

## 📝 Énoncé

Dans une liste chaînée de taille paire, on définit les paires "jumelles" comme suit : le nœud `i` est le jumeau du nœud `n - 1 - i`. Le "twin sum" est la somme de deux jumeaux. Retourne la valeur maximale de ces twin sums.

[Voir l’énoncé sur LeetCode](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)

## 💡 Stratégie

1. Utiliser deux pointeurs (`slow` et `fast`) pour trouver le milieu de la liste.
2. Inverser la deuxième moitié de la liste.
3. Repartir du début de la liste et de la fin inversée, et calculer les sommes des paires.
4. Garder la somme maximale observée.

## 🧠 Complexité

- Temps : `O(n)`
- Espace : `O(1)` (in-place reversal)

## ⚠️ Pièges à éviter

- Ne pas oublier que `fast` doit aller deux fois plus vite pour atteindre la fin pendant que `slow` atteint le milieu.
- Bien gérer l’inversion de la deuxième moitié (classique erreur de pointeur).
- Ne pas perdre le lien avec la tête de la liste.

## 💬 Ce que j’ai appris

- Manipuler une liste chaînée efficacement en deux passes.
- Inverser une liste en place.
- Optimiser sans utiliser de tableau temporaire.

## ✅ Statut

Fait le 05/08/2025.