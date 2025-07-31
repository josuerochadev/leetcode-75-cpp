# 724. Find Pivot Index

## 📝 Énoncé

Trouver l’indice pivot d’un tableau `nums` tel que la somme des éléments **à gauche** de l’indice soit égale à celle **à droite**.  
S’il n’existe pas, retourner `-1`.  
On retourne le **premier pivot** trouvé de gauche à droite.

## 💡 Stratégie

1. Calculer la somme totale du tableau `totalSum`.
2. Parcourir chaque élément, en gardant une `leftSum`.
3. À chaque index `i`, on vérifie si `leftSum == totalSum - leftSum - nums[i]`.
   - Si oui, on retourne `i`.
   - Sinon, on ajoute `nums[i]` à `leftSum` et on continue.
4. Si aucun pivot trouvé, on retourne `-1`.

## 🧠 Complexité

- Temps : `O(n)` – une seule passe dans le tableau.
- Espace : `O(1)` – pas de structure supplémentaire.

## ⚠️ Pièges à éviter

- Ne pas oublier que `leftSum` est 0 au début.
- Ne pas inclure `nums[i]` dans le calcul du `rightSum`.
- Retourner le premier pivot trouvé.

## 💬 Ce que j’ai appris

- Comment utiliser un seul parcours pour calculer un équilibre gauche/droite.
- Utiliser la somme totale pour simplifier le problème.

## ✅ Statut

Résolu le 31/07/2025