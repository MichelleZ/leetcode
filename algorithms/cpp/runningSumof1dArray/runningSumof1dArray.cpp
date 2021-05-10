// Source: https://leetcode.com/problems/running-sum-of-1d-array/
// Author: Miao Zhang
// Date:   2021-05-10

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
