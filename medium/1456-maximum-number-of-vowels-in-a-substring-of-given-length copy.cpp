// 1456. Maximum Number of Vowels in a Substring of Given Length
// Résolu par Josué Xavier Rocha le 2025-07-30

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxVowelCount = 0;
        int currentCount = 0;

        // Compter les voyelles dans la première fenêtre de taille k
        for (int i = 0; i < k; ++i) {
            if (vowels.count(s[i])) {
                currentCount++;
            }
        }
        maxVowelCount = currentCount;

        // Glisser la fenêtre
        for (int i = k; i < s.size(); ++i) {
            if (vowels.count(s[i])) currentCount++;
            if (vowels.count(s[i - k])) currentCount--;
            maxVowelCount = max(maxVowelCount, currentCount);
        }

        return maxVowelCount;
    }
};