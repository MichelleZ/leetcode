// Source: https://leetcode.com/problems/symmetric-tree/
// Author: Miao Zhang
// Date:   2021-01-18

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return dfs(root->left, root->right);
    }
    
    bool dfs(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr && q) return q == nullptr;
        if (q == nullptr && p) return p == nullptr;
        if (p->val != q->val) return false;
        return dfs(p->left, q->right) && dfs(p->right, q->left);
    }
};

