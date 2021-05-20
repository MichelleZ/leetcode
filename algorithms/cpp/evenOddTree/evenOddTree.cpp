// Source: https://leetcode.com/problems/even-odd-tree/
// Author: Miao Zhang
// Date:   2021-05-20

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
    bool isEvenOddTree(TreeNode* root) {
        vector<int> vals;
        function<bool(TreeNode*, int)> dfs = [&] (TreeNode* root, int d) {
            if (!root) return true;
            if (vals.size() <= d) {
                vals.push_back(d % 2 == 0 ? -1 : INT_MAX);
            }
            int& val = vals[d];
            if (d % 2 == 0) {
                if (root->val % 2 == 0 || root->val <= val)
                    return false;
            }
            if (d % 2 == 1) {
                if (root->val % 2 == 1 || root->val >= val)
                    return false;
            }
            val = root->val;
            return dfs(root->left, d + 1) && dfs(root->right, d + 1);
        };
        return dfs(root, 0);
    }
};
