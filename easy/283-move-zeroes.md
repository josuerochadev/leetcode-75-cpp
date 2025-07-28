# 283. Move Zeroes
## 📝 Énoncé
Déplacez tous les 0 d’un tableau vers la fin **sans changer l’ordre des autres éléments**. L’opération doit être faite **in-place** (sans créer de copie du tableau).

## 💡 Stratégie
On utilise deux pointeurs : un pour parcourir le tableau (`i`), l’autre pour suivre la position d’insertion (`insertPos`). À chaque élément non nul, on l’insère à `insertPos` puis on le fait avancer. Ensuite, on remplit le reste du tableau avec des zéros.

## 🧠 Complexité
- Temps : O(n)
- Espace : O(1)

## ⚠️ Pièges à éviter
- Changer l’ordre des éléments non nuls
- Créer une copie du tableau (interdit)
- Oublier de remplir le reste du tableau avec des zéros

## 💬 Ce que j’ai appris
- Manipuler efficacement les tableaux avec des pointeurs
- Utiliser des algorithmes in-place
- Optimiser sans créer de structures temporaires

## ✅ Statut
Résolu avec succès ✅