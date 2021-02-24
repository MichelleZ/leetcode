// Source: https://leetcode.com/problems/construct-string-from-binary-tree/
// Author: Miao Zhang
// Date:   2021-02-24

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
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string s = std::to_string(t->val);
        if (!t->left && !t->right) return s;
        if (!t->right) {
            return s + "(" + tree2str(t->left) + ")";
        }
        return s + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
    }
};
