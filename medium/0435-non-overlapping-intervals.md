# 0435. Non-overlapping Intervals

## 📝 Énoncé

On reçoit un tableau `intervals` où chaque élément est `[start, end]`.  
Objectif: retourner le **nombre minimum d’intervalles à supprimer** pour que le reste **ne se chevauche pas**.  
Deux intervalles qui se touchent en un point (ex. `[1,2]` et `[2,3]`) **ne** se chevauchent **pas**.

## 💡 Stratégie

- **Insight**: Minimiser les suppressions ⇔ **maximiser le nombre d’intervalles non-chevauchants** conservés.
- **Greedy optimal**:
  1. **Trier par fin croissante** (`end`).
  2. **Garder** toujours l’intervalle qui **finit le plus tôt** (il laisse le plus de place aux suivants).
  3. Lorsqu’un intervalle **chevauche** le précédent gardé (`start < prevEnd`), on **le supprime** (on incrémente `removals`) et **on conserve** l’ancien `prevEnd` (car il est minimal grâce au tri).

Pourquoi ça marche ?  

- Le choix local « fin la plus petite » est **optimal** pour maximiser le nombre d’intervalles compatibles (preuve classique des problèmes d’ordonnancement par échéance).

## 🧠 Complexité

- **Temps**: `O(n log n)` à cause du tri.  
- **Espace**: `O(1)` (hors coût du tri in-place).

## ⚠️ Pièges à éviter

- Confondre « toucher » et « chevaucher » : `start < prevEnd` ⇒ chevauchement ; `start >= prevEnd` ⇒ **pas** de chevauchement (le cas `==` est **OK**).
- Trier par **start** au lieu de **end** casse l’optimalité.
- Tenter de « fusionner » les intervalles : ce problème ne demande **pas** la fusion, uniquement le **compte des suppressions**.
- Gérer correctement les bornes négatives (les valeurs peuvent être jusqu’à `-5e4`).

## 💬 Ce que j’ai appris

- La stratégie **greedy par date de fin** est un pattern récurrent (scheduling, activités compatibles).
- Compter les **suppressions** pendant la sélection greedy est plus simple que calculer « taille - maximum conservé ».

## ✅ Statut

Résolu ✅ – Solution `O(n log n)` propre et réutilisable.
