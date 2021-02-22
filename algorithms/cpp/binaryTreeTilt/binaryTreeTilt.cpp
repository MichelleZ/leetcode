// Source: https://leetcode.com/problems/binary-tree-tilt/
// Author: Miao Zhang
// Date:   2021-02-22

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
    int findTilt(TreeNode* root) {
        int res = 0;
        postorder(root, res);
        return res;
    }

private:
    int postorder(TreeNode* root, int& res) {
        if (!root) return 0;
        int lsum = postorder(root->left, res);
        int rsum = postorder(root->right, res);
        res += abs(lsum - rsum);
        return lsum + rsum + root->val;
    }
};
