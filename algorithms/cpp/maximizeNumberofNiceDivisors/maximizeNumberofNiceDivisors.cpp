// Source: https://leetcode.com/problems/maximize-number-of-nice-divisors/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        int kMod = 1e9 + 7;
        function<long(long, int)> pow = [&] (long base, int exp) {
            long res = 1;
            while (exp) {
                if (exp & 1) res = (res * base) % kMod;
                base = (base * base) % kMod;
                exp >>= 1;
            }
            return res;
        };
        if (primeFactors <= 3) return primeFactors;
        if (primeFactors % 3 == 0) {
            return pow(3, primeFactors / 3);
        } else if (primeFactors % 3 == 1) {
            return (pow(3, primeFactors / 3 - 1) * 4) % kMod;
        } else {
            return (pow(3, primeFactors / 3) * 2) % kMod;
        }
        return -1;
    }
};
