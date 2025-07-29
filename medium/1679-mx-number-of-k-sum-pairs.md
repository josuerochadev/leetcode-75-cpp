# 1679. Max Number of K-Sum Pairs
## 📝 Énoncé
On vous donne un tableau d'entiers `nums` et un entier `k`.  
En une opération, vous pouvez choisir **deux nombres** du tableau dont **la somme est égale à `k`**, et les **retirer** du tableau.  

Retournez **le nombre maximal d'opérations** que vous pouvez effectuer.

**Exemples** :  
Input: nums = [1,2,3,4], k = 5  
Output: 2

Input: nums = [3,1,3,4,3], k = 6  
Output: 1

## 💡 Stratégie
Utilisons un `unordered_map<int, int>` pour compter les fréquences de chaque nombre.

Pour chaque `num` dans `nums`, on cherche s’il existe `complement = k - num` avec une fréquence > 0.  
On vérifie aussi que `num` lui-même est encore disponible dans le map.

Si oui :
- on décrémente `num` et `complement`
- on ajoute 1 au nombre total d’opérations

**Cas spécial** : si `num == complement`, il faut au moins **2 occurrences** de ce nombre pour faire une opération.

## 🧠 Complexité
- Temps : O(n) — une seule passe sur le tableau + accès constant à la map.
- Espace : O(n) — pour stocker les fréquences dans le `unordered_map`.

## ⚠️ Pièges à éviter
- Penser à **retirer les éléments** après avoir formé une paire.
- Ne pas **compter deux fois** la même paire (`num`, `k - num`).
- Bien gérer le cas où `num == k - num`.

## 💬 Ce que j’ai appris
- Utiliser un map de fréquences pour gérer efficacement les opérations sans modifier le tableau d’origine.
- Optimiser une solution en évitant les approches `brute-force` O(n²).
- Le pattern **complementary pair** est fréquent dans les exercices sur les sommes.

## ✅ Statut
✅ Résolu le 2025-07-29