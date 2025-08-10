# 2542. Maximum Subsequence Score
## 📝 Énoncé
On te donne deux tableaux `nums1` et `nums2` de même taille `n` et un entier positif `k`.  
Tu dois choisir un sous-ensemble d’indices de taille `k`.  
Le score de ce sous-ensemble est:

`(sum(nums1[i] pour les indices choisis)) * (min(nums2[i] pour ces mêmes indices))`

Objectif: retourner le score maximal possible.

## 💡 Stratégie
**Insight clé (greedy + heap)**  
1) Coupler chaque position: `(nums2[i], nums1[i])`.  
2) **Trier** ces paires par `nums2` **en ordre décroissant**.  
   - Ainsi, quand on se positionne sur une paire de `nums2 = m`, on sait que toutes les paires déjà vues ont un `nums2 ≥ m`.  
   - Si on prend un sous-ensemble uniquement parmi les éléments déjà vus, **le minimum** de leurs `nums2` sera **exactement `m`** (puisque `m` est le plus petit rencontré jusqu’ici).
3) Pour **maximiser** le score `m * somme(nums1_choisis)`, on veut **maximiser la somme de `nums1`** pour `k` éléments.  
   - On maintient un **min-heap** (taille ≤ `k`) avec les `nums1` déjà rencontrés et une **somme courante**.  
   - À chaque nouvelle paire, on push `nums1` dans le heap et on ajuste: si on dépasse `k`, on pop le plus petit (on garde les `k` plus gros `nums1`).  
   - Quand la taille du heap vaut `k`, on calcule le score candidat: `somme_courante * nums2_courant`.
4) On prend le maximum global sur tout le parcours.

**Pourquoi c’est optimal ?**  
- On **fixe** le minimum `m` (en parcourant `nums2` décroissant) puis on **optimise** la somme de `nums1` via un **top-k** (min-heap).  
- Tout autre choix qui mélangerait des `nums2` plus petits que `m` ferait chuter le min, donc il est préférable d’**empiler les meilleurs `nums1`** disponibles au moment où `m` est défini.

## 🧠 Complexité
- Tri: `O(n log n)`  
- Parcours + heap (taille ≤ `k`): `O(n log k)`  
- **Global:** `O(n log n)` temps, `O(k)` mémoire.

## ⚠️ Pièges à éviter
- **Débordements**: utiliser `long long` pour la somme et le produit.  
- **Ordre de tri**: c’est **par `nums2` décroissant**, pas croissant.  
- **Gestion du heap**: on doit **retirer** le plus petit quand la taille dépasse `k`.  
- **k = 1**: le score est `max(nums1[i] * nums2[i])`. L’algorithme gère naturellement ce cas.

## 💬 Ce que j’ai appris
- Le pattern “**fixer le min via tri décroissant**” + “**maximiser une somme via top-k (min-heap)**” est un **levier puissant**.  
- Penser en **deux étages**: (1) ordonner pour contrôler le minimum, (2) structure de données pour maximiser la somme.

## ✅ Statut
✅ Fini — 10/08/2025