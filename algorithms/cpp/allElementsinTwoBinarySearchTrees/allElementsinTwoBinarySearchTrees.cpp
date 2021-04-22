// Source: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Author: Miao Zhang
// Date:   2021-04-22

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        function<void(TreeNode*, stack<TreeNode*>&)> smallest = [&] (TreeNode* root, stack<TreeNode*>& s) {
            if (!root) return;
            s.push(root);
            smallest(root->left, s);
        };
        smallest(root1, s1);
        smallest(root2, s2);
        vector<int> res;
        while (!s1.empty() || !s2.empty()) {
            stack<TreeNode*>& s = s1.empty() ? s2 : s2.empty() ? s1 : s1.top()->val < s2.top()->val ? s1 : s2;
            TreeNode* n = s.top();
            s.pop();
            res.push_back(n->val);
            smallest(n->right, s);
        }
        return res;
    }
};
