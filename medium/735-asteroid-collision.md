# 735. Asteroid Collision

## 📝 Énoncé
On reçoit un tableau `asteroids` contenant des entiers :
- La **valeur absolue** indique la taille de chaque astéroïde.
- Le **signe** indique la direction : `+` = droite, `-` = gauche.

Quand deux astéroïdes se rencontrent :
- Le plus petit explose.
- S’ils sont de même taille, les deux explosent.
- Deux astéroïdes dans la même direction ne se rencontrent jamais.

## 💡 Stratégie
Utiliser une **pile (stack)** pour simuler les collisions :
- On empile les astéroïdes allant vers la droite.
- Lorsqu’un astéroïde allant vers la gauche arrive, on vérifie s’il entre en collision avec le sommet de la pile.
- On applique les règles de destruction et on ajuste la pile.

## 🧠 Complexité
- Temps : O(n) — chaque astéroïde est ajouté et retiré au plus une fois.
- Espace : O(n) — pour la pile.

## ⚠️ Pièges à éviter
- Ne pas oublier de gérer l’égalité de taille (les deux explosent).
- Bien gérer les boucles `while` imbriquées sans `else` mal placé.
- Ne pas empiler un astéroïde détruit !

## 💬 Ce que j’ai appris
- Utiliser une pile pour résoudre des problèmes de "collision" ou "réaction en chaîne".
- Approche efficace pour simuler un processus dynamique avec conditions imbriquées.

## ✅ Statut
Résolu le 02/08/2025.