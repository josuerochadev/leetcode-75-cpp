// 1732_find_the_highest_altitude.cpp
// Solution to LeetCode 1732 - Find the Highest Altitude
// https://leetcode.com/problems/find-the-highest-altitude/

#include <vector>
#include <algorithm> // for max
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int maxAltitude = 0;
        int currentAltitude = 0;

        for (int g : gain)
        {
            currentAltitude += g;
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};