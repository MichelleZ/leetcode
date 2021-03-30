// Source: https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
// Author: Miao Zhang
// Date:   2021-03-29

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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        int pos = 0;
        solve(root, voyage, pos, res);
        if (!res.empty() && res[0] == -1) return {-1};
        return res;
    }

private:
    void solve(TreeNode* root, vector<int>& voyage, int& pos, vector<int>& res) {
        if (!root) return;
        if (root->val != voyage.at(pos)) {
            res.clear();
            res.push_back(-1);
            return;
        }
        if (root->left && root->left->val != voyage.at(pos + 1)) {
            swap(root->left, root->right);
            res.push_back(root->val);
        }
        pos++;
        solve(root->left, voyage, pos, res);
        solve(root->right, voyage, pos, res);
    }
};
