# 162. Find Peak Element

## 📝 Énoncé
On vous donne un tableau `nums` (indexé à partir de 0).  
Un "peak element" est un élément strictement plus grand que ses voisins.  
`nums[-1]` et `nums[n]` sont considérés comme `-∞`.  
Retournez **l’index** de **n’importe** quel peak trouvé.  
Complexité demandée : **O(log n)**.

Exemple :

`Input: nums = [1,2,3,1]
Output: 2`

## 💡 Stratégie
- Utiliser **binary search** pour réduire la recherche à O(log n).
- Comparer `nums[mid]` avec `nums[mid+1]` :
  - Si `nums[mid] > nums[mid+1]`, un peak est à gauche (inclus mid).
  - Sinon, un peak est à droite (excluant mid).
- Répéter jusqu’à ce que `left == right`.

## 🧠 Complexité
- **Temps** : O(log n) (recherche binaire)
- **Espace** : O(1) (pas de structure supplémentaire)

## ⚠️ Pièges à éviter
- Ne pas oublier que `nums[-1]` et `nums[n]` sont `-∞` (pas besoin de les coder explicitement).
- Ne pas utiliser O(n) (ex : simple parcours linéaire), cela ne respecterait pas la contrainte.
- Attention à la gestion des indices et à ne pas dépasser `nums[mid+1]`.

## 💬 Ce que j’ai appris
- Comment transformer un problème de recherche d’élément maximal local en recherche binaire.
- Utilisation intelligente de la comparaison entre mid et mid+1 pour orienter la recherche.

## ✅ Statut
Résolu et testé