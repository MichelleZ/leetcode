// Source: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: Miao Zhang
// Date:   2021-01-21

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
    void preorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);
        preorder(node->left, res);
        preorder(node->right, res);
    }
};

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            } else {
                TreeNode* node = st.top();
                st.pop();
                root = node->right;
            }
        }
        return res;
    }
};
