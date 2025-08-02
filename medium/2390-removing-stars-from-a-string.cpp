// 2390. Removing Stars From a String
// LeetCode 75 Challenge – Medium Level
// Problem link: https://leetcode.com/problems/removing-stars-from-a-string/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string result;
        for (char c : s) {
            if (c == '*') {
                if (!result.empty()) {
                    result.pop_back(); // supprime le dernier caractère ajouté
                }
            } else {
                result.push_back(c); // ajoute le caractère courant
            }
        }
        return result;
    }
};