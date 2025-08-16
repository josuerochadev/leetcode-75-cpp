// 0714-best-time-to-buy-and-sell-stock-with-transaction-fee.cpp
// LeetCode 714. Best Time to Buy and Sell Stock with Transaction Fee
// Difficulty: Medium
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//
// 📝 Résumé :
// On cherche à maximiser le profit en achetant et revendant des actions.
// Chaque vente est soumise à une taxe fixe (fee).
// Règle : On ne peut pas détenir plusieurs actions en même temps.
//
// 💡 Stratégie : Dynamic Programming (DP).
// - On garde deux états pour chaque jour :
//   1. hold = profit max si on a une action ce jour-là.
//   2. cash = profit max si on n’a pas d’action ce jour-là.
// - Transitions :
//   • hold[i] = max(hold[i-1], cash[i-1] - prices[i])
//   • cash[i] = max(cash[i-1], hold[i-1] + prices[i] - fee)
// - On retourne cash[n-1], car le maximum final est atteint sans action en main.
//
// 🧠 Complexité :
// - Temps : O(n), on parcourt les prix une seule fois.
// - Mémoire : O(1), car on réutilise deux variables (pas besoin d’un tableau).
//
// ✅ Statut : Solution validée

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -prices[0];   // si on achète le premier jour
        int cash = 0;            // si on ne fait rien le premier jour

        for (int i = 1; i < n; i++) {
            hold = max(hold, cash - prices[i]);                // garder ou acheter
            cash = max(cash, hold + prices[i] - fee);          // garder ou vendre
        }

        return cash;
    }
};