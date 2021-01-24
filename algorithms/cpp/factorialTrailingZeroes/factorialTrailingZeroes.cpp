// Source: https://leetcode.com/problems/factorial-trailing-zeroes/
// Author: Miao Zhang
// Date:   2021-01-24

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n >= 5) {
            n /= 5;
            res += n;
        }
        return res;
    }
};
