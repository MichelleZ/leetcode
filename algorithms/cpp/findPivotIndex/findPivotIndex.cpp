// Source: https://leetcode.com/problems/find-pivot-index/submissions/
// Author: Miao Zhang
// Date:   2021-03-04

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l = 0;
        int r = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) {
            r -= nums[i];
            if (l == r) return i;
            l += nums[i];
        }
        return -1;
    }
};
