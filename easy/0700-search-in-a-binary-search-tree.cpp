// 0700-search-in-a-binary-search-tree.cpp
// LeetCode 700 - Search in a Binary Search Tree
// https://leetcode.com/problems/search-in-a-binary-search-tree/
// Résolu dans le cadre du challenge LeetCode 75 en C++

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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Cas de base : si l'arbre est vide ou si on trouve la valeur
        if (!root || root->val == val)
            return root;

        // Si la valeur recherchée est inférieure, chercher dans le sous-arbre gauche
        if (val < root->val)
            return searchBST(root->left, val);

        // Sinon, chercher dans le sous-arbre droit
        return searchBST(root->right, val);
    }
};