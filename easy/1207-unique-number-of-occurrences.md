# 1207. Unique Number of Occurrences

## 📝 Énoncé

Étant donné un tableau d'entiers `arr`, retourner `true` si chaque valeur apparaît un nombre unique de fois, sinon `false`.

**Exemples :**

- Input: [1,2,2,1,1,3] → Output: true  
- Input: [1,2] → Output: false  
- Input: [-3,0,1,-3,1,1,1,-3,10,0] → Output: true

## 💡 Stratégie

1. Compter les fréquences avec `unordered_map`.
2. Vérifier l'unicité des occurrences avec `unordered_set`.
3. Retourner `false` si un doublon est trouvé, sinon `true`.

## 🧠 Complexité

- Temps : O(n)
- Espace : O(n)

## ⚠️ Pièges à éviter

- Confondre valeurs du tableau et leur fréquence.
- Ne pas gérer les entiers négatifs.

## 💬 Ce que j’ai appris

- Utilisation combinée de `unordered_map` et `unordered_set`.
- Vérification d'unicité efficace à l’aide d’un set.

## ✅ Statut

Résolu avec succès le 01/08/2025.