# 338. Counting Bits

## 📝 Énoncé

Étant donné un entier `n`, retourner un tableau `ans` de longueur `n+1` tel que pour chaque `i` (0 ≤ i ≤ n), `ans[i]` soit le **nombre de 1** dans l’écriture **binaire** de `i`.

## 💡 Stratégie

- **DP via décalage** : `dp[i] = dp[i >> 1] + (i & 1)`.
  - `i >> 1` = `i` sans son dernier bit (division par 2).
  - `(i & 1)` = 1 si le dernier bit (LSB) de `i` vaut 1, sinon 0.
- On remplit `dp` en **une passe** de 1 à `n`, sans fonctions intégrées.

**Alternative (équivalente en perfs)**  

- **Lowbit clear** : `dp[i] = dp[i & (i - 1)] + 1` (supprime le bit à 1 le plus bas).

## 🧠 Complexité

- Temps : **O(n)**
- Espace : **O(n)** (pour le tableau des réponses)

## ⚠️ Pièges à éviter

- Utiliser `__builtin_popcount` → **interdit** pour le follow-up.
- Oublier `i = 0` : `dp[0] = 0`.
- Déborder le tableau (boucler `i` de **1** à `n`, `dp` a taille `n+1`).

## 💬 Ce que j’ai appris

- Le lien simple entre **division par 2** (décalage) et **parité** du LSB.
- Deux patterns DP de bit counting **canoniques** (shift vs lowbit).

## ✅ Statut

Préparé le **17/08/2025** — solution en O(n) sans built-ins.
