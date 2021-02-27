// Source: https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> left;
        res = 0;
        dfs(root, 0, 0, left);
        return res;
    }

    void dfs(TreeNode* root, int depth, long long pos, vector<int>& left) {
        if (!root) return;
        if (depth == left.size()) left.push_back(pos);
        res = max(res, int(pos - left[depth] + 1));
        dfs(root->left, depth + 1, (pos - left[depth]) * 2, left);
        dfs(root->right, depth + 1, (pos - left[depth]) * 2 + 1, left);
    }
private:
    int res;

};
