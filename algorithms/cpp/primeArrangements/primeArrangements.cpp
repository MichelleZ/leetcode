// Source: https://leetcode.com/problems/prime-arrangements/
// Author: Miao Zhang
// Date:   2021-04-15

class Solution {
public:
    int numPrimeArrangements(int n) {
        int kMod = 1e9 + 7;
        int p = 0;
        for (int i = 0; i <= n; i++) {
            p += isPrime(i);
        }
        long res = 1;
        for (int i = 1; i <= p; i++) {
            res = (res * i) % kMod;
        }
        for (int i = 1; i <= n - p; i++) {
            res = (res * i) % kMod;
        }
        return res;
    }

private:
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x == 2) return true;
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
};
