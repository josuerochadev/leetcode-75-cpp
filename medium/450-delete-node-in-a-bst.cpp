// 450-delete-node-in-a-bst.cpp
// LeetCode 450 - Delete Node in a BST
// 🟠 Medium | 🌲 BST | 🧠 Focus: Manipulation de pointeurs

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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node to delete found
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Find the in-order successor (min value in the right subtree)
            TreeNode* minNode = getMin(root->right);
            root->val = minNode->val; // Replace current node value
            root->right = deleteNode(root->right, minNode->val); // Delete duplicate
        }

        return root;
    }

private:
    TreeNode* getMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
};