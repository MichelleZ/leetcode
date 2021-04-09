// Source: https://leetcode.com/problems/delete-nodes-and-return-forest/
// Author: Miao Zhang
// Date:   2021-04-09

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s{begin(to_delete), end(to_delete)};
        function<TreeNode*(TreeNode*)> del = [&](TreeNode* n) -> TreeNode* {
            if (!n) return nullptr;
            if (n->left) n->left = del(n->left);
            if (n->right) n->right = del(n->right);
            if (!s.count(n->val)) return n;
            if (n->left) res.push_back(n->left);
            if (n->right) res.push_back(n->right);      
            return nullptr;
        };
        TreeNode* r = del(root);
        if (r) res.push_back(r);
        return res;
    }
};
