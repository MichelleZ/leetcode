// Source: https://leetcode.com/problems/maximum-binary-tree/
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return construct(nums, 0, nums.size() - 1);
    }

    TreeNode* construct(vector<int>& nums, int i, int j) {
        if (j < i) return nullptr;
        auto it = std::max_element(nums.begin() + i, nums.begin() + j + 1);
        TreeNode* root = new TreeNode(*it);
        int idx = it - nums.begin();
        root->left = construct(nums, i, idx - 1);
        root->right = construct(nums, idx + 1, j);
        return root;
    }
};
