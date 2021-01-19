// Source: https://leetcode.com/problems/path-sum/
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        sum -= root->val;
        if (sum == 0 && root->left == nullptr && root->right == nullptr) {
            return true;
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
