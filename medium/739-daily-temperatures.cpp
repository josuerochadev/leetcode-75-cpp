// 739-daily-temperatures.cpp
// LeetCode 739. Daily Temperatures
// Difficulty: Medium
// https://leetcode.com/problems/daily-temperatures/

#include <vector>
#include <stack>
using namespace std;

/**
 * @brief Solution for LeetCode 739 - Daily Temperatures
 *
 * Given an array of daily temperatures, return an array where answer[i]
 * represents the number of days you have to wait after the i-th day
 * to get a warmer temperature. If no such day exists, answer[i] = 0.
 *
 * Strategy:
 * - Use a monotonic decreasing stack (storing indices).
 * - Iterate through temperatures.
 * - For each temperature:
 *   - While stack is not empty and current temperature > temperature at top index:
 *     - Pop index from stack and compute waiting days.
 *   - Push current index into stack.
 * - Complexity: O(n), because each index is pushed and popped once.
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // store indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                answer[idx] = i - idx; // number of days waited
            }
            st.push(i);
        }
        return answer;
    }
};