# 739. Daily Temperatures

## 📝 Énoncé

On vous donne un tableau d’entiers `temperatures` représentant les températures journalières.  
Retournez un tableau `answer` tel que `answer[i]` soit le nombre de jours qu’il faut attendre après le jour `i` pour avoir une température plus chaude.  
Si ce n’est pas possible, alors `answer[i] = 0`.

Exemple :  
Input: `[73,74,75,71,69,72,76,73]`  
Output: `[1,1,4,2,1,1,0,0]`

## 💡 Stratégie

- Utiliser une **pile monotone décroissante** qui stocke les indices des jours.  
- Parcourir le tableau :  
  - Tant que la pile n’est pas vide et que la température actuelle est plus grande que celle stockée à l’indice en haut de pile → dépiler et calculer le nombre de jours d’attente.  
  - Empiler l’indice courant.  
- Chaque élément est empilé/dépilé au maximum une fois → complexité en **O(n)**.

## 🧠 Complexité

- Temps : **O(n)** (chaque élément est poussé et retiré une fois).  
- Mémoire : **O(n)** (pile des indices).

## ⚠️ Pièges à éviter

- Initialiser le tableau `answer` avec des zéros, sinon les jours sans solution ne seront pas gérés.  
- Ne pas confondre la valeur des températures et l’indice → on stocke les indices pour pouvoir calculer la différence.  
- Bien gérer la boucle `while` pour dépiler plusieurs indices si nécessaire.

## 💬 Ce que j’ai appris

- L’importance des **stacks monotones** pour résoudre rapidement des problèmes de "prochain élément plus grand".  
- Comment transformer un problème qui semble demander une double boucle naïve en une solution optimisée O(n).

## ✅ Statut

✔️ Fini et validé sur LeetCode.
