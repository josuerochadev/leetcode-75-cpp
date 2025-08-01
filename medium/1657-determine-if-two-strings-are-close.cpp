// 1657_determine_if_two_strings_are_close.cpp
// LeetCode 75 - Challenge C++
// https://leetcode.com/problems/determine-if-two-strings-are-close/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char, int> freq1, freq2;
        unordered_set<char> set1, set2;

        for (char c : word1) {
            freq1[c]++;
            set1.insert(c);
        }

        for (char c : word2) {
            freq2[c]++;
            set2.insert(c);
        }

        if (set1 != set2) return false;

        vector<int> values1, values2;
        for (auto& [ch, freq] : freq1) values1.push_back(freq);
        for (auto& [ch, freq] : freq2) values2.push_back(freq);

        sort(values1.begin(), values1.end());
        sort(values2.begin(), values2.end());

        return values1 == values2;
    }
};