// Source: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// Author: Miao Zhang
// Date:   2021-04-05

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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return maxDiff(root, root->val, root->val);
    }

private:
    int maxDiff(TreeNode* root, int l, int r) {
        if (!root) return 0;
        int cur = max(abs(root->val - l), abs(root->val - r));
        l = min(l, root->val);
        r = max(r, root->val);
        return max(cur, max(maxDiff(root->left, l, r),
                        maxDiff(root->right, l, r)));
    }
};
