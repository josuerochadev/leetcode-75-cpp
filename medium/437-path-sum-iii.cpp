// 437-path-sum-iii.cpp
// LeetCode 437 - Path Sum III (Medium)
// Résolution par Josué Xavier Rocha dans le cadre du challenge LeetCode 75 (C++)
// Lien : https://leetcode.com/problems/path-sum-iii/

#include <iostream>
using namespace std;

/**
 * Définition du noeud d'un arbre binaire (Fourni par LeetCode).
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        // Compte les chemins partant de ce noeud
        int countFromRoot = countPathsFromNode(root, targetSum);

        // Recurse sur les sous-arbres
        int countLeft = pathSum(root->left, targetSum);
        int countRight = pathSum(root->right, targetSum);

        return countFromRoot + countLeft + countRight;
    }

private:
    int countPathsFromNode(TreeNode* node, long long remainingSum) {
        if (!node) return 0;

        int count = 0;
        if (node->val == remainingSum) count++;

        count += countPathsFromNode(node->left, remainingSum - node->val);
        count += countPathsFromNode(node->right, remainingSum - node->val);

        return count;
    }
};