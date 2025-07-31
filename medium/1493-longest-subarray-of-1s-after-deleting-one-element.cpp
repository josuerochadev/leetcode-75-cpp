// 1493. Longest Subarray of 1's After Deleting One Element
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <vector>
#include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int left = 0;
        int maxLen = 0;
        int zeroCount = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0)
                ++zeroCount;

            while (zeroCount > 1) {
                if (nums[left] == 0)
                    --zeroCount;
                ++left;
            }

            // Longueur de la fenêtre actuelle
            maxLen = std::max(maxLen, right - left + 1);
        }

        // Il faut supprimer un élément obligatoirement
        return maxLen - 1;
    }
};