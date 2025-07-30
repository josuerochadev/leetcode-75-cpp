// 643. Maximum Average Subarray I
// LeetCode 75 - Easy
// Résolution en C++ par Josué Xavier Rocha

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Calcule la somme initiale des k premiers éléments
        double windowSum = 0;
        for (int i = 0; i < k; ++i) {
            windowSum += nums[i];
        }

        double maxSum = windowSum;

        // On glisse la fenêtre
        for (int i = k; i < nums.size(); ++i) {
            windowSum += nums[i] - nums[i - k]; // Ajout entrant - retrait sortant
            maxSum = max(maxSum, windowSum);
        }

        return maxSum / k;
    }
};
