// Source: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Author: Miao Zhang
// Date:   2021-05-07

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
    int goodNodes(TreeNode* root) {
        return good(root, INT_MIN);
    }
    
private:
    int good(TreeNode* root, int maxval) {
        if (!root) return 0;
        return good(root->left, max(maxval, root->val)) + good(root->right, max(maxval, root->val)) + (root->val >= maxval ? 1: 0);
    }
};
