// Source: https://leetcode.com/problems/nth-magical-number/
// Author: Miao Zhang
// Date:   2021-03-21

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int kMod = 1000000007;
        long l = 2;
        long r = 1e15;
        int d = gcd(a, b);
        while (l < r) {
            long m = l + (r - l) / 2;
            if (m / a + m / b - m / (a * b / d) < n) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l % kMod;
    }

private:
    int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
};
