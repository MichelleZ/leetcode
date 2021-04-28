// Source: https://leetcode.com/problems/balance-a-binary-search-tree/
// Author: Miao Zhang
// Date:   2021-04-28

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> inorder = [&] (TreeNode* root) {
            if (!root) return;
            inorder(root->left);
            res.push_back(root->val);
            inorder(root->right);
        };
        function<TreeNode*(int, int)> build = [&] (int l, int r) {
            if (l > r) return (TreeNode*)nullptr;
            int m = l + (r - l) / 2;
            auto root = new TreeNode(res[m]);
            root->left = build(l, m - 1);
            root->right = build(m + 1, r);
            return root;
        };
        inorder(root);
        return build(0, res.size() - 1);
    }
};
