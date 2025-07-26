# 1431. Kids With the Greatest Number of Candies

## 📝 Énoncé
On vous donne un tableau `candies[]` où chaque élément représente le nombre de bonbons que chaque enfant possède.  
Vous avez un nombre fixe de `extraCandies` à donner à **un seul** enfant.  
Pour chaque enfant, dites s'il peut **avoir le plus de bonbons** après avoir reçu **tous** les extraCandies.

Retournez un tableau de booléens `result[]` tel que `result[i]` est `true` si `candies[i] + extraCandies` est supérieur ou égal au maximum des `candies[]`.

## 💡 Stratégie
1. Identifier le **maximum actuel** des bonbons parmi tous les enfants.
2. Pour chaque enfant, additionner ses bonbons à `extraCandies`.
3. Comparer cette somme au maximum trouvé.
4. Retourner `true` si l’enfant **atteint ou dépasse** le maximum, sinon `false`.

## 🧠 Complexité
- **Temps** : `O(n)`  
  - `n` = taille du tableau `candies[]`.
  - On parcourt 2 fois le tableau : une fois pour le max, une fois pour le résultat.
- **Espace** : `O(n)`  
  - On stocke un tableau de booléens de taille `n`.

## ⚠️ Pièges à éviter
- Ne pas oublier que plusieurs enfants peuvent avoir le **même maximum**.
- Ne pas utiliser `std::max` sur chaque itération — mieux vaut calculer le max une fois avec `std::max_element`.

## 💬 Ce que j’ai appris
- Utilisation efficace de `std::max_element` pour trouver un max rapidement dans un `std::vector`.
- Comment transformer une logique simple en une solution élégante et lisible.
- L’intérêt d’une première passe pour calculer une valeur de référence (ici, le max).

## ✅ Statut
Résolu et compris ✔️