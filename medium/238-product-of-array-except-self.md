# 238. Product of Array Except Self

## 📝 Énoncé
On vous donne un tableau d’entiers `nums`. Vous devez retourner un tableau `answer` tel que `answer[i]` soit le produit de tous les éléments de `nums` sauf `nums[i]`, **sans utiliser la division** et en **O(n)** temps.

## 💡 Stratégie
On fait deux passages :
1. Calcul du produit de tous les éléments **à gauche** de chaque index.
2. Puis en partant de la fin, on multiplie avec le produit **à droite** de chaque index.

On garde tout dans le tableau de sortie pour respecter la contrainte d’**O(1)** espace supplémentaire.

## 🧠 Complexité
- Temps : `O(n)`
- Espace : `O(1)` (hors tableau de sortie)

## ⚠️ Pièges à éviter
- Ne pas utiliser de division.
- Attention à bien initialiser les produits à `1` (et non `0`).
- L’ordre des boucles est crucial : une va de gauche à droite, l’autre de droite à gauche.

## 💬 Ce que j’ai appris
- Comment combiner des préfixes et suffixes efficacement.
- Que l’on peut tout stocker dans le tableau de sortie pour optimiser la mémoire.
- L’importance de la direction des parcours dans les algorithmes de type accumulation.

## ✅ Statut
Résolu le 2025-07-27 ✅