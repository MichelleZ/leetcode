// Source: https://leetcode.com/problems/super-ugly-number/
// Author: Miao Zhang
// Date:   2021-02-01

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        set<int> s{begin(primes), end(primes)};
        for (int i = 0; i < n - 2; i++) {
            auto it = begin(s);
            int t = *it;
            s.erase(it);
            for (int p: primes) {
                if (INT_MAX / t < p) continue;
                s.insert(p * t);
            }
        }
        return *begin(s);
    }
};
