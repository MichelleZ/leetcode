// Source: https://leetcode.com/problems/cousins-in-binary-tree/
// Author: Miao Zhang
// Date:   2021-03-31

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
    bool isCousins(TreeNode* root, int x, int y) {
        preorder(root, nullptr, 0, x, y);
        return px_ != py_ && dx_ == dy_;
    }

private:
    TreeNode* px_;
    TreeNode* py_;
    int dx_;
    int dy_;
    
    void preorder(TreeNode* root, TreeNode* parent, int d, int x, int y) {
        if (!root) return;
        if (root->val == x) {
            px_ = parent;
            dx_ = d;
        }
        if (root->val == y) {
            py_ = parent;
            dy_ = d;
        }
        preorder(root->left, root, d + 1, x, y);
        preorder(root->right, root, d + 1, x, y);
    }
    
};
