// Source: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
// Author: Miao Zhang
// Date:   2021-04-23

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
    int sumEvenGrandparent(TreeNode* root) {
        res = 0;

        function<void(TreeNode*, int, int)> dfs = [&] (TreeNode* root, int p, int gp) {
            if (!root) return;
            if (gp % 2 == 0) {
                res += root->val;
            }
            dfs(root->left, root->val, p);
            dfs(root->right, root->val, p);
        };

        dfs(root, 1, 1);
        return res;
    }

private:
    int res;
};
