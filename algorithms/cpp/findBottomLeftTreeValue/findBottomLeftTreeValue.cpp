// Source: https://leetcode.com/problems/find-bottom-left-tree-value/
// Author: Miao Zhang
// Date:   2021-02-19

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
    int findBottomLeftValue(TreeNode* root) {
        int max_level = -1;
        int res;
        dfs(root, 0, max_level, res);
        return res;
    }

    void dfs(TreeNode* root, int level, int& max_level, int& res) {
        if (!root) return;
        dfs(root->left, level + 1, max_level, res);
        if (level > max_level) {
            res = root->val;
            max_level = level;
        }
        dfs(root->right, level + 1, max_level, res);
    }
};
