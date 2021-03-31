// Source: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Author: Miao Zhang
// Date:   2021-03-31

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(vals_.begin(), vals_.end(), [] (const vector<int>& v1, const vector<int>& v2) {
            if (v1[0] != v2[0]) {
                return v1[0] < v2[0];
            } else if (v1[1] != v2[1]) {
                return v1[1] < v2[1];
            }
            return v1[2] < v2[2];
        });
        vector<vector<int>> res;
        int lastx = -1000;
        for (auto& v: vals_) {
            if (v[0] != lastx) {
                res.push_back({});
                lastx = v[0];
            }
            res.back().push_back(v[2]);
        }
        return res;
    }

private:
    vector<vector<int>> vals_;
    void dfs(TreeNode* root, int x, int y) {
        if (!root) return;
        vals_.push_back({x, y, root->val});
        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }

};
