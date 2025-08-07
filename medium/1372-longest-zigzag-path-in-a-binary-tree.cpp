// 1372 - Longest ZigZag Path in a Binary Tree
// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

// Algorithme par DFS avec transmission de direction et profondeur pour chaque branche.
// Complexité : O(n) - chaque nœud est visité une seule fois.
// Statut : Résolu ✅

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    int maxLength = 0;

    void dfs(TreeNode* node, bool goLeft, int length) {
        if (!node) return;

        maxLength = max(maxLength, length);

        if (goLeft) {
            dfs(node->left, false, length + 1);  // Changement de direction : gauche -> droite
            dfs(node->right, true, 1);           // Reset si même direction
        } else {
            dfs(node->right, true, length + 1);  // droite -> gauche
            dfs(node->left, false, 1);
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;

        dfs(root->left, false, 1); // Commencer par gauche
        dfs(root->right, true, 1); // Commencer par droite

        return maxLength;
    }
};