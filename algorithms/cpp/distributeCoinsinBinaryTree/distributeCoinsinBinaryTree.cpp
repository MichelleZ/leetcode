// Source: https://leetcode.com/problems/distribute-coins-in-binary-tree/
// Author: Miao Zhang
// Date:   2021-03-30

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
    int distributeCoins(TreeNode* root) {
        int res = 0;
        balance(root, res);
        return res;
    }

private:
    int balance(TreeNode* root, int& res) {
        if (!root) return 0;
        int l = balance(root->left, res);
        int r = balance(root->right, res);
        res += abs(l) + abs(r);
        return l + r + root->val - 1;
    }
};
