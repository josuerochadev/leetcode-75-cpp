# 206. Reverse Linked List

## 📝 Énoncé
On te donne la tête d'une liste simplement chaînée. Ta tâche est de renverser cette liste et de renvoyer la nouvelle tête.

## 💡 Stratégie
On peut inverser une liste chaînée :
1. **Itérativement**, en réaffectant les pointeurs `next` de chaque nœud.
2. **Récursivement**, en déléguant le travail au reste de la liste et en inversant au retour de l’appel.

Itératif :
- On utilise deux pointeurs : `prev` (initialement `nullptr`) et `current` (la tête).
- À chaque itération, on inverse le lien et on avance les pointeurs.

Récursif :
- Le cas de base est une liste vide ou à un seul élément.
- À chaque appel, on renverse le reste de la liste et on rattache le nœud courant à la fin.

## 🧠 Complexité
- **Temps** : O(n), on parcourt chaque nœud une fois.
- **Espace** : 
  - Itératif : O(1)
  - Récursif : O(n) (pile d’appels récursifs)

## ⚠️ Pièges à éviter
- Ne pas perdre le pointeur `next` (toujours le sauvegarder avant d’inverser).
- Bien traiter les cas particuliers : liste vide ou à un seul nœud.
- En récursif, ne pas oublier de mettre `head->next = nullptr`.

## 💬 Ce que j’ai appris
- Revoir les fondamentaux des pointeurs et de l’inversion de liens.
- Le pattern itératif est plus simple à maintenir et à tester.
- La version récursive est élégante mais plus coûteuse en mémoire.

## ✅ Statut
Résolu le 05/08/2025 ✅