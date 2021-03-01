// Source: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
// Author: Miao Zhang
// Date:   2021-02-28

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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        return dfs(root, root->val);
    }
private:
    int dfs(TreeNode* root, int s1) {
        if (!root) return -1;
        if (root->val > s1) return root->val;
        int sl = dfs(root->left, s1);
        int sr = dfs(root->right, s1);
        if (sl == -1) return sr;
        if (sr == -1) return sl;
        return min(sl, sr);
    }
};
