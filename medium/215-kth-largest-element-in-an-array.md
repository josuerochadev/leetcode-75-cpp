# 215. Kth Largest Element in an Array

## 📝 Énoncé
Étant donné un tableau d’entiers `nums` et un entier `k`, retourner le `k`-ième **plus grand** élément du tableau (en ordre trié), **pas** le `k`-ième distinct. Idéalement, résoudre **sans trier** entièrement.

## 💡 Stratégie
- **Mapping indice** : le `k`-ième plus grand équivaut à l’indice `target = n - k` si le tableau était trié **croissant**.
- **Quickselect (Hoare)** : sélection d’ordre statistique en **O(n)** en moyenne, **in-place**, sans trier tout le tableau.
  - Choix d’un **pivot aléatoire** pour atténuer les pires cas.
  - **Partition (Lomuto)** : place le pivot à sa position finale comme si le tableau était trié croissant, éléments `<= pivot` à gauche, `> pivot` à droite.
  - Compare `newPivot` à `target` pour réduire l’intervalle de recherche.

Alternative robuste : **min-heap de taille k** (O(n log k)) si l’on privilégie la simplicité et la stabilité.

## 🧠 Complexité
- **Temps** : O(n) en moyenne ; O(n²) pire cas pathologique (pivot systématiquement mauvais).
- **Espace** : O(1) auxiliaire (in-place), hors stack ; ici version **itérative** donc pas de profondeur de récursion.

## ⚠️ Pièges à éviter
- Confondre `k`-ième **plus grand** avec `k`-ième **distinct** : on ne déduplique pas.
- Mauvais index cible : c’est `target = n - k` (tri croissant), pas `k - 1`.
- Partition incohérente (`<` vs `<=`) pouvant boucler ou mal placer le pivot.
- Oublier l’aléatoire → risque plus élevé de cas O(n²) sur données adverses.

## 💬 Ce que j’ai appris
- Quickselect fournit un **compromis optimal** quand on veut un ordre-statistique sans surcoût du tri complet.
- Le pivot aléatoire est un **levier de performance** simple contre les entrées dégénérées.
- Penser “indice cible” (`n - k`) clarifie toute la logique et évite les off-by-one.

## ✅ Statut
Implémenté (Quickselect itératif, pivot aléatoire). Tests de base OK.