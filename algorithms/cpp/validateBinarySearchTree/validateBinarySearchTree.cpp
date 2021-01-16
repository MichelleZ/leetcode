// Source: https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return isVal(root, LONG_MIN, LONG_MAX);
    }
    
    bool isVal(TreeNode* node, long long minv, long long maxv) {
        if (node == nullptr) return true;
        if (node->left) {
            if (node->left->val >= node->val || node->left->val <= minv) {
                return false;
            }
        }
        if (node->right) {
            if (node->right->val <= node->val || node->right->val >= maxv) {
                return false;
            }
        }
        return isVal(node->left, minv, node->val) && isVal(node->right, node->val, maxv);
    }
};
