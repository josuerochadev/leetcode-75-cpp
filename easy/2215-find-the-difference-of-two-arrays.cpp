// 2215-find-the-difference-of-two-arrays.cpp
// Author: Josué Rocha
// Date: 01/08/2025
// Description: LeetCode 75 - 2215. Find the Difference of Two Arrays

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> onlyInNums1;
        vector<int> onlyInNums2;

        for (int n : set1)
        {
            if (set2.find(n) == set2.end())
            {
                onlyInNums1.push_back(n);
            }
        }

        for (int n : set2)
        {
            if (set1.find(n) == set1.end())
            {
                onlyInNums2.push_back(n);
            }
        }

        return {onlyInNums1, onlyInNums2};
    }
};