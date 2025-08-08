# 547. Number of Provinces

## 📝 Énoncé

Il y a `n` villes représentées par une matrice `n x n` `isConnected`.  
- `isConnected[i][j] = 1` signifie que la ville `i` est directement connectée à la ville `j`.
- Deux villes connectées indirectement forment aussi une **province**.
- On veut retourner **le nombre de provinces**, c’est-à-dire de groupes de villes connectées entre elles (directement ou indirectement).

## 💡 Stratégie

C’est un problème classique de **graphe non orienté** représenté par une **matrice d’adjacence**.  
Chaque ville est un **nœud**, et `isConnected[i][j] == 1` est une **arête** entre les nœuds `i` et `j`.

On utilise une recherche en profondeur (**DFS**) pour visiter toutes les villes connectées à partir d’une ville non visitée.  
Chaque appel à DFS qui commence à une nouvelle ville non visitée compte pour une nouvelle **province**.

## 🧠 Complexité

- **Temps** : `O(n²)` car on visite chaque cellule au plus une fois.
- **Espace** : `O(n)` pour le tableau `visited`.

## ⚠️ Pièges à éviter

- Ne pas marquer une ville comme visitée => boucle infinie.
- Ne pas prendre en compte que `isConnected` est symétrique.
- Confondre ville et index de la matrice.

## 💬 Ce que j’ai appris

- Comment modéliser un graphe à partir d’une matrice d’adjacence.
- Appliquer DFS pour compter des composantes connexes.
- La récurrence de DFS dans un tableau `n x n`.

## ✅ Statut

Résolu avec succès ✅