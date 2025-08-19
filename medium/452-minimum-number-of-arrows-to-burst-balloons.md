# 452. Minimum Number of Arrows to Burst Balloons

## 📝 Énoncé

On a des ballons représentés par des intervalles `[xstart, xend]` sur l’axe X. Une flèche tirée verticalement à la position `x` perce tous les ballons tels que `xstart <= x <= xend`. On veut **le nombre minimal de flèches** pour percer **tous** les ballons.

## 💡 Stratégie

**Greedy par extrémité droite (interval scheduling)** :

1. **Trier** les ballons par `xend` croissant.
2. **Tirer une première flèche** à `x = end` du premier ballon trié.
3. **Parcourir** les autres ballons :
   - S’ils **commencent** `<= x` (position actuelle de la flèche), **ils sont déjà percés** (chevauchement).
   - Sinon, **nouvelle flèche** à la fin (`end`) de ce ballon.

Raison : en tirant à l’extrémité droite la plus petite possible, on **maximise** le chevauchement couvert par chaque flèche — c’est le cœur de l’optimum.

## 🧠 Complexité

- **Temps** : `O(n log n)` (tri) + `O(n)` (scan) → `O(n log n)`
- **Espace** : `O(1)` hors tri

## ⚠️ Pièges à éviter

- **Mauvais tri** (par `start`) → sous-optimal.
- **Comparator avec soustraction** → risque d’overflow (utiliser `a[1] < b[1]`).
- **Ne pas gérer** le cas `n=1`.
- **Valeurs négatives** ou grandes bornes : rester en comparaisons simples, pas d’arithmétique risquée.

## 💬 Ce que j’ai appris

- Les problèmes de **minimisation de ressources** sur des intervalles s’attaquent souvent avec **un tri par extrémité** et un **greedy** simple.
- Tirer à `end` est une heuristique **optimalement prouvée** dans les problèmes de recouvrement d’intervalles.

## ✅ Statut

✅ Résolu — testé sur exemples fournis.
