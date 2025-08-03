# 933. Number of Recent Calls

## 📝 Énoncé
On doit implémenter une classe `RecentCounter` avec deux opérations :
- `RecentCounter()` initialise le compteur.
- `ping(t)` ajoute un timestamp `t` (en millisecondes) et retourne le nombre de requêtes dans les 3000 dernières millisecondes, incluant `t`.

Les appels à `ping` sont toujours faits avec une valeur strictement croissante de `t`.

## 💡 Stratégie
On utilise une **file FIFO (`queue`)** pour garder uniquement les timestamps dans la fenêtre `[t - 3000, t]`.  
À chaque `ping(t)`, on :
1. Ajoute `t` dans la queue.
2. Supprime tous les éléments qui sont strictement inférieurs à `t - 3000`.
3. Retourne la taille de la queue (nombre de pings récents).

## 🧠 Complexité
- **Temps :** O(1) amorti par appel à `ping`, car chaque élément est inséré et supprimé au plus une fois.
- **Espace :** O(W), avec W = taille maximale de la fenêtre temporelle (en pratique ≤ 10⁴).

## ⚠️ Pièges à éviter
- Oublier de retirer les éléments en dehors de la fenêtre `[t-3000, t]`.
- Croire que les temps ne sont pas triés ; c’est garanti par la contrainte du problème.

## 💬 Ce que j’ai appris
- Utilisation efficace de `std::queue` pour une fenêtre glissante.
- Optimisation amortie des opérations grâce aux structures de données adaptées.

## ✅ Statut
Résolu le 03/08/2025