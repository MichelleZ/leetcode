// Source: https://leetcode.com/problems/next-permutation/
// Author: Miao Zhang
// Date:   2021-01-07

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0) {
            if (nums[i - 1] >= nums[i]) i--;
            else break;
        }
        if (i == 0) {
            return sort(nums.begin(), nums.end());
        }
        int j = i - 1;
        for (i = nums.size() - 1; i > j; i--) {
            if (nums[i] > nums[j]) break;
        }
        swap(nums[i], nums[j]);
        sort(nums.begin() + j + 1, nums.end());
    }
};
