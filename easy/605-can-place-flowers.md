# 605. Can Place Flowers

## 📝 Énoncé
On te donne un tableau `flowerbed` représentant une rangée où `0` = vide et `1` = fleur déjà plantée. Tu dois retourner `true` s’il est possible de planter `n` nouvelles fleurs sans qu’aucune fleur ne soit adjacente à une autre.

## 💡 Stratégie
On applique une approche "gourmande" :
- À chaque emplacement vide, on vérifie si les cases adjacentes sont aussi vides.
- Si oui, on "plante" une fleur (on modifie le tableau).
- Si on atteint `n == 0`, on retourne `true`.

## 🧠 Complexité
- Temps : O(n), où n = taille du tableau `flowerbed`
- Espace : O(1) (modification en place)

## ⚠️ Pièges à éviter
- Ne pas oublier de vérifier les bords (indice 0 et dernier).
- Ne pas planter si l’une des cases adjacentes est déjà occupée.
- Modifier le tableau en place pour éviter les placements en double.

## 💬 Ce que j’ai appris
- Implémentation d’un algorithme glouton simple mais précis.
- Manipulation des bords dans un tableau.
- Application stricte de conditions logiques.

## ✅ Statut
Résolu ✅