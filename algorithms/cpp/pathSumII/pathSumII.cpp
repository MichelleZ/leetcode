// Source: https://leetcode.com/problems/path-sum-ii/
// Author: Miao Zhang
// Date:   2021-01-19

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        dfs(root, sum, res, {});
        return res;
    }
    
    void dfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> path) {
        if (root == nullptr) return;
        if (sum == root->val && root->left == nullptr && root->right == nullptr) {
            path.push_back(root->val);
            res.push_back(path);
            path.pop_back();
        }
        path.push_back(root->val);
        dfs(root->left, sum - root->val, res, path);
        dfs(root->right, sum - root->val, res, path);
        path.pop_back();
    }
};
