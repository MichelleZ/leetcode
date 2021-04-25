// Source: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// Author: Miao Zhang
// Date:   2021-04-25

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
    int maxProduct(TreeNode* root) {
        int kMod = 1e9 + 7;
        long sums = 0;
        long res = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return 0;
            int l = dfs(node->left);
            int r = dfs(node->right);
            if (sums) res = max({res, (sums - l) * l, (sums - r) * r});
            return node->val + l + r;
        };
        sums = dfs(root);
        dfs(root);
        return res % kMod;
    }
};
