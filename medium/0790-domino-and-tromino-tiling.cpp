/*
 *  File: 0790-domino-and-tromino-tiling.cpp
 *  Problem: 790. Domino and Tromino Tiling (LeetCode)
 *  Level: Medium
 *  Link: https://leetcode.com/problems/domino-and-tromino-tiling/
 *
 *  Approach:
 *    DP itératif, optimisation O(1).
 *    F(n) = nombre de pavages complets d'un plateau 2 x n avec dominos (2x1) et trominos.
 *
 *    Faits connus / dérivation (voir .md pour la preuve détaillée):
 *      - Relation de récurrence compacte:  F(n) = 2*F(n-1) + F(n-3),  pour n >= 3
 *      - Conditions initiales: F(0)=1, F(1)=1, F(2)=2
 *      - Modulo M = 1e9+7
 *
 *    Complexité:
 *      - Temps:  O(n)
 *      - Espace: O(1) (on ne conserve que F(n-1), F(n-2), F(n-3))
 *
 *  Why this design:
 *    - Header minimal et réutilisable pour le repo.
 *    - Pas de I/O lourde; solution embarquée en classe Solution, conforme aux attentes LeetCode.
 */

#include <iostream>
using namespace std;

class Solution {
    static constexpr int MOD = 1'000'000'007;
public:
    int numTilings(int n) {
        // Cas de base directement retournés
        if (n == 0) return 1;      // convention utile pour la DP
        if (n == 1) return 1;
        if (n == 2) return 2;

        // f0 = F(n-3), f1 = F(n-2), f2 = F(n-1)
        long long f0 = 1; // F(0)
        long long f1 = 1; // F(1)
        long long f2 = 2; // F(2)

        for (int k = 3; k <= n; ++k) {
            long long fk = ( (2LL * f2) % MOD + f0 ) % MOD; // F(k) = 2*F(k-1) + F(k-3)
            // Shift window
            f0 = f1;
            f1 = f2;
            f2 = fk;
        }
        return static_cast<int>(f2 % MOD);
    }
};

// --- (Optionnel, utile pour tester localement) ---
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     Solution s;
//     cout << s.numTilings(3) << "\n"; // attendu: 5
//     cout << s.numTilings(1) << "\n"; // attendu: 1
//     cout << s.numTilings(2) << "\n"; // attendu: 2
//     cout << s.numTilings(5) << "\n"; // vérification supplémentaire
//     return 0;
// }