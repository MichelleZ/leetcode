// Source: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Author: Miao Zhang
// Date:   2021-02-20

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
    int getMinimumDifference(TreeNode* root) {
        min_diff = INT_MAX;
        preval = nullptr;
        inorder(root);
        return min_diff;
    }

private:
    int min_diff;
    int* preval;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (preval) min_diff = min(min_diff, root->val - *preval);
        preval = &root->val;
        inorder(root->right);
    }
};
