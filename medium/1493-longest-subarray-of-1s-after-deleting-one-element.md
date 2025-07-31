# 1493. Longest Subarray of 1's After Deleting One Element

## 📝 Énoncé

On te donne un tableau binaire `nums` (composé de 0 et 1). Tu dois supprimer **exactement un seul élément** du tableau (peu importe lequel), puis retourner **la longueur maximale d’une sous-suite consécutive ne contenant que des 1**.

## 💡 Stratégie

- Utilisation d’une **fenêtre glissante (sliding window)**.
- On autorise **au maximum un seul 0** dans la fenêtre (puisqu'on est autorisé à le supprimer).
- On déplace la fenêtre en avançant `left` si on dépasse un seul 0.
- À chaque itération, on met à jour le `maxLen = right - left + 1`.
- On retourne **`maxLen - 1`** car on doit obligatoirement supprimer un élément.

## 🧠 Complexité

- **Temps** : O(n), où `n` est la taille de `nums`.
- **Espace** : O(1), pas de structure auxiliaire utilisée.

## ⚠️ Pièges à éviter

- Ne pas oublier de **toujours supprimer un élément**, même s’il n’y a pas de zéro.
- Attention à la gestion des cas limites (ex : tous les 1 → retour `n - 1`).

## 💬 Ce que j’ai appris

- Maîtriser les fenêtres glissantes avec condition dynamique.
- Comprendre que la suppression obligatoire implique un ajustement du résultat final.

## ✅ Statut

Résolu ✅