# 1466. Reorder Routes to Make All Paths Lead to the City Zero

## 📝 Énoncé
On a `n` villes (0 à n-1) et `n-1` routes dirigées `connections[i] = [a, b]` signifiant une route de `a` vers `b`.  
Objectif : réorienter **le minimum** de routes pour que **toutes** les villes puissent atteindre la ville `0`.  
Retourner ce minimum.

## 💡 Stratégie
**Insight clé** : le graphe est un **arbre** (n-1 arêtes, connexe non cyclique).  
On construit un graphe **non dirigé** mais on tague chaque arête avec un bit qui dit si l’orientation originale est « à l’envers » par rapport au chemin vers `0`.

- Pour chaque `a -> b` donné :
  - Dans `adj[a]`, on pousse `(b, 1)` : si on va de `a` vers `b`, il faudra **inverser** cette arête pour la faire pointer vers `a` (et donc vers `0`).
  - Dans `adj[b]`, on pousse `(a, 0)` : dans l’autre sens, c’est déjà « bon » (pas d’inversion nécessaire).
- On fait un **BFS depuis 0** (safe stack vs DFS récursif, n ≤ 5e4).
- À chaque fois qu’on visite un voisin `(v, needsReverse)` encore non visité :
  - Si `needsReverse == 1` alors on **compte** une inversion.
- Le total est minimal car **chaque arête est comptée une seule fois** sur l’unique chemin vers `0`.

## 🧠 Complexité
- **Temps** : `O(n)` (on visite chaque arête deux fois en adjacence).
- **Mémoire** : `O(n)` pour l’adjacence + `O(n)` pour la visite.

## ⚠️ Pièges à éviter
- Penser en graphe **orienté** et tenter des plus courts chemins : inutile. L’arbre garantit un **chemin unique**.
- **DFS récursif** profond : risque de stack overflow selon environnement. **BFS** itératif = robuste.
- Oublier de marquer `visité` → boucles infinies (même si arbre, l’adjacence est bidirectionnelle).
- Compter deux fois la même arête : marquage `visité` côté **nœud** évite le double comptage.

## 💬 Ce que j’ai appris
- Taguer les arêtes lors de la conversion orienté → non orienté est un **pattern puissant** pour les problèmes d’orientation minimale.
- Sur les arbres, raisonner « depuis la racine 0 » simplifie radicalement la logique.

## ✅ Statut
- Implémenté en C++ (BFS), testé localement sur les exemples du problème.