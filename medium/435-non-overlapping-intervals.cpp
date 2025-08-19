/*
 * LeetCode 435. Non-overlapping Intervals
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/non-overlapping-intervals/
 *
 * Pattern: Greedy (tri par fin croissante, sélection d'intervalles compatibles)
 * Idée clé: Minimiser les suppressions = Maximiser le nombre d'intervalles non-chevauchants.
 *           On trie par "end" croissant et on garde l'intervalle qui finit le plus tôt.
 *
 * Complexité:
 *   - Temps: O(n log n) (à cause du tri)
 *   - Espace: O(1) (hors tri in-place)
 *
 * Notes:
 * - Deux intervalles qui se touchent en un point (ex: [1,2] et [2,3]) NE se chevauchent PAS.
 * - On peut compter directement les suppressions pendant la sélection greedy.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

namespace lc0435 {

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = (int)intervals.size();
        if (n <= 1) return 0;

        // 1) Trier par "end" croissant (interval[1])
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] != b[1]) return a[1] < b[1];
                 return a[0] < b[0];
             });

        // 2) Greedy: on essaie de garder un maximum d'intervalles compatibles
        //    prevEnd = "fin" du dernier intervalle retenu
        int removals = 0;
        int prevEnd = intervals[0][1]; // on garde le premier (finit le plus tôt après tri)

        for (int i = 1; i < n; ++i) {
            int start = intervals[i][0];
            int end   = intervals[i][1];

            // Si l'intervalle courant commence avant la fin du précédent gardé => chevauchement
            if (start < prevEnd) {
                // Conflit: on supprime CELUI-CI (implicite) car il finit plus tard ou égal
                // (Le tri garantit que prevEnd est minimal à ce stade)
                ++removals;
                // On NE change PAS prevEnd: on conserve l'intervalle qui finit le plus tôt
            } else {
                // Pas de conflit: on le garde et on met à jour prevEnd
                prevEnd = end;
            }
        }

        return removals;
    }
};

} // namespace lc0435

/*
 * Notes de debug rapides:
 * - En cas d'erreur "use of undeclared identifier 'Solution'":
 *   -> Veillez à référencer lc0435::Solution si vous testez localement.
 *
 * Exemple d'usage local (à ne pas soumettre sur LeetCode):
 *
 * int main() {
 *     vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
 *     cout << lc0435::Solution().eraseOverlapIntervals(intervals) << "\n"; // attendu: 1
 * }
 */