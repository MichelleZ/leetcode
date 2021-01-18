// Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() && inorder.empty()) return nullptr;
        return buildTreeCore(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeCore(vector<int>& preorder, vector<int>& inorder, int pre_pos, int in_left, int in_right) {
        if (pre_pos >= preorder.size()) return nullptr;
        int val = preorder[pre_pos];
        int in_pos;
        if (in_left > in_right) return nullptr;
        for (int i = in_left; i <= in_right; i++) {
            if (inorder[i] == val) {
                in_pos = i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(val);
        root->left = buildTreeCore(preorder, inorder, pre_pos + 1, in_left, in_pos - 1);
        root->right = buildTreeCore(preorder, inorder, pre_pos + in_pos - in_left + 1, in_pos + 1, in_right);
        return root;
    }
};
