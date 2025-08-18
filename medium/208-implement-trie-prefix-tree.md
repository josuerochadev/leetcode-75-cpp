# 208. Implement Trie (Prefix Tree)

## 📝 Énoncé

Implémenter une structure `Trie` avec les méthodes :

- `insert(word)`
- `search(word) -> bool` : vrai si `word` a été inséré.
- `startsWith(prefix) -> bool` : vrai si un mot inséré commence par `prefix`.

Contraintes : `word`/`prefix` en minuscules, longueur ≤ 2000, ~3 * 10^4 appels au total.

## 💡 Stratégie

- Utiliser un **arbre de préfixes (Trie)** où chaque nœud possède jusqu’à **26 enfants** (a-z) et un booléen `isEnd`.
- **Insertion** : parcourir les lettres et créer les nœuds manquants.
- **Recherche** : parcourir ; succès si on termine sur un nœud `isEnd == true`.
- **Prefix** : succès si on peut traverser tout le `prefix` (peu importe `isEnd`).

### Choix d’implémentation

- **Tableau fixe `children[26]`** pour des accès O(1) sans hashing.
- **Destructeur récursif** pour libérer la mémoire proprement.
- **Fonction utilitaire `traverse`** (réduction de duplication).

## 🧠 Complexité

- Temps :
  - `insert(word)`: **O(L)**
  - `search(word)`: **O(L)**
  - `startsWith(prefix)`: **O(P)**
- Espace :
  - **O(total_chars)** nœuds créés au cumul des insertions (26 pointeurs/nœud + 1 bool).

## ⚠️ Pièges à éviter

- Oublier de marquer `isEnd` à `true` après `insert`.
- Confondre `search` et `startsWith` (le premier exige `isEnd == true`).
- Dépasser l’index (`c - 'a'`) si caractères non a-z (protégé par contraintes).
- Fuites mémoire si allocations sans destructeur.

## 💬 Ce que j’ai appris

- Le Trie est imbattable pour des opérations **préfixes** à coût linéaire sur la longueur.
- Le choix **tableau vs map** impacte directement la perf et la prévisibilité.

## ✅ Statut

Réussi localement et conforme à l’API LeetCode.
