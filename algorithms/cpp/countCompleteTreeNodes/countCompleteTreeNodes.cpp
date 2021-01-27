// Source: https://leetcode.com/problems/count-complete-tree-nodes/
// Author: Miao Zhang
// Date:   2021-01-27

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        if (left_height == right_height) {
            return pow(2, left_height) + countNodes(root->right);
        } else {
            return pow(2, right_height) + countNodes(root->left);
        }
    }
    
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
};
