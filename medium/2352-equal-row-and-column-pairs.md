# 2352. Equal Row and Column Pairs

## 📝 Énoncé
On te donne une matrice carrée `n x n`. Tu dois retourner le nombre de paires `(ri, cj)` telles que la ligne `ri` et la colonne `cj` soient exactement identiques (même ordre, mêmes éléments).

## 💡 Stratégie
1. On convertit chaque **ligne** en une string formatée et on les stocke dans une `unordered_map` pour compter combien de fois elle apparaît.
2. Ensuite, on génère chaque **colonne** sous forme de string avec le même format et on regarde si cette colonne a une correspondance dans la map.
3. Si oui, on ajoute le nombre de fois où cette ligne existe au compteur.

## 🧠 Complexité
- 🕒 Temps : O(n²)
  - O(n²) pour lire toutes les lignes et colonnes.
- 🧠 Espace : O(n²)
  - Stockage des lignes sous forme de strings dans la map.

## ⚠️ Pièges à éviter
- Ne pas oublier de séparer les éléments avec un caractère (ex: virgule) pour éviter les collisions de clé (`[1,11]` vs `[11,1]`).
- Ne pas comparer directement les vecteurs ligne vs colonne sans transformation, car ce serait coûteux sans hash.

## 💬 Ce que j’ai appris
- Comment comparer efficacement des lignes et des colonnes dans une matrice en utilisant des clés stringifiées.
- Utiliser un `unordered_map` pour comptabiliser rapidement des séquences.

## ✅ Statut
Résolu le 02/08/2025.