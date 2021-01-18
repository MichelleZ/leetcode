// Source: https://leetcode.com/problems/balanced-binary-tree/
// Author: Miao Zhang
// Date:   2021-01-18

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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (abs(height(root->left) - height(root->right)) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
};
