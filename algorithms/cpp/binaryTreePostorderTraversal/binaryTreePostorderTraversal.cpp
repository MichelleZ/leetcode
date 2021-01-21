// Source: https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    
    void postorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                res.push_back(root->val);
                st.push(root);
                root = root->right;
            } else {
                TreeNode* node = st.top();
                st.pop();
                root = node->left;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
