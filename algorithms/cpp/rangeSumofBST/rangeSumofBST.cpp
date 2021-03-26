// Source: https://leetcode.com/problems/range-sum-of-bst/
// Author: Miao Zhang
// Date:   2021-03-27

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int sums = 0;
        if (root->val >= low && root->val <= high) {
            sums += root->val;
        }
        if (root->val >= low) {
            sums += rangeSumBST(root->left, low, high);
        }
        if (root->val <= high) {
            sums += rangeSumBST(root->right, low, high);
        }
        return sums;
    }
};
