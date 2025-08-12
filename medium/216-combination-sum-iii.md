# 216. Combination Sum III
## 📝 Énoncé
Trouver toutes les combinaisons de **k** nombres distincts dans **[1..9]** dont la somme est **n**.  
Chaque nombre est utilisé **au plus une fois**. Aucune combinaison dupliquée. Ordre libre.

## 💡 Stratégie
**Backtracking (DFS) avec pruning.**
- On construit une combinaison croissante `cur` en itérant des candidats `start..9`.  
- À chaque étape, on met à jour `kRestant` et `targetRestant`.
- **Prunings déterministes** pour couper tôt :
  1) **Capacité** : s’il reste moins de `kRestant` nombres entre `start` et `9`, impossible.  
     ⇒ `kRestant > (10 - start)` → stop.
  2) **Borne min** : somme minimale possible avec `kRestant` nombres consécutifs à partir de `start` :  
     `minSum = k * (2*start + (k-1)) / 2`.  
     Si `targetRestant < minSum` → stop.
  3) **Borne max** : somme maximale possible avec les `kRestant` plus grands nombres ≤ 9 :  
     `maxSum = k * (19 - k) / 2` (valide quand `start <= 10-k`).  
     Si `targetRestant > maxSum` → stop.

> En gardant les candidats **croissants** (on passe `start → x+1`) on élimine naturellement les doublons.

## 🧠 Complexité
- **Temps (pire cas)** : `O(C(9, k))` générations, fortement **réduit** par les prunings.  
- **Espace** : `O(k)` pour la pile et la combinaison en cours.

## ⚠️ Pièges à éviter
- Ne pas contrôler la **capacité** (`kRestant > 10 - start`) → branches inutiles.  
- Oublier l’ordre **croissant** → risque de doublons.  
- Ne pas **casser la boucle** quand `x > targetRestant` (croissance ⇒ tous les suivants sont pires).  
- Erreurs d’overflow minimes : ici les bornes tiennent dans `int` (petits entiers, OK).

## 💬 Ce que j’ai appris
- Utiliser des **bornes arithmétiques** (somme min/max d’une suite) booste massivement le pruning.  
- Le pattern “**combinaisons croissantes**” suffit pour éliminer les doublons sans set ni tri.

## ✅ Statut
Implémenté, testé localement (raisonnement), prêt pour soumission.