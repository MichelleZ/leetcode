// Source: https://leetcode.com/problems/powx-n/
// Author: Miao Zhang
// Date:   2021-01-12

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
            long long i = n;
            return 1.0 / myPow(x, -i);
        }
        if (n % 2) return x * myPow(x, n - 1);
        return myPow(x * x, n / 2);
    }
};
