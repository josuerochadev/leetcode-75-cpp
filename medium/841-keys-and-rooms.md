# 841. Keys and Rooms

## 📝 Énoncé
On a `n` salles numérotées de 0 à n - 1. Toutes sont fermées sauf la salle 0.  
Chaque salle peut contenir des clés vers d'autres salles.  
Il faut déterminer si l'on peut visiter **toutes** les salles.

## 💡 Stratégie
On utilise une **DFS itérative avec une stack** pour simuler une exploration à partir de la salle 0.  
On garde une structure `visited` pour savoir quelles salles ont été visitées.  
Chaque fois qu'on entre dans une salle, on ajoute les clés trouvées dans la pile.  
Si à la fin, on a visité toutes les salles, on retourne `true`.

## 🧠 Complexité
- Temps : O(N + E), où `N` est le nombre de salles et `E` le nombre total de clés.
- Espace : O(N), pour la pile et l’ensemble `visited`.

## ⚠️ Pièges à éviter
- Ne pas revisiter les salles déjà visitées (utiliser `unordered_set`).
- Ne pas oublier d’ajouter une clé **même si elle mène à une salle plus grande** que le numéro actuel.
- Attention : certaines salles peuvent ne pas contenir de clés du tout (`rooms[i] = []`).

## 💬 Ce que j’ai appris
- Les parcours DFS/BFS sont puissants pour les problèmes de connexité.
- Le `unordered_set` est idéal pour garder une trace des éléments déjà traités.
- Il est parfois plus simple d’implémenter DFS de manière **itérative** avec une pile plutôt que récursive.

## ✅ Statut
Résolu et testé avec succès le 08/08/2025.