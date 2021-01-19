// Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author: Miao Zhang
// Date:   2021-01-18

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        else if (root->left && root->right == nullptr) {
            return minDepth(root->left) + 1;
        } else if (root->left == nullptr && root->right) {
            return minDepth(root->right) + 1;
        } else {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
    }
};
