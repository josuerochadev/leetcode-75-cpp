# 1137. N-th Tribonacci Number

## 📝 Énoncé
La suite de Tribonacci est définie comme suit :
- T₀ = 0, T₁ = 1, T₂ = 1
- Tₙ₊₃ = Tₙ + Tₙ₊₁ + Tₙ₊₂ pour n ≥ 0

Étant donné un entier n, retourner Tₙ.

**Exemple :**

`Input: n = 4
Output: 4
Explication:
T₃ = 0 + 1 + 1 = 2
T₄ = 1 + 1 + 2 = 4`

## 💡 Stratégie
- Cas simples : n = 0 → 0, n = 1 ou n = 2 → 1.
- Pour n ≥ 3 : calculer chaque terme en additionnant les trois précédents.
- Utiliser trois variables pour stocker les derniers termes et itérer jusqu'à n.
- Complexité O(n) avec O(1) espace mémoire.

## 🧠 Complexité
- **Temps :** O(n)  
- **Espace :** O(1)

## ⚠️ Pièges à éviter
- Oublier les cas de base (0, 1, 2).
- Risque d’erreur si on modifie t0, t1, t2 dans le mauvais ordre (il faut utiliser une variable temporaire t3).
- Ne pas utiliser un tableau inutilement (inutile pour 0 <= n <= 37).

## 💬 Ce que j’ai appris
- La suite de Tribonacci est similaire à Fibonacci mais avec trois termes précédents.
- On peut réduire la mémoire à trois variables seulement.
- Pour de petites bornes, un calcul itératif est plus simple et efficace qu'une récursion.

## ✅ Statut
Solution validée ✅