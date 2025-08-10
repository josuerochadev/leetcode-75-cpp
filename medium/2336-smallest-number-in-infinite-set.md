# 2336. Smallest Number in Infinite Set

## 📝 Énoncé
On dispose d’un ensemble contenant tous les entiers positifs: [1, 2, 3, ...].  
Implémenter une classe `SmallestInfiniteSet` avec:
- `popSmallest()` → retire et renvoie le plus petit entier de l’ensemble.
- `addBack(num)` → réinsère `num` dans l’ensemble s’il n’y est plus.
- `SmallestInfiniteSet()` → initialise la structure.

Contraintes: `1 <= num <= 1000`, au plus 1000 appels combinés à `popSmallest` et `addBack`.

## 💡 Stratégie
**Idée clé:** séparer le flux naturel des entiers (1,2,3,...) d’un **stock de “retours”**.  
- On maintient un pointeur `next = 1` qui représente le **plus petit entier jamais encore “consommé”**.  
- Quand on fait `popSmallest()`:
  - S’il existe des nombres réinsérés plus petits que `next`, on les gère en priorité via un **min-heap** (tas min).
  - Sinon, on renvoie `next` et on fait `next++`.
- Quand on fait `addBack(num)`:
  - Réinsérer n’est utile **que si** `num` a déjà été “consommé” auparavant, c.-à-d. `num < next`.
  - Pour éviter les doublons, on garde un `unordered_set` qui mémorise ce qui est déjà dans le tas.

**Pourquoi c’est correct ?**  
- Tous les entiers ≥ `next` sont **implicitement présents** (pas besoin de les stocker).  
- Les seuls “trous” possibles sont les entiers **< `next`** déjà sortis : on les suit dans le min-heap.  
- Le min-heap garantit qu’on ressort toujours **le plus petit** parmi ces trous.

## 🧠 Complexité
- `popSmallest()` : `O(log k)` si le tas est non vide (k = taille du tas), sinon `O(1)`.  
- `addBack(num)` : `O(log k)` si insertion dans le tas, `O(1)` sinon.  
- Mémoire: `O(k)` pour le tas + set, où `k` ≤ nombre de réinsertions uniques actives.

## ⚠️ Pièges à éviter
- **Réinsérer un nombre déjà présent** dans le tas → utiliser un `set` pour dédupliquer.  
- **Réinsérer un nombre ≥ `next`** → inutile (il est déjà implicitement présent).  
- **Utiliser un set global pour “tous les entiers”** → impossible/inutile; on s’appuie sur `next`.

## 💬 Ce que j’ai appris
- Modéliser un ensemble infini via un **pointeur incrémental** + une structure auxiliaire pour les exceptions.  
- Trade-off classic “implicit stream + explicit corrections” → pattern réutilisable pour des files / infinités comptables.  
- Couplage **min-heap + hash set** pour assurer ordre + unicité.

## ✅ Statut
Implémenté, compilable côté LeetCode (classe seule).