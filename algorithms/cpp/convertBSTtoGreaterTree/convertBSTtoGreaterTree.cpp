// Source: https://leetcode.com/problems/convert-bst-to-greater-tree/
// Author: Miao Zhang
// Date:   2021-02-20

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        sums = 0;
        afterorder(root);
        return root;
    }

private:
    int sums;
    void afterorder(TreeNode* root) {
        if (!root) return;
        afterorder(root->right);
        sums += root->val;
        root->val = sums;
        afterorder(root->left);
    }
};
