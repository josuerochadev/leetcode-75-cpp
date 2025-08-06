# 437. Path Sum III

## 📝 Énoncé

On vous donne la racine d’un arbre binaire et un entier `targetSum`. Retournez le nombre de chemins où la somme des valeurs des nœuds est égale à `targetSum`.

⚠️ Les chemins :
- ne doivent pas nécessairement partir de la racine,
- ne doivent pas nécessairement se terminer sur une feuille,
- doivent aller vers le bas (du parent vers l’enfant uniquement).

## 💡 Stratégie

1. Pour chaque nœud, on considère ce nœud comme un **point de départ potentiel**.
2. Depuis ce point, on cherche **tous les chemins descendants** dont la somme donne `targetSum`.
3. Puis on fait la même chose récursivement pour les enfants gauche et droit.

On découpe donc le problème en deux fonctions :
- Une qui **compte les chemins à partir d’un nœud donné** (`countPathsFromNode`)
- Une autre qui applique cette logique **à tous les nœuds de l’arbre** (`pathSum`).

## 🧠 Complexité

- ⏱️ Temps : O(N²) dans le pire des cas (arbre déséquilibré)
- 🧠 Mémoire : O(N) pour la profondeur maximale de récursion (pile)

> Remarque : Peut être optimisé en O(N) via `prefix sum + hashmap` si nécessaire pour les gros inputs.

## ⚠️ Pièges à éviter

- Croire que les chemins doivent commencer à la racine ou finir à une feuille.
- Ne pas faire la somme **vers le bas uniquement** (interdiction de remonter).
- Ne pas confondre la recherche d’un seul chemin vs **plusieurs chemins**.

## 💬 Ce que j’ai appris

- À découpler une logique récursive en deux responsabilités : "à partir de ce nœud" et "dans le sous-arbre".
- À respecter rigoureusement les règles d’un parcours descendant dans un arbre.
- À implémenter une récursion imbriquée proprement (appels internes pour chaque sous-nœud).

## ✅ Statut

✅ Résolu le 06/08/2025