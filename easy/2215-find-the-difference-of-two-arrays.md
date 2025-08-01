# 2215. Find the Difference of Two Arrays

## 📝 Énoncé

Retourner deux listes :
- les entiers distincts dans `nums1` qui ne sont pas dans `nums2`
- les entiers distincts dans `nums2` qui ne sont pas dans `nums1`

## 💡 Stratégie

1. Utiliser deux `unordered_set` pour retirer les doublons.
2. Itérer chaque ensemble et vérifier ce qui est absent de l'autre.
3. Stocker les valeurs uniques dans des vecteurs et retourner `{vec1, vec2}`.

## 🧠 Complexité

- Temps : O(n + m) où n = taille de `nums1`, m = taille de `nums2`
- Espace : O(n + m) pour les `unordered_set` et le résultat

## ⚠️ Pièges à éviter

- Ne pas oublier de retirer les doublons.
- Ne pas retourner les doublons plusieurs fois.
- L'ordre des éléments n’a pas d’importance.

## 💬 Ce que j’ai appris

- Utiliser `unordered_set` permet une recherche rapide (O(1)) et évite les doublons.
- Attention à bien convertir les `vector` en `set` pour les comparaisons.

## ✅ Statut

Résolu avec succès le 01/08/2025