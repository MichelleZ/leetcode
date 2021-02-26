// Source: https://leetcode.com/problems/maximum-average-subarray-i/
// Author: Miao Zhang
// Date:   2021-02-26

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sums = 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) sums -= nums[i - k];
            sums += nums[i];
            if (i + 1 >= k) res = max(res, sums);
        }
        return static_cast<double>(res) / k;
    }
};
