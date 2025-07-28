// 1431. Kids With the Greatest Number of Candies
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Difficulty: Easy
// Tags: Array, Greedy
// LeetCode 75 Challenge — C++ implementation by Josué Xavier Rocha

#include <vector>
#include <algorithm> // pour std::max_element

class Solution
{
public:
    std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies)
    {
        // Étape 1 : Trouver le nombre maximum de bonbons parmi tous les enfants
        int maxCandies = *std::max_element(candies.begin(), candies.end());

        // Étape 2 : Comparer chaque enfant avec ce maximum après ajout des bonbons en plus
        std::vector<bool> result;
        for (int candy : candies)
        {
            result.push_back(candy + extraCandies >= maxCandies);
        }

        return result;
    }
};

// ✅ Exemple d’appel (à intégrer dans un main() pour tester)
/*
#include <iostream>
int main() {
    Solution sol;
    std::vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    std::vector<bool> result = sol.kidsWithCandies(candies, extraCandies);

    for (bool b : result) {
        std::cout << (b ? "true" : "false") << " ";
    }
    std::cout << std::endl;
}
*/