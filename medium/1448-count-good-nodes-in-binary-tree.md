# 1448. Count Good Nodes in Binary Tree

## 📝 Énoncé

Un nœud est "bon" si, sur le chemin depuis la racine jusqu’à lui, aucun nœud n’a une valeur plus grande.  
Retourner le nombre total de "bons" nœuds dans un arbre binaire.

## 💡 Stratégie

On parcourt l’arbre en profondeur (`DFS`) en gardant, à chaque étape, la **valeur maximale rencontrée jusqu'à présent** sur le chemin depuis la racine.  
À chaque nœud :
- S’il est **supérieur ou égal** à cette valeur maximale, il est "bon".
- Ensuite, on met à jour cette valeur max pour les appels récursifs à gauche et à droite.

## 🧠 Complexité

- ⏱ Temps : `O(n)` — chaque nœud est visité une seule fois.
- 🧠 Espace : `O(h)` — pile d'appels récursive, `h` étant la hauteur de l’arbre (`O(log n)` pour un arbre équilibré, `O(n)` au pire).

## ⚠️ Pièges à éviter

- Ne pas oublier de mettre à jour `maxSoFar` à chaque niveau.
- Toujours comparer `node->val` avec `maxSoFar`, pas l’inverse.
- Ne pas oublier de gérer le cas de base (`if (!node)`).

## 💬 Ce que j’ai appris

- Utiliser le DFS récursif avec un paramètre accumulé (`maxSoFar`) est une technique puissante pour propager des conditions dans un arbre.
- L’importance d’une bonne initialisation : ici, on commence avec la valeur du `root`.

## ✅ Statut

Résolu le 06/08/2025 ✅