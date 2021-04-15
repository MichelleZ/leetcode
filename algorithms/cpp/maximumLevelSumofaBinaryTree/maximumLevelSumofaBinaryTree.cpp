// Source: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Author: Miao Zhang
// Date:   2021-04-15

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
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;

        function<void(TreeNode*, int)> preorder = [&] (TreeNode* node, int level) {
            if (!node) return;
            if (sums.size() == level - 1) sums.push_back(0);
            sums[level - 1] += node->val;
            preorder(node->left, level + 1);
            preorder(node->right, level + 1);
        };

        preorder(root, 1);
        int res = 1;
        int maxsum = sums[0];
        for (int i = 1; i < sums.size(); i++) {
            if (sums[i] > maxsum) {
                maxsum = sums[i];
                res = i + 1;
            }
        }
        return res;
    }
};
