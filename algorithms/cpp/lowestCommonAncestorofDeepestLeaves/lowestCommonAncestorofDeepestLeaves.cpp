// Source: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
// Author: Miao Zhang
// Date:   2021-04-12

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }

private:
    TreeNode* dfs(TreeNode* root, int& height) {
        if (!root) {
            height = -1;
            return NULL;
        }
        int lheight;
        int rheight;
        auto left = dfs(root->left, lheight);
        auto right = dfs(root->right, rheight);
        height = max(lheight, rheight) + 1;
        if (lheight == rheight) return root;
        if (lheight > rheight) return left;
        return right;
    }
};
