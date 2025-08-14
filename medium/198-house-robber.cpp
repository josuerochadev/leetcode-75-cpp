/*
 * 198. House Robber
 * Difficulty: Medium
 * https://leetcode.com/problems/house-robber/
 *
 * Problem:
 * You are a professional robber planning to rob houses along a street.
 * Each house has some money stashed. You cannot rob two adjacent houses
 * because their security systems will alert the police.
 *
 * Given an integer array nums representing the money in each house,
 * return the maximum amount you can rob without alerting the police.
 *
 * Example:
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 *
 * Approach:
 * Dynamic Programming (Bottom-Up):
 * - Idea: At each house i, choose the better of:
 *   (1) Robbing current house → nums[i] + dp[i-2]
 *   (2) Skipping current house → dp[i-1]
 * - Base cases:
 *   dp[0] = nums[0]
 *   dp[1] = max(nums[0], nums[1])
 * - Result = dp[n-1]
 *
 * Complexity:
 * Time: O(n) — one pass through nums
 * Space: O(1) — only keep track of last two results
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = nums[0]; // dp[i-2]
        int prev1 = max(nums[0], nums[1]); // dp[i-1]

        for (int i = 2; i < n; ++i) {
            int current = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,1};
    vector<int> nums2 = {2,7,9,3,1};

    cout << sol.rob(nums1) << endl; // Output: 4
    cout << sol.rob(nums2) << endl; // Output: 12

    return 0;
}