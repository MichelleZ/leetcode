// Source: https://leetcode.com/problems/path-sum-iii/
// Author: Miao Zhang
// Date:   2021-02-11

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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        if (!root) return res;
        res += containRootPathSum(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }
    
    int containRootPathSum(TreeNode* root, int sum) {
        int res = 0;
        if (!root) return res;
        if (root->val == sum) res++;
        res += containRootPathSum(root->left, sum - root->val);
        res += containRootPathSum(root->right, sum - root->val);
        return res;
    }
};
