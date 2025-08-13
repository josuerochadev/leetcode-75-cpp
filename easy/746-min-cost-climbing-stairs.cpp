/*
 * 746. Min Cost Climbing Stairs
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/min-cost-climbing-stairs/
 *
 * Approach:
 *   Dynamic Programming (Bottom-Up)
 *   - At each step, the minimum cost to reach that step is:
 *       cost[i] + min(dp[i-1], dp[i-2])
 *   - Start from step 0 or step 1, result is min(dp[n-1], dp[n-2])
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) if optimized
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = 2; i <= n; i++) {
            int current = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

// Uncomment for manual testing
/*
int main() {
    Solution sol;
    vector<int> cost1 = {10, 15, 20};
    cout << sol.minCostClimbingStairs(cost1) << endl; // Expected 15

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << sol.minCostClimbingStairs(cost2) << endl; // Expected 6
}
*/