# 🧩 1768 - Merge Strings Alternately

## 📝 Énoncé
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

### Example 1:

> **Input:** word1 = "abc", word2 = "pqr"  
> **Output:** "apbqcr"  
> **Explanation:** The merged string will be merged as so:  
> word1:  a   b   c  
> word2:    p   q   r  
> merged: a p b q c r

### Example 2:

> **Input:** word1 = "ab", word2 = "pqrs"  
> **Output:** "apbqrs"  
> **Explanation:** Notice that as word2 is longer, "rs" is appended   to the end.  
> word1:  a   b  
> word2:    p   q   r   s  
> merged: a p b q   r   s

### Example 3:

> **Input:**: word1 = "abcd", word2 = "pq"  
> **Output**: "apbqcd"  
> **Explanation**: Notice that as word1 is longer, "cd" is appended to the end.  
word1:  a   b   c   d  
word2:    p   q  
merged: a p b q c   d

### Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

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