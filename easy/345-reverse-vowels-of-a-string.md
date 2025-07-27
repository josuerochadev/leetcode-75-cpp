# 345. Reverse Vowels of a String

## 📝 Énoncé
On vous donne une chaîne de caractères `s`. Vous devez inverser uniquement les voyelles présentes dans la chaîne, en gardant les autres caractères à leur place.

Voyelles à considérer : `a, e, i, o, u` + leurs versions majuscules.

### Exemples
- Input: `"IceCreAm"` → Output: `"AceCreIm"`
- Input: `"leetcode"` → Output: `"leotcede"`

## 💡 Stratégie
Utiliser deux pointeurs (`left` et `right`) :
- `left` part du début, `right` part de la fin.
- On avance les deux pointeurs jusqu'à ce qu'on trouve une voyelle de chaque côté.
- On les échange, puis on continue jusqu'à ce que `left >= right`.

Pour vérifier rapidement si un caractère est une voyelle, on utilise un `unordered_set`.

## 🧠 Complexité
- **Temps :** O(n), où n est la taille de la chaîne.
- **Espace :** O(1), car l'ensemble des voyelles est constant.

## ⚠️ Pièges à éviter
- Ne pas oublier les voyelles **majuscules**.
- S’assurer de ne **pas dépasser** les indices de la chaîne.
- Bien utiliser `std::swap` pour échanger les caractères.

## 💬 Ce que j’ai appris
- Manipulation de chaînes avec deux pointeurs.
- Utilisation efficace de `unordered_set` pour vérifier une appartenance.
- Bien gérer les cas de majuscules/minuscules dans les chaînes.

## ✅ Statut
✅ Résolu le 2025-07-27.