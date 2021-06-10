// Source: https://leetcode.com/problems/maximum-xor-for-each-query/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxval = (1 << maximumBit) - 1;
        int n = nums.size();
        int sums = 0;
        for (int num: nums) sums ^= num;
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            res[n - 1 - i] = sums ^ maxval;
            sums ^= nums[i];
        }
        return res;
    }
};
