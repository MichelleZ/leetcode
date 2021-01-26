// Source: https://leetcode.com/problems/minimum-size-subarray-sum/
// Author: Miao Zhang
// Date:   2021-01-25

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int res = INT_MAX;
        int cursum = 0;
        while (r < nums.size()) {
            cursum += nums[r];
            while (cursum >= s) {
                res = min(res, r - l + 1);
                cursum -= nums[l];
                l += 1;
            }
            r += 1;
        }
        return (res != INT_MAX) ? res : 0;
    }
};
