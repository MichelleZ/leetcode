// Source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) return;
        while (root) {
            if (root->left == nullptr) {
                root = root->right;
            } else {
                TreeNode* pre = root->left;
                while (pre && pre->right) {
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
};
