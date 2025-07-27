# 151. Reverse Words in a String

## 📝 Énoncé

> Given an input string `s`, reverse the order of the words.
>
> A word is defined as a sequence of non-space characters.
> The words in `s` will be separated by at least one space.
>
> Return a string of the words in reverse order concatenated by a single space.
> Ignore leading/trailing spaces and reduce multiple spaces to a single one.

## 💡 Stratégie

1. Utiliser `std::istringstream` pour découper la chaîne en mots, en sautant les espaces.
2. Stocker les mots dans un `vector<string>`.
3. Inverser le vecteur.
4. Reconstituer la chaîne finale avec des espaces simples.

## 🧠 Complexité

- Temps : O(n), où `n` est la taille de la chaîne.
- Espace : O(n), pour stocker les mots (pas in-place).

## ⚠️ Pièges à éviter

- Ne pas oublier de supprimer les espaces superflus en début, milieu ou fin.
- Attention à ne pas ajouter de double espace entre les mots en reconstituant la chaîne.
- Le `reverse` s'applique sur les mots, pas sur les caractères.

## 💬 Ce que j’ai appris

- `std::istringstream` est un excellent outil pour gérer les entrées basées sur des mots.
- La manipulation d’un `vector<string>` est très pratique pour gérer des séquences.
- Même un problème « string » peut être traité proprement en étapes modélisées.

## ✅ Statut

Résolu ✅ – soumis sur LeetCode avec succès.