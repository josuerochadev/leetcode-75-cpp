# 136. Single Number

## 📝 Énoncé

On vous donne un tableau `nums` non vide d'entiers. Chaque élément apparaît **exactement deux fois**, sauf **un** élément qui apparaît **une seule** fois. Trouvez cet élément unique.

**Contraintes clés :**

- Temps linéaire `O(n)`
- Espace additionnel constant `O(1)`

## 💡 Stratégie

**XOR (⊕)**, propriétés:

- `x ⊕ x = 0`
- `x ⊕ 0 = x`
- Associatif et commutatif

En XORant tous les éléments, chaque paire s’annule (`a ⊕ a = 0`), et il reste **l’unique**.

`acc = 0
pour v dans nums:
acc = acc XOR v
return acc`

Pourquoi c’est optimal ?

- **O(n)** : un seul passage
- **O(1)** : une seule variable d’accumulation
- Gère **négatifs** et **grands entiers** (XOR bit-à-bit, pas d’overflow arithmétique)

## 🧠 Complexité

- Temps : `O(n)`
- Espace : `O(1)`

## ⚠️ Pièges à éviter

- Utiliser un `unordered_map`/`set` (viole l’espace `O(1)`).
- Trier le tableau (dégrade en `O(n log n)`).
- Penser que XOR ne marche pas avec des **négatifs** : c’est bitwise, donc ça marche.
- Initialiser l’accumulateur à autre chose que `0`.

## 💬 Ce que j’ai appris

- Les propriétés du XOR permettent de résoudre élégamment des problèmes de **paires** et d’**unicité** sans mémoire additionnelle.
- Penser **bitwise** est souvent la meilleure option sous contrainte d’espace constant.

## ✅ Statut

✅ Fini — 17/08/2025
