# 1004. Max Consecutive Ones III

## 📝 Énoncé
On te donne un tableau binaire `nums` et un entier `k`. Tu peux changer **au plus `k` zéros** en des 1. Retourne la **longueur maximale** d’une sous-partie du tableau avec uniquement des 1 consécutifs après ces changements.

## 💡 Stratégie
Utilisation d'une **fenêtre glissante** pour conserver une sous-partie avec au plus `k` zéros.  
Dès que le nombre de zéros dépasse `k`, on déplace le début de la fenêtre (`left`) jusqu'à ce qu'elle contienne de nouveau au plus `k` zéros.  
À chaque étape, on met à jour la **longueur maximale** observée.

## 🧠 Complexité
- Temps : `O(n)` — chaque élément est vu au plus deux fois (par `right` et `left`)
- Espace : `O(1)` — pas de structure auxiliaire

## ⚠️ Pièges à éviter
- Ne pas oublier de **réduire la fenêtre** si le nombre de zéros dépasse `k`
- Bien gérer le cas où `k = 0` (aucun zéro autorisé)
- Ne pas utiliser `erase()` sur un vecteur — trop coûteux ici

## 💬 Ce que j’ai appris
- La puissance de la technique **sliding window** pour gérer des contraintes dynamiques
- Comment maintenir des contraintes (ici : ≤ `k` zéros) sur une sous-partie d’un tableau

## ✅ Statut
✅ Résolu le 2025-07-30