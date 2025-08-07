// 236-lowest-common-ancestor-of-a-binary-tree.cpp
// LeetCode 236 - Lowest Common Ancestor of a Binary Tree
// Difficulty: Medium
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Trouve le plus bas ancêtre commun (Lowest Common Ancestor) entre deux nœuds p et q
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root; // p et q se trouvent chacun d’un côté
        }

        return left ? left : right;
    }
};