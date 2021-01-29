// Source: https://leetcode.com/problems/binary-tree-paths/
// Author: Miao Zhang
// Date:   2021-01-28

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
    
    void dfs(TreeNode* node, string path, vector<string>& res) {
        if (!node) return;
        if (!node->left && !node->right) {
            res.push_back(path + to_string(node->val));
            return;
        }
        if (node->left) {
            dfs(node->left, path + to_string(node->val) + "->", res);
        }
        if (node->right) {
            dfs(node->right, path + to_string(node->val) + "->", res);
        }
    }
};
