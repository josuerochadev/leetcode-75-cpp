// 1004. Max Consecutive Ones III
// Sliding window: maximize window with at most k zeros

#include <vector>
#include <algorithm> // pour max()

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int left = 0;
        int zeros = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) zeros++;

            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++; // réduire la fenêtre
            }

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};