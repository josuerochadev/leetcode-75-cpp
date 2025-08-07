// 0199-binary-tree-right-side-view.cpp
// LeetCode 199 - Binary Tree Right Side View
// ✅ Challenge LeetCode 75 - Niveau Medium
// 🧠 Thème : Binary Tree / BFS / DFS
// 🔗 https://leetcode.com/problems/binary-tree-right-side-view/

#include <vector>
#include <queue>
using namespace std;

// Définition de l'arbre binaire (fournie par LeetCode)
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* node;

            for (int i = 0; i < levelSize; ++i) {
                node = q.front(); q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(node->val); // Dernier noeud visité dans ce niveau = côté droit
        }

        return result;
    }
};