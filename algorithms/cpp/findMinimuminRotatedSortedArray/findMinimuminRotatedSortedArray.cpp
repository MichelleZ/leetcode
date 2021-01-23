// Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Author: Miao Zhang
// Date:   2021-01-22

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findmin(nums, 0, nums.size() - 1);
    }
    
    int findmin(vector<int>& nums, int l, int r) {
        if (l + 1 >= r) {
            return min(nums[l], nums[r]);
        }
        if (nums[l] < nums[r]) {
            return nums[l];
        }
        int mid = (l + r) / 2;
        return min(findmin(nums, l, mid - 1), findmin(nums, mid, r));
    }
    
};
