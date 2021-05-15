// Source: https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/
// Author: Miao Zhang
// Date:   2021-05-15

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int high = 0;
        for (int x: nums) {
            high = max(high, 31 - __builtin_clz(x | 1));
            res += std::bitset<32>(x).count();
        }
        return res + high;
    }
};
