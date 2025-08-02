# 2390. Removing Stars From a String

## 📝 Énoncé

On te donne une chaîne `s` contenant des lettres minuscules et des étoiles (`*`).  
À chaque `*`, tu dois **supprimer le caractère le plus proche à sa gauche**, **puis** la `*` elle-même.

Tu dois retourner la chaîne finale, une fois toutes les opérations effectuées.

Exemples :

- Input : `"leet**cod*e"` → Output : `"lecoe"`
- Input : `"erase*****"` → Output : `""`

## 💡 Stratégie

On peut simuler le comportement avec une **string** (ou stack) pour accumuler les caractères.  
À chaque fois qu’on lit une `*`, on fait un `pop_back()` pour annuler le dernier caractère.  
Sinon, on ajoute le caractère à la chaîne `result`.

Pourquoi ça fonctionne ?
- L’énoncé garantit que chaque `*` aura un caractère à gauche.
- On lit la chaîne de gauche à droite, ce qui permet de traiter les suppressions dans l’ordre.

## 🧠 Complexité

- **Temps** : O(n) – Un seul passage sur la chaîne.
- **Espace** : O(n) – Dans le pire des cas, on stocke tous les caractères sans `*`.

## ⚠️ Pièges à éviter

- Ne pas oublier de vérifier que `result` n’est pas vide avant `pop_back()`.
- Ne pas traiter la chaîne en arrière → le sens est important.
- Bien penser à ajouter les lettres une par une (pas de `.replace()` ou `.erase()` lourds).

## 💬 Ce que j’ai appris

- Utiliser une `string` comme une stack est très utile et plus lisible ici.
- Ce genre de problème illustre bien le concept de **structure de pile implicite**.
- Lire attentivement l’ordre des opérations dans les énoncés.

## ✅ Statut

Résolu le 02/08/2025