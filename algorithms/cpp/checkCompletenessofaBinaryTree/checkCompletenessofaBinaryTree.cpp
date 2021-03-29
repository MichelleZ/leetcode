// Source: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Author: Miao Zhang
// Date:   2021-03-29

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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool missing = false;
        while (!q.empty()) {
            auto size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                if (node) {
                    if (missing) return false;
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    missing = true;
                }
            }
        }
        return true;
    }
};
