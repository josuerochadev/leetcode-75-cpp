// 872-leaf-similar-trees.cpp
//
// Solution for LeetCode 872: Leaf-Similar Trees
// https://leetcode.com/problems/leaf-similar-trees/
// Challenge: LeetCode 75 in C++ (Easy)
// Author: Josué Xavier Rocha
// Date: 06/08/2025

#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Fonction principale pour comparer les feuilles de deux arbres
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }
private:
    // Fonction auxiliaire pour collecter les valeurs des feuilles
    void getLeaves(TreeNode* node, vector<int>& leaves) {
        if (!node) return;
        if (!node->left && !node->right) {
            leaves.push_back(node->val);
        } else {
            getLeaves(node->left, leaves);
            getLeaves(node->right, leaves);
        }
    }
};