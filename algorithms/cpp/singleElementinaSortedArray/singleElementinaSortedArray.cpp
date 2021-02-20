// Source: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // int n = m % 2 == 0 ? m + 1 : m - 1
            int n = mid ^ 1;
            if (nums[mid] == nums[n]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
