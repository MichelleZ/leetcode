// Source: https://leetcode.com/problems/number-of-1-bits/
// Author: Miao Zhang
// Date:   2021-01-25

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n = n & (n - 1);
            res += 1;
        }
        return res;
    }
};
