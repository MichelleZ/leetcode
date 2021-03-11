// Source: https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/
// Author: Miao Zhang
// Date:   2021-03-11

class Solution {
public:
    int preimageSizeFZF(int K) {
        return g(K) - g(K - 1);
    }

private:
    int g(int K) {
        long l = 0;
        long r = LONG_MAX;
        while (l < r) {
            long m = l + (r - l) / 2;
            long zeros = numZeros(m);
            if (zeros <= K)
                l = m + 1;
            else
                 r = m;
        }
        return l;
    }

    long numZeros(long n) {
        return n < 5 ? 0 : n / 5 + numZeros(n / 5);
    }
};
