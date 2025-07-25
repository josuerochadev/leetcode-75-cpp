#include <string>
#include <iostream>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
                std::string result;
        int i = 0, j = 0;
        int n1 = word1.length(), n2 = word2.length();

        // On fusionne les lettres tant qu'il y a des caractères dans les deux chaînes
        while (i < n1 && j < n2) {
            result += word1[i++];
            result += word2[j++];
        }

        // Ajoute les caractères restants
        if (i < n1) result += word1.substr(i);  // Reste de word1
        if (j < n2) result += word2.substr(j);  // Reste de word2

        return result;
    }
};