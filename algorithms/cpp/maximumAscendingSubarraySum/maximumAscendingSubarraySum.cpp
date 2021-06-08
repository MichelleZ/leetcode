// Source: https://leetcode.com/problems/maximum-ascending-subarray-sum/
// Author: Miao Zhang
// Date:   2021-06-08

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sums = nums[0], res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sums += nums[i];
            } else {
                res = max(res, sums);
                sums = nums[i];
            }
        }
        res = max(res, sums);
        return res;
    }
};
