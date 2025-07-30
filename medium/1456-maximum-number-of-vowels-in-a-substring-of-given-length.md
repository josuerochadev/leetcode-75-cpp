# 1456. Maximum Number of Vowels in a Substring of Given Length

## 📝 Énoncé
On vous donne une chaîne `s` et un entier `k`. Retournez le nombre maximal de voyelles présentes dans une sous-chaîne de `s` de longueur exactement `k`.

Les voyelles sont `a`, `e`, `i`, `o`, `u`.

## 💡 Stratégie
Utiliser une **fenêtre glissante de taille fixe `k`** pour parcourir `s` une seule fois.

- Initialiser le compteur de voyelles pour la première fenêtre.
- Glisser la fenêtre de gauche à droite :
  - Ajouter 1 si le nouveau caractère est une voyelle.
  - Soustraire 1 si le caractère sortant était une voyelle.
  - Garder le maximum global.

## 🧠 Complexité
- Temps : O(n)
- Espace : O(1)

## ⚠️ Pièges à éviter
- Ne pas oublier de retirer la voyelle sortante.
- Bien vérifier les indices quand la fenêtre dépasse `k`.
- Attention aux chaînes très courtes ou très longues.

## 💬 Ce que j’ai appris
- Sliding window : efficace pour les sous-chaînes de taille fixe.
- Optimisation importante face à une approche naïve en O(n*k).

## ✅ Statut
Résolu ✅ — testé avec succès.