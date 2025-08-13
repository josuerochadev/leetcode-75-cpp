/*
    LeetCode 1137 - N-th Tribonacci Number
    Difficulty: Easy
    Date: 13/08/2025
    Author: Josué Xavier Rocha

    Description:
    The Tribonacci sequence is defined as:
        T0 = 0, T1 = 1, T2 = 1
        Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0

    Task:
    Given an integer n, return the value of Tn.

    Constraints:
    - 0 <= n <= 37
    - Answer fits in a 32-bit signed integer
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        // Cas de base : retour immédiat
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        // Variables pour stocker les 3 derniers termes
        int t0 = 0, t1 = 1, t2 = 1;

        // Calcul itératif jusqu'à n
        for (int i = 3; i <= n; i++) {
            int t3 = t0 + t1 + t2; // Somme des trois précédents
            t0 = t1; // Avance dans la séquence
            t1 = t2;
            t2 = t3;
        }

        return t2;
    }
};

// Main de démonstration (non nécessaire pour LeetCode, mais utile pour debug local)
int main() {
    Solution sol;
    cout << sol.tribonacci(4) << endl;   // Attendu: 4
    cout << sol.tribonacci(25) << endl;  // Attendu: 1389537
    return 0;
}