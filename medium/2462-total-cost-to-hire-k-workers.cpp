/*
 *  LeetCode 2462 - Total Cost to Hire K Workers
 *  Difficulty: Medium
 *  Date: 2025-08-10
 *
 *  Pattern: Two-pointer + Two min-heaps (priority_queue with greater<>).
 *  Key idea:
 *    - On considère deux fenêtres de "candidates" en tête et en queue du tableau.
 *    - À chaque session d'embauche, on prend le coût minimal parmi les deux tas.
 *      Tie-break: si coûts égaux, on choisit l'indice le plus petit.
 *    - Après avoir choisi à gauche, on pousse le prochain élément à gauche (si non croisé),
 *      idem pour la droite. On évite tout chevauchement gauche/droite.
 *
 *  Complexity:
 *    - Build & operations: O((n + k) * log C) où C = candidates (au max ~2C en tas).
 *    - Mémoire: O(C).
 *
 *  Notes de repo:
 *    - En-tête standard, pas de I/O depuis stdin pour faciliter l'import dans LeetCode.
 *    - Utiliser long long pour la somme.
 */

#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        const int n = (int)costs.size();
        // Min-heaps de paires (cost, index) pour tie-break par plus petit index.
        using Node = pair<int,int>;
        priority_queue<Node, vector<Node>, greater<Node>> leftPQ, rightPQ;

        int L = 0;
        int R = n - 1;

        // Remplir la fenêtre gauche (jusqu'à candidates éléments, sans croiser R)
        for (int c = 0; c < candidates && L <= R; ++c) {
            leftPQ.emplace(costs[L], L);
            ++L;
        }
        // Remplir la fenêtre droite (idem)
        for (int c = 0; c < candidates && L <= R; ++c) {
            rightPQ.emplace(costs[R], R);
            --R;
        }

        long long total = 0;

        for (int hired = 0; hired < k; ++hired) {
            // Choisir le meilleur entre leftPQ et rightPQ.
            // Cas bord: si un des tas est vide, on prend dans l'autre.
            if (rightPQ.empty() || (!leftPQ.empty() && leftPQ.top() <= rightPQ.top())) {
                // Prendre à gauche
                auto [cost, idx] = leftPQ.top(); leftPQ.pop();
                total += (long long)cost;

                // Recharger la fenêtre gauche si possible
                if (L <= R) {
                    leftPQ.emplace(costs[L], L);
                    ++L;
                }
            } else {
                // Prendre à droite
                auto [cost, idx] = rightPQ.top(); rightPQ.pop();
                total += (long long)cost;

                // Recharger la fenêtre droite si possible
                if (L <= R) {
                    rightPQ.emplace(costs[R], R);
                    --R;
                }
            }
        }

        return total;
    }
};

/*
 * Snippet de test local (optionnel):
 *
 * int main() {
 *     Solution s;
 *     vector<int> costs = {17,12,10,2,7,2,11,20,8};
 *     cout << s.totalCost(costs, 3, 4) << "\n"; // attendu: 11
 *     vector<int> costs2 = {1,2,4,1};
 *     cout << s.totalCost(costs2, 3, 3) << "\n"; // attendu: 4
 * }
 */