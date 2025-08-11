# 374. Guess Number Higher or Lower

## 📝 Énoncé
On joue à un jeu où l’on doit deviner un nombre choisi entre 1 et n.
On utilise une API `guess(int num)` qui :
- retourne `-1` si notre nombre est trop grand,
- retourne `1` si notre nombre est trop petit,
- retourne `0` si c’est le bon nombre.

Trouver ce nombre.

## 💡 Stratégie
Utiliser **recherche binaire** :
- On commence avec `left = 1` et `right = n`.
- On calcule `mid` et on demande à l’API.
- Selon le retour :
  - `0` → trouvé, on retourne `mid`.
  - `-1` → le nombre est trop grand, on réduit `right`.
  - `1` → le nombre est trop petit, on augmente `left`.
- On répète jusqu’à trouver la réponse.

## 🧠 Complexité
- Temps : **O(log n)**, car on divise la plage de recherche par deux à chaque étape.
- Mémoire : **O(1)**, car on n’utilise que quelques variables.

## ⚠️ Pièges à éviter
- Calculer `mid` avec `left + (right - left) / 2` pour éviter l’overflow.
- Bien mettre à jour `left` et `right` sinon risque de boucle infinie.
- Ne pas oublier que l’API est déjà fournie par LeetCode (ne pas l’implémenter soi-même).

## 💬 Ce que j’ai appris
- Comment utiliser la recherche binaire sur une plage connue.
- L’importance d’éviter l’overflow avec `mid`.
- L’usage d’une API fournie par LeetCode dans la solution.

## ✅ Statut
Résolu ✅