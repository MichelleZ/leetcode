// Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author: Miao Zhang
// Date:   2021-01-18

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        int mid = nums.size() / 2;
        return sortedArrayToBSTCore(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArrayToBSTCore(vector<int>& nums, int start, int end) {
        if (end < start) return nullptr;
        int mid = (end + start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTCore(nums, start, mid - 1);
        root->right = sortedArrayToBSTCore(nums, mid + 1, end);
        return root;
    }
};
