# 649. Dota2 Senate
## 📝 Énoncé
Simulation du vote dans le sénat de Dota2 où chaque sénateur peut bannir un autre ou déclarer la victoire de son camp. Retourner "Radiant" ou "Dire" selon le vainqueur.

## 💡 Stratégie
On utilise deux files (`queue<int>`) pour stocker les index des sénateurs R et D. À chaque round, celui avec l'index le plus petit bannit l'autre et revient au tour suivant avec un index incrémenté de `n`.

## 🧠 Complexité
- Temps : `O(n)` par round, avec potentiellement `O(n²)` dans le pire cas.
- Espace : `O(n)` pour les deux files.

## ⚠️ Pièges à éviter
- Ne pas utiliser `erase()` sur une string (trop lent).
- Ne pas confondre les indices avec les personnages.
- Bien penser à réinjecter l'index + n pour les rounds suivants.

## 💬 Ce que j’ai appris
Simulation efficace avec des `queue` permet de modéliser des processus circulaires sans altérer la string d’origine.

## ✅ Statut
Résolu avec succès le 04/08/2025