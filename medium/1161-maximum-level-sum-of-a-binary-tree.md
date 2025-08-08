# 1161. Maximum Level Sum of a Binary Tree

## 📝 Énoncé
Étant donné la racine d’un arbre binaire, retourner le plus petit niveau `x` tel que la somme des valeurs des nœuds à ce niveau est maximale.  
Le niveau de la racine est 1, celui de ses enfants est 2, et ainsi de suite.

## 💡 Stratégie
On fait un parcours **BFS (Breadth-First Search)**, niveau par niveau, en utilisant une `queue`.  
À chaque niveau, on calcule la somme des valeurs, et on met à jour le `niveau_max` si la somme est la plus élevée rencontrée jusqu’ici.

## 🧠 Complexité
- Temps : `O(n)` — chaque nœud est visité une seule fois.
- Espace : `O(w)` — `w` est la largeur maximale de l’arbre (taille de la queue à son maximum).

## ⚠️ Pièges à éviter
- Ne pas confondre “niveau” avec “profondeur”.
- Ne pas oublier de comparer les sommes **strictement supérieures** pour garder le plus petit niveau possible.
- Ne pas oublier que `level` commence à 1, pas 0.

## 💬 Ce que j’ai appris
- Maîtrise du parcours en largeur (BFS) avec file.
- Optimisation de calculs sur chaque niveau.
- Prise en compte de la condition "smallest level" dans les égalités.

## ✅ Statut
Résolu avec succès ✅