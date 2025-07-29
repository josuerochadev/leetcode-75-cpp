# 392. Is Subsequence
## 📝 Énoncé
On vous donne deux chaînes de caractères `s` et `t`. Retournez `true` si `s` est une sous-séquence de `t`, sinon `false`.

Une sous-séquence est formée en supprimant certains caractères (ou aucun) **sans changer l’ordre des caractères restants**.

**Exemples :**
- Input: s = "abc", t = "ahbgdc" → Output: true
- Input: s = "axc", t = "ahbgdc" → Output: false

## 💡 Stratégie
Utiliser deux pointeurs :
- `i` pour `s`
- `j` pour `t`

On parcourt `t` et dès qu’on trouve un caractère qui correspond à `s[i]`, on avance dans `s`.  
Si on atteint la fin de `s`, alors tous ses caractères ont été trouvés dans `t` dans le bon ordre.

## 🧠 Complexité
- Temps : O(n), où n = taille de `t`
- Espace : O(1)

## ⚠️ Pièges à éviter
- Ne pas confondre **sous-séquence** avec **sous-chaîne**.
- Penser à gérer le cas où `s` est vide : c’est toujours une sous-séquence de n’importe quelle `t`.

## 💬 Ce que j’ai appris
- La logique des deux pointeurs est puissante pour comparer des séquences.
- Un problème simple mais fondamental pour bien comprendre les notions d’ordre et de sous-séquences.

## ✅ Statut
Résolu et compris.