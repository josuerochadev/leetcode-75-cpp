/*
 * LeetCode 2300 - Successful Pairs of Spells and Potions
 * Difficulty: Medium
 * Topic: Binary Search, Sorting, Two Pointers
 * Repository: leetcode-75-cpp/medium
 *
 * Strategy (TL;DR):
 * - Trier `potions` croissant.
 * - Pour chaque `spell`, trouver via binary search le premier `potion >= ceil(success / spell)`.
 * - Le nombre de paires = potions.size() - index_trouvé.
 *
 * Why it works:
 * - On évite O(n*m) en remplaçant la recherche linéaire par O(log m) avec un tableau trié.
 * - Attention aux dépassements: utiliser des 64-bit (long long).
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Tri des potions pour permettre une recherche binaire
        sort(potions.begin(), potions.end());

        const int m = static_cast<int>(potions.size());
        vector<int> result;
        result.reserve(spells.size());

        for (int s : spells) {
            // s >= 1 d'après les contraintes
            long long spell = static_cast<long long>(s);

            // Seuil minimal de potion pour réussir: ceil(success / spell)
            // Calcul en entier sûr: (success + spell - 1) / spell
            long long minPotion = (success + spell - 1) / spell;

            // lower_bound: premier index i tel que potions[i] >= minPotion
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            int idx = static_cast<int>(it - potions.begin());
            int count = (idx <= m) ? (m - idx) : 0;

            result.push_back(count);
        }
        return result;
    }
};

/* --------------- Boilerplate de test manuel (facultatif) ---------------
   Décommente pour tester vite fait en local.

int main() {
    Solution sol;
    vector<int> spells = {5,1,3};
    vector<int> potions = {1,2,3,4,5};
    long long success = 7;
    auto res = sol.successfulPairs(spells, potions, success);
    for (int x : res) cout << x << " ";
    cout << "\n"; // attendu: 4 0 3
}
*/