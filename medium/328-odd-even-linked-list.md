# 328. Odd Even Linked List

## 📝 Énoncé

On te donne la tête d’une liste simplement chaînée. Tu dois regrouper tous les nœuds d’**indices impairs** ensemble, suivis des nœuds d’**indices pairs**, puis renvoyer la nouvelle tête de la liste.

Le 1er nœud est considéré comme impair, le 2e comme pair, etc. L’ordre relatif doit rester le même.

**Contraintes** :
- Complexité en temps : `O(n)`
- Complexité en espace : `O(1)`

## 💡 Stratégie

1. Gérer les cas particuliers (liste vide ou avec un seul élément).
2. Initialiser deux pointeurs :
   - `odd` : commence à `head`
   - `even` : commence à `head->next`
   - `evenHead` : pour mémoriser le début des pairs (à rattacher à la fin).
3. Boucle tant que `even` et `even->next` existent :
   - `odd->next = even->next`
   - `odd = odd->next`
   - `even->next = odd->next`
   - `even = even->next`
4. À la fin, rattacher la fin des impairs (`odd->next`) à `evenHead`.

## 🧠 Complexité

- Temps : `O(n)` (on parcourt chaque nœud une fois)
- Espace : `O(1)` (pas de structure auxiliaire)

## ⚠️ Pièges à éviter

- Ne pas oublier de reconnecter `odd->next = evenHead` à la fin.
- Bien vérifier les conditions `even && even->next` dans la boucle.
- Ne pas inverser valeurs impaires/paires avec valeurs à indices impairs/pairs.

## 💬 Ce que j’ai appris

- Manipuler des listes chaînées avec plusieurs pointeurs simultanés.
- Importance de préserver les débuts de sous-listes (ici `evenHead`).
- Implémentation en `O(1)` espace est possible avec bonne gestion de pointeurs.

## ✅ Statut

Résolu ✅ le 04/08/2025