# 236. Lowest Common Ancestor of a Binary Tree

## 📝 Énoncé

Étant donné la racine d’un arbre binaire et deux nœuds `p` et `q`, trouver leur plus bas ancêtre commun (LCA).  
Définition : le LCA est le nœud le plus bas dans l’arbre qui a `p` et `q` comme descendants (on autorise qu’un nœud soit descendant de lui-même).

## 💡 Stratégie

Utiliser la récursion pour explorer l’arbre depuis la racine. À chaque appel récursif :
- Si le nœud courant est `nullptr`, on retourne `nullptr`.
- Si le nœud courant est égal à `p` ou `q`, on le retourne.
- Sinon, on cherche dans les sous-arbres gauche et droit.
  - Si on trouve `p` d’un côté et `q` de l’autre : le nœud courant est le LCA.
  - Sinon, on remonte le résultat trouvé (soit `p`, soit `q`, soit `nullptr`).

## 🧠 Complexité

- Temps : `O(n)` où `n` est le nombre de nœuds dans l’arbre.
- Espace : `O(h)` pour la profondeur de la pile (h = hauteur de l’arbre).

## ⚠️ Pièges à éviter

- Ne pas confondre les cas où `p` ou `q` est lui-même le LCA.
- Bien gérer les `nullptr` en base de récursion.
- Ne pas faire d’appels récursifs inutiles si on a déjà trouvé un des nœuds.

## 💬 Ce que j’ai appris

- À implémenter un algorithme de backtracking dans un arbre binaire.
- À gérer proprement des cas limites où un des nœuds est le parent de l’autre.
- À utiliser la récursion pour résoudre des problèmes complexes d’arbres de façon élégante.

## ✅ Statut

Résolu le 07/08/2025