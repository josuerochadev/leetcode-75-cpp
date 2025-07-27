// 238-product-of-array-except-self.cpp
// LeetCode 238 - Product of Array Except Self
// Résolution sans division, en O(n) temps et O(1) espace supplémentaire (hors output)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1); // Initialiser tous les éléments à 1

        // Étape 1 : produit des éléments à gauche de i
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Étape 2 : produit des éléments à droite de i (suffix)
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};