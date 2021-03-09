// Source: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Author: Miao Zhang
// Date:   2021-03-08

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
        for (int x = L; x <= R; x++) {
            int cnt = 0;
            for (int j = x; j > 0;  j >>= 1) {
                cnt += j & 1;
            }
            res += primes.count(cnt);
        }
        return res;
    }
};
