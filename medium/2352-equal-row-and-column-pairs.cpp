// 2352-equal-row-and-column-pairs.cpp
// LeetCode 2352 - Equal Row and Column Pairs (Medium)
// https://leetcode.com/problems/equal-row-and-column-pairs/

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> row_map;

        // Convertir chaque ligne en string et compter les occurrences
        for (const auto& row : grid) {
            string key;
            for (int val : row) {
                key += to_string(val) + ",";
            }
            row_map[key]++;
        }

        int count = 0;
        // Pour chaque colonne, générer une clé et vérifier dans le map
        for (int j = 0; j < n; ++j) {
            string col_key;
            for (int i = 0; i < n; ++i) {
                col_key += to_string(grid[i][j]) + ",";
            }
            count += row_map[col_key];
        }

        return count;
    }
};