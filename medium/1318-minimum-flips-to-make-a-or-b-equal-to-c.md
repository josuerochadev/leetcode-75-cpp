# 1318. Minimum Flips to Make a OR b Equal to c

## 📝 Énoncé

Étant donnés trois entiers positifs `a`, `b` et `c`, retourner le **nombre minimum de flips de bits** (changer `0↔1`) sur `a` et `b` de sorte que `(a OR b) == c`.

**Contraintes** : `1 ≤ a, b, c ≤ 10^9`.

## 💡 Stratégie

On raisonne **bit par bit** (du LSB vers le MSB) :

- Note `ai`, `bi`, `ci` les bits i-ème de `a`, `b`, `c`.
- Si `ci == 1` : au moins un de `ai` ou `bi` doit être `1`.
  - Si `(ai | bi) == 0` → **1 flip** (mettre `ai` ou `bi` à `1`).
  - Sinon `0 flip`.
- Si `ci == 0` : il faut `ai == 0` **et** `bi == 0`.
  - Ajouter `ai + bi` (le nombre de `1` à éteindre).

On additionne ces coûts sur tous les bits jusqu’à ce que `a|b|c == 0`.

Pourquoi ça marche ? Le OR à un bit est local : ajuster un bit n’impacte pas les autres.

## 🧠 Complexité

- Temps : `O(31)` ≈ `O(1)` (jusqu’à 31 bits utiles vu les bornes).
- Espace : `O(1)`.

## ⚠️ Pièges à éviter

- Utiliser `~` sur des `int` signés sans masque peut ramener des `1` “fantômes” dans les bits de signe. La boucle bit-à-bit évite ce piège.
- Oublier que si `ci==0` et `ai==bi==1`, il faut **2 flips** (éteindre les deux).
- S’arrêter trop tôt : la condition de boucle correcte est `while (a|b|c)`.

## 💬 Ce que j’ai appris

- Décomposer un OR bit-à-bit simplifie la logique et élimine la complexité perçue.
- Les cas se résument à deux règles simples (ci=1 → au moins un 1 ; ci=0 → tous 0).
- `__builtin_popcount` peut condenser la solution, mais attention aux compléments sur types signés.

## ✅ Statut

En cours 👉 Solution implémentée en C++ (classe `Solution`, méthode `minFlips`), testée mentalement sur les exemples fournis.
