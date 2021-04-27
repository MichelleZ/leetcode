// Source: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
// Author: Miao Zhang
// Date:   2021-04-27

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
    int longestZigZag(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    
private:
    pair<int, int> dfs(TreeNode* root, int& res) {
        if (!root) return {0, 0};
        auto [ll, lr] = dfs(root->left, res);
        auto [rl, rr] = dfs(root->right, res);
        int l = root->left ? (lr + 1) : 0;
        int r = root->right ? (rl + 1) : 0;
        res = max({res, l, r});
        return {l, r};
    }
};
