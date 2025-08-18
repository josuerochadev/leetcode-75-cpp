/*
 * LeetCode 1318. Minimum Flips to Make a OR b Equal to c
 * Difficulty: Medium
 * Topic: Bit Manipulation
 * Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
 *
 * 🔎 Problem (Résumé)
 * Given integers a, b, c, return the minimum number of single-bit flips
 * (0->1 or 1->0) to make (a OR b) == c.
 *
 * ✅ Key Insight
 * On each bit position i, compare ai, bi, ci:
 * - If ci == 1: at least one of ai or bi must be 1.
 *      -> flips += 1 if (ai|bi)==0, else 0.
 * - If ci == 0: both ai and bi must be 0.
 *      -> flips += (ai==1) + (bi==1)  // i.e., count ones in (a,b)
 *
 * ⏱️ Complexity
 * We check at most 31 bits (given constraints ≤ 1e9).
 * Time: O(31) ~ O(1). Space: O(1).
 *
 * 🧯 Pitfalls
 * - Ne pas “~c” sans masque si tu tentes une solution vectorisée (risque de bits de signe).
 * - Boucler tant que (a|b|c) != 0 pour s’arrêter dès que les bits restants sont nuls.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        // Boucle bit à bit jusqu'à ce que tous les restes de bits soient 0
        while (a | b | c) {
            int ai = a & 1;
            int bi = b & 1;
            int ci = c & 1;

            if (ci == 1) {
                // Au moins un des deux doit être 1 ; si (ai|bi)==0, il faut 1 flip
                if ((ai | bi) == 0) {
                    ++flips;
                }
            } else {
                // ci == 0 -> ai==0 et bi==0 requis
                // Ajouter le nombre de bits à 1 à éteindre
                flips += ai + bi;
            }

            // Décaler pour passer au bit suivant
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};

/*
 * ✨ Variante “vectorisée” (optionnelle)
 * On peut aussi calculer en une passe via masques et popcount :
 *
 *   // Bits où c=1 mais (a|b)=0 -> 1 flip nécessaire
 *   int needOne = __builtin_popcount((~(a | b)) & c);
 *
 *   // Bits où c=0 mais a=1 / b=1 -> flips pour éteindre ces 1
 *   int turnOffA = __builtin_popcount(a & ~c);
 *   int turnOffB = __builtin_popcount(b & ~c);
 *
 *   return needOne + turnOffA + turnOffB;
 *
 * ⚠️ Attention aux compléments (~) sur int signés. Utiliser des masques 32 bits
 * (ou du unsigned) si tu généralises au-delà des contraintes.
 */