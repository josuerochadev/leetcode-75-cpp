# 994. Rotting Oranges
## 📝 Énoncé
On dispose d’une grille `m x n` contenant:
- `0` : case vide
- `1` : orange fraîche
- `2` : orange pourrie

Chaque minute, toute orange fraîche adjacente **4-directionnellement** à une orange pourrie devient pourrie.  
Retourner le **minimum** de minutes pour qu’il ne reste **aucune** orange fraîche. Si c’est **impossible**, retourner `-1`.

## 💡 Stratégie
**Multi-source BFS** (parfait pour une propagation simultanée):
1. Enfiler **toutes** les positions des oranges pourries (`2`) dès le départ.
2. Compter le nombre d’oranges **fraîches**.
3. Lancer un BFS **par niveaux** (chaque niveau = 1 minute si au moins une propagation a lieu).
4. À chaque vague, pour chaque case pourrie actuelle, infecter ses voisins frais (haut, bas, gauche, droite), les marquer `2`, les enfiler, décrémenter le compteur de fraîches.
5. **Compter les minutes** uniquement si au moins une orange a pourri durant la vague.
6. À la fin, si des fraîches restent → `-1`, sinon → minutes.

Pourquoi ça marche : toutes les sources (oranges pourries) propagent **en parallèle**, ce qui modélise exactement “chaque minute” sur l’ensemble de la grille.

## 🧠 Complexité
- **Temps** : `O(m*n)` (chaque case visitée au plus une fois).
- **Espace** : `O(m*n)` (file du BFS dans le pire cas).

## ⚠️ Pièges à éviter
- **Incrémenter chaque tour de boucle sans propagation** : fausse une minute supplémentaire. Utiliser un flag `progressed`.
- **Oublier le cas “aucune orange fraîche au départ”** : la réponse doit être `0`.
- **Traiter les diagonales** : l’énoncé n’autorise que 4 directions.
- **Ne pas marquer immédiatement une orange fraîche comme pourrie** : risque de la pourrir plusieurs fois, ou de la compter deux fois.

## 💬 Ce que j’ai appris
- Le pattern **multi-source BFS** est clé pour toutes les diffusions simultanées en grille (feu, rumeurs, gaz, distance minimale depuis plusieurs sources).
- Le compteur de fraîches simplifie la condition de fin (et évite un rescan de la grille).

## ✅ Statut
Implémenté et testé localement (logique BFS validée sur les exemples de l’énoncé).