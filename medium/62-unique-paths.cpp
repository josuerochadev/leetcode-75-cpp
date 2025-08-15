// 0062-unique-paths.cpp
// Problem: 62. Unique Paths
// Level: Medium
// Link: https://leetcode.com/problems/unique-paths/
// Date: 2025-08-15
//
// Strategy:
//  - Math/combinatorics: number of paths = C(m+n-2, m-1) = (m+n-2)! / ((m-1)! (n-1)!)
//  - Compute iteratively in O(min(m,n)) to avoid factorial overflow and keep integers exact.
//  - Uses 64-bit (long long); the problem guarantees answer <= 2e9.
//
// Reusability notes:
//  - Keep the Solution class signature exactly as LeetCode expects.
//  - No i/o main(): LeetCode injecte ses propres tests.
//
// Complexity:
//  - Time: O(min(m, n))
//  - Space: O(1)

#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Handle trivial cases explicitly
        if (m == 1 || n == 1) return 1;

        // We compute C(N, K) where N = m + n - 2, K = min(m-1, n-1)
        long long N = static_cast<long long>(m + n - 2);
        long long K = static_cast<long long>(min(m - 1, n - 1));

        long long res = 1;
        // Multiplicative formula: C(N, K) = product_{i=1..K} (N - K + i) / i
        for (long long i = 1; i <= K; ++i) {
            res = (res * (N - K + i)) / i; // exact division at each step
        }
        return static_cast<int>(res);
    }
};