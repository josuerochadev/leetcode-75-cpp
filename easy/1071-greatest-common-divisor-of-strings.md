# 1071. Greatest Common Divisor of Strings

## 📝 Énoncé

Pour deux chaînes `str1` et `str2`, retourner la plus grande chaîne `x` telle que `x` divise les deux chaînes. Cela signifie que `str1 = x + x + ...` et `str2 = x + x + ...`.

Exemples :

- `Input: str1 = "ABCABC", str2 = "ABC"` → `Output: "ABC"`
- `Input: str1 = "ABABAB", str2 = "ABAB"` → `Output: "AB"`
- `Input: str1 = "LEET", str2 = "CODE"` → `Output: ""`

---

## 💡 Stratégie

- Vérifier si `str1 + str2 == str2 + str1`. Si ce n’est pas le cas, il n’existe **aucun diviseur commun**.
- Sinon, la chaîne qui divise à la fois `str1` et `str2` est le **préfixe commun** de longueur égale à `gcd(len(str1), len(str2))`.
- On retourne donc `str1.substr(0, gcd(len1, len2))`.

---

## 🧠 Complexité

- **Temps :** `O(n + m)` pour la concaténation et le calcul du GCD, avec `n = |str1|`, `m = |str2|`
- **Espace :** `O(1)` (en dehors de la sortie)

---

## ⚠️ Pièges à éviter

- Ne pas oublier de vérifier l’égalité `(str1 + str2 == str2 + str1)` — c’est la clé de la validité du diviseur.
- Attention à bien utiliser `std::gcd` pour éviter d’écrire l’algorithme de l’Euclide manuellement.

---

## 💬 Ce que j’ai appris

- L’idée que deux chaînes partagent un "motif de base" implique une symétrie dans leur concaténation.
- Le GCD s’applique aussi aux longueurs de chaînes pour identifier un motif répété commun.

---

## ✅ Statut

Résolu avec succès en C++. Solution validée sur LeetCode.