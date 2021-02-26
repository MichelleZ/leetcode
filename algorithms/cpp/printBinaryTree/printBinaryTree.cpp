// Source: https://leetcode.com/problems/print-binary-tree/
// Author: Miao Zhang
// Date:   2021-02-26

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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int w = (1 << h) - 1;
        vector<vector<string>> res(h, vector<string>(w, ""));
        fill(root, res, 0, 0, w - 1);
        return res;
    }

private:
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void fill(TreeNode* root, vector<vector<string>>& res, int h, int l, int r) {
        if (!root) return;
        int mid = (l + r) / 2;
        res[h][mid] = std::to_string(root->val);
        fill(root->left, res, h + 1, l, mid - 1);
        fill(root->right, res, h + 1, mid + 1, r);
    }
};
