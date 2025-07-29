// 392-is-subsequence.cpp
// LeetCode 75 - Challenge C++
// Josué Rocha - 2025-07-29

#include <iostream>
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int i = 0; // pointeur pour s
        int j = 0; // pointeur pour t

        // tant qu'on n'a pas fini l'un des deux strings
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++; // on avance dans s si les lettres correspondent
            }
            j++; // on avance toujours dans t
        }

        // si on a parcouru tout s, alors s est une sous-séquence de t
        return i == s.length();
    }
};