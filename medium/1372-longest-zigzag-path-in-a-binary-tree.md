# 1372. Longest ZigZag Path in a Binary Tree

## 📝 Énoncé

Un **chemin ZigZag** est une suite de mouvements alternés gauche/droite à partir d’un nœud de l’arbre binaire. On retourne la longueur maximale d’un tel chemin (nombre de nœuds visités - 1).

## 💡 Stratégie

- Utiliser une **DFS** récursive en transmettant :
  - la direction (aller à gauche ou à droite),
  - la longueur actuelle du chemin ZigZag.
- À chaque nœud :
  - Si on change de direction, on augmente la longueur.
  - Si on garde la même direction, on redémarre depuis 1.

## 🧠 Complexité

- **Temps** : `O(n)` où `n` est le nombre de nœuds, chaque nœud est visité 1x.
- **Espace** : `O(h)` avec `h` la hauteur de l’arbre (pire cas O(n)).

## ⚠️ Pièges à éviter

- Ne pas confondre le sens gauche/droite avec la structure gauche/droite du nœud.
- Bien redémarrer à 1 si on ne change pas de direction.
- Le ZigZag est défini par les **alternances**.

## 💬 Ce que j’ai appris

- Utiliser une fonction récursive avec des arguments directionnels pour implémenter une logique alternée efficacement.
- Importance de bien identifier les moments où il faut “reset” le compteur.
- Optimisation d’un parcours d’arbre sans surcoût mémoire.

## ✅ Statut

Résolu manuellement ✅