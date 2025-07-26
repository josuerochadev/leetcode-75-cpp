# 1768 - Merge Strings Alternately

## 📝 Énoncé
Tu dois fusionner deux chaînes `word1` et `word2` **en alternant les lettres** de l’une et de l’autre.  
Si une chaîne est plus longue que l’autre, tu ajoutes les lettres restantes à la fin.

## 💡 Stratégie
- Utiliser deux pointeurs (`i`, `j`) pour parcourir les deux chaînes.
- Ajouter une lettre de `word1`, puis une de `word2`, jusqu’à la fin d’une des deux.
- Ajouter les lettres restantes de la chaîne la plus longue.

## 🧠 Complexité
- Temps : `O(n + m)`
- Espace : `O(n + m)` (chaîne résultat)

## ⚠️ Pièges à éviter
- Ne pas oublier d’ajouter les lettres restantes après la boucle.
- Bien vérifier les indices (i < length).

## 💬 Ce que j’ai appris
- Utilisation de `std::string::substr()`
- Gestion des indices dans deux boucles imbriquées
- Lecture et interprétation d’un énoncé algorithmique

## ✅ Statut
✔️ Validé sur LeetCode - 2025-07-25