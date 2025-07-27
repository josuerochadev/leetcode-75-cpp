// 151_reverse_words.cpp
// Date: 2025-07-27
// Problem: 151. Reverse Words in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::istringstream iss(s);
        std::vector<std::string> words;
        std::string word;

        // Extraction des mots en ignorant les espaces multiples
        while (iss >> word) {
            words.push_back(word);
        }

        // Inversion de l'ordre des mots
        std::reverse(words.begin(), words.end());

        // Reconstitution de la chaîne avec un seul espace entre les mots
        std::string result;
        for (size_t i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};

// Pour tester localement
// int main() {
//     Solution sol;
//     std::string s = "  hello   world  ";
//     std::cout << "[" << sol.reverseWords(s) << "]" << std::endl;
//     return 0;
// }