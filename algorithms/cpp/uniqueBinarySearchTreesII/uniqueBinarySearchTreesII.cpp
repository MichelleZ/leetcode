// Source: https://leetcode.com/problems/unique-binary-search-trees-ii/
// Author: Miao Zhang
// Date:   2021-01-15

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return dfs(1, n);
    }
    
    vector<TreeNode*> dfs(int left, int right) {
        if (left > right) return {nullptr};
        vector<TreeNode*> res;
        for (int i = left; i < right + 1; i++) {
            vector<TreeNode*> left_nodes = dfs(left, i - 1);
            vector<TreeNode*> right_nodes = dfs(i + 1, right);
            for (auto left_node: left_nodes) {
                for (auto right_node: right_nodes) {
                    TreeNode* root = new TreeNode(i);
                    res.push_back(root);
                    root->left = left_node;
                    root->right = right_node;
                }
            }
        }
        return res;
    }
};
