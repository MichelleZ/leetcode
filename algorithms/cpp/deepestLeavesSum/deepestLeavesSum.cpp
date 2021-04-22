// Source: https://leetcode.com/problems/deepest-leaves-sum/
// Author: Miao Zhang
// Date:   2021-04-22

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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        int maxdepth = 0;
        function<void(TreeNode*, int)> dfs = [&] (TreeNode* root, int d) {
            if (!root) return;
            if (d > maxdepth) {
                maxdepth = d;
                res = 0;
            }
            if (d == maxdepth) {
                res += root->val;
            }
            dfs(root->left, d + 1);
            dfs(root->right, d + 1);
        };

        dfs(root, 0);
        return res;
    }
};
