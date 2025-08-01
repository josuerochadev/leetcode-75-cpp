# 1657. Determine if Two Strings Are Close

## 📝 Énoncé
Deux chaînes sont dites « close » si on peut transformer l'une en l'autre à l'aide :
1. D'échanges de lettres (swap).
2. D'échanges globaux de lettres existantes (tous les `a` deviennent des `b`, et vice versa).

## 💡 Stratégie
- Vérifier si les deux mots ont les **mêmes lettres** (mêmes ensembles de caractères).
- Vérifier si les **fréquences des lettres**, peu importe leur attribution, sont identiques.

## 🧠 Complexité
- Temps : O(n log n), dû au tri des fréquences.
- Espace : O(1), 26 lettres max.

## ⚠️ Pièges à éviter
- Comparer `set<char>` et non les chaînes directement.
- Trier les fréquences, pas les lettres.
- Ne pas confondre fréquence exacte et type de caractère.

## 💬 Ce que j’ai appris
- Utiliser `unordered_set` pour tester l'égalité d'alphabets.
- Une transformation de fréquence est possible uniquement si les caractères existent dans les deux chaînes.

## ✅ Statut
Résolu le 01/08/2025