// Source: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// Author: Miao Zhang
// Date:   2021-06-16

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; i++) {
            res = max(res, nums[i] + nums[n - 1 - i]);
        }
        return res;
    }
};
