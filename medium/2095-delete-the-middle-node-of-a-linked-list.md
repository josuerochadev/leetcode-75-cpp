# 2095. Delete the Middle Node of a Linked List

## 📝 Énoncé
Supprime le nœud du milieu d'une liste chaînée à indexation 0. Si la liste a un seul nœud, retourne `nullptr`.

## 💡 Stratégie
Utiliser deux pointeurs :
- `fast` avance deux fois plus vite que `slow`.
- Quand `fast` atteint la fin, `slow` pointe le milieu.
On garde également une référence à `prev` pour supprimer proprement le nœud `slow`.

## 🧠 Complexité
- Temps : `O(n)` — On traverse la liste une fois.
- Espace : `O(1)` — Pas de mémoire additionnelle utilisée.

## ⚠️ Pièges à éviter
- N'oublie pas de gérer le cas où la liste contient un seul élément.
- Ne pas perdre le lien entre `prev` et le reste de la liste.

## 💬 Ce que j’ai appris
- Le schéma classique "slow/fast pointer" est idéal pour détecter un milieu.
- Bien gérer les pointeurs dans une liste chaînée est crucial pour éviter les leaks.

## ✅ Statut
Résolu le 04/08/2025