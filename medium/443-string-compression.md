# 443. String Compression

## 📝 Énoncé

On vous donne un tableau de caractères. Compressez-le en regroupant les caractères répétés consécutivement sous la forme "lettre + nombre de répétitions". Le tout doit être stocké dans le tableau d'origine. Retournez la nouvelle taille du tableau.

## 💡 Stratégie

- Utiliser deux pointeurs :
  - `i` : lecture des groupes de caractères
  - `write` : position pour écrire le résultat
- Pour chaque groupe de caractères répétés :
  - Écrire le caractère
  - S'il y a plus d’une occurrence, écrire le nombre en caractères

## 🧠 Complexité

- Temps : O(n) — Chaque caractère est lu et écrit une seule fois
- Espace : O(1) — Aucun espace supplémentaire utilisé (à part quelques variables)

## ⚠️ Pièges à éviter

- N'oublie pas de convertir les chiffres du `count` en `char`
- Ne pas écrire le chiffre `1` après une lettre : `"a"` reste `"a"`, pas `"a1"`
- Évite de dépasser les bornes avec `i < chars.size()`

## 💬 Ce que j’ai appris

- Comment manipuler un tableau en C++ en place
- Utilisation de `std::to_string` pour convertir un `int` en `string`
- Techniques à deux pointeurs (lecture/écriture)

## ✅ Statut

✅ Résolu et testé avec succès.