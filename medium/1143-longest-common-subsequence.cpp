/*
 * LeetCode 1143. Longest Common Subsequence
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-common-subsequence/
 *
 * ✨ Approach
 * DP (programmation dynamique) Bottom-Up.
 * Soit text1 de taille n, text2 de taille m.
 * Définissons dp[i][j] = longueur de la LCS entre suffixes text1[i:] et text2[j:].
 * Transition:
 *   - Si text1[i] == text2[j]  -> dp[i][j] = 1 + dp[i+1][j+1]
 *   - Sinon                    -> dp[i][j] = max(dp[i+1][j], dp[i][j+1])
 * Base: toute case en dehors du tableau vaut 0.
 * Réponse: dp[0][0].
 *
 * ⏱️ Complexité
 * Temps:  O(n * m)
 * Mémoire: O(n * m) (version tabulation claire)
 * (Option: optimisation mémoire à O(min(n, m)) possible si besoin.)
 *
 * ✅ Bonnes pratiques
 * - Éviter la récursion pure (exponentielle) sans mémoïsation.
 * - Inverser les boucles (du bas vers le haut) pour éviter des conditions supplémentaires.
 * - Optionnel: swapper pour itérer sur la string la plus courte en optimisation 1D.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Version tabulation 2D lisible et robuste
    int longestCommonSubsequence(string text1, string text2) {
        const int n = (int)text1.size();
        const int m = (int)text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // On remplit en partant du bas (suffixes)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }

    // --- Variante mémoire O(min(n, m)) (non utilisée par défaut)
    int longestCommonSubsequenceSpaceOptimized(string a, string b) {
        // On force b à être la plus courte
        if (b.size() > a.size()) swap(a, b);
        const int n = (int)a.size();
        const int m = (int)b.size();
        vector<int> next(m + 1, 0), curr(m + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            // curr[m] = 0 (déjà initialisé)
            for (int j = m - 1; j >= 0; --j) {
                if (a[i] == b[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            swap(curr, next);
            fill(curr.begin(), curr.end(), 0);
        }
        return next[0];
    }
};

/*
 * Notes de maintenance
 * - API attendue sur LeetCode: int longestCommonSubsequence(string, string)
 * - Pas de main() local requis. LeetCode instancie Solution et appelle la méthode.
 */