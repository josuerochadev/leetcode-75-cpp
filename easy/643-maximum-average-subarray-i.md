# 643. Maximum Average Subarray I

## 📝 Énoncé

On vous donne un tableau `nums` d'entiers de taille `n`, et un entier `k`.

Trouvez la sous-liste contiguë de taille `k` avec la **valeur moyenne maximale** et retournez cette valeur.  
Une précision d’erreur inférieure à `1e-5` est acceptée.

### Exemples :

```txt
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
=> (12 + (-5) + (-6) + 50) / 4 = 12.75

Input: nums = [5], k = 1
Output: 5.00000
```

## 💡 Stratégie
- Utilisation de la fenêtre glissante (sliding window).
- Calcul de la somme initiale des k premiers éléments.
- On glisse la fenêtre, en ajoutant l’élément entrant et en retirant l’élément sortant.
- Mise à jour de la somme maximale à chaque itération.

## 🧠 Complexité
- Temps : O(n)
- Espace : O(1) (en dehors du tableau d’entrée)

## ⚠️ Pièges à éviter
- Penser à bien convertir en double pour le retour.
- Ne pas recalculer la somme complète à chaque fois — optimiser avec glissement.
- Attention à la précision demandée (< 1e-5), donc éviter les divisions précoces.

## 💬 Ce que j’ai appris
- Renforcement de la technique de la fenêtre glissante.
- Attention au type de retour (double) et à la précision en C++.
- Importance d’un algorithme linéaire dans un tableau jusqu’à 10^5 éléments.

## ✅ Statut
Résolu ✅