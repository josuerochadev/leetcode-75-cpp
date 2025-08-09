# 399. Evaluate Division
## 📝 Énoncé
On reçoit des équations du type `Ai / Bi = value` (avec `Ai`, `Bi` des variables-strings), et des requêtes `Cj / Dj = ?`.  
Retourner, pour chaque requête, la valeur si elle est déterminable à partir des équations, sinon `-1.0`.  
Les variables jamais vues sont considérées comme **indéfinies**.

## 💡 Stratégie
- Modéliser les équations comme un **graphe orienté pondéré**:
  - Pour `a / b = v`, ajouter `a -> b (v)` et `b -> a (1/v)`.
- Pour `C / D`, chercher un **chemin** de `C` vers `D` (DFS/BFS) et **multiplier** les poids rencontrés.
- Règles de bord:
  - Si `C` ou `D` n’existe pas dans le graphe → `-1.0`.
  - Si `C == D`, renvoyer `1.0` **uniquement si** la variable est connue (sinon `-1.0`).

## 🧠 Complexité
- Construction: `O(E)` où `E` = nb d’équations.
- Par requête: `O(V + E)` au pire.
- Mémoire: `O(V + E)`.

## ⚠️ Pièges à éviter
- `x / x` quand `x` est **inconnu** → `-1.0` (et non `1.0`).
- Oublier l’arête inverse `b -> a (1/v)`.
- Ne pas réinitialiser `visited` **par requête**.
- Retours flottants: utiliser `double`.

## 💬 Ce que j’ai appris
- Traduire un système d’équations en graphe pondéré.
- Accumulation multiplicative le long d’un chemin (produit des poids).
- Gestion propre des cas limites (variables inconnues, self-query).

## ✅ Statut
Implémenté, testé sur les exemples de l’énoncé, conforme.