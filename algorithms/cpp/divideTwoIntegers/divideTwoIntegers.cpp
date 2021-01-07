// Source: https://leetcode.com/problems/divide-two-integers/
// Author: Miao Zhang
// Date:   2021-01-07

class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag = (dividend > 0) ^ (divisor > 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
        int res = 0;
        while (dividend >= divisor) {
            int multidivisor = divisor , multi = 1;
            while (dividend >= multidivisor) {
                res += multi;
                dividend -= multidivisor;
                multi = multi << 1;
                multidivisor = multidivisor << 1;
            }
        }
        if (flag) {
            res *= -1;
        }
        
        if (INT_MIN <= res <= INT_MAX) {
            return res;
        }
        return INT_MAX;
    }
};
