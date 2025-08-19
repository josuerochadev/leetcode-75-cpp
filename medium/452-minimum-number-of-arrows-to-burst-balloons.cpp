/*
 * LeetCode 452 — Minimum Number of Arrows to Burst Balloons (Medium)
 * URL: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 *
 * ✅ Approche: Interval Scheduling Greedy (trier par extrémité droite croissante)
 * 🧠 Idée clé:
 *   - Un tir vertical à x perce tous les ballons dont [start, end] contient x.
 *   - Pour minimiser les flèches, on maximise le chevauchement couvert par une flèche.
 *   - Stratégie gloutonne standard: trier par 'end' (croissant) et tirer à 'end' du premier intervalle,
 *     puis réutiliser ce tir pour tous les intervalles qui commencent <= x_tir.
 *     Dès qu'un intervalle commence > x_tir, on doit tirer une nouvelle flèche à son 'end'.
 *
 * ⏱️ Complexité:
 *   - Tri: O(n log n)
 *   - Parcours: O(n)
 *   - Espace: O(1) hors tri
 *
 * ⚠️ Pièges à éviter:
 *   - Ne pas trier par start: le bon tri est par end (croissant).
 *   - Comparator: éviter les soustractions (risque overflow); comparer avec '<'.
 *   - Cas n=1 => réponse 1.
 *   - Valeurs négatives possibles et grands entiers: rester en 32 bits sans soustraction dans le tri.
 *
 * 🧩 Modèle de repo:
 *   - Classe globale Solution pour compatibilité LeetCode.
 *   - Aucun main(); comments de test fournis mais désactivés.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int n = static_cast<int>(points.size());
        if (n == 0) return 0;
        // 1) Trier par extrémité droite (xend) croissante
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] == b[1]) return a[0] < b[0]; // tie-break facultatif
                 return a[1] < b[1];
             });

        // 2) Tirer une première flèche au 'end' du 1er intervalle
        int arrows = 1;
        long long arrowX = static_cast<long long>(points[0][1]); // cast prudent

        // 3) Réutiliser la flèche tant que les prochains intervalles chevauchent arrowX
        for (int i = 1; i < n; ++i) {
            long long start = static_cast<long long>(points[i][0]);
            long long end   = static_cast<long long>(points[i][1]);
            if (start <= arrowX) {
                // chevauchement: la flèche actuelle perce aussi ce ballon
                continue;
            }
            // rupture de chevauchement -> nouvelle flèche placée à la fin de cet intervalle
            ++arrows;
            arrowX = end;
        }

        return arrows;
    }
};

/*
 // 🧪 Exemple de test local (désactivé pour LeetCode)
 // Compile localement en isolant ce fichier:
 // g++ -std=c++17 -O2 452-minimum-number-of-arrows-to-burst-balloons.cpp && ./a.out
int main() {
    Solution s;
    vector<vector<int>> p1 = {{10,16},{2,8},{1,6},{7,12}};
    cout << s.findMinArrowShots(p1) << " (attendu 2)\n";

    vector<vector<int>> p2 = {{1,2},{3,4},{5,6},{7,8}};
    cout << s.findMinArrowShots(p2) << " (attendu 4)\n";

    vector<vector<int>> p3 = {{1,2},{2,3},{3,4},{4,5}};
    cout << s.findMinArrowShots(p3) << " (attendu 2)\n";
}
*/