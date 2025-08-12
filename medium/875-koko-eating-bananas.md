# 875. Koko Eating Bananas

## 📝 Énoncé
On dispose de `piles` de bananes, `piles[i]` représentant la quantité dans la pile `i`. Koko choisit une vitesse entière `k` (bananes/heure). À chaque heure, elle choisit **une seule** pile et mange `k` bananes de cette pile (ou tout ce qui reste si moins de `k`). Elle veut **finir toutes les bananes** en au plus `h` heures.  
**Objectif :** retourner la **plus petite** vitesse entière `k` qui permet de terminer dans `h` heures.

## 💡 Stratégie
**Binary Search on Answer** (recherche binaire sur la réponse) :
- Observation clé : si une vitesse `k` est suffisante pour finir dans `h` heures, alors **toute vitesse > k** est également suffisante → **monotonicité**.
- On binaire‑recherche `k` entre un plancher et un plafond :
  - **Plancher (lower bound)** : `max(1, ceil(sum(piles)/h))` — vitesse minimale crédible.
  - **Plafond (upper bound)** : `max(piles)` — inutile d’aller au‑delà de la plus grosse pile.
- **Test de faisabilité** pour une vitesse `k` :
  - Heures nécessaires = `Σ ceil(piles[i] / k)` (division entière arrondie vers le haut par `(pile + k - 1) / k`).
  - Si `heures <= h` ⇒ `k` est faisable, on essaie plus petit. Sinon, on augmente `k`.

## 🧠 Complexité
- Soit `n = piles.length`, `M = max(piles)`.
- **Temps :** `O(n * log M)` — chaque étape de la recherche binaire parcourt `piles`.
- **Espace :** `O(1)`.

## ⚠️ Pièges à éviter
- **Arrondis** : bien utiliser `ceil` sans flottants → `(pile + k - 1) / k`.
- **Débordement** : accumuler le total d’heures en `long long`.
- **Bornes** : ne pas fixer `hi` au‑delà de `max(piles)` ; ne pas oublier que `lo` peut être optimisé par `ceil(sum/h)`.
- **Mauvaise monotonicité** : le test doit retourner `true` pour les `k` **suffisants**.

## 💬 Ce que j’ai appris
- Le pattern **“binary search on answer”** se déclenche quand on a une fonction de faisabilité monotone.
- L’optimisation de la borne basse accélère la convergence sans changer le résultat.
- Le **ceil entier** est un incontournable pour éviter les erreurs de `double`.

## ✅ Statut
Terminé ✅ – Solution en C++ implémentée et documentée.