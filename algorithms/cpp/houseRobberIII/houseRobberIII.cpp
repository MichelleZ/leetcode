// Source: https://leetcode.com/problems/house-robber-iii/
// Author: Miao Zhang
// Date:   2021-02-03

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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dic;
        return dfs(root, dic);
    }
    
    int dfs(TreeNode* root, unordered_map<TreeNode*, int> &dic) {
        if (!root) return 0;
        if (dic.count(root)) return dic[root];
        int val = root->val;
        int ll = root->left ? dfs(root->left->left, dic) : 0;
        int lr = root->left ? dfs(root->left->right, dic) : 0;
        int rl = root->right ? dfs(root->right->left, dic) : 0;
        int rr = root->right ? dfs(root->right->right, dic) : 0;
        dic[root] = max(val + ll + lr + rl + rr, dfs(root->left, dic) + dfs(root->right, dic));
        return dic[root];
    }
};
