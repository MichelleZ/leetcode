// Source: https://leetcode.com/problems/recover-binary-search-tree/
// Author: Miao Zhang
// Date:   2021-01-16

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
    TreeNode* pre;
    TreeNode* first;
    TreeNode* second;
    void recoverTree(TreeNode* root) {
        pre = nullptr;
        first = nullptr;
        second = nullptr;
        inorder(root);
        swap(first->val, second->val);
    }
    
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        if (pre && pre->val > root->val) {
            if (first == nullptr) first = pre;
            second = root;
        }
        pre = root;
        inorder(root->right);
    }
};
