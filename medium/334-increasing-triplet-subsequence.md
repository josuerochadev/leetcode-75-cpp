# 334. Increasing Triplet Subsequence

## 📝 Énoncé

Étant donné un tableau d'entiers `nums`, retournez `true` s’il existe des indices `(i, j, k)` tels que :
- `i < j < k`
- `nums[i] < nums[j] < nums[k]`

Sinon, retournez `false`.

**Exemples :**

```txt
Input: nums = [1,2,3,4,5]
Output: true

Input: nums = [5,4,3,2,1]
Output: false

Input: nums = [2,1,5,0,4,6]
Output: true
```

## 💡 Stratégie
On cherche à trouver trois éléments croissants avec un seul passage sur le tableau, et sans utiliser de mémoire supplémentaire.
**Idée :**
- Utiliser deux variables first et second :
  - first : le plus petit nombre rencontré jusqu’à présent
  - second : le plus petit nombre supérieur à first
  
À chaque itération :
- Si num <= first, on met à jour first
- Sinon si num <= second, on met à jour second
- Sinon, cela veut dire qu’on a trouvé un nombre plus grand que second, donc on a un triplet croissant.

## 🧠 Complexité
- ⏱️ Temps : O(n) — un seul passage sur le tableau
- 🧠 Espace : O(1) — aucune structure de données utilisée

## ⚠️ Pièges à éviter
- Ne pas confondre avec la nécessité de retourner le triplet lui-même — ici, seul le booléen true ou false est requis.
- Ne pas réinitialiser first et second inutilement.
- Ne pas supposer que les nombres sont triés ou uniques.

## 💬 Ce que j’ai appris
- On peut résoudre des problèmes de “sous-séquences croissantes” avec une approche en deux pointeurs sans utiliser de mémoire supplémentaire.
- Une seule boucle bien pensée peut suffire pour des problèmes de complexité élevée en apparence.

## ✅ Statut
Résolu le 2025-07-28 ✅