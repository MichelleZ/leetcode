// Source: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Author: Miao Zhang
// Date:   2021-04-27

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
    int maxSumBST(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    // {minval, maxval, sum, valid_bst}
    tuple<int, int, int, bool> dfs(TreeNode* root, int& res) {
        if (!root) return {INT_MAX, INT_MIN, 0, true};
        auto [lmin, lmax, lsum, lvalid] = dfs(root->left, res);
        auto [rmin, rmax, rsum, rvalid] = dfs(root->right, res);
        bool valid = lvalid && rvalid && root->val > lmax && root->val < rmin;
        int sums = valid ? lsum + rsum + root->val : -1;
        res = max(res, sums);
        return {min(lmin, root->val), max(rmax, root->val), sums, valid};
    }
};
