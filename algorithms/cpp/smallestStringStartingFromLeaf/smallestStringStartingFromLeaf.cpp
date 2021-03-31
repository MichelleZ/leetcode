// Source: https://leetcode.com/problems/smallest-string-starting-from-leaf/
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
    string smallestFromLeaf(TreeNode* root) {
        string tmp;
        dfs(root, tmp);
        return res;
    }
private:
    string res = "|";
    void dfs(TreeNode* node, string& tmp) {
        if (!node) return;
        tmp.push_back('a' + node->val);
        if (!node->left && !node->right) {
            reverse(tmp.begin(), tmp.end());
            res = min(res, tmp);
            reverse(tmp.begin(), tmp.end());
        }
        dfs(node->left, tmp);
        dfs(node->right, tmp);
        tmp.pop_back();
    }
};
