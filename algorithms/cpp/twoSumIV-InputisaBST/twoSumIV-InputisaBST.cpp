// Source: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int sums = nums[l] + nums[r];
            if (sums == k) {
                return true;
            } else if (sums > k) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }

    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};
