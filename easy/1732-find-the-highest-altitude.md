# 1732. Find the Highest Altitude

## 📝 Énoncé

Tu commences un voyage à vélo à l’altitude 0. On te donne un tableau `gain` où `gain[i]` représente le gain (ou la perte) d’altitude entre les points `i` et `i+1`.

Retourne **l’altitude la plus haute atteinte** pendant le trajet.

Exemple :  
Input: `[-5,1,5,0,-7]` → Altitudes : `[0, -5, -4, 1, 1, -6]` → max = **1**

## 💡 Stratégie

1. Initialiser `currentAltitude = 0`
2. Itérer sur `gain` :
   - Ajouter chaque gain à `currentAltitude`
   - Garder en mémoire le maximum entre `maxAltitude` et `currentAltitude`
3. Retourner `maxAltitude`

## 🧠 Complexité

- Temps : `O(n)` — une seule passe sur le tableau `gain`
- Espace : `O(1)` — utilisation de deux variables

## ⚠️ Pièges à éviter

- Ne pas oublier que l'altitude initiale est `0`
- Ne pas confondre `gain[i]` avec l’altitude absolue : il s’agit d’un **écart**, pas de l’altitude en soi

## 💬 Ce que j’ai appris

- Comment calculer des altitudes cumulées avec une somme partielle
- L’intérêt de suivre un maximum pendant une itération

## ✅ Statut

Résolu le 31/07/2025