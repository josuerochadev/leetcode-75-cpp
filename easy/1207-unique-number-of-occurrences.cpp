// 1207_unique_number_of_occurrences.cpp
// LeetCode 1207 - Unique Number of Occurrences
// Résolution par Josué Rocha

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        for (int num : arr)
        {
            freq[num]++;
        }

        unordered_set<int> occurrences;
        for (auto &[_, count] : freq)
        {
            if (occurrences.count(count))
            {
                return false; // Une occurrence est déjà vue
            }
            occurrences.insert(count);
        }

        return true;
    }
};