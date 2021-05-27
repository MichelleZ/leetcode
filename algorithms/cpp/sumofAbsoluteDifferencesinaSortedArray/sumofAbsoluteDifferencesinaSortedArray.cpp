// Source: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int sums = 0;
        for (int i = 1; i < n; i++) {
            sums += (nums[i] - nums[i - 1]) * i;
            res[i] += sums;
        }
        sums = 0;
        for (int i = n - 2; i >= 0; i--) {
            sums += (nums[i + 1] - nums[i]) * (n - i - 1);
            res[i] += sums;
        }
        return res;
    }
};
