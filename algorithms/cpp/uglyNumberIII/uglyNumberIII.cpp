// Source: https://leetcode.com/problems/ugly-number-iii/
// Author: Miao Zhang
// Date:   2021-04-17

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long l = 1;
        long r = INT_MAX;
        long ab = lcm(a, b);
        long ac = lcm(a, c);
        long bc = lcm((long)b, (long)c);
        long abc = lcm(ab, c);
        while (l < r) {
            long m = l + (r - l) / 2;
            long k = m / a + m / b + m / c - m / ac - m / ab - m / bc + m / abc;
            if (k >= n) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
