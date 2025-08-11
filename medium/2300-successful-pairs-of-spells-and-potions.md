# 2300. Successful Pairs of Spells and Potions

## 📝 Énoncé
On a deux tableaux positifs : `spells` (taille n) et `potions` (taille m).  
Une paire `(spell, potion)` est **réussie** si `spell * potion >= success`.  
Retourner, pour chaque `spell`, le **nombre de potions** formant une paire réussie avec lui.

## 💡 Stratégie
- Trier `potions` en ordre croissant.
- Pour un `spell` donné, la condition `spell * potion >= success` revient à `potion >= ceil(success / spell)`.
- Calculer `minPotion = (success + spell - 1) / spell` en **entiers 64-bit**.
- Chercher via **binary search** (`lower_bound`) le premier indice `i` tel que `potions[i] >= minPotion`.
- Le nombre de paires = `m - i`.

Alternative (non nécessaire ici) : trier aussi les `spells` avec leurs index d’origine et utiliser un pointeur de fin depuis la droite (two-pointers). Complexité similaire, code un peu plus verbeux.

## 🧠 Complexité
- Tri des potions : `O(m log m)`
- Pour chaque spell : `O(log m)`  
**Total** : `O(m log m + n log m)` avec `O(1)` mémoire additionnelle (hors sortie).

## ⚠️ Pièges à éviter
- **Overflow** : `success` peut aller jusqu’à `1e10`. Utiliser `long long` pour `success`, `spell`, `minPotion` et les produits implicites.
- **Division flottante** : éviter le `double` -> utiliser `ceil((double)success / spell)` peut introduire des erreurs ; préférer la formule entière `((success + spell - 1) / spell)`.
- **Ordre des spells** : ne pas trier `spells` si vous devez conserver l’ordre des réponses (ici on ne les trie pas).
- **Cas limites** :
  - `spell` = 1 → `minPotion = success`
  - `success` très grand → parfois `minPotion > max(potions)` ⇒ nombre de paires = 0

## 💬 Ce que j’ai appris
- Comment convertir une contrainte multiplicative en **seuil unidimensionnel** exploitable avec une recherche binaire.
- Le pattern `lower_bound` est un accélérateur massif pour convertir `O(n*m)` en `O(n log m)`.
- La **division entière plafonnée** `ceil_div(a, b)` s’écrit proprement `(a + b - 1) / b` en 64-bit.

## ✅ Statut
✅ Soumis et validé localement ; prêt pour LeetCode.