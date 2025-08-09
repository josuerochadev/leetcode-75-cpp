/*
 * LeetCode 994 - Rotting Oranges
 * Difficulty: Medium
 * Topic Tags: BFS, Matrix, Multi-source BFS
 *
 * Summary:
 *   On propague la "pourriture" depuis toutes les oranges pourries (valeur 2)
 *   simultanément, minute par minute (niveaux BFS). Chaque minute, toutes les
 *   oranges fraîches (1) adjacentes en 4-directions deviennent pourries (2).
 *   On cherche le nombre minimal de minutes pour que plus aucune orange fraîche ne reste.
 *   Si impossible, on retourne -1.
 *
 * Why this implementation:
 *   - Multi-source BFS naturel: on enfile toutes les sources (2) au départ.
 *   - Comptage des niveaux BFS pour calculer le temps.
 *   - Compteur de fraîches pour valider l’atteignabilité.
 *
 * Complexity:
 *   - Temps: O(m*n) — chaque case visitée au plus une fois.
 *   - Espace: O(m*n) pour la queue dans le pire cas.
 *
 * Reusability:
 *   - Patron simple de BFS grille avec directions et comptage par "vagues".
 *   - Facile à répliquer pour d’autres problèmes de diffusion en grille.
 */

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = (int)grid.size();
        const int n = (int)grid[0].size();

        queue<pair<int,int>> q;   // positions des oranges pourries initiales
        int fresh = 0;            // nombre d'oranges fraîches
        // Directions: haut, bas, gauche, droite
        const int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        // 1) Scanner la grille: compter les fraîches et enqueuer toutes les pourries
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    ++fresh;
                }
            }
        }

        // Cas rapide: aucune orange fraîche dès le départ
        if (fresh == 0) return 0;

        int minutes = 0;

        // 2) BFS par "vagues" (chaque vague = 1 minute si on fait pourrir au moins une orange)
        while (!q.empty()) {
            int sz = (int)q.size();
            bool progressed = false; // indique si au moins une orange a pourri dans cette minute

            for (int i = 0; i < sz; ++i) {
                auto [r, c] = q.front(); q.pop();

                for (auto &d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    // On ne peut faire pourrir que des oranges fraîches dans les bornes
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] != 1) continue;

                    // Cette orange fraîche devient pourrie
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    --fresh;
                    progressed = true;
                }
            }

            // Si on a fait progresser la pourriture, on a consommé une minute
            if (progressed) ++minutes;
        }

        // 3) Si des fraîches restent, impossible de toutes les atteindre
        return (fresh == 0) ? minutes : -1;
    }
};

/*
 * Notes d’implémentation:
 * - Pas de main() car LeetCode instancie Solution et appelle orangesRotting().
 * - "progressed" évite d’incrémenter les minutes quand aucune propagation n’a lieu.
 * - Stratégie robuste face aux grilles sans pourri initial (si fresh>0 && q vide => -1).
 */