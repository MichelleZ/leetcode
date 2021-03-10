// Source: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// Author: Miao Zhang
// Date:   2021-03-10

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
    int minDiffInBST(TreeNode* root) {
        mindiff_ = INT_MAX;
        prev_ = nullptr;
        inorder(root);
        return mindiff_;
    }

private:
    int mindiff_;
    int* prev_;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        if (prev_ != nullptr) {
            mindiff_ = min(mindiff_, abs(root->val - *prev_));
        }
        prev_ = &root->val;
        inorder(root->right);
    }
};
