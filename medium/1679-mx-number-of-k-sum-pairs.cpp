// 1679. Max Number of K-Sum Pairs
// Résolu par Josué Rocha le 29/07/2025
// https://leetcode.com/problems/max-number-of-k-sum-pairs/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  // Pour compter chaque nombre
        int operations = 0;

        for (int num : nums) {
            int complement = k - num;

            if (freq[complement] > 0) {
                // Il existe un complément disponible : on forme une paire
                operations++;
                freq[complement]--;  // On retire le complément utilisé
            } else {
                // Pas de complément dispo : on enregistre ce nombre
                freq[num]++;
            }
        }

        return operations;
    }
};