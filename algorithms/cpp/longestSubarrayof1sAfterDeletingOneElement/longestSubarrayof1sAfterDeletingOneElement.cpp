// Source: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// Author: Miao Zhang
// Date:   2021-05-11

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int sums = 0;
        int res = 0;
        for (int r = 0; r < n; r++) {
            sums += nums[r];
            while (l < r && sums < r - l) {
                sums -= nums[l++];
            }
            res = max(res, r - l);
        }
        return res;
    }
};
