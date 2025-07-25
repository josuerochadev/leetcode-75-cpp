#include <iostream>
#include <string>
#include <numeric> // pour std::gcd

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        // Vérifie que les deux chaînes ont un motif commun
        if (str1 + str2 != str2 + str1) return "";

        // Utilise le GCD des longueurs pour déterminer le motif de base
        int gcdLength = std::gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};