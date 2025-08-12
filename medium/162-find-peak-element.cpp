/*
 * Author: Josué Xavier Rocha
 * Date: 2025-08-12
 * Problem: 162 - Find Peak Element
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-peak-element/
 * Topics: Array, Binary Search
 * 
 * Description:
 * Given an integer array nums, find a peak element and return its index.
 * A peak element is an element strictly greater than its neighbors.
 * nums[-1] and nums[n] are considered -∞.
 * Must be solved in O(log n) time.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element is greater than next, peak is on the left side (including mid)
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            // Else, peak is on the right side
            else {
                left = mid + 1;
            }
        }
        return left; // left == right, peak found
    }
};

// Example usage (can be removed in final submission)
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << "Peak Index: " << sol.findPeakElement(nums) << endl; // Output: 2
    return 0;
}