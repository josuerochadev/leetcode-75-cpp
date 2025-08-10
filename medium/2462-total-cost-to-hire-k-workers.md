# 2462. Total Cost to Hire K Workers
## 📝 Énoncé
On dispose d’un tableau `costs` (0-indexé) où `costs[i]` est le coût d’embauche du i-ème travailleur, et de deux entiers `k` et `candidates`. On doit mener `k` sessions d’embauche. À chaque session, on choisit **le coût minimal** parmi :
- les `candidates` premiers travailleurs restants (fenêtre gauche), ou
- les `candidates` derniers travailleurs restants (fenêtre droite).
En cas d’égalité sur le coût, on choisit **l’indice le plus petit**. Si moins de `candidates` restent, on choisit le minimum parmi ceux qui restent. Chaque travailleur ne peut être choisi qu’une seule fois. Retourner le **coût total** minimal pour embaucher exactement `k` travailleurs.

## 💡 Stratégie
- **Insight clé** : à tout instant, la décision ne dépend que des `candidates` plus proches de la gauche **et** des `candidates` plus proches de la droite. On n’a jamais besoin de regarder le milieu tant qu’il n’entre pas dans ces fenêtres.
- **Data structure** : deux **min-heaps** (tas min) contenant des paires `(coût, index)` :
  - `leftPQ` pour la fenêtre gauche, `rightPQ` pour la fenêtre droite.
  - Cette structure gère naturellement le tie-break en comparant `(coût, index)`.
- **Two-pointers** :
  - `L` démarre à 0, `R` à `n-1`.
  - On remplit chaque tas avec jusqu’à `candidates` éléments sans se chevaucher (`L <= R`).
  - À chaque embauche :
    1) on compare les tops de `leftPQ` et `rightPQ`;
    2) on prend le plus petit (tie-break sur index) ;
    3) on recharge le tas correspondant avec le prochain candidat (`L++` côté gauche, `R--` côté droit) tant que `L <= R`.
- **Pourquoi ça marche** : on respecte strictement les règles du problème (uniquement les `candidates` premiers/derniers visibles à l’instant t). Dès qu’on “consomme” un extrême, on expose le suivant.

## 🧠 Complexité
- **Temps** : `O((n + k) log C)` où `C = candidates` (chaque push/pop est `log C`, et on pousse au plus `n` éléments au total, on pop `k` fois).
- **Espace** : `O(C)` pour stocker les deux tas (au plus ~`2 * candidates` éléments cumulés).

## ⚠️ Pièges à éviter
- **Chevauchement** gauche/droite quand `2 * candidates > n` : ne **pas** insérer deux fois le même index. Conditionner l’insertion par `L <= R`.
- **Somme en 32 bits** : utiliser `long long` pour le total.
- **Tie-break** : si `cost` égaux, prendre l’**indice** le plus petit **même entre tas différents** → comparer `(cost, index)` des deux tops.
- **Recharge après pop** : après avoir choisi à gauche (resp. droite), pousser le **prochain** de ce côté si disponible ; sinon, l’autre tas sera le seul vivier.

## 💬 Ce que j’ai appris
- Le pattern “**fenêtres aux extrémités + double min-heap**” est un design robuste pour des règles “prendre parmi les `candidates` de gauche ou de droite”.
- Les **paires (cost, index)** simplifient le tie-break cross-borders sans sur-logiciel.
- Sécuriser les bornes `L <= R` évite les bugs discrets quand les fenêtres se rejoignent.

## ✅ Statut
✅ Résolu — tests de base validés (exemples de l’énoncé).