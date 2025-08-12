/*
 * LeetCode 216. Combination Sum III
 * Niveau : Medium
 * Lien   : https://leetcode.com/problems/combination-sum-iii/
 *
 * Pattern : Backtracking (DFS) avec pruning arithmétique.
 * Idée clé : choisir k nombres distincts dans [1..9] dont la somme vaut n.
 *            On construit les combinaisons croissantes pour éviter les doublons.
 *
 * Réutilisable :
 *  - Helper backtrack(start, kRestant, targetRestant, courant, res)
 *  - Prunings :
 *      1) kRestant > nombres restants disponibles → stop
 *      2) Somme min possible > targetRestant → stop
 *      3) Somme max possible < targetRestant → stop
 *
 * Complexité (pire cas) ~ O(C(9, k)) en génération, avec du pruning qui réduit fortement.
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(/*start=*/1, k, n, cur, res);
        return res;
    }

private:
    // Somme arithmétique d'une suite consécutive croissante : a + (a+1) + ... + (a+m-1)
    // = m * (2a + (m - 1)) / 2
    static int sumMinPossible(int start, int m) {
        // plus petits m nombres disponibles à partir de start
        return m * (2 * start + (m - 1)) / 2;
    }

    // Somme max possible en prenant les m plus grands nombres disponibles entre start..9
    // Si start <= 10 - m, les m plus grands sont (9, 8, ..., 9-m+1) → m * (19 - m) / 2
    // Sinon, il n'y a pas assez de nombres → ce cas est filtré en amont.
    static int sumMaxPossible(int start, int m) {
        if (m == 0) return 0;
        if (m > 10 - start) return -1; // impossible : pas assez d'éléments
        return m * (19 - m) / 2;
    }

    void backtrack(int start, int kLeft, int targetLeft,
                   vector<int>& cur, vector<vector<int>>& res) {

        // 1) Si plus rien à choisir : valider la somme
        if (kLeft == 0) {
            if (targetLeft == 0) res.push_back(cur);
            return;
        }

        // 2) Pruning : pas assez d'éléments disponibles dans [start..9]
        if (kLeft > 10 - start) return;

        // 3) Pruning bornes arithmétiques
        int minSum = sumMinPossible(start, kLeft);
        int maxSum = sumMaxPossible(start, kLeft);
        if (maxSum == -1) return;                // sécurité
        if (targetLeft < minSum) return;         // même les plus petits sont trop grands
        if (targetLeft > maxSum) return;         // même les plus grands sont trop petits

        // 4) Essayer chaque candidat croissant pour éviter les doublons
        for (int x = start; x <= 9; ++x) {
            if (x > targetLeft) break;           // croissance ⇒ tous les suivants seront trop grands
            cur.push_back(x);
            backtrack(x + 1, kLeft - 1, targetLeft - x, cur, res);
            cur.pop_back();
        }
    }
};

// Note : pas de main() requis pour LeetCode.