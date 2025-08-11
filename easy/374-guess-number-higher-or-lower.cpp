/*
========================================================
Title       : 374. Guess Number Higher or Lower
Difficulty  : Easy
Author      : Josué Xavier Rocha
Date        : 11/08/2025
Link        : https://leetcode.com/problems/guess-number-higher-or-lower/
========================================================
Description :
We need to guess a number between 1 and n using a predefined API `guess(int num)`:
    - returns -1 if the guess is higher than the picked number
    - returns 1  if the guess is lower than the picked number
    - returns 0  if the guess is correct

Goal: Find the picked number efficiently.

Approach:
Use Binary Search to reduce the search range in O(log n) time.

Time Complexity  : O(log n)
Space Complexity : O(1)
========================================================
*/

// Forward declaration of guess API (provided by LeetCode)
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left <= right) {
            // Avoid overflow with mid calculation
            int mid = left + (right - left) / 2;

            int res = guess(mid);

            if (res == 0) {
                return mid; // Found the picked number
            }
            else if (res < 0) {
                // Our guess is too high → search left half
                right = mid - 1;
            }
            else {
                // Our guess is too low → search right half
                left = mid + 1;
            }
        }
        return -1; // Should never reach here if constraints are valid
    }
};