// Source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() && postorder.empty()) return nullptr;
        return buildTreeCore(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTreeCore(vector<int>& inorder, vector<int>& postorder, int in_left, int in_right, int post_left, int post_right) {
        if (post_right < 0) return nullptr;
        int val = postorder[post_right];
        int in_pos;
        if (in_left > in_right) return nullptr;
        for (int i = in_left; i <= in_right; i++) {
            if (inorder[i] == val) {
                in_pos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(val);
        root->left = buildTreeCore(inorder, postorder, in_left, in_pos - 1, post_left, post_left + in_pos - in_left - 1);
        root->right = buildTreeCore(inorder, postorder, in_pos + 1, in_right, post_left + in_pos - in_left, post_right - 1);
        return root;
    }
};
