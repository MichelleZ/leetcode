// Source: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// Author: Miao Zhang
// Date:   2021-04-07

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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root->left == root->right) {
            return root->val < limit ? nullptr : root;
        }

        if (root->left) {
            root->left = sufficientSubset(root->left, limit - root->val);
        }
        if (root->right) {
            root->right = sufficientSubset(root->right, limit - root->val);
        }

        return root->left == root->right ? nullptr : root;
    }
};
