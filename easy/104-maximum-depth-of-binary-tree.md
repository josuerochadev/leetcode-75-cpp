# 104. Maximum Depth of Binary Tree

## 📝 Énoncé
Étant donné la racine d’un arbre binaire, retourne sa profondeur maximale.

La profondeur maximale d’un arbre binaire est le nombre de nœuds le long du chemin le plus long du nœud racine jusqu’à la feuille la plus éloignée.

## 💡 Stratégie
On utilise la récursivité :

- Si le nœud est `nullptr`, on retourne 0 (cas de base).
- Sinon, on calcule la profondeur maximale de ses sous-arbres gauche et droit.
- On prend le maximum des deux et on ajoute 1 (le nœud courant).

C’est une approche classique de type **post-order traversal**.

## 🧠 Complexité

- Temps : `O(n)` — où `n` est le nombre de nœuds dans l’arbre (chaque nœud est visité une fois).
- Espace : `O(h)` — où `h` est la hauteur de l’arbre (profondeur de la pile récursive).

## ⚠️ Pièges à éviter

- Ne pas oublier le cas où `root == nullptr`.
- Bien comprendre que l’on mesure un **chemin en nombre de nœuds** (et non en arêtes).
- Éviter de recalculer des profondeurs inutilement.

## 💬 Ce que j’ai appris

- Approche récursive très élégante pour les arbres binaires.
- Révision de l’algorithme de parcours post-order.
- La définition exacte de la "profondeur" (vs hauteur).

## ✅ Statut

Résolu avec succès ✅