// Source: https://leetcode.com/problems/increasing-order-search-tree/
// Author: Miao Zhang
// Date:   2021-03-23

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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy(0);
        prev_ = &dummy;
        inorder(root);
        return dummy.right;
    }

private:
    TreeNode* prev_;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        prev_->right = root;
        prev_ = root;
        root->left = nullptr;
        inorder(root->right);
    }
};
