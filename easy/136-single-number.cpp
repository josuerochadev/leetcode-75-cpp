/*
 * LeetCode 136. Single Number
 * Niveau: Easy
 * Lien: https://leetcode.com/problems/single-number/
 * Date: 2025-08-17
 *
 * TL;DR:
 *  - Chaque nombre apparaît deux fois sauf un: trouver l'unique.
 *  - Contrainte: O(n) temps, O(1) espace -> XOR bitwise.
 *
 * Invariants & bonnes pratiques:
 *  - Pas d'allocation inutile, pas de containers additionnels (O(1) extra space).
 *  - Compatible avec l'exécuteur LeetCode (classe Solution uniquement).
 *
 * Idée centrale (XOR):
 *  - x ^ x == 0
 *  - x ^ 0 == x
 *  - Commutatif & associatif -> l'ordre n'a pas d'importance
 *  => En XORant tout, les paires s'annulent et il reste l'unique.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int acc = 0;
        for (int v : nums) {
            acc ^= v;      // annule les doublons, conserve l'unique
        }
        return acc;
    }
};

/*
 * Notes d'implémentation:
 * - Complexité: O(n) temps, O(1) espace.
 * - Robustesse: aucun overflow (XOR bit à bit), gère les négatifs.
 * - Alternative (non retenue pour la contrainte O(1) espace):
 *   - HashSet: O(n) temps, O(n) espace.
 *   - Tri: O(n log n) temps, O(1)/O(n) espace selon l'algo.
 */