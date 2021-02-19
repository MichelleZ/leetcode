// Source: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Author: Miao Zhang
// Date:   2021-02-19

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        inorder(root, 0, res);
        return res;
    }

private:
    void inorder(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        while (res.size() <= level) res.push_back(INT_MIN);
        inorder(root->left, level + 1, res);
        res[level] = max(res[level], root->val);
        inorder(root->right, level + 1, res);
    }
};
