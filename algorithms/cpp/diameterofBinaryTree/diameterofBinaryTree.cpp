// Source: https://leetcode.com/problems/diameter-of-binary-tree/
// Author: Miao Zhang
// Date:   2021-02-21

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
    int diameterOfBinaryTree(TreeNode* root) {
        diameter_ = 0;
        depth(root);
        return diameter_;
    }

private:
    int diameter_;
    int depth(TreeNode* root) {
        if (!root) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        diameter_ = max(diameter_, l + r);
        return 1 + max(l, r);
    }
};
