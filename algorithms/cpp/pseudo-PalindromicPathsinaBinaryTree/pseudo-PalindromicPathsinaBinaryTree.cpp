// Source: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
// Author: Miao Zhang
// Date:   2021-05-08

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
    int pseudoPalindromicPaths (TreeNode* root) {
        return p(root, 0);
    }

    int p(TreeNode* root, int s) {
        if (!root) return 0;
        s ^= (1 << root->val);
        if (!root->left && !root->right) {
            return __builtin_popcount(s) <= 1;
        }
        return p(root->left, s) + p(root->right, s);
    }
};
