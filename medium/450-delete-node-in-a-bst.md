# 450. Delete Node in a BST

## 📝 Énoncé

On te donne la racine d’un arbre binaire de recherche (BST) et une clé `key`. Supprime le nœud correspondant à la clé et retourne la nouvelle racine (potentiellement mise à jour).

- Si le nœud n’existe pas, retourne l’arbre tel quel.
- Si le nœud existe, applique les règles classiques de suppression en BST :
  - Sans enfant : supprime simplement.
  - Avec un seul enfant : remplace par l’enfant.
  - Avec deux enfants : remplace par l’in-order successor.

## 💡 Stratégie

1. Traverse récursivement l’arbre pour trouver le nœud à supprimer.
2. Une fois trouvé :
   - S’il n’a pas d’enfant ou un seul, on retourne l’enfant ou `nullptr`.
   - S’il a deux enfants, on cherche le minimum de son sous-arbre droit (in-order successor).
   - On remplace la valeur du nœud par celle du successeur et on supprime ce dernier récursivement.

## 🧠 Complexité

- Temps : `O(h)` avec `h = hauteur de l’arbre`. En moyenne `O(log n)`, dans le pire cas (arbre déséquilibré), `O(n)`.
- Espace : `O(h)` pour la pile d’appels récursive.

## ⚠️ Pièges à éviter

- Ne pas oublier de reconnecter les sous-arbres après suppression.
- Bien gérer les cas avec 0, 1 ou 2 enfants.
- Ne pas confondre l’in-order successor (min à droite) avec le predecessor (max à gauche).

## 💬 Ce que j’ai appris

- Supprimer un nœud dans un BST est une opération fondamentale mais délicate.
- C’est un excellent exercice pour manipuler des pointeurs et gérer des cas conditionnels.
- L’approche récursive est élégante et maintient le code clair.

## ✅ Statut

Résolu ✅ le 08/08/2025