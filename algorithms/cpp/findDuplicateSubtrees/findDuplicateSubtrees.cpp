// Source: https://leetcode.com/problems/find-duplicate-subtrees/
// Author: Miao Zhang
// Date:   2021-02-26

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> cnts;
        vector<TreeNode*> res;
        serialize(root, cnts, res);
        return res;
    }

private:
    string serialize(TreeNode* root, unordered_map<string, int>& cnts, vector<TreeNode*>& res) {
        if (!root) return "#";
        string key = to_string(root->val) + ","
                     + serialize(root->left, cnts, res) + ","
                     + serialize(root->right, cnts, res);
        if (++cnts[key] == 2) res.push_back(root);
        return key;
    }
};
