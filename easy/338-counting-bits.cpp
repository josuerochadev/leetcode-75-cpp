// ============================================================================
//  LeetCode 338. Counting Bits
//  Difficulty: Easy
//  Author: Josué Xavier Rocha (Jurema)
//  Date: 2025-08-17
//
//  Énoncé (résumé):
//    Pour chaque i dans [0..n], retourner le nombre de bits à 1 de i.
//
//  Contraintes: 0 <= n <= 1e5
//
//  Approche retenue (DP - bit shift):
//    dp[i] = dp[i >> 1] + (i & 1)
//    Intuition: i >> 1 supprime le dernier bit (division par 2), (i & 1)
//    vaut 1 si le bit de poids faible de i est 1, sinon 0.
//    On calcule en une passe, O(n), sans __builtin_popcount.
//
//  Complexité:
//    Temps:  O(n)
//    Espace: O(n) pour le tableau de réponses
//
//  Alternatives:
//    - "lowbit" clear: dp[i] = dp[i & (i - 1)] + 1
//      (retire le bit à 1 le plus bas; également O(n))
// ============================================================================

#include <vector>

class Solution {
public:
    // Retourne pour chaque i ∈ [0..n] le nombre de bits à 1 de i.
    std::vector<int> countBits(int n) {
        std::vector<int> dp(n + 1, 0);
        // dp[0] = 0 par défaut
        for (int i = 1; i <= n; ++i) {
            // i >> 1 : i sans son LSB ; (i & 1) vaut 1 si le LSB est 1
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }

    // Variante pédagogique (non utilisée par LeetCode):
    // dp[i] = dp[i & (i - 1)] + 1; // enlève le bit à 1 le plus bas
    // std::vector<int> countBitsLowbit(int n) {
    //     std::vector<int> dp(n + 1, 0);
    //     for (int i = 1; i <= n; ++i) {
    //         dp[i] = dp[i & (i - 1)] + 1;
    //     }
    //     return dp;
    // }
};
