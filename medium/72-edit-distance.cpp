// 72-edit-distance.cpp
// LeetCode 72. Edit Distance
// Difficulty: Medium
// Author: Josué (repo: leetcode-75-cpp)
// Description:
//   Compute the Levenshtein distance (minimum edits: insert, delete, replace)
//   to transform word1 into word2.
// Key idea:
//   Bottom-up DP over prefixes of the two strings.
//   dp[i][j] = min edits to convert word1[0..i-1] -> word2[0..j-1].
//   Transitions:
//     if word1[i-1] == word2[j-1]:
//        dp[i][j] = dp[i-1][j-1]
//     else:
//        dp[i][j] = 1 + min(
//           dp[i-1][j]   , // delete in word1
//           dp[i][j-1]   , // insert into word1
//           dp[i-1][j-1]   // replace
//        )
//
// Complexity:
//   Time:  O(n * m)
//   Space: O(n * m) (can be optimized to O(min(n,m)) if needed)

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        const int n = static_cast<int>(word1.size());
        const int m = static_cast<int>(word2.size());

        // Edge cases covered naturally by the DP base rows/cols,
        // but early-outs are cheap and explicit.
        if (n == 0) return m; // insert all chars of word2
        if (m == 0) return n; // delete all chars of word1

        // dp[i][j] = edits for word1[0..i-1] -> word2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases: one string empty
        for (int i = 0; i <= n; ++i) dp[i][0] = i; // delete i chars
        for (int j = 0; j <= m; ++j) dp[0][j] = j; // insert j chars

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // no-op
                } else {
                    int del = dp[i - 1][j];     // delete word1[i-1]
                    int ins = dp[i][j - 1];     // insert word2[j-1]
                    int rep = dp[i - 1][j - 1]; // replace word1[i-1] -> word2[j-1]
                    dp[i][j] = 1 + min({del, ins, rep});
                }
            }
        }
        return dp[n][m];
    }
};

/*
//// Optional: space-optimized variant (O(min(n,m)) memory)

int minDistance_spaceOptimized(string a, string b) {
    if (a.size() < b.size()) swap(a, b); // ensure a is longer
    int n = a.size(), m = b.size();
    vector<int> prev(m + 1), cur(m + 1);
    iota(prev.begin(), prev.end(), 0); // prev[j] = j

    for (int i = 1; i <= n; ++i) {
        cur[0] = i;
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) cur[j] = prev[j - 1];
            else cur[j] = 1 + min({ prev[j], cur[j - 1], prev[j - 1] });
        }
        swap(prev, cur);
    }
    return prev[m];
}
*/