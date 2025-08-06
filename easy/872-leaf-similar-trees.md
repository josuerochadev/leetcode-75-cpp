# 872. Leaf-Similar Trees

## 📝 Énoncé

Deux arbres binaires sont "leaf-similar" si la séquence des valeurs de leurs feuilles (de gauche à droite) est identique.  
Écrire une fonction qui prend deux racines d’arbres binaires et retourne `true` si les arbres sont leaf-similar.

[Voir l’énoncé sur LeetCode](https://leetcode.com/problems/leaf-similar-trees/)

---

## 💡 Stratégie

1. Parcourir les deux arbres en profondeur (DFS).
2. À chaque feuille rencontrée, ajouter sa valeur à une liste dédiée à chaque arbre.
3. Comparer les deux listes de feuilles à la fin : si elles sont identiques, les arbres sont leaf-similar.

---

## 🧠 Complexité

- Temps : `O(N + M)`  
  Où `N` et `M` sont le nombre de nœuds dans chaque arbre (parcours complet de chaque arbre).
- Espace : `O(L1 + L2)`  
  Où `L1` et `L2` sont le nombre de feuilles de chaque arbre.

---

## ⚠️ Pièges à éviter

- Attention à bien comparer la séquence **dans l’ordre** gauche à droite.
- Ne pas confondre feuille (nœud sans enfants) et nœud interne.
- Penser à gérer les arbres avec une seule feuille ou totalement asymétriques.

---

## 💬 Ce que j’ai appris

- Renforcement du parcours DFS et manipulation de listes de résultats.
- Pratique du pattern "collect & compare" sur des structures arborescentes.
- Importance de bien isoler la logique de collecte de feuilles pour la réutilisation/testabilité.

---

## ✅ Statut

Résolu, testé, documenté.