// Source: https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author: Miao Zhang
// Date:   2021-01-20

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
    int res = 0;

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        dfs(root, root->val);
        return res;
    }
    
    void dfs(TreeNode* root, int val) {
        if (!root->left && !root->right) {
            res += val;
            return;
        }
        if (root->left) {
            dfs(root->left, val * 10 + root->left->val);
        }
        if (root->right) {
            dfs(root->right, val * 10 + root->right->val);
        }
    }
};
