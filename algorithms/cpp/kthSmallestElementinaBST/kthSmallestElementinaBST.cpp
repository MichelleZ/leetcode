// Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author: Miao Zhang
// Date:   2021-01-28

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode* node = st.top();
                k--;
                if (k == 0) return node->val;;
                st.pop();
                root = node->right;
            }
        }
        return -1;
    }
};
