# 394. Decode String

## 📝 Énoncé
On reçoit une chaîne encodée du type `k[encoded_string]`, ce qui signifie que `encoded_string` doit être répété `k` fois. Il peut y avoir des encodages imbriqués, et l'entrée est toujours bien formée.

**Exemples :**
- Input: `"3[a]2[bc]"` → Output: `"aaabcbc"`
- Input: `"3[a2[c]]"` → Output: `"accaccacc"`
- Input: `"2[abc]3[cd]ef"` → Output: `"abcabccdcdcdef"`

## 💡 Stratégie
Utiliser deux piles (stacks) :
- Une pour stocker les coefficients `k`
- Une pour stocker les chaînes construites jusqu’à chaque `[`.

Quand on rencontre un `]`, on dépile et on reconstruit la chaîne jusqu’au niveau précédent.

## 🧠 Complexité
- Temps : O(n), avec n = taille de `s`, chaque caractère est traité au plus une fois.
- Espace : O(n), pour les piles.

## ⚠️ Pièges à éviter
- Ne pas oublier de gérer les nombres à plusieurs chiffres (ex: `"10[a]"`).
- Bien réinitialiser `k` et `currentString` au bon moment.
- Attention aux imbrications : `"3[a2[c]]"` doit produire `"accaccacc"` et non `"acacac"`.

## 💬 Ce que j’ai appris
- Manipuler les piles pour décoder une structure récursive.
- Identifier les bons moments pour stocker et récupérer les états intermédiaires.
- Gérer l’accumulation de chiffres pour `k`.

## ✅ Statut
Résolu le 03/08/2025 ✅