// Source: https://leetcode.com/problems/sum-of-two-integers/
// Author: Miao Zhang
// Date:   2021-02-04

class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b & 0x7fffffff) << 1);
    }
};
