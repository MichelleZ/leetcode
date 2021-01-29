// Source: https://leetcode.com/problems/missing-number/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int shouldsum = (n + 1) * n / 2;
        return shouldsum - accumulate(nums.begin(), nums.end(), 0);
    }
};
