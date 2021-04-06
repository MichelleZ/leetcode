// Source: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
// Author: Miao Zhang
// Date:   2021-04-06

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
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }

private:
    int s_ = 0;
    
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->right);
        root->val = s_ += root->val;
        dfs(root->left);
    }
}; 
