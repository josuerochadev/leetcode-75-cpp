// 605_can_place_flowers.cpp
// LeetCode 605 - Can Place Flowers
// Résolution dans le cadre du challenge LeetCode 75 en C++
// Auteur : Josué Xavier Rocha
// Date : 2025-07-26

#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0) {
                bool emptyLeft = (i == 0 || flowerbed[i - 1] == 0);
                bool emptyRight = (i == size - 1 || flowerbed[i + 1] == 0);

                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1; // On "plante" ici
                    n--;
                    if (n == 0) return true;
                }
            }
        }

        return n <= 0;
    }
};