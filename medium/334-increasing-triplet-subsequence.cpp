// 334-increasing-triplet-subsequence.cpp
// Solution au problème LeetCode 334 - Increasing Triplet Subsequence
// Josué Xavier Rocha - 28/07/2025

#include <vector>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int num : nums)
        {
            if (num <= first)
            {
                first = num; // Plus petit nombre rencontré
            }
            else if (num <= second)
            {
                second = num; // Deuxième plus petit nombre, supérieur à first
            }
            else
            {
                // Si on trouve un num plus grand que second -> triplet trouvé
                return true;
            }
        }
        return false; // Aucun triplet trouvé
    }
};