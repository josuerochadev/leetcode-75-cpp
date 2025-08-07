# 199. Binary Tree Right Side View

## 📝 Énoncé

On vous donne la racine d’un arbre binaire. Imaginez que vous vous tenez du côté **droit** de l’arbre : retournez les **valeurs des nœuds visibles** de haut en bas.

**Exemple :**

`Input: [1,2,3,null,5,null,4]
Output: [1,3,4]`

## 💡 Stratégie

Utiliser un parcours **BFS niveau par niveau**.  
À chaque niveau, on garde uniquement le **dernier nœud visité**, car c’est celui qu’on voit à droite.

### Étapes :
1. Initialiser une `queue` pour le BFS avec la racine.
2. Pour chaque niveau, parcourir tous les nœuds présents.
3. Enregistrer **le dernier nœud** de ce niveau dans `result`.

C’est une solution efficace et facile à maintenir.

## 🧠 Complexité

- Temps : `O(n)` — chaque nœud est visité une seule fois.
- Espace : `O(d)` — la queue peut contenir jusqu'à `d` nœuds (profondeur max de l’arbre).

## ⚠️ Pièges à éviter

- Ne pas confondre **dernier nœud du niveau** avec le dernier enfant (ce n’est pas un DFS).
- Ne pas oublier le cas `root == nullptr`.
- Bien **pousser left puis right** pour que le dernier élément de chaque niveau soit bien le plus à droite.

## 💬 Ce que j’ai appris

- Le parcours BFS est très adapté à la logique “niveau par niveau”.
- Pour voir un “côté” d’un arbre, il suffit d’exploiter l’ordre d’insertion dans la queue.
- Excellente occasion de réviser les parcours d’arbre en largeur.

## ✅ Statut

Résolu manuellement ✅