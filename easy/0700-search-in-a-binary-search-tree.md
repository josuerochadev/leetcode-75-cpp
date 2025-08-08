# 700. Search in a Binary Search Tree

## 📝 Énoncé

On te donne la racine d’un arbre binaire de recherche (BST) et un entier `val`.

Retourne le **sous-arbre** enraciné dans le nœud dont la valeur est égale à `val`, ou `null` si ce nœud n’existe pas.

## 💡 Stratégie

1. Utiliser la propriété d’un **BST** :
   - Les valeurs à gauche sont **inférieures** au nœud courant.
   - Les valeurs à droite sont **supérieures**.

2. On compare `val` avec `root->val` :
   - S’il est égal → on retourne ce nœud.
   - S’il est plus petit → chercher dans le sous-arbre gauche.
   - S’il est plus grand → chercher dans le sous-arbre droit.

On peut le faire :
- **récursivement** (comme ici).
- **itérativement** (en boucle `while`, option valide aussi).

## 🧠 Complexité

- Temps : `O(h)` où `h` est la hauteur de l’arbre (log n si équilibré, n si totalement dégénéré).
- Espace :
  - `O(h)` en récursif à cause de la pile d’appels.
  - `O(1)` si on fait la version itérative.

## ⚠️ Pièges à éviter

- Ne pas confondre **BST** avec un simple arbre binaire : ici on peut **optimiser** la recherche.
- Ne pas oublier les cas de base (`root == nullptr`).
- Bien retourner le **sous-arbre**, pas juste un booléen ou une valeur.

## 💬 Ce que j’ai appris

- Utiliser les propriétés d’un arbre binaire de recherche pour optimiser les recherches.
- Rappel sur les récursions simples dans les arbres.
- Bonne opportunité de comparer approche récursive vs itérative.

## ✅ Statut

Résolu le 08/08/2025.