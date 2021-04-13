// Source: https://leetcode.com/problems/binary-tree-coloring-game/
// Author: Miao Zhang
// Date:   2021-04-13

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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        nums(root, x);
        int p = n - (1 + l_ + r_);
        return max(p, max(l_, r_)) > n / 2;
    }

private:
    int l_;
    int r_;
    int nums(TreeNode* root, int x) {
        if (!root) return 0;
        int l = nums(root->left, x);
        int r = nums(root->right, x);
        if (root->val == x) {
            l_ = l;
            r_ = r;
        }
        return l + r + 1;
    }
};
