// Source: https://leetcode.com/problems/add-one-row-to-tree/
// Author: Miao Zhang
// Date:   2021-02-25

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root) return root;
        if (d == 1) {
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            root = newroot;
        } else if (d == 2) {
            TreeNode* newleft = new TreeNode(v);
            TreeNode* newright = new TreeNode(v);
            newleft->left = root->left;
            newright->right = root->right;
            root->left = newleft;
            root->right = newright;
        } else {
            addOneRow(root->left, v, d - 1);
            addOneRow(root->right, v, d - 1);
        }
        return root;
    }
};
