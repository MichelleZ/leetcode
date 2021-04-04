// Source: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Author: Miao Zhang
// Date:   2021-04-03

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
    int sumRootToLeaf(TreeNode* root) {
        return sums(root, 0);
    }

private:
    int kMod = 1e9 + 7;
    int sums(TreeNode* root, int c) {
        if (!root) return 0;
        c = ((c << 1) | root->val) % kMod;
        if (!root->left && !root->right) {
            return c;
        }
        return sums(root->left, c) + sums(root->right, c);
    }
};
