# 1268. Search Suggestions System

## 📝 Énoncé

On reçoit `products` (liste de chaînes) et `searchWord` (chaîne).  
Après chaque caractère saisi de `searchWord`, on doit proposer **au plus 3** produits **lexicographiquement minimums** partageant le **préfixe courant**.

**Sortie** : une liste de listes, où l’ième liste correspond aux suggestions après le ième caractère saisi.

## 💡 Stratégie

**Approche retenue : Tri + `lower_bound`**

1. Trier `products` une fois (ordre lexicographique).
2. Pour chaque préfixe de `searchWord`, utiliser `lower_bound(prefix)` pour trouver l’index de départ des mots ≥ `prefix`.
3. Itérer depuis cet index et **prélever au plus 3** produits qui commencent par `prefix`.  
4. Pousser la liste dans le résultat pour ce préfixe.

**Pourquoi cette approche ?**

- Simple, fiable, et très performante pour les contraintes de l’exercice.
- Pas besoin d’implémenter un `Trie` (plus lourd en code) pour un gain marginal ici.

### Alternative

- **Trie**: stocker les mots et accéder aux suggestions par nœud (préfixe). Intéressant si tu enchaînes beaucoup de requêtes ou si tu enrichis la suggestion (ex: top-k pondéré).

## 🧠 Complexité

- **Temps** : `O(n log n + L log n + 3L)` ≈ `O(n log n + L log n)`  
  - `n` = nombre de produits, `L` = longueur de `searchWord`.
- **Espace** : `O(1)` additionnel (en dehors du coût de tri).

## ⚠️ Pièges à éviter

- Oublier de **trier** les produits avant la recherche binaire.
- Ne pas **stopper** la collecte quand `starts_with` échoue (le tri permet de couper).
- Refaire `lower_bound` depuis `begin()` à chaque itération : commencer la recherche à la **position précédente** peut micro-optimiser (préfixes croissants).
- Erreurs d’index si on tente d’accéder sans vérifier la taille ; toujours **borne ≤ 3**.

## 💬 Ce que j’ai appris

- Combiner `sort` + `lower_bound` donne un **autocomplete** concis et rapide.
- L’ordre lexicographique permet une **sortie anticipée** dès que le préfixe ne matche plus.
- Un `Trie` est pédagogique mais pas toujours nécessaire pour passer en production.

## ✅ Statut

Implémenté, relu, et prêt pour push.
