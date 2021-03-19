// Source: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
// Author: Miao Zhang
// Date:   2021-03-19

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* res;
        depth(root, &res);
        return res;
    }

private:
    int depth(TreeNode* root, TreeNode** s) {
        if (root == nullptr) return -1;
        TreeNode* sl;
        TreeNode* sr;
        int l = depth(root->left, &sl);
        int r = depth(root->right, &sr);
        *s = (l == r) ? root: ((l > r) ? sl: sr);
        return max(l, r) + 1;
    }
};
