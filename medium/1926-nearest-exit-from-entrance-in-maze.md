# 1926. Nearest Exit from Entrance in Maze

## 📝 Énoncé
On vous donne une grille `m x n` représentant un labyrinthe : `'.'` = case vide, `'+'` = mur.  
On vous donne la position d’entrée `[erow, ecol]`. À chaque pas, on peut se déplacer en haut, bas, gauche, droite, sans traverser les murs ni sortir de la grille.  
Un **exit** est une case vide située sur la **bordure** de la grille (l’entrée ne compte pas).  
But : retourner le **nombre minimal de pas** pour atteindre **l’exit le plus proche**, ou `-1` si impossible.

## 💡 Stratégie
- Modéliser la grille comme un graphe non pondéré → **BFS (Breadth-First Search)** pour la plus courte distance.
- Démarrer la BFS depuis l’entrée (la marquer visitée immédiatement).
- Parcourir couche par couche (niveau par niveau). La première fois qu’on arrive sur **une case vide en bordure**, on retourne `steps + 1`.
- Marquer les cases visitées **dès l’enqueue** (par exemple en remplaçant `'.'` par `'+'`) pour éviter les revisites et les cycles.

## 🧠 Complexité
- **Temps** : `O(m * n)` (chaque case est insérée au plus une fois dans la file).
- **Espace** : `O(m * n)` dans le pire cas (contenu de la file / marquage visité).

## ⚠️ Pièges à éviter
- **Ne pas compter l’entrée comme exit** même si elle est sur la bordure. On ne retourne jamais `0`.
- **Toujours marquer visité à l’enqueue** et non au dequeue → évite d’enfiler deux fois la même case.
- **Contrôler les bornes** avant de tester la valeur de la case.
- **Ne pas marcher sur les `'+'`** (murs ou cases déjà visitées).
- **Premier exit gagné** : dès qu’une case vide en bordure est atteinte, c’est la plus proche grâce à la BFS.

## 💬 Ce que j’ai appris
- Les plus courts chemins dans un graphe non pondéré se résolvent naturellement avec une **BFS**.
- Le marquage **in-place** (remplacer `'.'` par `'+'`) simplifie l’empreinte mémoire et le code.
- La gestion **par niveaux** clarifie le comptage des pas.

## ✅ Statut
Terminé ✅ – solution BFS validée localement.